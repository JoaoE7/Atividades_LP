#include <iostream>
using namespace std;

int main () {
	int x, int1=0, int2=0, int3=0, int4=0;
	cout << "Entre com valores inteiros (Ctrl+d p/ encerrar): " << endl;
	while (cin >> x) {
		if (x>= 0 && x < 25) {
			int1++;
		} else if (x>= 25 && x < 50) {
			int2++;
		} else if (x>= 50 && x < 75) {
			int3++;
		} else if (x>= 75 && x <= 100) {
			int4++;
		}
	}
	cout << "Intervalo 1: " << int1 << endl;
	cout << "Intervalo 2: " << int2 << endl;
	cout << "Intervalo 3: " << int3 << endl;
	cout << "Intervalo 4: " << int4 << endl;
}
