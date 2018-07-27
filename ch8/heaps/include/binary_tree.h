#ifndef COMPLETE_TREE

#include "bin_tree_position.h"
#include <cmath>        // std::pow
#include <deque>

#define COMPLETE_TREE

template <typename T>
class CompleteTree
{
	private:
		Position<T>* _root; //pointer to root
		int n;//number of nodes
		std::deque< Position<T>* > Q;
		typename std::deque< Position<T>* >::iterator _last;
		int _level; //depth of tree
		void updateLevel();
		void addRoot(T e);

	public:
		CompleteTree();
		int size() const;
		bool empty() const;
		Position<T> root(); //get root position
		PositionList<T> positions(bool pre_post = true) const;
		void add(T t);
		void remove();
		
		void printQ();
		Position<T> left(const Position<T>& p);//get left child
		Position<T> right(const Position<T>& p);//get right child
		Position<T> parent(const Position<T>& p); //get parent
		bool hasLeft(const Position<T>& p) const;//does node have left child?
		bool hasRight(const Position<T>& p) const;//does node have right child?
		bool isRoot(const Position<T>& p) const; //is this the root
		Position<T>* last(); //get last node
		void addLast(const T& t);
		void removeLast();
		void swap(Position<T>& p, Position<T>& q);
		
	protected:
		void inorder(Position<T>* v, PositionList<T>& pl) const;
		void preorder(Position<T>* v, PositionList<T>& pl) const;
		void postorder(Position<T>* v, PositionList<T>& pl) const;
};

template <typename T>
void CompleteTree<T>::remove()
{
	if(Q.empty()) return;
		
	Position<T>* w = Q.back();
	if(!hasLeft(*_last) && !hasRight(*_last) && (*_last) != _root)
	{
		--_last;
	}
	Q.pop_back();
	--n;
	delete w;
}

template <typename T>
void CompleteTree<T>::removeLast()
{remove();}

template <typename T>
void CompleteTree<T>::add(T t)
{
	if(Q.empty())
	{
		addRoot(t);
		++_level;
		Q.push_back(_root);
		_last = Q.begin();
	}
	else
	{
		Position<T>* temp = new Position<T>();
		temp->setElement(t);
		
		if(!hasLeft(*_last))
		{
			(*_last)->setLeft(temp);
			temp->setParent(*_last);
			Q.push_back(temp);	
			++n;	
			updateLevel();
			return;		
		}
		else if(hasLeft(*_last) && !hasRight(*_last))
		{
			(*_last)->setRight(temp);
			temp->setParent(*_last);	
			Q.push_back(temp);
			++n;
			updateLevel();
			++_last;
			return;
		} 
	}
}

template <typename T>
void CompleteTree<T>::addLast(const T& t)
{
	add(t);
}

template <typename T>
void CompleteTree<T>::updateLevel()
{
	auto completion_nodes = std::pow(2, _level-1) + 1;
	if(n == completion_nodes) ++_level;
}

template <typename T>
void CompleteTree<T>::printQ()
{
	std::cout << "size of Q: " << Q.size() << std::endl;
	for(auto it = Q.begin(); it != Q.end(); ++it)
	{
		std::cout << *(*(*it)) << std::endl;
	}
}

template <typename T>
Position<T>* CompleteTree<T>::last()
{
	return (*_last);
}

template <typename T>
int CompleteTree<T>::size() const
{
	return n;
}

template <typename T>
Position<T> CompleteTree<T>::left(const Position<T>& p) 
{
	return *(p.left());
}

template <typename T>
Position<T> CompleteTree<T>::right(const Position<T>& p) 
{
	return *(p.right());
}

template <typename T>
Position<T> CompleteTree<T>::parent(const Position<T>& p) 
{
	return *(p.parent());
}

template <typename T>
bool CompleteTree<T>::hasLeft(const Position<T>& p) const
{
	return (p.left() != nullptr ? true : false);
}

template <typename T>
bool CompleteTree<T>::hasRight(const Position<T>& p) const
{
	return (p.right() != nullptr ? true : false);
}

template <typename T>
bool CompleteTree<T>::isRoot(const Position<T>& p) const
{
	return (*p.parent() != nullptr ? true : false);
}

template <typename T>
Position<T> CompleteTree<T>::root()
{
	return (*_root);
}

template <typename T>
CompleteTree<T>::CompleteTree(): _root(nullptr), n(0), _level(1)
{
} 


template <typename T>
bool CompleteTree<T>::empty() const
{
	return size() == 0;
}


template <typename T>
void CompleteTree<T>::addRoot(T e)
{
	_root = new Position<T>();
	_root->setElement(e);
	n = 1;
}

template <typename T>
PositionList<T> CompleteTree<T>::positions(bool pre_post) const
{
	PositionList<T> pl;
	if(pre_post)
		preorder(_root, pl);
	else
		postorder(_root, pl);
	return PositionList<T>(pl);
}


template <typename T>
void CompleteTree<T>::preorder(Position<T>* v, PositionList<T>& pl) const
{
	pl.push_back(Position<T>(v));
	std::cout << "v->element: " << *(*v) << std::endl;
	if(v->left() != nullptr)
	{	
		//std::cout << "going to left" << std::endl;
		preorder(v->left(), pl);
	}
	if(v->right() != nullptr)
	{
		//std::cout << "going to right" << std::endl;
		preorder(v->right(), pl);
	}
}

template <typename T>
void CompleteTree<T>::postorder(Position<T>* v, PositionList<T>& pl) const
{
	if(v->left() != nullptr)
	{	
		postorder(v->left(), pl);
	}
	if(v->right() != nullptr)
	{
		postorder(v->right(), pl);
	}
	pl.push_back(Position<T>(v));
	std::cout << "v->element: " << *(*v) << std::endl;
}

template <typename T>
void CompleteTree<T>::inorder(Position<T>* v, PositionList<T>& pl) const
{
	if(v->left() != nullptr)
	{	
		inorder(v->left(), pl);
	}
	pl.push_back(Position<T>(v));
	std::cout << "v->element: " << *(*v) << std::endl;
	if(v->right() != nullptr)
	{
		inorder(v->right(), pl);
	}
}

template <typename T>
void CompleteTree<T>::swap(Position<T>& p, Position<T>& q)
{
	T temp = *q;
	std::cout << "temp: " << temp << std::endl;
	T p_val = *p;
	std::cout << "p_val: " << p_val << std::endl;
	q.setElement(p_val); 
	//*q = *p; 
	//*p = e;
	p.setElement(temp);
}

#endif
