#include "data_structure_stacks.h"

int main(int argc, char *argv[])
{
	LinkedStack<std::string> sll_stack;
	
	
	sll_stack.push("first");
	//sll_stack.push(1);
	sll_stack.print_list(); 
	
	sll_stack.push("second");
	//sll_stack.push(2);
	sll_stack.print_list(); 
	
	sll_stack.push("third");
	//sll_stack.push(3);
	sll_stack.print_list(); 
	
	sll_stack.pop();
	sll_stack.print_list();
	
	return 0;
}
