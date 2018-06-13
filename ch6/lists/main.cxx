
#include "dll_node_list_iterator.h"
#include <string>

int main(int argc, char *argv[])
{
	/*
	NodeList<int> dll_nl;
	dll_nl.insertFront(10);
	dll_nl.printElements(); 
	dll_nl.insertFront(14);
	dll_nl.printElements(); 
	dll_nl.insertFront(7);
	dll_nl.printElements(); 
	dll_nl.eraseFront();
	dll_nl.printElements();
	dll_nl.insertBack(5);
	dll_nl.printElements();
	*/
	NodeList<std::string> dll_nl;
	dll_nl.insertFront("Stayin Alive");
	dll_nl.printElements();
	dll_nl.insertFront("Le Freak");
	dll_nl.printElements();
	dll_nl.insertFront("Jive Talkin");
	dll_nl.printElements();
	dll_nl.insertBack("Ain't no sunshine");
	dll_nl.printElements();
	dll_nl.insertFront("Disco Inferno");
	dll_nl.printElements();
	
	return 0;
}
