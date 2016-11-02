#include <iostream>
#include <cmath>

using namespace std;

int raizes (float a, float b, float c, float * x1, float * x2) {

	float temp;

	*x1 = (-b + sqrt((b*b) - 4*a*c)) / 2*a;
	*x2 = (-b - sqrt((b*b) - 4*a*c)) / 2*a;

	if (*x1 && *x2) {
		if (*x1 > *x2) {
			temp = *x2;
			*x2 = *x1;
			*x1 = temp;
		}
		return 2;
	} else if (*x1 == *x2) {
		return 1;
	} else {
		*x1 = 0;
		*x2 = 0;
		return 0;
	}
}

int main() {
	float a, b, c, *x1, *x2, r1, r2, num;
	x1 = &r1;
	x2 = &r2;

	cin >> a;
	cin >> b;
	cin >> c;

	num = raizes(a, b, c, x1, x2);
	cout << "A equação tem " << num << " raiz(es)"; 
}