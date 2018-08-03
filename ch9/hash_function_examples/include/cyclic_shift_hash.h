#ifndef CYC_SHFT_HASH

#include <iostream>
#include <cmath> 

#define CYC_SHFT_HASH

const int a = 33;

int hashCode(const char* p, int len)
{
	unsigned int h = 0;
	std::cout << std::hex << h << std::endl;
	for(int i = 0; i < len; i++)
	{
		h = (h << 5) | (h >> 27);
		h += (unsigned int)p[i];
		std::cout << std::hex << h << std::endl;
	}
	return int(h);
}

int hashCode(const float& x)
{
	int len = sizeof(x);
	const char* p = reinterpret_cast<const char*>(&x);
	return hashCode(p, len);
}

int polyHash(const char* p, int len)
{
	unsigned int h = 0;
	std::cout << std::hex << h << std::endl;
	for(int i = 0; i < len; i++)
	{
		h += (unsigned int)p[i] * std::pow(a, i);
		std::cout << std::hex << h << std::endl;		   
	}
	return (int(h));
}

#endif
