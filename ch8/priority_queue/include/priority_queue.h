#ifndef PRIORITY_QUEUE

#include <list>

#define PRIORITY_QUEUE

template <typename T, typename C>
class ListPriorityQueue
{
	public:
		int size() const;
		bool isEmpty() const;
		void insert(const T& t);
		const T& min();
		void removeMin();

	 private:
		std::list<T> L;//priority queue contents
		C isLess;//less than comparator

};

template < typename T, typename C>
int ListPriorityQueue< T, C >::size() const
{
	return L.size();
}

template < typename T, typename C >
bool ListPriorityQueue< T, C >::isEmpty() const
{
	return L.empty();
}

template < typename T, typename C >
void ListPriorityQueue< T, C >::insert(const T& t)
{
	typename std::list<T>::iterator p;
	p = L.begin();
	while(p != L.end() && !isLess(t, *p) ++p;
	L.insert(p, t);
}

template < typename T, typename C >
const T& ListPriorityQueue< T, C >::min()
{
	return L.front();
}

template < typename T, typename C >
void ListPriorityQueue< T, C >::removeMin()
{
	L.pop_front(); 
}

#endif
