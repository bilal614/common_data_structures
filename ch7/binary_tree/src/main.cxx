#include "bin_tree_position.h"
#include "binary_tree.h"

int main(int argc, char * argv[])
{
	LinkedBinaryTree<int> bin_tree;
	
	bin_tree.addRoot(0);
	auto bin_root =  bin_tree.root();
	std::cout << *(*bin_root) << std::endl;
	bin_tree.expandExternal(bin_root, 101, 102);
	bin_tree.expandExternal(bin_root->left(), 201, 202);
	bin_tree.expandExternal(bin_root->right(), 203, 204);
	//std::cout << "left of root: " << *(*(bin_root->left())) << std::endl;
	/*
	bin_tree.expandExternal(new Position<int>(101));
	bin_tree.expandExternal(new Position<int>(102));
	bin_tree.expandExternal(new Position<int>(201));
	bin_tree.expandExternal(new Position<int>(202));
	*/
	auto pos_list = bin_tree.positions();
	std::cout << "size of pos_list: " << pos_list.size() << std::endl;
	std::cout << "size of bin_tree: " << bin_tree.size() << std::endl; 
	return 0;
}
