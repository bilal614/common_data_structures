/*
 * dll_node_sequence.h
 *
 *  Created on: Jun 15, 2018
 *      Author: bilal
 */
/*
#ifndef INCLUDE_DLL_NODE_SEQUENCE_H_

#include "dll_node_list_iterator.h"
#define INCLUDE_DLL_NODE_SEQUENCE_H_




template <typename T>
class NodeSequence: public NodeList<T>
{
	public:
		class Iterator
		{
			public:
				T& operator*();//reference to the element
				bool operator==(const Iterator& p) const;//compare positions
				bool operator!=(const Iterator& p) const;
				Iterator& operator++();//move to next position
				Iterator& operator--();//move to previous position

				friend class NodeSequence<T>;
			//private:
			public:
				typedef typename NodeList<T>::Node* NodePtr;

				NodePtr v;//pointer to node
				Iterator(NodePtr u);//create from node

		};
	public:
		Iterator atIndex(int i) const;

		int indexOf(Iterator& p) const;

		Iterator begin();//beginning position
		Iterator end();//(just beyond) last position

};



endif /* INCLUDE_DLL_NODE_SEQUENCE_H_ */
/*
*/
