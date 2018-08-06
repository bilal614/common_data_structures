#ifndef HASH_MAP

#include "maps.h"

#define HASH_MAP

template <typename K, typename V>
class Entry
{
	public:
		Entry(const K& k = K(), const V& v = V()): _key(k), _value(v){}
		const K& key(){ return _key;}
		const V& value(){ return _value;}
		void setKey(const K& k){ _key = k;}
		void setValue(const V& v){ _value = v;}
	private:
		K _key;
		V _value;
};

template <typename K, typename V, typename H>
class HashMap
{
	public:
		typedef Entry<const K,V> Entry;
		class Iterator;
	public:
		HashMap(int capcaity = 100);
		int size() const;
		bool empty() const;
};


#endif
