#include <iostream>
#include <cstdlib>
using namespace std;

long int b_Sequencial_I (long int chave, long int* vetor, long int ini, long int tam, int ocor) {
	int cond=0;
	for (int i = ini; i <= tam; i++) {
		if (vetor[i] == chave) {
			cond++;
			if (cond > ocor) {
				return i;
			}
		}
	}
	return -1;
}

long int b_Sequencial_R (long int chave, long int* vetor, long int ini, long int tam, int ocor) {
	if (ini > tam) {
		return -1;
	}

	if (vetor[ini] == chave) {
		if (ocor == 0) {
			return ini;
		}
		return b_Sequencial_R(chave, vetor, ini+1, tam, ocor-1);
	} else {
		return b_Sequencial_R(chave, vetor, ini+1, tam, ocor);
	} 
}

long int b_Binaria_R (long int chave, long int* vetor, long int ini, long int tam, int ocor) {
	long int meio;
	meio = (ini+tam)/2;
	if (ini > tam) {
		return -1;
	}

	if (chave == vetor[meio]) {
		if (meio == 0) {
			if (vetor[meio+ocor] == chave) {
				return meio+ocor;
			} else {
				return -1;
			}
		}
		if (vetor[meio-1] == chave) {
			return b_Binaria_R(chave, vetor, ini, meio, ocor);
		}
		if (vetor[meio+ocor] == chave) {
			return meio+ocor;
		} else {
			return -1;
		}
	} else if (chave > vetor[meio]){
		return b_Binaria_R(chave, vetor, meio+1, tam, ocor);
	} else {
		return b_Binaria_R(chave, vetor, ini, meio-1, ocor);
	}
}

long int b_Binaria_I (long int chave, long int* vetor, long int ini, long int tam, int ocor) {
	long int i=0, f=tam, meio, inicio;
	while (i <= f) {
		meio = (i+f)/2;

		if (chave == vetor[meio]) {
			for (int j = meio; j >= 0; j--) {
				if (chave == vetor[j]){
					inicio = j;
				}
			}

			if (chave == vetor[inicio+ocor]) {
				return inicio+ocor;
			} else {
				return -1;
			}
			
		} else if (chave > vetor[meio]) {
			i = meio + 1;
		} else {
			f = meio - 1;
		}
	}
	return -1;
}

long int b_Ternaria_I (long int chave, long int* vetor, long int ini, long int tam, int ocor) {
	int long p1=0, p2=0, i=0, f=tam, var, inicio;

	while (i <= f) {
		var = (f-i)/3;
		p1 = var + i;
		p2 = p1 + var; 
		if (chave == vetor[p1]) {
			for (int j = p1; j >= 0; j--) {
				if (chave == vetor[j]){
					inicio = j;
				}
			}
			if (chave == vetor[inicio+ocor]) {
				return inicio+ocor;
			} else {
				return -1;
			}
		} else if (chave == vetor[p2]) {
			for (int j = p2; j >= 0; j--) {
				if (chave == vetor[j]){
					inicio = j;
				}
			}
			if (chave == vetor[inicio+ocor]) {
				return inicio+ocor;
			} else {
				return -1;
			}
		} else if (chave < vetor[p1]) {
			f = p1 - 1;
		} else if (chave > vetor[p2]) {
			i = p2 + 1;
		} else {
			i = p1 + 1;
			f = p2 - 1; 
		}
	}

	return -1;
}

long int b_Ternaria_R (long int chave, long int* vetor, long int ini, long int tam, int ocor) {
	long int p1, p2;
	p1 = ((tam-ini)/3) + ini;
	p2 = ((tam-ini)/3) + p1;
	if (ini > tam) {
		return -1;
	}

	if (chave == vetor[p1]) {
		if (p1 == 0) {
			if (chave == vetor[p1+ocor]) {
				return p1+ocor;
			} else {
				return -1;
			}
		}
		if (chave == vetor[p1-1]) {
			return b_Ternaria_R(chave, vetor, ini, p1, ocor);
		}
		if (chave == vetor[p1+ocor]) {
			return p1+ocor;
		} else {
			return -1;
		}
	} else if (chave == vetor[p2]) {
		if (p2 == 0) {
			if (chave == vetor[p1+ocor]) {
				return p1+ocor;
			} else {
				return -1;
			}
		}
		if (chave == vetor[p2-1]) {
			return b_Ternaria_R(chave, vetor, ini, p2, ocor);
		}
		if (chave == vetor[p2+ocor]) {
			return p2+ocor;
		} else {
			return -1;
		}
	} else if (chave < vetor[p1]) {
		return b_Ternaria_R(chave, vetor, ini, p1-1, ocor);
	} else if (chave > vetor[p2]) {
		return b_Ternaria_R(chave, vetor, p2+1, tam, ocor);
	} else {
		return b_Ternaria_R(chave, vetor, p1+1, p2-1, ocor);
	}
}

long int b_Sequencial_P (long int chave, long int* vetor, long int ini, long int tam, int ocor) {
	std::vector<long int> c;
	for (int i = 0; i <= ocor; i++) {
		c.push_back(chave);
	}

	long int *it = (long int *) search(vetor, vetor+tam+1, c.begin(), c.end());

	if ( it != (vetor+tam+1) ) {
		return (it - vetor+ocor);
	} else {
		return -1;
	}

	
}	

int comp(const void *ap, const void *bp) {
    const int *a = (int *) ap;
    const int *b = (int *) bp;
    return *a - *b;
}

long int b_Binaria_P (long int chave, long int* vetor, long int ini, long int tam, int ocor) {
	long int *r = (long int*) bsearch(&chave, vetor, tam+1, sizeof(vetor[0]), comp);
	long int *aux = r;
	long int valor;
	if (r == NULL) {
		return -1;
	} else {
		while (aux != NULL) {
			valor = aux - vetor;
			aux = (long int*) bsearch(&chave, vetor, valor, sizeof(vetor[0]), comp);
		}
		if (vetor[valor+ocor] == chave) {
			return valor+ocor;
		}else {
			return -1;
		}
	}
}