#include <iostream>
using namespace std;

int main () {
	int n1 = 0, valor;
	for (int i = 0; i < 5; i++) {
		cin >> valor;
		if (valor < 0) {
			n1++;
		}
	}
	cout << "Tem " << n1 << " numeros negativos na sequencia"<< endl;
}
