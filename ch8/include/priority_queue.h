#ifndef PRIORITY_QUEUE


#define PRIORITY_QUEUE

template <typename T, typename C>
class PriorityQueue
{
	public:
		int size() const;
		bool isEmpty() const;
		void insert(const T& t);
		const T& min();
		void removeMin();

	 

};




#endif
