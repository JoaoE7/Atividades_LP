#include "AbsQueue.h"
#include <exception>

template <typename Object>
class QueueAr : public AbsQueue<Object> {
	private:
		int tamanho_max, frente, final;
		Object *vetor;
		void resize();
	public:
		QueueAr(int tam = 10);
		~QueueAr();
		void enqueue (const Object & x);
		Object dequeue();
		Object getFront() const;
		bool isEmpty() const;
		void makeEmpty();
};

template <typename Object>
QueueAr<Object>::QueueAr(int tam) {
	tamanho_max = tam;
	final = 0;
	frente = -1;
	vetor = new Object [tamanho_max];
}

template <typename Object>
QueueAr<Object>::~QueueAr() {
	delete [] vetor;
}

template <typename Object>
void QueueAr<Object>::resize() {
	Object *novo_vetor;
	novo_vetor = new Object [2*tamanho_max];
	int j=0;
	for (int i = frente; i < tamanho_max; i++, j++) {
		novo_vetor[j] = vetor[i];
	}
	for (int k = 0; k < final; k++, j++) {
			novo_vetor[j] = vetor[k];
	}
	tamanho_max *= 2;
	delete [] vetor;
	vetor = novo_vetor;
	frente = 0;
	final = j;
}

template <typename Object>
void QueueAr<Object>::enqueue (const Object & x) {
	if (frente == final) {
		resize();
	}
	vetor[final] = x;
	if (frente == -1) {
		frente++;
		final++;
	} else if (final+1 == tamanho_max) {
		final = 0;
	} else {
		final++;
	}
}

template <typename Object>
Object QueueAr<Object>::dequeue() {
	if (frente == -1) {
		throw out_of_range("Underflow na fila");
	}
	Object f = vetor[frente];
	if (frente+1 == tamanho_max) {
		frente = 0;
	} else {
		frente++;
	}

	if (frente == final) {
		frente = -1;
		final = 0;
	} 
	return f;
}

template <typename Object>
Object QueueAr<Object>::getFront() const {
	if (frente == -1) {
		throw out_of_range("Underflow na fila");
	}
	return vetor[frente];
}

template <typename Object>
bool QueueAr<Object>::isEmpty() const {
	if (frente == -1) {
		return true;
	}
	return false;
}

template <typename Object>
void QueueAr<Object>::makeEmpty() {
	final = 0;
	frente = -1;			
}	