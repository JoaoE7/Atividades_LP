#include "stackint.h"
#include <exception>

using namespace std;

StackInt::StackInt (int tamanho) {
	tamanho_max = tamanho;
	topo = 0;
	vetor =  new int [tamanho];
}

StackInt::~StackInt () {
	delete [] vetor ;
}

void StackInt::push (const int & o) {
	if (topo == tamanho_max) {
		resize();
	}
		vetor[topo] = o;
		topo++;
}

void StackInt::resize () {
	int *np;
	np = new int [tamanho_max*2];
	tamanho_max *= 2;
	for (int i = 0; i < topo; i++) {
		np[i] = vetor[i];
	}
	delete [] vetor ;
	vetor = np;
}

int StackInt::pop () {
	if (topo != 0) {
		int retorno = vetor[topo-1];
		topo--;
		return retorno;
	}
	throw out_of_range("Underflow");
}

int StackInt::top () const {
	if (topo != 0) {
		return vetor[topo-1];
	}
	throw out_of_range("Underflow");
}

bool StackInt::isEmpty () const {
	if (topo == 0) return 1;
	else return 0;
}

void StackInt::makeEmpty ()  {
	topo = 0;
}