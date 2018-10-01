//#include "binary_tree.h"
#include "bin_srch_tree.h"

int main(int argc, char * argv[])
{
	
	using MyEntry = Entry<int, std::string>;
	SearchTree< MyEntry > srch_tree;
	srch_tree.insert(10, "Messi");
	srch_tree.insert(7, "Ronaldo");
	srch_tree.insert(8, "Rooney");
	srch_tree.printTree();
	
	/*
	LinkedBinaryTree<int> bin_tree;
	
	bin_tree.addRoot();
	
	LinkedBinaryTree<int>::Position bin_root = bin_tree.root();

	bin_tree.expandExternal(bin_root);
	bin_root.setElement(1);
	std::cout << *bin_root << std::endl;
	//Position<int> 
	
	LinkedBinaryTree<int>::Position left_node = bin_root.left();
	left_node.setElement(101); 
	std::cout << *left_node << std::endl;
	bin_tree.expandExternal(left_node);
	
	auto right_node = bin_root.right(); 
	right_node.setElement(102);
	bin_tree.expandExternal(right_node);
	
	//bin_tree.expandExternal(bin_root.right());
	//bin_root.left().setElement(101);
	//bin_root.right().setElement(102);
	
	bin_tree.printTree();
	/*
	//bin_tree.expandExternal(bin_root->left(), 201, 202);
	//bin_tree.expandExternal(bin_root->right(), 203, 204);
	*/
}
