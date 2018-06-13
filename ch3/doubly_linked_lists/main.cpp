
#include "doubly_linked_lists_templated.h"
#include <fstream>


int main(int argc, char *argv[])
{
	//DoublyLinkedList<int> dbl_ll;
	DoublyLinkedList<std::string> dbl_ll;

	std::ofstream of_writer ("test.txt", std::ofstream::out);
	
	//dbl_ll.addFront(10);
	dbl_ll.addFront("Stayin Alive");
	of_writer << dbl_ll.front() << std::endl;
	dbl_ll.printElements(); 
	
	//dbl_ll.addFront(14);
	dbl_ll.addFront("Le Freak");
	of_writer << dbl_ll.front() << std::endl;
	dbl_ll.printElements(); 
	
	//dbl_ll.addFront(7);
	dbl_ll.addFront("Jive Talkin");
	of_writer << dbl_ll.front() << std::endl;
	dbl_ll.printElements(); 
	
	dbl_ll.removeFront();
	dbl_ll.printElements();
	
	//dbl_ll.addBack(5);
	dbl_ll.addFront("Disco Inferno");
	of_writer << dbl_ll.front() << std::endl;
	dbl_ll.printElements();
	
	dbl_ll.listReverse();
	dbl_ll.printElements();
	
	of_writer.close();
	return 0;
}
