#ifndef DLL_PRACTICE_H
#define DLL_PRACTICE_H

#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>

template <typename T>
struct Node;

template <typename T>
class Iterator;

template <typename T>
class NodeList
{
	/*
	private:
		template <typename T>
		struct Node;

	public:
		template <typename T>
		class Iterator;
	*/
	public:
		NodeList();//default constructor
		//~NodeList();
		int size() const;//list size
		bool empty() const;//is the list empty
		Iterator<T> begin() const;//beginning position
		Iterator<T> end() const;//(just beyond) last position
		void insert(const Iterator<T>& p, const T& e);//insert e before p
		void insertFront(const T& e);//insert at front
		void insertBack(const T& e);//insert at rear
		void erase(const Iterator<T>& p);//remove p
		void eraseFront();//remove first
		void eraseBack();//remove last
		void printElements();

	private://data members
		int n;//number of items
		Node<T>* header;//head of list sentinel
		Node<T>* trailer;//tail of list sentinel
};


template <typename T>
struct Node
{
	T element;
	Node<T>* prev;//previous node in the list
	Node<T>* next;//next node in the list
};


template <typename T>
class Iterator
{
	public:
		T& operator*();//reference to the element
		bool operator==(const Iterator<T>& p) const;//compare positions
		bool operator!=(const Iterator<T>& p) const;
		Iterator<T>& operator++();//move to next position
		Iterator<T>& operator--();//move to previous position

		//template <typename T>
		friend class NodeList<T>;

	//private:
	public:
		Node<T>* v;//pointer to node
		Iterator(Node<T>* u);//create from node

};


template <typename T>
Iterator<T>::Iterator(Node<T>* u)
{
	v = u;	
}

template <typename T>
T& Iterator<T>::operator*()
{
	return v->element;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator<T>& p) const
{
	return v == p.v;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T>& p) const
{
	return v != p.v;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
	v = v->next;
	return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator--()
{
	v = v->prev;
	return *this;
}


template <typename T>
NodeList<T>::NodeList()
{
	n = 0;
	header = new Node<T>;
	trailer = new Node<T>;
	header->next = trailer;
	trailer->prev = header;
}

template <typename T>
int NodeList<T>::size() const
{
	return n;
}


template <typename T>
bool NodeList<T>::empty() const
{
	return (n == 0);
}


template <typename T>
Iterator<T> NodeList<T>::begin() const//begin position is the first item
{
	return (Iterator<T>(header->next));
}

template <typename T>
Iterator<T> NodeList<T>::end() const//begin position is the first item
{
	return (Iterator<T>(trailer));
}

template <typename T>//insert e before p
void NodeList<T>::insert(const Iterator<T>& p, const T& e)
{
	Node<T>* w = p.v;//p's node
	Node<T>* u = w->prev;//p's predecessor
	Node<T>* v = new Node<T>;//new Node to insert
	v->element = e;
	v->next = w;w->prev = v;//link in v before w
	v->prev = u;u->next = v;
	n++;
}

template <typename T>//insert e before p
void NodeList<T>::insertFront(const T& e)
{
	insert(begin(), e);
}

template <typename T>//insert e before p
void NodeList<T>::insertBack(const T& e)
{
	insert(end(), e);
}

template <typename T>//remove p
void NodeList<T>::erase(const Iterator<T>& p)
{
	Node<T>* v = p.v; //Node to remove
	Node<T>* w = v->next;//successor
	Node<T>* u = v->prev; //predecessor
	w->prev = u; 
	u->next = w;
	delete v;
	n--;
}

template <typename T>
void NodeList<T>::eraseFront()
{
	erase(begin());
}

template <typename T>
void NodeList<T>::eraseBack()
{
	erase(--end());
}

template <typename T>
void NodeList<T>::printElements()
{
	Iterator<T> it(begin());
	Iterator<T> ending(end());
	for(; it != ending; ++it)
	{
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}


#endif
