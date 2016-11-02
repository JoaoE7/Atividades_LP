
/** @file class.h
 *		   @brief Arquivo com as assinaturas
 *         Contem toda a assinatura das classes
 */
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class STCard {
	public:
	  	// ENUM FOR ATTRIBUTES
	    enum attrib{ID, NAME, MAKER, YEAR_MODEL, VEL, VOO, LENGHT, SPREAD};
	    
	    // CONSTRUCTOR
	    STCard(vector <string> attributes);
	    STCard();
	    // FUNCTION TO GET ATTRIBUTES
	    string getAttribute(int at);

	    // FUNCTION TO DISPLAY CARDS FOR PLAYER
	    void displayCard();
	private:
		vector <string> att;
};

class STPlayer {
	public:
		STPlayer(string name);  //V Construtor, recebe o nome como argumento
		string name(); //V Retorna o nome do jogador
		STCard popCard (); //VRetorna a carta do topo e depois remove ela do deck
		int chooseRandomAttrib();  //VEscolhe aleatoriamente o atributo da carta
		void addCard(STCard Card); //V Adiciona uma carta no deck
		void displayCards(); //V Exibe todas as cartas do jogador
		int nCards(); //Retorna o numero de cartas
	private:
		string name_player;
		vector <STCard> Cards;
}; 

class STGame {
	public:
	  	int readDeckFromFile(string file);
	  	void addPlayer(STPlayer &player); //I 
	  	int dealCards(int k);
	  	void displayDeck(); //I
	  	void displayPlayers(); //I
	  	int run();
	  	int displayStatusRound( STPlayer &Player_round);//I
	  	void displayCardsOnTable(); //I
	  	STPlayer winner();
	  	void delCard(int pos);
	  	int sizeDeck(); //I
	  	STCard elemDeck (int n);
	  	void printfCard(int id); //I

	private:
		vector<STCard> Deck;
    	vector<STPlayer> Players;
    	vector<STCard> Table;

};

