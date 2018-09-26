#ifndef BIN_SRCH_TREE


#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>
#include <list>
#include <algorithm>    // std::for_each
#include <iterator>


#define BIN_SRCH_TREE

template <typename _type> class Position;
template <typename _type> class LinkedBinaryTree;
 


template <typename R>
class LinkedBinaryTree
{
	protected:
		struct Node
		{
			R element;
			Node* _parent;
			Node* _left;
			Node* _right;
			Node():element(), _parent(nullptr), _left(nullptr), _right(nullptr){}	
			Node(R e):element(e), _parent(nullptr), _left(nullptr), _right(nullptr){}	
			
		};

	public:
		class Position
		{	
			private:
				Node* v;
			public:
				Position(Node* _v = nullptr):v(_v) {}
				R& operator*(){ return v->element; }
				//void setElement(E e) { v->element = e; }
				Position left() const { Position(v->_left); }
				Position right() const { Position(v->_right); }
				Position parent() const { Position(v->_parent); }
				bool isRoot() const { v->parent == nullptr; }
				bool isExternal() const { return v->_left == nullptr && v->_right == nullptr;}
				
				void setElement(const R& elem) { v->element = elem; }
				
				bool operator==(const Position& p) const { return this->element == p.element; }
			
				friend class LinkedBinaryTree;
				friend std::ostream& operator<<(std::ostream& os, const Position& pos); 
		};

		typedef std::list< Position > PositionList;
	private:
		Node* _root; //pointer to root
		int n;//number of nodes

	public:
		LinkedBinaryTree();
		int size() const;
		bool empty() const;
		Position root() const;
		PositionList positions() const;
		void addRoot();
		void expandExternal(const Position& p);
		Position& removeAboveExternal(const Position& p);
	
		void printTree();
	protected:
		void preorder(Node* v, PositionList& pl) const;		
};


template <typename S>
std::ostream& operator<<(std::ostream& os, const Position<S>& pos)  
{  
	os << pos->element;  
	return os;  
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
bool LinkedBinaryTree<T>::empty() const
{
	return size() == 0;
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::root() const
{
	return Position(_root);//copy constructor
}

template <typename T>
void LinkedBinaryTree<T>::addRoot()
{
	_root = new Node; n = 1;
}


template <typename T>
void LinkedBinaryTree<T>::expandExternal(const typename LinkedBinaryTree<T>::Position& p)
{
	Node* v = p.v;
	v->_left = new Node;
	v->_left->_parent = v;
	v->_right = new Node;
	v->_right->_parent = v;
	n += 2;
}

template <typename T>
typename LinkedBinaryTree<T>::Position& LinkedBinaryTree<T>::removeAboveExternal(const Position& p)
{
	Node* w = p.v;
	Node* v = w->_parent;
	Node* sib = (w == v->_left ? v->_left : v->_right);
	if(v == _root)
	{
		_root = sib;
		sib->parent = nullptr;
	}  
	else
	{
		Node* gpar = v->_parent;
		if(v == gpar->left) gpar->_left = sib;
		else gpar->_right = sib;
		sib->_parent = gpar;
	}
	delete w; delete v;
	n -= 2;
	return sib;
}

template <typename T>
typename LinkedBinaryTree<T>::PositionList LinkedBinaryTree<T>::positions() const
{
	PositionList pl;
	preorder(_root, pl);
	return PositionList(pl);
}

template <typename T>
void LinkedBinaryTree<T>::preorder(Node* v, PositionList& pl) const
{
	std::cout << "v->element: " << v->element << std::endl;
	pl.push_back(Position(v));
	if(v->_left != nullptr)
		preorder(v->_left, pl);
	if(v->_right != nullptr)
		preorder(v->_right, pl);
}

template <typename T>
void LinkedBinaryTree<T>::printTree()
{
	PositionList printPl;
	preorder(_root, printPl);
}

#endif
