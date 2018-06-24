#ifndef TREE_INTERFACE

#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>

//#include "dll_node_list_iterator.h"
//#inclde <list>

#define TREE_INTERFACE 

template <typename T>
class NodeList
{
	protected:
		struct Node
		{
			T element;
			Node* prev;//previous node in the list
			Node* next;//next node in the list
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

				friend class NodeList<T>;
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

	private: //data members
		int n;//number of items
		Node* header;//head of list sentinel
		Node* trailer;//tail of list sentinel
};


template <typename E>
class Position
{
	public:
		Position(E elem, );
		E& operator *();	//get element
		Position parent() const;	//get parent
		NodeList<Position> children() const;	//get node's children
		//std::list<Position> childre() const;
		bool isRoot() const;	//root node?
		bool isExternal() const;	//external node?
	private:
		E element;
		Position _parent;//previous node in the list
		NodeList<Position> _children;//next node in the list
		bool _root;
};


template <typename E>
class Tree
{
	public: 
		class Position;	//a node Position
		//class NodeList;	//a list of positions
	public:
		int size() const;	//number of nodes
		bool empty() const;	//is tree empty?
		Position root() const;	//get the root
		NodeList<Position> positions() const;	//get positions of all nodes
		//std::list<Position> positions() const;
};

#endif
