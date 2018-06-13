//#include "arrays.h"
#include "arrays_templated.h"
/*
int main(int argc, char *argv[])
{
	Array* ary = new Array(10);
	ArrayElement a1 = ArrayElement("bilal", 28);
	ArrayElement a2 = ArrayElement("dene", 24);
	ary->add(a1);
	ary->printElements(); 
	ary->add(a2);
	ary->printElements();
	
	delete ary;
	return 0;
}
*/

int main(int argc, char *argv[])
{
	Array<int>* ary = new Array<int>(10);
	ArrayElement<int> a1 = ArrayElement<int>("abc", 28);
	ArrayElement<int> a2 = ArrayElement<int>("def", 24);
	ArrayElement<int> a3 = ArrayElement<int>("ghi", 40);
	ArrayElement<int> a4 = ArrayElement<int>("jkl", 21);
	ary->add(a1);
	ary->printElements(); 
	ary->add(a2);
	ary->printElements();
	ary->add(a3);
	ary->printElements();
	ary->add(a4);
	ary->printElements();
	
	ary->remove(2);
	ary->printElements();
	delete ary;
	return 0;
}
