#ifndef DLL_PRACTICE_H

#include <iostream>
#include <typeinfo>
#include <exception>
#include <string>

#define DLL_PRACTICE_H


template <typename T>
class NodeList
{
	protected:
		struct Node
		{
			T element;
			Node* prev;//previous node in the list
			Node* next;//next node in the list
		};
	
	public:
		class Iterator
		{
			public:
				T& operator*();//reference to the element
				bool operator==(const Iterator& p) const;//compare positions
				bool operator!=(const Iterator& p) const;
				Iterator& operator++();//move to next position
				Iterator& operator--();//move to previous position

				friend class NodeList<T>;
			//private:
			public:
				Node* v;//pointer to node
				Iterator(Node* u);//create from node

		};
	public:
		NodeList();//default constructor
		//~NodeList();
		int size() const;//list size
		bool empty() const;//is the list empty
		Iterator begin() const;//beginning position
		Iterator end() const;//(just beyond) last position
		void insert(const Iterator& p, const T& e);//insert e before p
		void insertFront(const T& e);//insert at front
		void insertBack(const T& e);//insert at rear
		void erase(const Iterator& p);//remove p
		void eraseFront();//remove first
		void eraseBack();//remove last
		void printElements();

	private: //data members
		int n;//number of items
		Node* header;//head of list sentinel
		Node* trailer;//tail of list sentinel
};


template <typename T>
class NodeSequence: public NodeList<T>
{

	public:
		typename NodeList<T>::Iterator atIndex(int i) const;

		int indexOf(typename NodeList<T>::Iterator& p) const;

		void printElements();
		void swap(typename NodeList<T>::Iterator& a, typename NodeList<T>::Iterator& b);
		void bubbleSort();

};


#endif
