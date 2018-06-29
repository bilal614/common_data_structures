#ifndef BINARY_TREE

#include "bin_tree_position.h"

#define BINARY TREE

template <typename T>
class LinkedBinaryTree
{
	private:
		Node* _root; //pointer to root
		int n;//number of nodes

	public:
		LinkedBinaryTree();
		int size() const;
		bool empty() const;
		Position<T> root() const;
		PositionList<T> positions() const;
		void addRoot();
		void expandExternal(const Position& p);
		Position removeAboveExternal(const Position& p);

	protected:
		void preorder(Node* v, PositionList<T>& pl) const;
}


template <typename T>
LinkedBinaryTree<T>::LinkedBinaryTree(): _root(nullptr), n(0)
{
}

template <typename T>
int LinkedBinaryTree<T>::size() const
{
	return n;
}

template <typename T>
int LinkedBinaryTree<T>::empty() const
{
	return size() == 0;
}


#endif
