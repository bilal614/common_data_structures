#include "arrays_templated.h"

using namespace std;

template <class T>
ArrayElement<T>::ArrayElement()//: name(n), element(s)
{
}

template <class T>
ArrayElement<T>::ArrayElement(const string& n, T s)//: name(n), element(s)
{
	name = n;
	element = s;
}

template <class T>
T ArrayElement<T>::getElement() const
{ return element; }

template <class T>
std::string ArrayElement<T>::getName() const
{
	return name;
}

template <class T>
Array<T>::Array(int maxElements): maxEntries(maxElements), numEntries(0)
{
	
	//elements = malloc(maxEntries*sizeof(T));
	elements = new ArrayElement<T>[maxEntries]; //allocate array storage
}

template <class T>
void Array<T>::add(const ArrayElement<T>& e)//add element to array
{
	T newEl = e.getElement();//element to add
	ArrayElement<T>* tempEl = new ArrayElement<T>(e.getName(), e.getElement());
	std::cout << "new Element: " << newEl << std::endl;
	if(numEntries == maxEntries)//check if array is full
	{
		if(newEl <= elements[maxEntries - 1].getElement())
			return;//
	}
	else numEntries++;
	
	int i = numEntries - 2; //start with next to last element
	std::cout << "numEntries: " << numEntries << std::endl;
	while(i >= 0  && newEl > elements[i].getElement())
	{
		elements[i+1] = elements[i];//shift to right if smaller
		//elements[i+1] = tempEl;
		i--;
	}
	elements[i+1] = e;//put e in empty spot
}

template <class T>
void Array<T>::printElements()
{
	std::cout << "numEntries: " << numEntries << std::endl;
	for(int i = 0; i < numEntries; i++)
	{
		std::cout << elements[i].getName() << ": " << elements[i].getElement() << ", ";
	}
	std::cout << std::endl;	
}

template <class T>
T &Array<T>::operator[](int i)
{
	if(i > maxEntries || i < 0)
	{
		return NULL; 
	}
	else
		return elements[i];
}

template <class T>
Array<T>::~Array()
{
	delete[] elements;
}

