#ifndef DLL_PRACTICE_H
#define DLL_PRACTICE_H

#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>


template <typename T>
class NodeList
{
	private:
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
				T& operator*();//reference to the element
				bool operator==(const Iterator& p) const;//compare positions
				bool operator!=(const Iterator& p) const;
				Iterator& operator++();//move to next position
				Iterator& operator--();//move to previous position

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

/*
template <typename T>
NodeList<T>::Iterator::Iterator(Node* u)
{
	v = u;	
}

template <typename T>
T& NodeList<T>::Iterator::operator*()
{
	return v->element;
}

template <typename T>
bool NodeList<T>::Iterator::operator==(const Iterator& p) const
{
	return v == p.v;
}

template <typename T>
bool NodeList<T>::Iterator::operator!=(const Iterator& p) const
{
	return v != p.v;
}

template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator++()
{
	v = v->next;
	return *this;
}

template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator--()
{
	v = v->prev;
	return *this;
}


template <typename T>
NodeList<T>::NodeList()
{
	n = 0;
	header = new Node;
	trailer = new Node;
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
typename NodeList<T>::Iterator NodeList<T>::begin() const//begin position is the first item
{
	return (Iterator(header->next));
}

template <typename T>
typename NodeList<T>::Iterator NodeList<T>::end() const//begin position is the first item
{
	return (Iterator(trailer));
}

template <typename T>//insert e before p
void NodeList<T>::insert(const Iterator& p, const T& e)
{
	Node* w = p.v;//p's node
	Node* u = w->prev;//p's predecessor
	Node* v = new Node;//new Node to insert
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
void NodeList<T>::erase(const Iterator& p)
{
	Node* v = p.v; //Node to remove
	Node* w = v->next;//successor
	Node* u = v->prev; //predecessor
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
	Iterator it(begin());
	Iterator ending(end());
	for(; it != ending; ++it)
	{
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}
*/

#endif
