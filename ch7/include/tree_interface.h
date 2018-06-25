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
class NodeList
{
	public:
		class Node
		{
			public:
				T element;
				Node* parent = NULL;//previous node in the list
				NodeList* next = NULL;//next node in the list
				Node(){std::cout << "calling Node constructor" << std::endl;}
				Node* parent() const;	//get parent
				
		};
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
				Node* v;//pointer to node
				Iterator(Node* u);//create from node

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
		void insertBack(const T& e);//insert at rear
		void erase(const Iterator& p);//remove p
		void eraseFront();//remove first
		void eraseBack();//remove last
		void printElements();
		//friend class Position;

	private: //data members
		int n;//number of items
		Node* header;//head of list sentinel
		Node* trailer;//tail of list sentinel
};

template <typename T>
class Position
{
	private:
		typename NodeList<T>::Node* _element;
		Position* _parent = NULL;//previous node in the list
		//Node* next;//next node in the list
		NodeList< Position > _children;
	public:
		//Position(){_element = new typename NodeList<T>::Node;}
		Position(T elem);
		Position(T elem, Position* prnt);
		T& operator *();	//get element
		//T& operator <<();
		Position* parent() const;	//get parent
		NodeList< Position > children() const;	//get node's children
		bool isRoot() const;	//root node?
		bool isExternal() const;	//external node?
		void addChild(T e);
		
};

template <typename T>
NodeList<T>::Iterator::Iterator(Node* u)
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
	header = new Node;
	trailer = new Node;
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
	return (Iterator(header->next));
}

template <typename T>
typename NodeList<T>::Iterator NodeList<T>::end() const//begin position is the first item
{
	return (Iterator(trailer));
}

template <typename T>//insert e before p
void NodeList<T>::insert(const Iterator& p, const T& e)
{
	Node* w = p.v;//p's node
	Node* u = w->prev;//p's predecessor
	Node* v = new Node;//new Node to insert
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
	Node* v = p.v; //Node to remove
	Node* w = v->next;//successor
	Node* u = v->prev; //predecessor
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
		std::cout << *(*it) << ", ";
	}
	std::cout << std::endl;
}

template <typename T>
T& Position<T>::operator*()
{
	return _element->element;
}



template <typename T>
Position<T>* Position<T>::parent() const
{
	return _parent;
}

template <typename T>
//template <>
NodeList< Position<T> > Position<T>::children() const
{
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
void Position<T>::addChild(T e)
{
	Position<T> temp = Position<T>(e, this);
	_children.insertFront(temp._element->element);
}


/*
template <typename T>
Position<T>::Position()
{
	_element = new typename NodeList<T>::Node; 
}
*/

template <typename T>
Position<T>::Position(T elem)
{ 
	std::cout << "creating Node" << std::endl;
	_element = new typename NodeList<T>::Node; 
	std::cout << "created Node" << std::endl;
	_element->element = elem; 
}

template <typename T>
Position<T>::Position(T elem, Position* prnt)
{
	_element = new typename NodeList<T>::Node; 
	_element->element = elem; 
	_parent = prnt;
}

#endif
