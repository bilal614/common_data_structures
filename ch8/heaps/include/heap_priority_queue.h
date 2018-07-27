#ifndef HEAP_QUEUE

#include "binary_tree.h"

#define HEAP_QUEUE


template <typename T, typename C>
class HeapPriorityQueue
{
	public:
		int size() const;	//number of elements
		bool empty() const;	//is the queue empty?
		void insert(const T& t);	//insert element
		const T& min();	//minimum element
		void removeMin();	//remove minimum
		void printHeap();
	private:
		CompleteTree<T> Tree;	//priority queue contents
		C isLess;	//less-than comparator
};

template <typename T, typename C>
int HeapPriorityQueue< T, C>::size() const
{
	return Tree.size();
}

template <typename T, typename C>
bool HeapPriorityQueue< T, C>::empty() const
{
	return Tree.empty();
}

template <typename T, typename C>
const T& HeapPriorityQueue< T, C>::min() const
{
	return *(Tree.root());
}

template <typename T, typename C>
void HeapPriorityQueue< T, C>::printHeap()
{Tree.printQ();}

template <typename T, typename C>
void HeapPriorityQueue< T, C>::insert(const T& t) const
{
	Tree.addLast(t);
	Position<T>* v = Tree.last();
	while(!T.isRoot(v))
	{
		Position<T>* u = v.parent();
		if(!isLess(*(*v), *(*u))) break;
		T.swap(v, u);
		v = u;
	}
}


#endif
