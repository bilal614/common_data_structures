#include "heaps.h"


int main(int argc, char * argv[])
{	
	VectorCompleteTree<int> myTree;

	myTree.addLast(10);
	myTree.addLast(11);
	myTree.addLast(12);
	myTree.addLast(13);
	myTree.addLast(14);
	myTree.printTree();	

	return 0;
}
