#include <iostream>

using namespace std;

int main () {

	int V[30], temp, x;

	for (int i = 0; i < 20; i++) {
		cin >> V[i];
	}

	for (int i = 1; i < 20; i++) {
		for (int j = 0; j < 20-i; j++) {
			if (V[j] > V[j+1]) {
				temp = V[j];
				V[j] = V[j+1];
				V[j+1] = temp;
			}
		}

	}

	for (int w = 1; w <= 10; w++) {
		cin >> x;
		V[19 + w] = x;
		for (int i = 1; i < 20+w; i++) {
			for (int j = 0; j < 20+w-i; j++) {
				if (V[j] > V[j+1]) {
					temp = V[j];
					V[j] = V[j+1];
					V[j+1] = temp;
				}
			}

		}	
		
	}

	for (int i = 0; i < 30; i++) {
		cout << V[i] << " ";
	}

	return 0;
}