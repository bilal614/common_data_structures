
#ifndef CLL_PRACTICE_H
#define CLL_PRACTICE_H

#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>

template <typename T>
class Node
{
	private:
		T element;
		Node<T>* next;//next node in the list
		template<class U>//in the definition of Node we must already let the Node class know that DoublyLinkedList is
		//template class and it cannot shadow the template parameter T of the Node class 
		friend class CircleLinkedList;//provides DoublyLinkedList class access to private members of Node class
};


//In the class declaration of DoublyLinkedList we already identify the Node member head as being templated with T
//,so there is no conflict the Node and the DoublyLinkedList will share the same template type T 
template <typename T>
class CircleLinkedList
{
	public:
		CircleLinkedList();//constructor
		~CircleLinkedList();//destructor
		bool empty() const;//is list empty?
		const T& front() const;//return reference to front element
		const T& back() const;//return reference to back element
		void advance();//advance cursor
		T& operator++();
		void add(const T& e);//add after cursor
		void remove();//remove node after cursor
		void printElements();//print all the elements in the list
	private:
		Node<T>* cursor;//the cursor
};


template <typename T>
CircleLinkedList<T>::CircleLinkedList(): cursor(NULL)
{
}

template <typename T>
CircleLinkedList<T>::~CircleLinkedList()
{
	//Keep calling remove front until list is empty, then remove sentinels
	while(!empty()){ remove();}
}

template <typename T>
bool CircleLinkedList<T>::empty() const
{
	//returns true if the list is empty when the cursor is pointing to nullptr, remember NULL is just a macro for nullptr
	return cursor == NULL;
}

template <typename T>
const T& CircleLinkedList<T>::front() const
{
	return cursor->element;
}

template <typename T>
const T& CircleLinkedList<T>::back() const
{
	return cursor->next->element;
}

template <typename T>
void CircleLinkedList<T>::advance()
{
	cursor = cursor->next;
}

template <typename T>
T& CircleLinkedList<T>::operator++()
{
	this->advance();
	return cursor->element;
}

template <typename T>
void CircleLinkedList<T>::add(const T& e)
{
	Node<T>* v = new Node<T>;
	v->element = e;
	if(cursor == NULL)
	{
		v->next = v;
		cursor = v;
	}
	else
	{
		v->next = cursor->next;
		cursor->next = v;
	}
}

template <typename T>
void CircleLinkedList<T>::remove()
{
	if(cursor == NULL)
		return;
	Node<T>* old = cursor->next;
	if(cursor == old)//there was only node in the list
	{
		cursor = NULL;
	}
	else
	{
		cursor->next = old->next;
	}
	delete old;
}


template <typename T>
void CircleLinkedList<T>::printElements()
{
	int count = 0;
	Node<T> *original = cursor;
	if(this->empty())
	{
		std::cout << "the list is empty..."; 
		return;
	}
	
	do
	{
		this->advance();
		std::cout << count << ": " << cursor->element << ", ";
		count++;
	}while(cursor != original);
	
	std::cout << std::endl;	
	return;
}


#endif
