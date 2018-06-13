#ifndef SLL_PRACTICE_H
#define SLL_PRACTICE_H

#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>

template <typename T>
class Node
{
	private:
		T element;
		Node<T>* prev;//previous node in the list
		Node<T>* next;//next node in the list
		template<class U>//in the definition of Node we must already let the Node class know that DoublyLinkedList is
		//template class and it cannot shadow the template parameter T of the Node class 
		friend class DoublyLinkedList;//provides DoublyLinkedList class access to private members of Node class
};


//In the class declaration of DoublyLinkedList we already identify the Node member head as being templated with T
//,so there is no conflict the Node and the DoublyLinkedList will share the same template type T 
template <typename T>
class DoublyLinkedList
{
	public:
		DoublyLinkedList();//constructor
		~DoublyLinkedList();//destructor
		bool empty() const;//is list empty?
		const T& front() const;//return reference to front element
		const T& back() const;//return reference to back element
		void addFront(const T& e);//add to the front of list
		void addBack(const T& e);//add to the back of list
		void removeFront();//remove from front
		void removeBack();//remove from back 
		void printElements();//print all the elements in the list
		void listReverse();
	private:
		Node<T>* header;//templated Node pointer to the head of the list
		Node<T>* trailer;//templated Node pointer to the tail of the list
	protected:
		void add(Node<T>* v, const T& e);//insert new node before v
		void remove(Node<T>* v);
};


template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	header = new Node<T>;
	trailer = new Node<T>;
	header->next = trailer;
	//header->prev = NULL;
	trailer->prev = header;
	//trailer->next = NULL;
	
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	//Keep calling remove front until list is empty, then remove sentinels
	while(!empty()){ removeFront();}
	delete header;
	delete trailer;
}

template <typename T>
bool DoublyLinkedList<T>::empty() const
{
	//returns true if the list is empty when the head is pointing to nullptr, remember NULL is just a macro for nullptr
	return (header->next == trailer);
	//alternatively
	/*return (trailer->prev == header)*/
}


/* Returns reference to the type T lhs value at the front of the list. Remember lhs are almost always locations in memory. This
 * function simply returns the element member of head Node.*/
template <typename T>
const T& DoublyLinkedList<T>::front() const
{
	return header->next->element;
}

/* Returns reference to the type T lhs value at the back of the list. Remember lhs are almost always locations in memory. This
 * function simply returns the element member of head Node.*/
template <typename T>
const T& DoublyLinkedList<T>::back() const
{
	return trailer->prev->element;
}

template <typename T>
void DoublyLinkedList<T>::add(Node<T>* v, const T& e)
{
	//Node e will be placed in the front of v
	Node<T>* n = new Node<T>;
	n->element = e;
	//std::cout << n->element << std::endl;
	n->next = v;
	n->prev = v->prev;
	
	v->prev->next = v->prev= n;
}

template <typename T>
void DoublyLinkedList<T>::addFront(const T& e)
{
	add(header->next, e);
}

template <typename T>
void DoublyLinkedList<T>::addBack(const T& e)
{
	add(trailer, e);
}

template <typename T>
void DoublyLinkedList<T>::remove(Node<T>* v)
{
	v->prev->next = v->next;
	v->next->prev = v->prev;
	delete v;
}


template <typename T>
void DoublyLinkedList<T>::removeFront()
{
	remove(header->next);
}

template <typename T>
void DoublyLinkedList<T>::removeBack()
{
	remove(trailer->prev);
}


template <typename T>
void DoublyLinkedList<T>::printElements()
{
	int count = 0;
	Node<T> * temp = header->next;
	if(this->empty())
	{
		std::cout << "the list is empty..."; 
		return;
	}
	while(temp != trailer)
	{
		std::cout << count << ": " << temp->element << ", ";
		temp = temp->next;
		count++;
	}
	
	std::cout << std::endl;	
	return;
}

template <typename T>
void DoublyLinkedList<T>::listReverse()
{
	DoublyLinkedList<T> S;
	while(!this->empty())
	{
		T s = this->front();
		this->removeFront();
		S.addFront(s);
	}
	
	while(!S.empty())
	{
		T s = S.front();
		S.removeFront();
		this->addBack(s);
	}
	
	return;
}

#endif
