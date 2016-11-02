#include <iostream>

using namespace std;

int main() {

	int x, menor, pos = 0;
	int Vet[20];

	cin >> x;
	Vet[0] = x;
	menor = x;

	//Adiciona os valores ao vetor
	for (int i = 1; i < 20; i++) {
		cin >> x;
		Vet[i] = x;
		if (menor > x) {
			menor = x;
			pos = i;
		}
	}

	// Mostra todos os valores
	for (int i = 0; i < 20; i++) {
		cout << Vet[i] << " ";	
	}

	cout << endl;
	cout << "O menor elemento é " << menor << " e esta na posiçao " << pos;

	return 0;
}