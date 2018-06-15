
#include "dll_node_list_iterator.h"
#include <string>

int main(int argc, char *argv[])
{

	NodeList<int> dll_nl_int;
	dll_nl_int.insertFront(10);
	dll_nl_int.printElements(); 
	dll_nl_int.insertFront(14);
	dll_nl_int.printElements(); 
	dll_nl_int.insertFront(7);
	dll_nl_int.printElements(); 
	dll_nl_int.eraseFront();
	dll_nl_int.printElements();
	dll_nl_int.insertBack(5);
	dll_nl_int.printElements();
	
	NodeList<std::string> dll_nl_str;
	dll_nl_str.insertFront("Stayin Alive");
	dll_nl_str.printElements();
	dll_nl_str.insertFront("Le Freak");
	dll_nl_str.printElements();
	dll_nl_str.insertFront("Jive Talkin");
	dll_nl_str.printElements();
	dll_nl_str.insertBack("Ain't no sunshine");
	dll_nl_str.printElements();
	dll_nl_str.insertFront("Disco Inferno");
	dll_nl_str.printElements();
	
	
	NodeList<float> dll_nl_float;
	dll_nl_float.insertFront(10.567);
	dll_nl_float.printElements(); 
	dll_nl_float.insertFront(14.978);
	dll_nl_float.printElements(); 
	dll_nl_float.insertFront(7.777);
	dll_nl_float.printElements(); 
	dll_nl_float.eraseFront();
	dll_nl_float.printElements();
	dll_nl_float.insertBack(5.412);
	dll_nl_float.printElements();
	
	return 0;
}