#include "hash_map.h"
#include "hash_dict.h"

class HashCode
{
	public:
		int operator()(int p)
		{
			unsigned int h = p;
			//std::cout << std::hex << h << std::endl;
			h = (h << 5) | (h >> 27);
			std::cout << std::hex << h << std::endl;
			return int(h);
		}
};


int main(int argc, char * argv[])
{
	/*
	HashMap<int, std::string, HashCode> h_map(10);
	h_map.put(15, "Python");
	h_map.put(10, "C++");
	h_map.put(21, "Java");
	h_map.put(12, "C");
	h_map.put(30, "PHP");
	
	h_map.printHashMap();
	std::cout << "size of hash map: " << h_map.size() << std::endl;
	*/
	HashDict<int, std::string, HashCode> h_map(11);
	h_map.insert(15, "Python");
	h_map.insert(10, "C++");
	h_map.insert(21, "Java");
	h_map.insert(10, "C");
	h_map.insert(30, "PHP");
	h_map.insert(21, "C#");

	h_map.printHashMap();
	
	auto a_range = h_map.findAll(10);
	h_map.printRange(a_range);
	
	auto b_range = h_map.findAll(21);
	h_map.printRange(b_range);
	
	auto c_range = h_map.findAll(15);
	h_map.printRange(c_range);
	
	return 0;
}
