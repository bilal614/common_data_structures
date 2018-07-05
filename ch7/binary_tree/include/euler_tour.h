#ifndef EULER_TOUR

#include "binary_tree.h"

#define EULER_TOUR

template < typename T, typename R >
class PrintExpressionTour: public EulerTour< T,R >
{
	protected:
		typedef LinkedBinaryTree<T> BinaryTree;
		typedef Position<T> EulerPosition;
		typedef typename EulerTour< T, R >::Result Result;
	public:
		void execute(const BinaryTree& t){initialize(t); std::cout << "Expression: " << eulerTour(t.root()) << "\n";}
	protected:
		virtual void visitExternal(EulerPosition& p, Result& r) const
		{
			std::cout << (*p);
		}
		
		virtual void visitBelow(EulerPosition& p, Result& r) const
		{
			std::cout << (*p);
		}
		
		virtual void visitLeft(EulerPosition& p, Result& r) const
		{
			std::cout << "(";
		}
		
		virtual void visitRight(EulerPosition& p, Result& r) const
		{
			std::cout << ")";
		}
}; 


#endif
