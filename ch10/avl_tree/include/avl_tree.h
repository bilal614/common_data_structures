#ifndef AVL_TREE

#include "bin_srch_tree.h"
#include <algorithm>

#define AVL_TREE

namespace DataStructures
{

	template <typename E> class AVLTree;

	template <typename E>
	class AVLEntry : public E
	{
		private:
			int ht;	//node height
		protected:
			typedef typename E::Key K;
			typedef typename E::Value V;
			int height() const {return ht;}
			void setHeight(int h) {ht = h;}
		public:
			AVLEntry(const K& k = K(), const V& v = V()): E(k, v), ht(0){}
			friend class AVLTree<E>;
	};

	template <typename E>
	class AVLTree: public SearchTree< AVLEntry<E> >
	{
		public:
			//typedef AVLEntry<E> AVLEntry;
			typedef typename SearchTree< AVLEntry<E> >::Iterator Iterator;
		protected:
			typedef typename AVLEntry<E>::Key K;//key
			typedef typename AVLEntry<E>::Value V;//value 
			typedef SearchTree< AVLEntry<E> > ST;//SearchTree
			typedef typename ST::TPos TPos;//tree position 
		public:
			AVLTree();
			TPos insert(const K& k, const V& x);
			void erase(const K& k);
			void erase(const Iterator& p);
		protected:
			int height(const TPos& v) const;
			void setHeight(TPos v);
			bool isBalanced(const TPos& v) const;
			TPos tallGrandchild(const TPos& v) const;
			void rebalance(const TPos& v);

	};

	template <typename E>
	AVLTree<E>::AVLTree() : ST() {}

	template <typename E>
	int AVLTree<E>::height(const TPos& v) const
	{
		return (v.isExternal() ? 0 : v->height());
	}

	template <typename E>
	void AVLTree<E>::setHeight(TPos v)
	{
		int hl = height(v.left());
		int hr = height(v.right());
		v.setHeight(1 + std::max(hl, hr));
	}

	template <typename E>
	bool AVLTree<E>::isBalanced(const TPos& v) const
	{
		int bal = height(v.left()) - height(v.right());
		return ((-1 <= bal) && (bal <= 1));
	}

	template <typename E>
	typename AVLTree<E>::TPos AVLTree<E>::tallGrandchild(const TPos& z) const
	{
		TPos zl = z.left();
		TPos zr = z.right();
		if(height(zl) >= height(zr))
			if(height(zl.left()) >= height(zl.right()))
				return zl.left();
			else
				return zl.right();
		else
			if(height(zr.left()) >= height(zr.right()))
				return zr.left();
			else
				return zr.right();
	}

	template <typename E>
	void AVLTree<E>::rebalance(const TPos& v)
	{
		TPos z = v;
		while(!(z == ST::root()))
		{
			z = z.parent();
			setHeight(z);
			if(!isBalanced(z))
			{
				TPos x = tallGrandchild(z);
				z = SearchTree< AVLEntry<E> >::restructure(x);
				setHeight(z.left());
				setHeight(z.right());
				setHeight(z);
			}
		}
	}

	template <typename E>
	typename AVLTree<E>::TPos AVLTree<E>::insert(const K& k, const V& x)
	{
		TPos v = SearchTree< AVLEntry<E> >::inserter(k, x);
		setHeight(v);//re-adjust height of v
		rebalance(v);
		return v;
	}

	template <typename E>
	void AVLTree<E>::erase(const K& k)
	{
		TPos v = finder(k, ST::root());
		if(Iterator(v) == ST::end())
		{
			return;
		}
		TPos w = eraser(v);//remove v
		rebalance(w);
	}
}
#endif
