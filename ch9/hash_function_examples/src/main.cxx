#include "cyclic_shift_hash.h"
#include <string>
#include <cstring>

int main(int argc, char* argv[])
{
	std::cout << "Please enter a word to be converted to hash code: ";
	std::string myStr;

	std::cin >> myStr;
	
	char* myWord = new char [myStr.length() + 1];	
	std::strcpy(myWord, myStr.c_str());		
	int word_length = myStr.length();
	std::cout << "length of word entered is " << word_length << std::endl;
	int result = hashCode(myWord, word_length);
	std::cout << "Result: " << std::dec << result << std::endl;
	int pol_result = polyHash(myWord, word_length);
	std::cout << "Poly Result: " << std::dec << pol_result << std::endl;
	return 0;
}
