#ifndef TREE_INTERFACE

#include "dll_node_list_iterator.h"
//#inclde <list>

#define TREE_INTERFACE 

template <typename E>
class Position
{
	public:
		E& operator *();	//get element
		Position parent() const;	//get parent
		NodeList<Position> children() const;	//get node's children
		//std::list<Position> childre() const;
		bool isRoot() const;	//root node?
		bool isExternal() const;	//external node?
}


template <typename E>
class Tree
{
	public: 
		class Position;	//a node Position
		class NodeList;	//a list of positions
	public:
		int size() const;	//number of nodes
		bool empty() const;	//is tree empty?
		Position root() const;	//get the root
		NodeList<Position> positions() const;	//get positions of all nodes
		//std::list<Position> positions() const;
}

#endif
