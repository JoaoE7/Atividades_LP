#include "AbsStack.h"


template <typename Object>
class StackAr : public AbsStack<Object> {

	private:
		Object *vetor;
		int topo;
		int tamanho_max;
		void resize();
	public:
		StackAr(int tam = 10);
		~StackAr();

		void push(const Object & o);
		Object pop();
		Object top() const ;

		bool isEmpty() const ;
		void makeEmpty() ;		
};

#include "stackar.inl"