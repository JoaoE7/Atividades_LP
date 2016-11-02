#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int x1, x2, y1, y2;
	float n;

	cout << "Digite as duas coordenadas: " << endl;
	cin >> x1;
	cin >> y1;
	cout << endl;
	cout << "Digite as duas coordenadas: " << endl;
	cin >> x2;
	cin >> y2;
	cout << endl;
	n = ((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1));
	
	cout << "A distancia e de: " << sqrt(n) << endl;
	return 0;
}

