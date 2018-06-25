#include "tree_interface.h"

int main(int argc, char *argv[])
{
	Position<int> root(1);
	
	root.addChild(11);
	root.addChild(12);
	root.addChild(13);
	
	std::cout << "size of root: " << root.children().size() << std::endl;
	
	root.children().printElements();
	

	return 0;
}
