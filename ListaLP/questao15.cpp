#include <iostream>
#include <cmath>

using namespace std;

void swap ( int* x, int* y) {
	int temp;
	temp = *y;
	*y = *x;
	*x = temp;
}

void ordena3 ( int* n, int* n2, int* n3, char ord) {
	if (ord == "V") {
		if (*n > *n2) {
			swap(n, n2);
		} else if (*n > *n3) {
			swap(n, n3);
		} else  if (*n2 > *n3) {
			swap(n2, n3);
		}
	} else if (ord == "F") {
		if (*n < *n2) {
			swap(n, n2);
		} else if (*n < *n3) {
			swap(n, n3);
		} else  if (*n2 < *n3) {
			swap(n2, n3);
		}
	}
}

int EhPrimo (int x) {
	int resp = 1;
	if (x > 1) {
		for (int i = 2; i < sqrt(x); i++) {
			if (x%i == 0) {
				resp = 0;
			}
		}
	}
	return resp;
} //Testado

char EhPar (int x) {
	if (x%2 == 0) {
		return "V";
	} else {
		return "F";
	}
} 

char EhAmigo (int x, int y) {
	int soma = 0, soma2 = 0;
	
	for (int i = 1; i < x; i++) {
		if (x%i == 0) {
			soma+= i;
		}
	}

	for (int i = 1; i < y; i++) {
		if (y%i == 0) {
			soma2+= i;
		}
	}

	if (soma == y || soma2 == x) {
		return 'V';
	} else {
		return 'F';
	}
} //Testado

int mdc (int x, int y, int w) {
	int temp;
	while (x%y != 0 || y > 1) {
		if (x < y) {
			temp = x;
			x = y;
			y = temp;

			temp = y;
			y = x%y;
			x = temp;
		} else {
			temp = y;
			y = x%y;
			x = temp;
		}
	}

	while (y%w != 0 || w > 1) {
		if (y < w) {
			temp = y;
			y = w;
			w = temp;

			temp = w;
			w = y%w;
			y = temp;
		} else {
			temp = w;
			w = y%w;
			y = temp;
		}
	}

	return w;
}

int mmc (int x, int y, int w) {
	int mmc;
	mmc = x*y*w/mdc(x, y, w);
	return mmc;
}

int Fatorial (int x) {
	if (x >= 0) {
		int fat = 1;

		for (int i = 1; i <= x; i++) {
			fat = i * fat;
		}

		return fat;
	} else {
		return 0;
	}
}

int main () {

	return 0;
}