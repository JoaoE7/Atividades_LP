#include <iostream>

using namespace std;

int main() {

	int C[20], x, j, cond;

	for (int i = 0; i < 20; i++) {
		cin >> x;
		C[i] = x;
	}

	for (int i = 0; i < 20; i++) {
		cout << C[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < 20; i++) {
		if (C[i] <= 0) {
			for (int j = i; j < 20; j++) {
				C[j] = C[j+1];
			}
			C[19] = 0;
		}	
	}

	for (int i = 0; i < 20; i++) {
		if (C[i] != 0) {
			cout << C[i] << " ";
		}
	}

	return 0;
}