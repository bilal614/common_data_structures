#ifndef ARRAY_PRACTICE_H
#define ARRAY_PRACTICE_H

#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>

class ArrayElement//Array Elements
{
	public:
		ArrayElement(const std::string& n="", int s = 0);//constructor
		std::string getName() const;
		int getElement() const;
		
	private:
		std::string name;
		int element;
		
};

class Array
{
	public:
		Array(int maxElements = 10);//constructor
		~Array();//destructor
		void add(const ArrayElement& e);//add an element
		
		ArrayElement remove(int i)//remove the i'th entry
			/*throw(IndexOutOfBounds)*/;
		void printElements();
		//T& operator[](int i);
	private:
		int maxEntries;//maximum number of entries
		int numEntries;//actual number of entries
		ArrayElement* elements;//array of elements
};
#endif
