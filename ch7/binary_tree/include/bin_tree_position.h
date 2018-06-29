#ifndef BIN_TREE_POS


#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>
#include <list>
#include <algorithm>    // std::for_each
#include <iterator>


#define BIN_TREE_POS


/* type alias, alias template */
template <typename T>
using PositionList = std::list< Position<T> >;

template <typename T, typename N>
class Node
{
	private:
		T element;
		N* parent;
		N* left;
		N* right;
		N():element(), parent(nullptr), left(nullptr), right(nullptr){}		
};

template <typename T>
class Position<T>: public Node< T, Position<T> >
{	
	public:
		T& operator*();
		Position left() const;
		Position right() const;
		Position parent() const;
		void setLeft(Position* l);
		void setRight(Position* r);
		void setParent(Position* p);
		
		bool isRoot() const;
		bool isExternal() const;
		//Position(Position* p = nullptr): {}
}

template <typename T>
T& Position<T>::operator*() 
{
	return element;
}

template <typename T>
Position<T> Position<T>::left() const
{
	return *left;
}

template <typename T>
Position<T> Position<T>::right() const
{
	return *right;
}

template <typename T>
bool Position<T>::isRoot() const
{
	return (this->parent == nullptr);
}

template <typename T>
bool Position<T>::isExternal() const
{
	return (this->left == nullptr && this->right == nullptr);
}


template <typename T>
void Position<T>::setLeft(Position* l)
{
	left = l;
}

template <typename T>
void Position<T>::setRight(Position* r)
{
	right = r;
}

template <typename T>
void Position<T>::setParent(Position* p)
{
	parent = p;
}


#endif
