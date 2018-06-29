#ifndef TREE_INTERFACE

#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>
#include <list>
#include <algorithm>    // std::for_each
#include <iterator>

#define TREE_INTERFACE 

template <typename T>
class NodeList;

template <typename T, typename N>
class Node
{
	public:
		T element;
		N* prev = NULL;//previous node in the list
		N* next = NULL;//next node in the list
	
};

template <typename T>
class Position: public Node< T, Position<T> >
{
	private:
		Position* _parent;//previous node in the list
		typename NodeList< T >::NodeList* _children = NULL;
	
	public:
		friend class NodeList<T>;
		
		template<typename E>//use different name than T to avoid shadowing template parameters
		friend std::ostream& operator<<(std::ostream& os, const Position<T>& pos);  

	public:
		Position(){this->prev = NULL; this->next = NULL;}
		Position(T elem);
		Position(T elem, Position* prnt);
		T& operator *();	//get element
		Position* parent() const;	//get parent
		typename NodeList< T >::NodeList* children() const;	//get node's children
		bool isRoot() const;	//root node?
		bool isExternal() const;	//external node?
		
		/*The following functions may be part of a Tree class, but for simple explanation purposes I keep them in the Position class.*/
		void addChild(T e);
		int depth();
		int height();
		void preorderPrint();
		void postorderPrint();
		
};

template <typename T>
class NodeList
{
	public:
		class Iterator
		{
			public:
				//NOTE: You must ensure that the Iterator does not go out of bound.
				T& operator*();//reference to the element
				bool operator==(const Iterator& p) const;//compare positions
				bool operator!=(const Iterator& p) const;
				Iterator& operator++();//move to next position
				Iterator& operator--();//move to previous position
				Iterator& operator+( int pos);
				Iterator& operator-( int pos);

				friend class NodeList;
			//private:
			public:
				Position<T>* v;//pointer to node
				Iterator(Position<T>* u);//create from node

		};
	public:
		NodeList();//default constructor
		//~NodeList();
		int size() const;//list size
		bool empty() const;//is the list empty
		Iterator begin() const;//beginning position
		Iterator end() const;//(just beyond) last position
		void insert(const Iterator& p, const T& e);//insert e before p
		void insertFront(const T& e);//insert at front
		void insertFront(Position<T>* p);//overloaded
		void insertBack(const T& e);//insert at rear
		void erase(const Iterator& p);//remove p
		void eraseFront();//remove first
		void eraseBack();//remove last
		void printElements();
		//friend class Position;

	private: //data members
		int n;//number of items
		Position<T>* header;//head of list sentinel
		Position<T>* trailer;//tail of list sentinel
};




template <typename T>
std::ostream& operator<<(std::ostream& os, const Position<T>& pos)  
{  
	os << pos->_element->element;  
	return os;  
}


template <typename T>
NodeList<T>::Iterator::Iterator(Position<T>* u)
{
	v = u;	
}

template <typename T>
T& NodeList<T>::Iterator::operator*()
{
	return v->element;
}

template <typename T>
bool NodeList<T>::Iterator::operator==(const Iterator& p) const
{
	return v == p.v;
}

template <typename T>
bool NodeList<T>::Iterator::operator!=(const Iterator& p) const
{
	return v != p.v;
}

template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator++()
{
	v = v->next;
	return *this;
}

template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator--()
{
	v = v->prev;
	return *this;
}

template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator+( int pos)
{
	int i = 0;
	while(i < pos)
	{
		++i;
		v = v->next;
	}
	return *this;
}

template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator-( int pos)
{
	int i = 0;
	while(i < pos)
	{
		++i;
		v = v->prev;
	}
	return *this;
}


template <typename T>
NodeList<T>::NodeList()
{
	n = 0;
	header = new Position<T>;
	trailer = new Position<T>;
	header->next = trailer;
	trailer->prev = header;
}

template <typename T>
int NodeList<T>::size() const
{
	return n;
}


template <typename T>
bool NodeList<T>::empty() const
{
	return (n == 0);
}


template <typename T>
typename NodeList<T>::Iterator NodeList<T>::begin() const//begin position is the first item
{
	return (Iterator((this->header)->next));
}

template <typename T>
typename NodeList<T>::Iterator NodeList<T>::end() const//begin position is the first item
{
	return (Iterator(trailer));
}


template <typename T>//insert e before p
void NodeList<T>::insertFront(Position<T>* p)
{

	Position<T>* w = (this->begin()).v;//p's node
	Position<T>* u = w->prev;//p's predecessor
	p->next = w;w->prev = p;//link in v before w
	p->prev = u;u->next = p;
	n++;
}


template <typename T>//insert e before p
void NodeList<T>::insert(const Iterator& p, const T& e)
{
	Position<T>* w = p.v;//p's node
	Position<T>* u = w->prev;//p's predecessor
	Position<T>* v = new Position<T>;//new Node to insert
	v->element = e;
	v->next = w;w->prev = v;//link in v before w
	v->prev = u;u->next = v;
	n++;
}

template <typename T>//insert e before p
void NodeList<T>::insertFront(const T& e)
{
	insert(begin(), e);
}

template <typename T>//insert e before p
void NodeList<T>::insertBack(const T& e)
{
	insert(end(), e);
}

template <typename T>//remove p
void NodeList<T>::erase(const Iterator& p)
{
	Position<T>* v = p.v; //Node to remove
	Position<T>* w = v->next;//successor
	Position<T>* u = v->prev; //predecessor
	w->prev = u; 
	u->next = w;
	delete v;
	n--;
}

template <typename T>
void NodeList<T>::eraseFront()
{
	erase(begin());
}

template <typename T>
void NodeList<T>::eraseBack()
{
	erase(--end());
}

template <typename T>
void NodeList<T>::printElements()
{
	Iterator it(begin());
	Iterator ending(end());
	for(; it != ending; ++it)
	{
		std::cout << (*it) << ", ";
	}
	std::cout << std::endl;
}

template <typename T>
T& Position<T>::operator*()
{
	return this->element;
}


template <typename T>
Position<T>* Position<T>::parent() const
{
	return _parent;
}

template <typename T>
//template <>
typename NodeList< T >::NodeList* Position<T>::children() const
{
	//std::cout << "returning children NodeList"  << std::endl;
	return _children;	
}

template <typename T>
bool Position<T>::isRoot() const	//root node?
{
	if(_parent == NULL)
		return true;
	return false;
}

template <typename T>
bool Position<T>::isExternal() const	//root node?
{
	if(children()->size() != 0)
		return false;
	return true;
}

template <typename T>
void Position<T>::addChild(T e)
{
	Position<T>* temp = new Position<T>(e, this);
	_children->insertFront(temp);
}


template <typename T>
Position<T>::Position(T elem)
{ 
	//std::cout << "creating Node" << std::endl;
	_children = new typename NodeList<T>::NodeList();
	this->element = elem; 
	//std::cout << "created Node" << std::endl;
	this->prev = NULL;
	this->next = NULL;
	_parent = NULL;
}

template <typename T>
Position<T>::Position(T elem, Position* prnt)
{
	if(_children == NULL)
	{
		_children = new typename NodeList<T>::NodeList();
	}
	//std::cout << "parent of elem( " << elem << " ): " << prnt->element << std::endl; 
	this->element = elem; 
	//std::cout << "element initialized " << std::endl; 
	_parent = prnt;
	//std::cout << "parent pointer set" << std::endl; 
}

template <typename T>
int Position<T>::depth()
{
	if(this->isRoot())
		return 0;
	else
		return 1 + (this->parent())->depth();
}

template <typename T>
int Position<T>::height()
{
	if(this->isExternal())
		return 0;
	else
	{
		int h = 0;
		NodeList<T>* ch = this->children(); 
		typename NodeList<T>::Iterator q = ch->begin();
		for(;q!=ch->end();++q)
		{
			h = std::max(h, (q.v)->height());
		}
		return 1 + h;
	}
}

template <typename T>
void Position<T>::preorderPrint()
{
	std::cout << this->element;
	auto ch = this->children();
	for(auto q = ch->begin(); q != ch->end(); ++q)
	{
		std::cout << ", ";
		(q.v)->preorderPrint();
	}
}

template <typename T>
void Position<T>::postorderPrint()
{
	auto ch = this->children();
	for(auto q = ch->begin(); q != ch->end(); ++q)
	{
		(q.v)->postorderPrint();
		std::cout << ", ";
	}
	std::cout << this->element;
}

#endif
