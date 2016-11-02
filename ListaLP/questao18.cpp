#include <iostream>

using namespace std;

void inverterVetor ( int* v, int tam) {
	int temp;
	for (int i = 0, j = tam-1; i < j; i++, j--) {
		temp = *(v+i);
		*(v+i) = *(v+j);
		*(v+j) = temp;
	}
}


int main () {
	int V[5] = {1, 2, 9, 4, 5};
	int tam = 5;
	inverterVetor(V, tam);
	for (int i = 0; i < tam; i++) {
		cout << V[i] << " ";
	}
	return 0;
}