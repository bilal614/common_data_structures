#ifndef BIN_SRCH_TREE

#include "binary_tree.h"
#include <memory>

#define BIN_SRCH_TREE

template <typename K, typename V>
class Entry
{
	public:
		typedef K Key;
		typedef V Value;
	public: 
		Entry(const K& k = K(), const V& v = V()): _key(k), _value(v){}
		const K& key() const { return _key; }
		const V& value() const { return _value; }
		void setKey(const K& k) { _key = k; }
		void setValue(const V& v) { _value = v; }
		bool operator==(const Entry& p) const { return this->key() == p.key(); }
		
		friend std::ostream& operator<<(std::ostream& os, const Entry& pos);
	private:
		K _key;
		V _value;
};

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const Entry<K,V>& pos)  
{  
	os << "(" << pos->_key << ", " << pos->_value << ")";  
	return os;  
}
//template <typename K, typename V>
//typedef typename 

template <typename E>
class SearchTree
{
	public:
		
		typedef typename E::Key K;
		typedef typename E::Value V;
		class Iterator; // an iterator/position
		
		//class Entry<K,V>;
		
	public:
		SearchTree(); //constructor
		int size() const;
		bool empty() const;
		Iterator find(const K& k);
		Iterator insert(const K& k, const V& x);
		void erase(const K& k); //should throw exception when an element does not exist but we keep it simple here
		void erase(const Iterator& p); 
		Iterator begin();
		Iterator end();
		~SearchTree();
		void printTree();
	protected:
		typedef LinkedBinaryTree<E> BinaryTree;
		typedef typename LinkedBinaryTree<E>::Position TPos;
		TPos root() const;
		TPos finder(const K& k, const TPos& v);
		TPos inserter(const K& k, const V& x);
		TPos eraser(TPos& p);
		TPos restructure(const TPos& p); //restructure
	private:
		BinaryTree T; //linked binary tree
		int n;	//number of entries
		
	public:
		class Iterator
		{
			private:
				TPos v;//position entry
			public:
				Iterator(TPos& vv): v(vv) { /*std::cout << __PRETTY_FUNCTION__ << std::endl;*/ }//constructor: direct initialization for object of type Entry
				const E& operator *() const { return (*v); } //get entry(read only)
				E& operator *() { return (*v); }//read/write access
				bool operator==(const Iterator& p) const { return v == p.v; }
				Iterator& operator++();
				friend class SearchTree;
				~Iterator(){ v = nullptr; }
		};
};


template < class E >
typename SearchTree<E>::Iterator& SearchTree<E>::Iterator::operator++()
{
	TPos w = v.right();
	if(w.isInternal())
	{
		do{v = w; w = w.left(); }
		while(!w.isExternal());
	}
	else
	{
		w = v.parent();
		while(v == w.right())
		{
			v = w; 
			w = w.parent();
		}
		v = w;
	}
	return *this;
}

template < class E >
SearchTree<E>::SearchTree(): T(), n(0)
{
		T.addRoot();
		T.expandExternal(T.root());
}

template < class E >
SearchTree<E>::~SearchTree()
{
	auto it = begin();
	auto a_root = root();
	auto ending = Iterator(a_root);
	while((it == ending) == false)
	{
		erase(it);
		it = begin();
	}
}

template < class E >
typename SearchTree<E>::TPos SearchTree<E>::root() const
{
	TPos myRoot = T.root().node->_left;
	return myRoot;
}

template < class E >
typename SearchTree<E>::Iterator SearchTree<E>::begin()
{
	TPos v = root();
	while(v.isInternal())
	{
		v = v.left();
	}
	auto a_parent = v.parent(); 
	return Iterator(a_parent);
}

template < class E >
typename SearchTree<E>::Iterator SearchTree<E>::end()
{
	auto a_root = T.root();
	return Iterator(a_root);
}

template < class E >
typename SearchTree<E>::TPos SearchTree<E>::finder(const K& k, const TPos& v)
{
	if(v.isExternal()) return v;
	if(k < v.node->element.key())
	{
		TPos a_left = v.left();
		return finder(k, a_left);
	}
	else if(v.node->element.key() < k)
	{
		TPos a_right = v.right();
		return finder(k, a_right);
	}
	return v;
}


template < class E >
typename SearchTree<E>::Iterator SearchTree<E>::find(const K& k)
{
	TPos v = finder(k, root());
	if(v.isInternal()) return Iterator(v);
	else return end();
}

template < class E >
typename SearchTree<E>::TPos SearchTree<E>::inserter(const K& k, const V& x)
{
	TPos v = finder(k, root());
	while(v.isInternal())
	{
		auto move_on = v.right(); 
		v = finder(k, move_on);
	}
	T.expandExternal(v);
	
	v.node->element.setKey(k);
	v.node->element.setValue(x);
	n++;
	return v;
}


template < class E >
typename SearchTree<E>::Iterator SearchTree<E>::insert(const K& k, const V& x)
{
	TPos v = inserter(k, x);
	return Iterator(v);  
}

template < class E >
typename SearchTree<E>::TPos SearchTree<E>::eraser(TPos& p)
{
	TPos w;
	if(p.left().isExternal()) w = p.left();
	else if(p.right().isExternal()) w = p.right();
	else
	{
		w = p.right();
		do{ w = w.left(); }while(!w.isExternal());
		TPos u = w.parent();
		p.node->element.setKey(u.node->element.key());
		p.node->element.setValue(u.node->element.value());
		//p.setKey(u->key()); p->setValue(u->value());
	}
	n--;
	return T.removeAboveExternal(w);
}


template < class E >
void SearchTree<E>::erase(const K& k)
{
	TPos v = finder(k, root());
	if(v.isExternal())
		return 
	eraser(v);  
}

template < class E >
void SearchTree<E>::erase(const Iterator& p)
{
	auto _erase_TPos = p.v;
	eraser(_erase_TPos);  
}

template < class E >
void SearchTree<E>::printTree()
{
	
	auto it = begin();
	auto ending = end();
	while((it == ending) == false)
	{
			std::cout << (*it).key() << ", " << (*it).value() << std::endl;
		++it;
	}
}

#endif
