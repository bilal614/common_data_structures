#include "hash_map.h"

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
	HashMap<int, std::string, HashCode> h_map;
	h_map.put(15, "Python");
	h_map.put(10, "C++");
	h_map.put(21, "Java");
	h_map.put(12, "C");
	h_map.put(30, "PHP");
	
	h_map.printHashMap();
	std::cout << "size of hash map: " << h_map.size() << std::endl;
	return 0;
}
