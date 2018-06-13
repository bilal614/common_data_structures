#ifndef QUEUE_PRACTICE_H
#define QUEUE_PRACTICE_H


#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>
#include "circularly_linked_lists_templated.h"

class QueueEmpty
{
	private:
		std::string errorMsg;
	public:
		QueueEmpty(const std::string& err){errorMsg = err;}
		std::string getMsg() {return errorMsg;}
};


template <typename T>
class Queue
{
	public:
		Queue();
		~Queue();
		int size() const;	//number of items in queue
		bool empty() const;	//check if queue is empty
		const T& front() const throw(QueueEmpty);	//get the element in front of the queue
		void enqueue(const T& e);	//push element to the back of the queue
		void dequeue() throw(QueueEmpty);	//pop the stack 
		void print_queue();
	private:
		CircleLinkedList<T> C;	//linked list of elements
		int n;	//number of elements
};


template <typename T>
Queue<T>::Queue():C(), n(0){}

template <typename T>
Queue<T>::~Queue(){}

template <typename T>
int Queue<T>::size() const
{
	return n;
}

template <typename T>
bool Queue<T>::empty() const
{
	return n == 0;
}

template <typename T>
const T& Queue<T>::front() const throw(QueueEmpty)
{
	if(empty()) throw QueueEmpty("Front of empty queue");
	return C.front();
}

template <typename T>
void Queue<T>::enqueue(const T& e)
{ 
	C.add(e);
	//C.advance();
	++C;
	++n;
}

template <typename T>
void Queue<T>::dequeue() throw(QueueEmpty)
{
	if(empty()) throw QueueEmpty("Pop from empty queue");
	--n;
	C.remove();
}

template <typename T>
void Queue<T>::print_queue()
{
	C.printElements();
}


#endif
