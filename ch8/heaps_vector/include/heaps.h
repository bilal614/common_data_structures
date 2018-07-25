#ifndef HEAPS

#include <vector>
#include <iostream>

#define HEAPS

template < typename T > 
class VectorCompleteTree
{
	private:
		std::vector<T> V;
	public:
		typedef typename std::vector<T>::iterator Position;//a position in the tree
	protected:
		Position pos(int i){return V.begin() + i;}
		int idx(const Position& p) const { return p - V.begin();}
	public:
		VectorCompleteTree(): V(1){}//constructor
		int size() const { return V.size() - 1;}
		Position left(const Position& p) {return pos(2*idx(p));}
		Position right(const Position& p){return pos(2*idx(p)+1);}
		Position parent(const Position& p) { return pos(idx(p)/2);}
		bool hasLeft(const Position& p) const { return 2*idx(p) <= size(); }
		bool hasRight(const Position& p) const { return 2*idx(p) + 1 <= size(); }
		bool isRoot(const Position& p) const { return idx(p) == 1; }
		Position root() { return pos(1);}
		Position last() { return post(size()); }
		void addLast(const T& t) { V.push_back(t);}
		void removeLast() { V.pop_back();}
		void swap(const Position& p, const Position& q) { T t = *q; *q = *p; *p = t; }
		void printTree()
		{
			Position p = V.begin();
			while(p != V.end())
			{
				std::cout << *p << ", ";
				++p;
			}
			std::cout << std::endl;
		}

};



#endif
