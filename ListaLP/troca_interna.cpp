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

	for (int i = 0; i < 10; i++) {
		temp = A[19-i];
		A[19-i] = A[i];
		A[i] = temp;
	}

	for (int i = 0; i < 20; i++) {
		cout << A[i] << " ";	
	}
	return 0;
}