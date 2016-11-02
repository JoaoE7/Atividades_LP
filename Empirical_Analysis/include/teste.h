using namespace std;

long int b_Sequencial_I (long int chave, long int* vetor, long int ini, long int tam, int ocor);
long int b_Sequencial_R (long int chave, long int* vetor, long int ini, long int tam, int ocor);
long int b_Sequencial_P (long int chave, long int* vetor, long int ini, long int tam, int ocor);
long int b_Binaria_P (long int chave, long int* vetor, long int ini, long int tam, int ocor);
long int b_Binaria_I (long int chave, long int* vetor, long int ini, long int tam, int ocor);
long int b_Binaria_R (long int chave, long int* vetor, long int ini, long int tam, int ocor);
long int b_Ternaria_I (long int chave, long int* vetor, long int ini, long int tam, int ocor);
long int b_Ternaria_R (long int chave, long int* vetor, long int ini, long int tam, int ocor);
int comp(const void *ap, const void *bp);

#include "teste.inl"