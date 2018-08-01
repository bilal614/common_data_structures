#ifndef MAPS_INTERFACE

#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>
#include <list>

#define MAPS_INTERFACE

template <typename K, typename V>
class Map
{
	public:
		class Entry
		{
			public:
				Entry(const K& k = K(), const V& v = V()): _key(k), _value(v){}
				const K& key() const { return _key;}
				const V& value() const { return _value;}
				void setKey(const K& k) { _key = k;}
				void setValue(const V& v) { _value = v; }
			private:
				K _key;
				V _value;
		};
		
		typedef typename std::list< Map<K,V>::Entry >::iterator Iterator;
		
		Map(); //constructor
		int size() const;	//number of entries
		bool empty() const;	//is map empty?
		Iterator find(const K& k);	//find entry with key K and return as Iterator
		Iterator put(const K& k, const V& v);	//insert/replace pair (k,v)
		void erase(const K& k);
		void erase(const Iterator& p);
		Iterator begin();
		Iterator end();
		void printMap();
		void printEntry(Iterator& p);
		
	private: //data members
		int n;//number of items
		std::list< Map<K,V>::Entry > map_list;

};

template <typename K, typename V>
Map<K,V>::Map():n(0){}

template <typename K, typename V>
int Map<K,V>::size() const
{
	return n;
}

template <typename K, typename V>
bool Map<K,V>::empty() const
{
	return (n == 0);
}

template <typename K, typename V>
typename Map<K,V>::Iterator Map<K,V>::find(const K& k)
{
	Iterator _end = end();
	Iterator it = begin();
	for(; it != _end; ++it)
	{
		if( (*it).key() == k)
			return it;
	}
	return _end;	
}

template <typename K, typename V>
typename Map<K,V>::Iterator Map<K,V>::put(const K& k, const V& v)
{
	Iterator _exists = find(k);
	if(_exists != end())
	{
		(*_exists).setValue(v);
	}
	else
	{
		map_list.push_front(Entry(k, v));
		++n;
		return (--_exists);
	}
	return _exists;
}

template <typename K, typename V>
typename Map<K,V>::Iterator Map<K,V>::begin()
{
	return map_list.begin();
}

template <typename K, typename V>
typename Map<K,V>::Iterator Map<K,V>::end()
{
	return map_list.end();
}

template <typename K, typename V>
void Map<K,V>::erase(const K& k)
{
	Iterator it = find(k);
	erase(it);
}

template <typename K, typename V>
void Map<K,V>::erase(const Iterator& p)
{
	map_list.erase(p);
	--n;
}

template <typename K, typename V>
void Map<K,V>::printMap()
{
	Iterator _end = this->end();
	Iterator _it = this->begin();
	for(; _it != _end; ++_it)
	{
		std::cout << "key: " << (*_it).key() << ", value: " << (*_it).value() << std::endl;
	}	
}

template <typename K, typename V>
void Map<K,V>::printEntry(Iterator& p)
{
	std::cout << "key: " << (*p).key() << ", value: " << (*p).value() << std::endl;	
}

#endif
