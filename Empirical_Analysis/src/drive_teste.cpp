#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <cstring>
#include <string>
#include "teste.h"

using namespace std;

constexpr auto MAX(268435456); 
constexpr auto MIN(16);	

void vetorRandom(long int *vetor, long int tam) {
    cout << "Preenchendo vetor..." << endl;
    for (int i = 0; i < tam; i++) {
    	vetor[i] = (rand()%80000) + 1;
    }																																																																																																																																																																																																																																																																	
    cout << "Vetor preenchido" << endl;
}

int main( int argc, char * argv[] ) {
    auto tam(MAX);
    long double M0 = 0;
    long double Media = 0;						
    long int ocorrencia = 0, s;
    int gpi = 0, gpf = 8, ordenar = 1;
    char *pch;
    ofstream out; 
    stringstream ic;
    //Verifica se algum valor foi inserido na linha de comando
    if ( argc > 1 ) {
    	for (int i = 1; i < argc-1; i++) {
    		if (strcmp (argv[i],"-t") == 0) {
    			pch=strchr(argv[i+1],'-');
    			if (pch == NULL) {
    				stringstream( argv[i+1] ) >> tam;
    				if (tam < MIN || tam > MAX) {
    					tam = MAX;
    					cout << "PADRÃO: TAMANHO IGUAL O MÁXIMO" << endl;
    				}
    			}

    		} else if (strcmp (argv[i],"-g") == 0) {
    			pch=strchr(argv[i+1],'-');
    			if (pch == NULL) {
    				stringstream( argv[i+1] ) >> gpi;
    				if (strcmp (argv[i+1],"seq") == 0) {
    					gpi = 0;
    					gpf = 3;
    					ordenar = 0;
    				} else if (gpi < 0 || gpi > 7) {
    					gpi = 0;
    					cout << "PADRÃO: TODOS OS ALGORITMOS" << endl;

    				} else {
    					gpf = gpi + 1;
    				}
    			}
    		} else if (strcmp (argv[i],"-o") == 0){
    			pch=strchr(argv[i+1],'-');
    			if (pch == NULL) {
    				stringstream( argv[i+1] ) >> ocorrencia;
    				if (ocorrencia < 0) {
    					ocorrencia = 0;    	
    					cout << "PADRÃO: PRIMEIRA OCORRENCIA" << endl;
    				}
    			}
    		}
    	}
    }
    // Cria um vetor com o tamanho máximo
    long int *vetor;
    vetor = new long int [tam];
    //Preenche com valores pseudo-ramdomicos
    vetorRandom(vetor, tam);
    //Ordena de modo crescente
    if (ordenar) {
	    cout << "Ordenando vetor..." << endl;
	    qsort(vetor, tam, sizeof(vetor), comp);
	    cout << "Vetor ordenado" << endl;
	}
    //Vetor de ponteiro para função
	long int (*fun[8])(long int, long int*, long int, long int, int) = {
		b_Sequencial_I,
		b_Sequencial_R,
		b_Sequencial_P,
		b_Binaria_P,
		b_Binaria_I,
		b_Binaria_R,
		b_Ternaria_I,
		b_Ternaria_R};

	cout << "Digite o numero que deseja procurar dentro do vetor: " << endl;	
	cin >> s;		
	cout <<"Testando algoritmos..." << endl;
	//For para todas as funções
	//out<<"ALGORITMO | TAMANHO | MÉDIA |"<<"\n";	
	for (int f = gpi; f < gpf; f++) {
		ic << f;

		string endereco;
		endereco = "data/dados" + ic.str() + ".dat";
		out.open(endereco);
		//For do 2⁴ até o 2^n que seja <= tam
		if (f == 1) {
			for (long int i = MIN; i <= 65536; i *= 2) {
				//For para 100 testes
				for (int l = 1; l <= 100; l++) {
					//Começa a medição de tempo
					auto start = std::chrono::steady_clock::now();
					fun[f](s, vetor, 0, i-1, ocorrencia);
					//Termina a medição de tempo
					auto end = std::chrono::steady_clock::now();
					auto diff = end - start;
					auto tempo = std::chrono::duration<long double, std::milli> (diff).count();
					// Calcula a media progressiva
					Media = M0 + ((tempo - M0) / l);
					M0 = Media;
				}
				//Plota a media no arquivo .dat com todas as informações
				out<<f<<"    "<<i<<"    "<<Media<<"\n";
				Media = 0;
				M0 = 0;
			}
		} else {
			for (long int i = MIN; i <= tam; i *= 2) {
				//For para 100 testes
				for (int l = 1; l <= 100; l++) {
					//Começa a medição de tempo
					auto start = std::chrono::steady_clock::now();
					fun[f](s, vetor, 0, i-1, ocorrencia);
					//Termina a medição de tempo
					auto end = std::chrono::steady_clock::now();
					auto diff = end - start;
					auto tempo = std::chrono::duration<long double, std::milli> (diff).count();
					// Calcula a media progressiva
					Media = M0 + ((tempo - M0) / l);
					M0 = Media;
				}
				//Plota a media no arquivo .dat com todas as informações
				out<<f<<"    "<<i<<"    "<<Media<<"\n";
				Media = 0;
				M0 = 0;
			}
		}
		out.close();
		ic << "";
	}
	cout << "Fim dos testes" << endl;
	delete [] vetor;
}