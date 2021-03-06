#ifndef BINARY_TREE

#include "bin_tree_position.h"

#define BINARY_TREE

template <typename T>
class LinkedBinaryTree
{
	private:
		//Position<T>* _root; //pointer to root
		Node<T>* _root;
		int n;//number of nodes

	public:
		LinkedBinaryTree();
		int size() const;
		bool empty() const;
		Position<T> root() const;
		//Position<T>* root() const;
		PositionList<T> positions(bool pre_post = true) const;
		//void addRoot(T e);
		void addRoot();
		void expandExternal(const Position<T>& p);
		Position<T> removeAboveExternal(const Position<T>& p);
		//void expandExternal(Position<T>* p, T left_element, T right_element);
		//Position<T>& removeAboveExternal(const Position<T>& p);
		//void inorder(Position<T>* v, PositionList<T>& pl) const;
		void inorder(Position<T> v, PositionList<T>& pl) const;
	public:
		void preorder(Position<T> v, PositionList<T>& pl) const;
		void postorder(Position<T> v, PositionList<T>& pl) const;
		
};


template <typename T, typename R>
class EulerTour{
	protected:
		struct Result{
				R leftResult;
				R rightResult;
				R finalResult;
			};
	protected:
		const LinkedBinaryTree<T>* tree;
		
	public:
		void initialize(const LinkedBinaryTree<T>& t){tree = &t;}
		int eulerTour(Position<T>& p) const;
	protected:
			virtual void visitExternal(Position<T>& p, Result& r) const{}
			virtual void visitLeft(Position<T>& p, Result& r) const {}
			virtual void visitBelow(Position<T>& p, Result& r) const {}
			virtual void visitRight(Position<T>& p, Result& r) const {} 
			Result initResult() const {return Result();}
			int result(const Result& r) const { return r.finalResult; }
};

template < typename T, typename R >
int EulerTour< T, R >::eulerTour(Position<T>& p) const
{
	Result r = initResult();
	
	if(p.isExternal())
	{
		visitExternal(p, r);
	}
	else
	{
		visitLeft(p, r);
		r.leftResult = eulerTour(*(p.left()));
		visitBelow(p, r);
		r.rightResult = eulerTour(*(p.right()));
		visitRight(p, r);
	}
	return result(r);
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
void LinkedBinaryTree<T>::addRoot()
//void LinkedBinaryTree<T>::addRoot(T e)
{
	_root = new Node<T>();
	//_root = new Position<T>();
	//_root->setElement(e);
	n = 1;
}

template <typename T>
void LinkedBinaryTree<T>::expandExternal(const Position<T>& p)
//void LinkedBinaryTree<T>::expandExternal(Position<T>* p, T left_element, T right_element)
{
	/*
	Position<T>* v = p;
	auto left_child = new Position<T>(left_element);
	v->setLeft(left_child);
	left_child->setParent(v);
	//std::cout << "left_child: " << *(*left_child->parent()) << std::endl;
	auto right_child = new Position<T>(right_element);
	v->setRight(right_child);
	right_child->setParent(v);
	//std::cout << "right_child: " << *(*right_child->parent()) << std::endl;
	*/
	Node<T>* v = p.v;
	v->_left = new Node<T>();
	v->_left->_parent = v;
	v->_right = new Node<T>();
	v->_right->_parent = v;
	n += 2;
}

template <typename T>
Position<T> LinkedBinaryTree<T>::removeAboveExternal(const Position<T>& p)
{
	/*
	Position<T>* w = p;
	Position<T>* v = p.parent;
	Position<T>* sib = (w == v->right ? v->left : v->right);
	if(v == _root)
	{
		_root = sib;
		sib->parent = nullptr;
	}  
	else
	{
		Position<T>* gpar = v->parent;
		if(v == gpar->left) gpar->left = sib;
		else gpar->right = sib;
		sib->parent = gpar;
	}
	*/
	Node<T>* w = p.v; Node<T>* v = w->_parent;
	Node<T>* sib = (w == v->_right ? v->_left : v->_right);
	if(v == _root)
	{
		_root = sib;
		sib->_parent = nullptr;
	}
	else
	{
		Node<T>* gpar = v->_parent;
		if(v == gpar->_left) gpar->_left = sib;
		else gpar->_right = sib;
		sib->_parent = gpar;
	}
	delete w; delete v;
	n -= 2;
	return Position<T>(sib);
}

template <typename T>
PositionList<T> LinkedBinaryTree<T>::positions(bool pre_post) const
{
	PositionList<T> pl;
	if(pre_post)
		preorder(_root, pl);
	else
		postorder(_root, pl);
	return PositionList<T>(pl);
}

template <typename T>
Position<T> LinkedBinaryTree<T>::root() const
//Position<T>* LinkedBinaryTree<T>::root() const
{
	return Position<T>(_root);
}

template <typename T>
void LinkedBinaryTree<T>::preorder(Position<T> v, PositionList<T>& pl) const
{
	pl.push_back(Position<T>(v));
	std::cout << "v->element: " << (*v) << std::endl;
	if(v.left() != nullptr)
	{	
		//std::cout << "going to left" << std::endl;
		preorder(v.left(), pl);
	}
	if(v.right() != nullptr)
	{
		//std::cout << "going to right" << std::endl;
		preorder(v.right(), pl);
	}
}

template <typename T>
void LinkedBinaryTree<T>::postorder(Position<T> v, PositionList<T>& pl) const
{
	if(v.left() != nullptr)
	{	
		postorder(v.left(), pl);
	}
	if(v.right() != nullptr)
	{
		postorder(v.right(), pl);
	}
	pl.push_back(Position<T>(v));
	std::cout << "v->element: " << (*v) << std::endl;
}

template <typename T>
void LinkedBinaryTree<T>::inorder(Position<T> v, PositionList<T>& pl) const
//void LinkedBinaryTree<T>::inorder(Position<T>* v, PositionList<T>& pl) const
{
	if(v.left() != nullptr)
	{	
		inorder(v.left(), pl);
	}
	//pl.push_back(Position<T>(v));
	pl.push_back(v);
	std::cout << "v->element: " << (*v) << std::endl;
	if(v.right() != nullptr)
	{
		inorder(v.right(), pl);
	}
}



#endif
