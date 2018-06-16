/*
 * dll_node_sequence.cxx
 *
 *  Created on: Jun 15, 2018
 *      Author: bilal
 */
/*
#include "dll_node_sequence.h"

template <typename T>
NodeList<T>::Iterator::Iterator(Node* u)
{
	v = u;
}


template <typename T>
T& NodeSequence<T>::Iterator::operator*()
{
	return v->element;
}

template <typename T>
bool NodeSequence<T>::Iterator::operator==(const Iterator& p) const
{
	return v == p.v;
}

template <typename T>
bool NodeSequence<T>::Iterator::operator!=(const Iterator& p) const
{
	return v != p.v;
}

template <typename T>
typename NodeSequence<T>::Iterator& NodeSequence<T>::Iterator::operator++()
{
	v = v->next;
	return *this;
}

template <typename T>
typename NodeSequence<T>::Iterator& NodeSequence<T>::Iterator::operator--()
{
	v = v->prev;
	return *this;
}



template <typename T>
typename NodeSequence<T>::Iterator NodeSequence<T>::atIndex(int i) const
{
	typename NodeSequence<T>;
	Iterator p = begin();
	for(int j = 0; j < i; j++) ++p;
	return p;
}

template <typename T>
int NodeSequence<T>::indexOf(NodeSequence<T>::Iterator& p) const
{
	typename NodeSequence<T>;
	Iterator q = begin();
	int i = 0;
	while(q != p)
	{
		++q;
		++i;
	}
	return i;
}

template <typename T>
typename NodeSequence<T>::Iterator begin()
{
	return (Iterator(NodeSequence<T>::header->next));
}

template <typename T>
typename NodeSequence<T>::Iterator end()
{
	return (Iterator(NodeSequence<T>::trailer));
}

template NodeSequence<int>::Iterator NodeSequence<int>::atIndex(int i) const;
template NodeSequence<std::string>::Iterator NodeSequence<std::string>::atIndex(int i) const;
template NodeSequence<float>::Iterator NodeSequence<float>::atIndex(int i) const;
template NodeSequence<double>::Iterator NodeSequence<double>::atIndex(int i) const;


template int NodeSequence<int>::indexOf(NodeSequence<int>::Iterator& p) const;
template int NodeSequence<std::string>::indexOf(NodeSequence<std::string>::Iterator& p) const;
template int NodeSequence<float>::indexOf(NodeSequence<float>::Iterator& p) const;
template int NodeSequence<double>::indexOf(NodeSequence<double>::Iterator& p) const;
*/
