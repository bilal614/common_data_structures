#include "tree_interface.h"

int main(int argc, char *argv[])
{
	Position<int>* root= new Position<int>(1);
	
	root->addChild(11);
	root->addChild(12);
	root->addChild(13);
	
	std::cout << "size of root: " << root->children()->size() << std::endl;
	std::cout << "check if root isRoot: " << root->isRoot() << std::endl;
	root->children()->printElements();
	
	Position<int>* first_child = ((root->children()->begin()).v);
	//std::cout << "typeid of first_child: "  << typeid(first_child).name() << std::endl;
	std::cout << first_child->element << std::endl;
	std::cout << "check if root first_child: " << first_child->isRoot() << std::endl;
	first_child->addChild(131);
	std::cout << "added child to first child" << std::endl;
	first_child->addChild(132);
	first_child->addChild(133);
	first_child->children()->printElements();
	
	Position<int>* second_child = (Position<int>*)((++(root->children()->begin())).v);
	std::cout << second_child->element << std::endl;
	second_child->addChild(121);
	second_child->addChild(122);
	second_child->children()->printElements();
	//std::cout << "check if root second_child: " << second_child->isRoot() << std::endl;
	
	return 0;
}
