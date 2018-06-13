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
		Node<T>* next;
		template<class U>//in the definition of Node we must already let the Node class know that SinglyLinkedList is
		//template class and it cannot shadow the template parameter T of the Node class 
		friend class SinglyLinkedList;//provides SinglyLinkedList class access to private members of Node class
};


//In the class declaration of SinglyLinkedList we already identify the Node member head as being templated with T
//,so there is no conflict the Node and the SinglyLinkedList will share the same template type T 
template <typename T>
class SinglyLinkedList
{
	public:
		SinglyLinkedList();//constructor
		~SinglyLinkedList();//destructor
		bool empty() const;
		const T& front() const;
		void addFront(const T& e);
		void removeFront();
		void printElements();
	private:
		Node<T>* head;
};


template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(): head(NULL){}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	//Keep calling remove front until list is empty
	while(!empty()){ removeFront();}
}

template <typename T>
bool SinglyLinkedList<T>::empty() const
{
	//returns true if the list is empty when the head is pointing to nullptr, remember NULL is just a macro for nullptr
	return head == NULL;
}


/* Returns reference to the type T lhs value. Remember lhs are almost always locations in memory. This
 * function simply returns the element member of head Node.*/
template <typename T>
const T& SinglyLinkedList<T>::front() const
{
	return head->element;
}

template <typename T>
void SinglyLinkedList<T>::addFront(const T& e)
{
	//Node e will be placed in the front and will become the new head
	Node<T>* n = new Node<T>;
	n->element = e;
	n->next = head;//head now follows n
	head = n;//n is now the new head
}


template <typename T>
void SinglyLinkedList<T>::removeFront()
{
	//create temporary Node pointer old and make it point to the old head, remember head is also a pointer itself 
	Node<T> * old = head;
	head = old->next;//make head point to the next member of old head which is going to be deleted so we don't 
	delete old;//want to lose the Node it points to before it's deleted
}


template <typename T>
void SinglyLinkedList<T>::printElements()
{
	int count = 0;
	Node<T> * temp = head;
	if(temp == NULL)
	{
		std::cout << "the list is empty..."; 
		return;
	}
	while(temp != NULL)
	{
		std::cout << count << ": " << temp->element << ", ";
		temp = temp->next;
		count++;
	}
	
	std::cout << std::endl;	
	return;
}

#endif
