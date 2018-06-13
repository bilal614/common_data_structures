
#include "singly_linked_lists_templated.h"

int main(int argc, char *argv[])
{
	SinglyLinkedList<int> sll;
	
	
	sll.addFront(10);
	sll.printElements(); 
	
	sll.addFront(14);
	sll.printElements(); 
	
	sll.addFront(7);
	sll.printElements(); 
	
	sll.removeFront();
	sll.printElements();
	
	return 0;
}
