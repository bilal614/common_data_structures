#include "dll_node_list_iterator.h"

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


/**** Explicitly tell compiler which templates to instantiate for every definition in file. ***/
template NodeList<int>::Iterator::Iterator(Node* u);
template NodeList<std::string>::Iterator::Iterator(Node* u);
template NodeList<float>::Iterator::Iterator(Node* u);
template NodeList<double>::Iterator::Iterator(Node* u);

template int& NodeList<int>::Iterator::operator*();
template std::string& NodeList<std::string>::Iterator::operator*();
template float& NodeList<float>::Iterator::operator*();
template double& NodeList<double>::Iterator::operator*();

template bool NodeList<int>::Iterator::operator==(const Iterator& p) const;
template bool NodeList<std::string>::Iterator::operator==(const Iterator& p) const;
template bool NodeList<float>::Iterator::operator==(const Iterator& p) const;
template bool NodeList<double>::Iterator::operator==(const Iterator& p) const;

template bool NodeList<int>::Iterator::operator!=(const Iterator& p) const;
template bool NodeList<std::string>::Iterator::operator!=(const Iterator& p) const;
template bool NodeList<float>::Iterator::operator!=(const Iterator& p) const;
template bool NodeList<double>::Iterator::operator!=(const Iterator& p) const;

template NodeList<int>::Iterator& NodeList<int>::Iterator::operator++();
template NodeList<std::string>::Iterator& NodeList<std::string>::Iterator::operator++();
template NodeList<float>::Iterator& NodeList<float>::Iterator::operator++();
template NodeList<double>::Iterator& NodeList<double>::Iterator::operator++();

template NodeList<int>::Iterator& NodeList<int>::Iterator::operator--();
template NodeList<std::string>::Iterator& NodeList<std::string>::Iterator::operator--();
template NodeList<float>::Iterator& NodeList<float>::Iterator::operator--();
template NodeList<double>::Iterator& NodeList<double>::Iterator::operator--();

template NodeList<int>::NodeList();
template NodeList<std::string>::NodeList();
template NodeList<float>::NodeList();
template NodeList<double>::NodeList();

template int NodeList<int>::size() const;
template int NodeList<std::string>::size() const;
template int NodeList<float>::size() const;
template int NodeList<double>::size() const;

template bool NodeList<int>::empty() const;
template bool NodeList<std::string>::empty() const;
template bool NodeList<float>::empty() const;
template bool NodeList<double>::empty() const;

template NodeList<int>::Iterator NodeList<int>::begin() const;
template NodeList<std::string>::Iterator NodeList<std::string>::begin() const;
template NodeList<float>::Iterator NodeList<float>::begin() const;
template NodeList<double>::Iterator NodeList<double>::begin() const;

template NodeList<int>::Iterator NodeList<int>::end() const;
template NodeList<std::string>::Iterator NodeList<std::string>::end() const;
template NodeList<float>::Iterator NodeList<float>::end() const;
template NodeList<double>::Iterator NodeList<double>::end() const;

template void NodeList<int>::insert(const Iterator& p, const int& e);
template void NodeList<std::string>::insert(const Iterator& p, const std::string& e);
template void NodeList<float>::insert(const Iterator& p, const float& e);
template void NodeList<double>::insert(const Iterator& p, const double& e);

template void NodeList<int>::insertFront(const int& e);
template void NodeList<std::string>::insertFront(const std::string& e);
template void NodeList<float>::insertFront(const float& e);
template void NodeList<double>::insertFront(const double& e);

template void NodeList<int>::insertBack(const int& e);
template void NodeList<std::string>::insertBack(const std::string& e);
template void NodeList<float>::insertBack(const float& e);
template void NodeList<double>::insertBack(const double& e);

template void NodeList<int>::erase(const Iterator& p);
template void NodeList<std::string>::erase(const Iterator& p);
template void NodeList<float>::erase(const Iterator& p);
template void NodeList<double>::erase(const Iterator& p);

template void NodeList<int>::eraseFront();
template void NodeList<std::string>::eraseFront();
template void NodeList<float>::eraseFront();
template void NodeList<double>::eraseFront();

template void NodeList<int>::eraseBack();
template void NodeList<std::string>::eraseBack();
template void NodeList<float>::eraseBack();
template void NodeList<double>::eraseBack();

template void NodeList<int>::printElements();
template void NodeList<std::string>::printElements();
template void NodeList<float>::printElements();
template void NodeList<double>::printElements();
