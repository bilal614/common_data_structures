//#include "bin_tree_position.h"
//#include "binary_tree.h"
#include "euler_tour.h" 

int main(int argc, char * argv[])
{
	/*
	LinkedBinaryTree<int> bin_tree;
	
	bin_tree.addRoot(0);
	auto bin_root =  bin_tree.root();
	std::cout << *(*bin_root) << std::endl;
	bin_tree.expandExternal(bin_root, 101, 102);
	bin_tree.expandExternal(bin_root->left(), 201, 202);
	bin_tree.expandExternal(bin_root->right(), 203, 204);
	//std::cout << "left of root: " << *(*(bin_root->left())) << std::endl;
	
	//bin_tree.expandExternal(new Position<int>(101));
	//bin_tree.expandExternal(new Position<int>(102));
	//bin_tree.expandExternal(new Position<int>(201));
	//bin_tree.expandExternal(new Position<int>(202));
	
	std::cout << "Pre-order traversal: " << std::endl;
	auto pre_list = bin_tree.positions();
	std::cout << "Post-order traversal: " << std::endl;
	auto post_list = bin_tree.positions(false);
	std::cout << "size of pre_list: " << pre_list.size() << std::endl;
	std::cout << "size of post_list: " << post_list.size() << std::endl;
	std::cout << "size of bin_tree: " << bin_tree.size() << std::endl; 
	
	PositionList<int> pl;
	std::cout << "In-order traversal: " << std::endl;
	bin_tree.inorder(bin_root, pl);
	
	*/
	LinkedBinaryTree< std::string > bin_tree;
	
	bin_tree.addRoot("*");
	auto bin_root =  bin_tree.root();
	bin_tree.expandExternal(bin_root, "+", "/");
	bin_tree.expandExternal(bin_root->left(), "5", "7");
	bin_tree.expandExternal(bin_root->right(), "*", "2");
	bin_tree.expandExternal(bin_root->right()->left(), "8", "11");
	
	PositionList< std::string > pl;
	std::cout << "In-order traversal: " << std::endl;
	bin_tree.inorder(bin_root, pl);
	
	PrintExpressionTour< std::string , int > exprTour;
	exprTour.eulerTour((*bin_root));
	std::cout << std::endl;
	
	return 0;
}
