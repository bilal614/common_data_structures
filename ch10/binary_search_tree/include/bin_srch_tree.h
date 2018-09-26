#ifndef BIN_SRCH_TREE

#include "binary_tree.h"

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
	private:
		K _key;
		V _value;
};

template < class E >
class SearchTree
{
		public:
			typedef typename E::Key K;
			typedef typename E::Value V;
			class Iterator; // an iterator/position
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
			void printTree();
		protected:
			typedef LinkedBinaryTree<E> BinaryTree;
			typedef Position<E> TPos;
			TPos root();
			TPos finder(const K& k, const TPos& v);
			TPos inserter(const K& k, const V& x);
			TPos eraser(TPos& p);
			TPos restructure(const TPos& p); //restructure
		public:
			bool isInternal(TPos p){ return T.isInternal(p); }
		private:
			BinaryTree T; //linked binary tree
			int n;	//number of entries
			
		public:
			class Iterator
			{
				private:
					TPos v;//position entry
				public:
					Iterator(const TPos& vv): v(vv) {}//constructor: direct initialization for object of type Entry
					const E& operator *() const { return *v; } //get entry(read only)
					E& operator *() { return *v; }
					bool operator==(const Iterator& p) const { return v == p.v; }
					//bool operator!=(const Iterator& p) const { return v != p.v; }
					Iterator& operator++();
					friend class SearchTree;
			};
};


template < class E >
typename SearchTree<E>::Iterator& SearchTree<E>::Iterator::operator++()
{
	TPos w = v.right();
	if(w.isInternal())
	{
		do{v = w; w = w.left(); }
		while(w.isInternal());
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
typename SearchTree<E>::TPos SearchTree<E>::root()
{
	return T.root();
	//return T.root()->left();
}

template < class E >
typename SearchTree<E>::Iterator SearchTree<E>::begin()
{
	TPos v = root();
	while(v.isInternal())
	{
		v = v.left();
	}
	return Iterator(v.parent());
}

template < class E >
typename SearchTree<E>::Iterator SearchTree<E>::end()
{
	return Iterator(T.root());
}

template < class E >
typename SearchTree<E>::TPos SearchTree<E>::finder(const K& k, const TPos& v)
{
	auto _v = v;
	if(_v.isExternal()) return v;
	if(k < (*_v).key())
	{
		return finder(k, _v.left());
	}
	else if((*_v).key() < k)
	{
		return finder(k, _v.right());
	}
	return v;
}


template < class E >
typename SearchTree<E>::Iterator SearchTree<E>::find(const K& k)
{
	TPos v = finder(k, root());
	if(v->isInternal()) return Iterator(v);
	else return end();
}

//INSERTER NOT WORKING PROPERLY
template < class E >
typename SearchTree<E>::TPos SearchTree<E>::inserter(const K& k, const V& x)
{
	if(n== 0)
	{
		auto v = root();
		v.setElement(Entry<K,V>(k, x));
		//(*v).setKey(k);
		//(*v).setValue(x);
		n++;
		return v;
	}
	else
	{
		TPos v = finder(k, root());
		while(v.isInternal())
		{
			v = finder(k, v.right());
		}
		T.expandExternal(&v);
		//auto _v = *v;
		//_v.setKey(k); 
		//_v.setValue(x);
		(*v).setKey(k);
		(*v).setValue(x);
		n++;
		return v;
	}
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
	if(p->left().isExternal()) w = p->left();
	else if(p->right().isExternal()) w = p->right();
	else
	{
		w = p->right();
		do{ w = w->left(); }while(w->isInternal());
		TPos u = w->parent();
		p->setKey(u->key()); p->setValue(u->value());
	}
	n--;
	return T.removeAboveExternal(w);
}


template < class E >
void SearchTree<E>::erase(const K& k)
{
	TPos v = finder(k, root());
	if(v->isExternal())
		return 
	eraser(v);  
}

template < class E >
void SearchTree<E>::erase(const Iterator& p)
{
	eraser(p.v);  
}

template < class E >
void SearchTree<E>::printTree()
{
	auto it = begin();
	auto ending = end();
	//for(; it != ending; ++it)
	while((it == ending) == false)
	{
		std::cout << (*it).key() << ", " << (*it).value() << std::endl;
		++it;
	}
}

#endif
