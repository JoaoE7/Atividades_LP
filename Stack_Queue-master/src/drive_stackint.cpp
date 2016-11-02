#include <iostream>
#include <exception>
#include "stackint.h"
#include "stackar.h"
#include "queuear.h"

using namespace std;

int main () {
	QueueAr<char> fila(7);
	StackAr<int> pilha(5);
	try {
		fila.enqueue('a');
		fila.enqueue('f');
		fila.enqueue('d');
		fila.enqueue('j');
		fila.enqueue('a');
		fila.enqueue('f');
		fila.enqueue('f');
		fila.enqueue('d');
		fila.enqueue('j');
		fila.enqueue('a');
		

		cout << "Saiu da fila: " << fila.dequeue() << endl;
		cout << "Saiu da fila: " << fila.dequeue() << endl;
		cout << "Saiu da fila: " << fila.dequeue() << endl;
		cout << "Saiu da fila: " << fila.dequeue() << endl;
		cout << "Saiu da fila: " << fila.dequeue() << endl;
		cout << "Primeiro da fila: " << fila.getFront() << endl;

		pilha.push(3);
		pilha.push(3);
		pilha.push(3);
		pilha.push(3);
		pilha.push(3);
		pilha.push(3);
		pilha.push(3);
		pilha.makeEmpty();
		cout << "topo da fila: " << pilha.top() << endl;
	}

	catch (const out_of_range& e) {
		cerr << e.what() << endl;
	}
}