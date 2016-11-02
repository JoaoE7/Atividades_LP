
/** @file class.h
 *		   @brief Arquivo principal do jogo
 *         Contem toda a estrutura do jogo
 */
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include "class.h"

using namespace std;

int main(int argc, char *argv[]){
	int n_players, n_cartas, erro = 0;
	string file, name_p;

	//processa argumentos da linha de comando
	if ( argc == 4 ) {
    	
    	stringstream( argv[1] ) >> file;
    	stringstream( argv[2] ) >> n_players;
    	if (n_players > 10 || n_players < 1) {
    		cerr << "Erro na atribuição dos valores" << endl;
    		erro++;
    	}
    	stringstream( argv[3] ) >> n_cartas;
    	if (n_cartas > (40/n_players) && n_cartas < 0) {
    		cerr << "Erro na atribuição dos valores" << endl;
    		erro++;
    	}

    } else {
    	cerr << "Erro na atribuição dos valores" << endl;
    	erro++;
    }

	if (erro == 0) {
		STGame myGame;
		if (! myGame.readDeckFromFile( file )) {
			cerr << "Ocorreu um erro na leitura de arquivo" << endl;
			return 0;
		} else {
			myGame.displayDeck();

			for (int i = 1; i <= n_players; i++) {
				cout << "Digite o nome do jogador: " << endl;
				cin >> name_p;
				STPlayer P(name_p);
				myGame.addPlayer(P);
			}
			
			if (! myGame.dealCards(n_cartas)) {
				cerr << "Ocorreu um erro na distribuição de cartas" << endl;
				return 0;
			}

			auto nRounds = myGame.run();
			STPlayer winner = myGame.winner();

			cout << "\n\n>>>> O vencedor depois de " << nRounds << " rodadas foi o jogador: " << winner.name() << endl; 
		}

	} else {
		cout << "ERRO" << endl;
	}
	return 0;
}

