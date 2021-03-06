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
			Node(const Node& _n)//copy constructor
			{ _parent = _n._parent; _left = _n._left; _right = _n,_right; element = _n.element; }
			//{ _parent = &_n->_parent; _left = &_n->_left; _right = &_n->_right; element = &_n->element; }
			Node& operator=(const Node& _n)//copy assignment operator
			{ _parent = _n._parent; _left = _n._left; _right = _n._right; element = _n.element; return *this;}
			//{ _parent = &_n->_parent; _left = &_n->_left; _right = &_n->_right; element = &_n->element; return *this;}
			//~Node(){delete _left; _left = nullptr; delete _right; _right = nullptr; delete _parent; _parent = nullptr;}
		};

	public:
		class Position
		{	
			public:
				Node* node;
			public:
				Position(Node* _v = nullptr): node(_v){ }
				Position(const Position& v): node(v.node){ }
				R& operator*(){ return node->element; }
				//Position(const Position& pos): node(pos.node) { }
				//void setElement(E e) { v->element = e; }
				Position left() const { return Position(node->_left); }
				Position right() const { return Position(node->_right); }
				Position parent() const { return Position(node->_parent); }
				bool isRoot() const { node->parent == nullptr; }
				bool isExternal() const { return node->_left == nullptr && node->_right == nullptr;}
				bool isInternal() const { return !isExternal();}
				//Own added functions
				//void setElement(const R& elem) { node->element = elem; }
				~Position() { node = nullptr; }
				bool operator==(const Position& p) const { return (node == p.node); }
			
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
		Position removeAboveExternal(const Position& p);
	
		void printTree();
		void preorder(Node* v, PositionList& pl) const;	
	protected:	
		//void preorder(Node* v, PositionList& pl) const;	
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
	return Position(_root);
}


template <typename T>
void LinkedBinaryTree<T>::addRoot()
{
	_root = new Node; n = 1;
}


template <typename T>
void LinkedBinaryTree<T>::expandExternal(const typename LinkedBinaryTree<T>::Position& p)
{
	Node* v = p.node;
	v->_left = new Node;
	v->_left->_parent = v;
	v->_right = new Node;
	v->_right->_parent = v;
	n += 2;
}

template <typename T>
typename LinkedBinaryTree<T>::Position LinkedBinaryTree<T>::removeAboveExternal(const Position& p)
{
	Node* w = p.node;
	Node* v = w->_parent;
	Node* sib = (w == v->_left ? v->_right : v->_left);
	if(v == _root)
	{
		_root = sib;
		sib->_parent = nullptr;
	}  
	else
	{
		Node* gpar = v->_parent;
		if(v == gpar->_left) gpar->_left = sib;
		else gpar->_right = sib;
		sib->_parent = gpar;
	}
	delete w; delete v;
	n -= 2;
	//auto _sib = Position(sib);
	//return _sib;
	return Position(sib);
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
