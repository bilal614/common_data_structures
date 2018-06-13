
#include "circularly_linked_lists_templated.h"
#include <fstream>


int main(int argc, char *argv[])
{
	//CircleLinkedList<int> crcl_ll;
	CircleLinkedList<std::string> crcl_ll;

	std::ofstream of_writer ("test.txt", std::ofstream::out);
	
	//crcl_ll.addFront(10);
	crcl_ll.add("Stayin Alive");
	of_writer << crcl_ll.front() << std::endl;
	crcl_ll.printElements(); 
	
	//crcl_ll.addFront(14);
	crcl_ll.add("Le Freak");
	of_writer << crcl_ll.front() << std::endl;
	crcl_ll.printElements(); 
	
	//crcl_ll.addFront(7);
	crcl_ll.add("Jive Talkin");
	of_writer << crcl_ll.front() << std::endl;
	crcl_ll.printElements(); 
	
	crcl_ll.remove();
	crcl_ll.printElements();
	
	//crcl_ll.addBack(5);
	crcl_ll.add("Disco Inferno");
	of_writer << crcl_ll.front() << std::endl;
	crcl_ll.printElements();
	
	crcl_ll.printElements();
	
	of_writer.close();
	return 0;
}
