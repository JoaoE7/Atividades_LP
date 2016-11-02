#include <iostream>

using namespace std;

int main() {

	int A[5], B[5], a = 0, b = 0, x;

	for (int i = 0; i < 20; i++) {
		cin >> x;
		if (x % 2 == 0) {
			A[a] = x;
			a++;
		} else {
			B[b] = x;
			b++;
		}

		if (a > 4) {
			for (int j = 0; j < 5; j++) {
				cout << A[j] << " ";
			}
			a = 0;
			cout << endl;
		}
		if (b > 4) {
			for (int j = 0; j < 5; j++) {
				cout << B[j] << " ";
			}
			b = 0;
			cout << endl;
		}
	}

	for (int j = 0; j < 5; j++) {
		cout << A[j] << " ";
	}
	cout << endl;
	for (int j = 0; j < 5; j++) {
		cout << B[j] << " ";
	}

	return 0;
}