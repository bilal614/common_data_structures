#ifndef HASH_MAP

#include <iostream>
#include <cmath> 
#include <string>
#include <list>
#include <vector>

#define HASH_MAP


template <typename K, typename V, typename H>
class HashMap
{
	//template <typename K, typename V> 
	public:
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

	public:
		//typedef Entry<const K,V> Entry;
		class Iterator;
	public:
		HashMap(int capcaity = 100);
		int size() const;
		bool empty() const;
		Iterator find(const K& k);
		Iterator put(const K& k, const V& v);
		void erase(const K& k);
		void erase(Iterator& p);
		Iterator begin();
		Iterator end();
		void printHashMap();
	protected:
		typedef std::list<Entry> Bucket;
		typedef std::vector<Bucket> BktArray;
		Iterator finder(const K& k);
		Iterator inserter(const Iterator& p, const Entry& e);
		void eraser(const Iterator& p);
		typedef typename BktArray::iterator BItor;
		typedef typename Bucket::iterator EItor;
		static void nextEntry(Iterator& p){ ++p.ent;}
		static bool endOfBkt(const Iterator& p){return p.ent == p.bkt->end();}
	private:
		int n;
		H hash; //hash function
		BktArray B;
	public:
		class Iterator
		{
			private:
				EItor ent;
				BItor bkt;
				const BktArray* ba;
			public:
				Iterator(const BktArray& a, const BItor& b, const EItor& q = EItor()):ent(q), bkt(b), ba(&a) {} 
				Entry& operator*() const;
				bool operator==(Iterator& p) const;
				
				bool operator!=(Iterator& p) const;
				
				Iterator& operator++();
				friend class HashMap;
		};		
};


template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Entry& HashMap<K,V,H>::Iterator::operator*() const
{
	return *ent;
}

template <typename K, typename V, typename H>
bool HashMap<K,V,H>::Iterator::operator==(HashMap<K,V,H>::Iterator& p) const
{
	if(ba != p.ba || bkt != p.bkt) return false;
	else if(bkt == ba->end()) return true;
	else return (ent == p.ent);
}

template <typename K, typename V, typename H>
bool HashMap<K,V,H>::Iterator::operator!=(HashMap<K,V,H>::Iterator& p) const
{
	if(ba != p.ba || bkt != p.bkt) return true;
	else if(bkt == ba->end()) return false;
	else return (ent != p.ent);
}


template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator& HashMap<K,V,H>::Iterator::operator++()
{
	++ent;//next entry in bucket
	if(endOfBkt(*this))//check if we are at end of this bucket, NOTE: you must dereference the Iterator to provide argument of Iterator& type
	{
		++bkt;//move to next bucket 
		while(bkt != ba->end() && bkt->empty())//find a non-empty bucket in bucket array 
			++bkt;
		if(bkt == ba->end()) return *this; //check if we have reached end of bucket array
		ent = bkt->begin();//set ent to first non-empty Entry
	}
	return *this;
}


template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::end()
{
	return HashMap<K,V,H>::Iterator(B, B.end()); 
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::begin()
{
	if(empty()) return end();//check if bucket array is empty
	BItor bkt = B.begin();//start with beginning bucket
	while(bkt->empty())++bkt;
	return HashMap<K,V,H>::Iterator(B, bkt, bkt->begin());	
}

template <typename K, typename V, typename H>
HashMap<K,V,H>::HashMap(int capacity):n(0), B(capacity)
{
}

template <typename K, typename V, typename H>
int HashMap<K,V,H>::size() const
{
	return n;
}

template <typename K, typename V, typename H>
bool HashMap<K,V,H>::empty() const
{
	return (size() == 0);
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::finder(const K& k)
{
	int i = hash(k) % B.size(); //get hash index i
	BItor bkt = B.begin() + i; //the ith bucket
	//std::cout << std::dec << "Bucket i: " << i << std::endl;
	HashMap<K,V,H>::Iterator p(B, bkt, bkt->begin()); //start of the bucket
	while(!endOfBkt(p) && (*p).key() != k)
		nextEntry(p);
	return p;
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::find(const K& k)
{
	HashMap<K,V,H>::Iterator p = finder(k);
	if(endOfBkt(p))
		return end();
	else
		return p;
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::inserter(const Iterator& p, const Entry& e)
{
	EItor ins = p.bkt->insert(p.ent, e);//insert before p	
	n++;
	return HashMap<K,V,H>::Iterator(B, p.bkt, ins);
}


template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator HashMap<K,V,H>::put(const K& k, const V& v)
{
	HashMap<K,V,H>::Iterator p = finder(k);
	if(endOfBkt(p))
		return inserter(p, HashMap<K,V,H>::Entry(k, v));
	else
	{
		/*
		p.ent->setValue(v);
		return p;
		*/
		if(p.ent->key() == k)
		{
			p.ent->setValue(v);
			return p;
		}
		else
		{
			return inserter(p, HashMap<K,V,H>::Entry(k, v));
		}
	}
}

template <typename K, typename V, typename H>
void HashMap<K,V,H>::eraser(const HashMap<K,V,H>::Iterator& p)
{
	p.bkt->erase(p.ent);
	n--;
}

template <typename K, typename V, typename H>
void HashMap<K,V,H>::erase(const K& k)
{
	HashMap<K,V,H>::Iterator p = finder(k);
	if(endOfBkt(p))
		return;
	eraser(p);	
}

template <typename K, typename V, typename H>
void HashMap<K,V,H>::erase(Iterator& p)
{
	eraser(p);
}

template <typename K, typename V, typename H>
void HashMap<K,V,H>::printHashMap()
{
	auto it = begin();
	auto ending = end();
	for(; it != ending; ++it)
	{
		std::cout << std::dec << (*it).key() << ": " << (*it).value() << std::endl;
	}
}

#endif
