#include "maps.h"

int main(int argc, char * argv[])
{
	Map<int, std::string> myMap;
	
	myMap.put(1, "Bilal");
	myMap.put(2, "Dene");
	myMap.put(3, "C++");
	myMap.put(4, "PHP");
	myMap.put(5, "Python");
	
	myMap.printMap();
	
	std::cout << "size of myMap: " << myMap.size() << std::endl;
	
	myMap.put(4, "Java");
	myMap.printMap();
	std::cout << "size of myMap: " << myMap.size() << std::endl;
	
	myMap.put(6, "PHP");
	myMap.printMap();
	std::cout << std::endl;
	
	auto It = myMap.find(6);
	myMap.erase(It);
	myMap.printMap();
	
	return 0;
}
