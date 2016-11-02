#include <iostream>

using namespace std;

int main() {
	int fib1 = 0, fib2 = 1, temp, x;
	cin >> x;
	while (fib2 < x) {
		cout << fib2 << " ";
		temp = fib1 + fib2;
		fib1 = fib2;
		fib2 = temp;
	}

	return 0;
}