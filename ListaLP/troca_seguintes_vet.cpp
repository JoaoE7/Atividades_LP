#include <iostream>

using namespace std;

int main() {

	int x, temp;
	int A[20];

	//Adiciona os valores ao vetor
	for (int i = 0; i < 20; i++) {
		cin >> x;
		A[i] = x;
	}

	// Mostra todos os valores
	for (int i = 0; i < 20; i++) {
		cout << A[i] << " ";	
	}

	cout << endl;

	for (int i = 1; i < 20; i+=2) {
		temp = A[i+1];
		A[i+1] = A[i];
		A[i] = temp;
	}

	for (int i = 0; i < 20; i++) {
		cout << A[i] << " ";	
	}
	return 0;
}