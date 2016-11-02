#include <iostream>

using namespace std;

int main() {
	int n, m, soma = 0;
	cout << "Entre com valores inteiros (Ctrl+d p/ encerrar): " << endl;
	while (m != n) {
		cin >> n;
		cin >> m;
		for (int i = 0; i < n; i++) {
			soma = soma + m + i;
		}
		cout << "A soma e: " << soma;
		soma = 0;
	}
	return 0; 
}
