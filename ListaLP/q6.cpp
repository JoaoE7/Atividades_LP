#include <iostream>

using namespace std;

int maiores (int* vet, int n, int x) {
	int qtd = 0;
	for (int i = 0; i < n; i++) {
		if (vet[i] > x) {
			qtd++;
		}
	}

	return qtd;
}

int main () {

	int n, x, v, qtd;
	cout << "Tamanho do vetor: " << endl;
	cin >> n ;
	int V[n];
	cout << "Digite os elementos do vetor: " << endl;
	for (int j = 0; j < n; j++) {
		cin >> 	v ;
		V[j] = v;
	}

	cout << "Digite um numero: " << endl;
	cin >> x;
	qtd = maiores(V, n, x);
	cout << "Existem " << qtd << " numeros maiores que " << x <<" no vetor" << endl; 



	return 0;
}