//#include "binary_tree.h"
#include "heap_priority_queue.h"

int main(int argc, char * argv[])
{
	
	//CompleteTree<int> bin_tree;
	HeapPriorityQueue<int> bin_tree;
	bin_tree.insert(0);
	bin_tree.insert(101);
	bin_tree.insert(102);
	bin_tree.insert(201);
	bin_tree.insert(202);
	bin_tree.insert(203);
	bin_tree.insert(204);
	bin_tree.insert(301);
	bin_tree.insert(302);
	bin_tree.insert(303);
	
	bin_tree.printHeap();
	
	/*
	bin_tree.printQ();
	auto Last = bin_tree.last();
	
	std::cout << typeid(Last).name() << std::endl;
	std::cout << "last: "<< *(bin_tree.last()) << std::endl;
	*/
	/*
	std::cout << "Pre-order traversal: " << std::endl;
	auto pre_list = bin_tree.positions();
	
	std::cout << "Post-order traversal: " << std::endl;
	auto post_list = bin_tree.positions(false);
	
	
	bin_tree.remove();
	bin_tree.printQ();
	
	auto myRoot = bin_tree.root();
	auto myLast = bin_tree.last();
	//std::cout << "myLeft: " << *(*myLeft) << std::endl;
	
	bin_tree.swap(*(bin_tree.root()), *myLast);
	bin_tree.printQ();
	*/
	return 0;
}
