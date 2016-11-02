class StackInt {

	private:
		int *vetor;
		int topo;
		int tamanho_max;
		void resize();
	public:
		StackInt(int tam = 10);
		~StackInt();
		void push(const int & o);
		int pop();
		int top() const ;

		bool isEmpty() const ;
		void makeEmpty() ;		

};