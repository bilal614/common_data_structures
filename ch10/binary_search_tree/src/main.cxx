#include "bin_srch_tree.h"

int main(int argc, char * argv[])
{
	using MyEntry = Entry<int, std::string>;
	SearchTree< MyEntry > srch_tree;
	srch_tree.insert(10, "Messi");
	srch_tree.insert(7, "Ronaldo");
	srch_tree.insert(8, "Rooney");
	srch_tree.printTree();
	
}
