#include "arrays.h"

using namespace std;


ArrayElement::ArrayElement(const string& n, int s): name(n), element(s)
{
}

int ArrayElement::getElement() const
{ return element; }

std::string ArrayElement::getName() const
{
	return name;
}


Array::Array(int maxElements): maxEntries(maxElements), numEntries(0)
{
	elements = new ArrayElement[maxEntries];//allocate array storage
}

void Array::add(const ArrayElement& e)//add element to array
{
	int newEl = e.getElement();//element to add
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

void Array::printElements()
{
	std::cout << "numEntries: " << numEntries << std::endl;
	for(int i = 0; i < numEntries; i++)
	{
		std::cout << elements[i].getName() << ": " << elements[i].getElement() << ", ";
	}
	std::cout << std::endl;	
}

Array::~Array()
{
	delete[] elements;
}
