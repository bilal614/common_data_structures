#include "tree_interface.h"

int main(int argc, char *argv[])
{
	Position<int> root(1);
	
	root.addChild(11);
	root.addChild(12);
	root.addChild(13);
	root.children().printElements();
	return 0;
}
