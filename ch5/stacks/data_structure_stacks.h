#ifndef STACK_PRACTICE_H
#define STACK_PRACTICE_H


#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>
#include "singly_linked_lists_templated.h"

class StackEmpty
{
	private:
		std::string errorMsg;
	public:
		StackEmpty(const std::string& err){errorMsg = err;}
		std::string getMsg() {return errorMsg;}
};


template <typename T>
class LinkedStack
{
	public:
		LinkedStack();
		~LinkedStack(); //FINISH IMPLEMENTING THE DESTRUCTOR
		int size() const;	//number of items in stack
		bool empty() const;	//check if stack is empty
		const T& top() const throw(StackEmpty);	//get the top element
		void push(const T& e);	//push element to the stack
		void pop() throw(StackEmpty);	//pop the stack 
		void print_list();
	private:
		SinglyLinkedList<T> S;	//linked list of elements
		int n;	//number of elements
};


template <typename T>
LinkedStack<T>::LinkedStack():S(), n(0){}

template <typename T>
int LinkedStack<T>::size() const
{
	return n;
}

template <typename T>
bool LinkedStack<T>::empty() const
{
	return n == 0;
}

template <typename T>
const T& LinkedStack<T>::top() const throw(StackEmpty)
{
	if(empty()) throw StackEmpty("Top of empty stack");
	return S.front();
}

template <typename T>
void LinkedStack<T>::push(const T& e)
{
	++n;
	S.addFront(e);
}

template <typename T>
void LinkedStack<T>::pop() throw(StackEmpty)
{
	if(empty()) throw StackEmpty("Pop from empty stack");
	--n;
	S.removeFront();
}

template <typename T>
void LinkedStack<T>::print_list()
{
	S.printElements();
}


#endif
