#include <iostream>

using namespace std;

void torre_hanoi (int v, char a, char b, char c, int* pvz) {
	if (v == 1) {
		cout << "Mova disco de " << a << " para " << b << endl;
		*pvz = *pvz + 1;
	} else {
		torre_hanoi(v-1, a, c, b, pvz);
		cout << "Mova disco de " << a << " para " << b << endl;
		*pvz = *pvz + 1;
		torre_hanoi(v-1, c, b, a, pvz);
	}
}

int main () {

	int valor, vz=0, *pvz = &vz;

	cin >> valor;

	torre_hanoi(valor, 'A', 'B', 'C', pvz);
	cout << "Foram necessarios "<< vz << " movimentos." << endl;
	return 0;
} 