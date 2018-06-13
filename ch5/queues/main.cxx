#include "data_structure_queues.h"
#include <string>

int main(int argc, char *argv[])
{
	Queue<std::string> cll_queue;
	
	
	cll_queue.enqueue("first");
	//cll_queue.enqueue(1);
	cll_queue.print_queue(); 
	
	cll_queue.enqueue("second");
	//cll_queue.enqueue(2);
	cll_queue.print_queue(); 
	
	cll_queue.enqueue("third");
	//cll_queue.enqueue(3);
	cll_queue.print_queue(); 
	
	cll_queue.enqueue("fourth");
	//cll_queue.enqueue(4);
	cll_queue.print_queue(); 
	
	cll_queue.enqueue("fifth");
	//cll_queue.enqueue(5);
	cll_queue.print_queue(); 
	
	cll_queue.dequeue();
	cll_queue.print_queue();
	
	cll_queue.dequeue();
	cll_queue.print_queue();
	
	return 0;
}
