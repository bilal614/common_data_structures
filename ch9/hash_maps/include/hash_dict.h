#ifndef HASH_DICT

#include "hash_map.h"
#define HASH_DICT



template < typename K, typename V, typename H>
class HashDict: public HashMap< K, V, H>
{
	public:
		typedef typename HashMap<K,V,H>::Iterator Iterator;
		typedef typename HashMap<K,V,H>::Entry Entry;
		class Range
		{
			private:
				Iterator _begin;
				Iterator _end;
			public:
				Range(const Iterator& b, const Iterator& e):_begin(b), _end(e){}
				Iterator& begin(){ return _begin; }
				Iterator& end(){ return _end; }
		};
	public:
		HashDict(int capacity = 100);
		Range findAll(const K& k);
		Iterator insert(const K& k, const V& v);
		void printRange(Range& r);
};


template <typename K, typename V, typename H>
HashDict<K,V,H>::HashDict(int capacity): HashMap<K,V,H>(capacity) //constructor
{
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashDict<K,V,H>::insert(const K& k, const V& v)
{
	Iterator p = HashMap<K,V,H>::finder(k);
	Iterator q = HashMap<K,V,H>::inserter(p, Entry(k, v));
	return q;
}

template <typename K, typename V, typename H>
typename HashDict<K,V,H>::Range HashDict<K,V,H>::findAll(const K& k)
{
	Iterator b = HashMap<K,V,H>::finder(k);
	Iterator p = b;
	//std::cout << "FindAll\n";
	while(!HashMap<K,V,H>::endOfBkt(p) && (*p).key() == (*b).key())
	{
		//std::cout << std::dec << (*p).key() << ": " << (*p).value() << std::endl;
		++p;
	}
	return Range(b, p);
}

template <typename K, typename V, typename H>
void HashDict<K,V,H>::printRange(Range& r)
{
	Iterator it = r.begin();
	Iterator ending = r.end();
	std::cout << "Printing found range\n";
	for(;it != ending; ++it)
	{
		std::cout << std::dec << (*it).key() << ": " << (*it).value() << std::endl;
	}
}

#endif
