#ifndef EULER_TOUR

#include "binary_tree.h"

#define EULER_TOUR

template < typename T, typename R >
class PrintExpressionTour: public EulerTour< E,R >
{
	protected:
		typedef typename EulerTour< E, R >::LinkedBinaryTree BinaryTree;
		typedef typename EulerTour< E, R >::Position Position;
		typedef typename EulerTour< E, R >::Result Result;
	public:
		void execute(const BinaryTree& T){initialize(T); std::cout << "Expression: " << eulerTour(T.root()) << "\n";}
	protected:
		virtual void visitExternal(const Position& p, Result& r) const
		{
			std::cout << *p;
		}
		
		virtual void visitBelow(const Position& p, Result& r) const
		{
			std::cout << *p;
		}
		
		virtual void visitLeft(const Position& p, Result& r) const
		{
			std::cout << "(";
		}
		
		virtual void visitRight(const Position& p, Result& r) const
		{
			std::cout << ")";
		}
}; 


#endif
