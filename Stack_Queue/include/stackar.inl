#include <exception>

using namespace std;

template <typename Object>
StackAr<Object>::StackAr (int tam) {
	tamanho_max = tam;
	topo = 0;
	vetor =  new Object [tam];
}

template <typename Object>
StackAr<Object>::~StackAr () {
	delete [] vetor ;
}

template <typename Object>
void StackAr<Object>::push (const Object & o) {
	if (topo == tamanho_max) 
		resize();
	vetor[topo] = o;
	topo++;
}

template <typename Object>
void StackAr<Object>::resize () {
	Object *np;
	np = new Object [tamanho_max*2];
	tamanho_max *= 2;
	for (int i = 0; i < topo; i++) {
		np[i] = vetor[i];
	}
	delete [] vetor ;
	vetor = np;
}

template <typename Object>
Object StackAr<Object>::pop () {
	if (topo != 0) {
		Object retorno = vetor[topo-1];
		topo--;
		return retorno;
	}
	
	throw out_of_range("Underflow na pilha");
}

template <typename Object>
Object StackAr<Object>::top () const {
	if (topo != 0) {
		return vetor[topo-1];
	}

	throw out_of_range("Underflow na pilha");
}

template <typename Object>
bool StackAr<Object>::isEmpty () const {
	if (topo == 0) return 1;
	else return 0;
}

template <typename Object>
void StackAr<Object>::makeEmpty ()  {
	topo = 0;
}