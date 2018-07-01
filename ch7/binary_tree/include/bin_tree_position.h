#ifndef BIN_TREE_POS


#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>
#include <list>
#include <algorithm>    // std::for_each
#include <iterator>


#define BIN_TREE_POS


template <typename T, typename N>
class Node
{
	protected:
		T element;
		N* _parent;
		N* _left;
		N* _right;
		Node():element(), _parent(nullptr), _left(nullptr), _right(nullptr){}	
		
};

template <typename T>
class Position: public Node< T, Position<T> >
{	
	public:
		T& operator*();
		Position* left() const;
		Position* right() const;
		Position* parent() const;
		void setLeft(Position* l);
		void setRight(Position* r);
		void setParent(Position* p);
		void setElement(T e);
		bool isRoot() const;
		bool isExternal() const;
		Position();
		Position(T elem);
		Position(T elem, Position* prnt);
		Position(Position* p){ Node< T, Position<T> >::element = p->element; 
			Node< T, Position<T> >::_parent = p->parent(); Node< T, Position<T> >::_left = p->left(); 
			Node< T, Position<T> >::_right = p->right();}
		//friend std::ostream& operator<<(std::ostream& os, const Position<T>& pos); 
	
};
/*
template <typename T>
std::ostream& operator<<(std::ostream& os, const Position<T>& pos)  
{  
	os << pos->element;  
	return os;  
}
*/

/* type alias, alias template */
template <typename T>
using PositionList = std::list< Position<T> >;

template <typename T>
T& Position<T>::operator*() 
{
	return Node< T, Position<T> >::element;
}

template <typename T>
Position<T>* Position<T>::left() const
{
	return Node< T, Position<T> >::_left;
}

template <typename T>
Position<T>* Position<T>::right() const
{
	return Node< T, Position<T> >::_right;
}

template <typename T>
Position<T>* Position<T>::parent() const
{
	return Node< T, Position<T> >::_parent;
}

template <typename T>
bool Position<T>::isRoot() const
{
	return (Node< T, Position<T> >::_parent == nullptr);
}

template <typename T>
bool Position<T>::isExternal() const
{
	return ((Node< T, Position<T> >::_left == nullptr) && (Node< T, Position<T> >::_right == nullptr));
}


template <typename T>
void Position<T>::setLeft(Position<T>* l)
{
	Node< T, Position<T> >::_left = l;
}

template <typename T>
void Position<T>::setRight(Position<T>* r)
{
	Node< T, Position<T> >::_right = r;
}

template <typename T>
void Position<T>::setParent(Position<T>* p)
{
	Node< T, Position<T> >::_parent = p;
}

template <typename T>
void Position<T>::setElement(T e)
{
	Node< T, Position<T> >::element = e;
}

template <typename T>
Position<T>::Position()
{
	setParent(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
}


template <typename T>
Position<T>::Position(T elem)
{ 
	Node< T, Position<T> >::element = elem; 
	Node< T, Position<T> >::_parent = nullptr;
	Node< T, Position<T> >::_left = nullptr;
	Node< T, Position<T> >::_right = nullptr;
}

template <typename T>
Position<T>::Position(T elem, Position* prnt)
{
	Node< T, Position<T> >::element = elem; 
	Node< T, Position<T> >::_parent = prnt;
	Node< T, Position<T> >::_left = nullptr;
	Node< T, Position<T> >::_right = nullptr;
}

#endif
