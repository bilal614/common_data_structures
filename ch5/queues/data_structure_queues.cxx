/*
#include "data_structure_stacks.h"

template <typename T>
LinkedStack<T>::LinkedStack():S(), n(0){}

int LinkedStack::size() const
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
*/
