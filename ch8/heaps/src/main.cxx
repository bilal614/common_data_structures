#include "binary_tree.h"


int main(int argc, char * argv[])
{
	CompleteTree<int> bin_tree;
	bin_tree.add(0);
	bin_tree.add(101);
	bin_tree.add(102);
	bin_tree.add(201);
	bin_tree.add(202);
	bin_tree.add(203);
	bin_tree.add(204);
	bin_tree.add(301);
	bin_tree.add(302);
	bin_tree.add(303);
	
	/*
	bin_tree.printQ();
	auto Last = bin_tree.last();
	
	std::cout << typeid(Last).name() << std::endl;
	std::cout << "last: "<< *(bin_tree.last()) << std::endl;
	*/
	std::cout << "Pre-order traversal: " << std::endl;
	auto pre_list = bin_tree.positions();
	
	std::cout << "Post-order traversal: " << std::endl;
	auto post_list = bin_tree.positions(false);
	
	
	bin_tree.remove();
	bin_tree.printQ();
		
	return 0;
}
