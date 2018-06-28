#include "tree_interface.h"

struct Foo
{
	std::string _name;
	int _id;
	Foo(): _name("None"), _id(0){}
	Foo(std::string name, int id):_name(name), _id(id){}
	
	friend std::ostream& operator<<(std::ostream& os, const Foo& foo);  

};

std::ostream& operator<<(std::ostream& os, const Foo& foo)  
{  
	os << foo._name << " " << foo._id;  
	return os;  
}



int main(int argc, char *argv[])
{
	Position<Foo>* root= new Position<Foo>(Foo("root foo", 1));
	
	root->addChild(Foo("child foo", 11));
	root->addChild(Foo("child foo", 12));
	root->addChild(Foo("child foo", 13));
	
	std::cout << "size of root: " << root->children()->size() << std::endl;
	std::cout << "check if root isRoot: " << root->isRoot() << std::endl;
	std::cout << "check if root isExternal: " << root->isExternal() << std::endl;
	root->children()->printElements();
	
	Position<Foo>* first_child = ((root->children()->begin()).v);
	std::cout << first_child->element << std::endl;
	std::cout << "check if root first_child: " << first_child->isRoot() << std::endl;
	std::cout << "check if isExternal first_child: " << first_child->isExternal() << std::endl;
	std::cout << "adding children to first child" << std::endl;
	first_child->addChild(Foo("child foo", 131));
	first_child->addChild(Foo("child foo", 132));
	//first_child->addChild(Foo("child foo", 133));
	first_child->children()->printElements();
	std::cout << "depth of first_child: " << first_child->depth() << std::endl;
	
	
	Position<Foo>* first_childs_first = ((first_child->children()->begin()).v);
	std::cout << "element of first_childs_first: " << first_childs_first->element << ", parent of first_childs_first: " 
	<< (first_childs_first->parent())->element << std::endl;
	std::cout << "depth of first_childs_first: " << first_childs_first->depth() << std::endl;
	std::cout << "check if isExternal first_childs_first: " << first_childs_first->isExternal() << std::endl;
	
	
	std::cout << "size of first_child: " << first_child->children()->size() << std::endl;
	
	Position<Foo>* second_child = (Position<Foo>*)((++(root->children()->begin())).v);
	std::cout << second_child->element << std::endl;
	std::cout << "size of second_child: " << second_child->children()->size() << std::endl;
	
	std::cout << "depth of second_child: " << second_child->depth() << std::endl;
	
	
	second_child->addChild(Foo("child foo", 121));
	second_child->addChild(Foo("child foo", 122));
	second_child->children()->printElements();
	
	std::cout << "height of root: " << root->height() << std::endl;
	std::cout << "height of first_child: " << first_child->height() << std::endl;
	std::cout << "height of first_childs_first: " << first_childs_first->height() << std::endl;
	std::cout << "height of second_child: " << second_child->height() << std::endl;
	
	root->preorderPrint();
	std::cout << std::endl;
	
	root->postorderPrint();
	std::cout << std::endl;
	return 0;
}
