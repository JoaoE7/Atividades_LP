#include <iostream>

using namespace std;

int main () {

	int x1, y1, x2, y2, p1, p2, cond = 1;

	while (cond) {
		cout << "Digite dois numeros para as coordenadas x e y de IE" << endl;
		cin >> x1;
		cin >> y1;
		cout << "Digite dois numeros para as coordenadas x e y de SD (Maiores que as de IE)" << endl;
		cin >> x2;
		cin >> y2;

		if (x1 < x2 && y1 < y2) {
			cond = 0;
		} else {
			cout << "coordenadas de IE nao sao menores do que as de SD, tente novamente" << endl << endl;
		}
	}
	cout << "Digite dois numeros para as coordenadas x e y do ponto P" << endl;
	cin >> p1;
	cin >> p2;

	if ( (p1 > x1 && p1 < x2) && (p2 > y1 && p2 < y2)) {
		cout << "O ponto P está dentro" << endl;
	} else if (((p1 == x1 || p1 == x2) && p2 > y1 && p2 < y2)  ||  ((p2 == y1 || p2 == y2) && p1 > x1 && p1 < x2)) {
		cout << "O ponto P está na borda" << endl;
	} else {
		cout << "O ponto P está fora" << endl;
	}


	return 0;
}