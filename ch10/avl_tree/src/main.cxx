#include "avl_tree.h"


int main(int argc, char * argv[])
{
	using namespace DataStructures;
	using _Entry = Entry<int, std::string>;
	using MyEntry = AVLEntry<_Entry>;
	AVLTree< MyEntry > avl_tree;
	avl_tree.insert(10, "Messi");
	avl_tree.insert(7, "Ronaldo");
	avl_tree.insert(8, "Rooney");
	avl_tree.printTree();
	return 0;
}
