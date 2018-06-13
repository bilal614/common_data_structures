#ifndef ARRAY_TEMPLATED_H
#define ARRAY_TEMPLATED_H

#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>

template <class T>
class ArrayElement//Array Elements
{
	public:
		ArrayElement();
		ArrayElement(const std::string& n, T s);//constructor
		std::string getName() const;
		T getElement() const;
		//T operator=
	private:
		std::string name;
		T element;
		
};


template <class T>
class Array
{
	public:
		Array(int maxElements = 10);//constructor
		~Array();//destructor
		void add(const ArrayElement<T>& e);//add an element
		
		ArrayElement<T> remove(int i)//remove the i'th entry
			/*throw(IndexOutOfBounds)*/;
		void printElements();
		T& operator[](int i);
	private:
		int maxEntries;//maximum number of entries
		int numEntries;//actual number of entries
		ArrayElement<T>* elements;//array of elements
};

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
ArrayElement<T> Array<T>::remove(int i)
{
	if(i < 0 || i > maxEntries)
	{
		return ArrayElement<T>();
	}
	
	ArrayElement<T> e = elements[i];
	for(int j = i+1; j < numEntries; j++)
	{
		elements[j-1] = elements[j];	
	}
	numEntries--;
	
	return e;
}


template <class T>
Array<T>::~Array()
{
	delete[] elements;
}


#endif

