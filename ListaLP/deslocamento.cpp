#include <iostream>

using namespace std;

void ShiftN (int n1, int n2, int n3, int n4, int d) {
	int v1, v2, v3, v4;

	switch ((1+d) % 4) {
		case 1:
			v1 = n1;
			break;
		case 2:
			v2 = n1;
			break;
		case 3:
			v3 = n1;
			break;
		case 0:
			v4 = n1;
			break;	
	}

	switch ((2+d) % 4) {
		case 1:
			v1 = n2;
			break;
		case 2:
			v2 = n2;
			break;
		case 3:
			v3 = n2;
			break;
		case 0:
			v4 = n2;
			break;	
	}

	switch ((3+d) % 4) {
		case 1:
			v1 = n3;
			break;
		case 2:
			v2 = n3;
			break;
		case 3:
			v3 = n3;;
			break;
		case 0:
			v4 = n3;
			break;	
	}

	switch ((4+d)% 4) {
		case 1:
			v1 = n4;
			break;
		case 2:
			v2 = n4;
			break;
		case 3:
			v3 = n4;
			break;
		case 0:
			v4 = n4;
			break;	
	}
	cout << "(" << v1 << ","<< v2 << "," << v3 << "," << v4 << ")";
}

int main () {

	int n1, n2, n3, n4, d;
	cin >> n1;
	cin >> n2;
	cin >> n3;
	cin >> n4;
	cin >> d;

	ShiftN(n1, n2, n3, n4, d);
	return 0;
}