
/** @file class.cpp
 *		   @brief Arquivo com implementação dos métodos
 *         Contem toda a implementação
 */
 
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "class.h"

using namespace std;

float convertToFloat(string arg){
	istringstream iss(arg);
	float arg_r = 0;
	iss >> arg_r;
	return arg_r;
}

STCard::STCard(vector<string> attributes){
	    	att = attributes;
}

STCard::STCard(){
	att.push_back("");
	att.push_back("");
	att.push_back("");
	att.push_back("");
	att.push_back("");
	att.push_back("");
	att.push_back("");
	att.push_back("");
}

string STCard::getAttribute(int at){
	    	return att[at];
}

void STCard::displayCard(){
	    	cout << " > [" << att[ID] << "]" << "[" << att[NAME] << "]" << "[" << att[MAKER] << "]" << "[" << att[YEAR_MODEL] << "]"
	    	<< "[" << att[VEL] << "]" << "[" << att[VOO] << "]" << "[" << att[LENGHT] << "]" << "[" << att[SPREAD] << "] -- "<< endl;
}

STPlayer::STPlayer (string name) {
	name_player = name;
}

string STPlayer::name() {
	return name_player;
}

STCard STPlayer::popCard () {
	int ult = Cards.size() - 1;
	STCard aux = Cards[ult];
	Cards.resize(ult);
	return aux;
}

int STPlayer::chooseRandomAttrib () {
	srand(time(0)*rand());
	int num = 4 + rand() % 4;
	return num;
}

void STPlayer::addCard(STCard Card) {
	Cards.push_back(Card);
}

void STPlayer::displayCards() {
	int tam = Cards.size();
	for (int i = 0; i < tam; i++) {
		Cards[i].displayCard();	
	}
}

int STPlayer::nCards() {
	int tam = Cards.size();
	return tam;	
}

int STGame::readDeckFromFile(string file){
	ifstream infile(file);
	int nCard = 0; 
	vector<string> _att;
	string att;
	while(getline( infile, att )){
		if(nCard <= 8)
		_att.push_back(att);
		nCard++;
		if(nCard == 9){
			STCard aux(_att) ;
			Deck.push_back( aux );
			_att.resize(0);
			nCard = 0;
		}
	}
	STCard aux(_att) ;
	Deck.push_back( aux );
	return 1;
}

void STGame::addPlayer(STPlayer &player) {
	Players.push_back(player);
}

void STGame::displayDeck(){
	int tam = Deck.size();
	for (int i = 0; i < tam; i++) {
		Deck[i].displayCard();	
	}
}

void STGame::displayPlayers(){
	int tam = Players.size();
	for (int i = 0; i < tam; i++) {
		cout <<  "PLAYER < " << Players[i].name() << " >" << endl;
		Players[i].displayCards();
		cout << endl;
	}
}

int STGame::displayStatusRound( STPlayer &Player_round) {
	int status_selected = Player_round.chooseRandomAttrib();
	string out;
	switch(status_selected){
		case 4:
			out = "SPEED";
			break;
		case 5:
			out = "VOO";
			break;
		case 6:
			out = "LENGHT";
			break;
		case 7:
			out = "SPREAD";
			break;
	}
	cout << "THE STATUS CHOOSEN IS " << out << endl;
	return status_selected;
}

void STGame::displayCardsOnTable() {
	int tam = Table.size();
	for (int i = 0; i < tam; i++) {
		Table[i].displayCard();	
	}
}

int STGame::sizeDeck(){
	  		return Deck.size();
}

void STGame::printfCard(int id){
	  		Deck[id].displayCard();
}

void STGame::delCard(int pos) {
	Deck.erase(Deck.begin()+pos);
}
STCard STGame::elemDeck (int n) {
	return Deck[n];
}
int STGame::dealCards(int k) {
	int tam = Players.size();
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < k ; j++) {
			srand(time(0)*rand());
			int num =  0 + (rand() % sizeDeck());
			Players[i].addCard(elemDeck(num));	
			delCard(num);																																																																																																																																																																																																																																																																																																																																																																																																																
		}
	}
	return 1;
}

STPlayer STGame::winner () {
	return Players[0];
}

int STGame::run(){
	int nRound = 1, x1_cards_count = 0;
	int currentPlayer = 0, players_in_game = Players.size();
	int att_choosen = 0, player_turn_winner = 0;
	float att_of_the_winner = 0;
	while(true){
		// ROUND CONTROLLER
		cout << "------------------------------------------------------" << endl;
		cout << "--------------------- " << nRound << " ROUND ------------------------" << endl;
		cout << "TIME TO " << Players[currentPlayer].name() << " CHOOSEN A ATTRIBUTE"<< endl;
		displayPlayers();
		att_choosen = displayStatusRound(Players[currentPlayer]);
		
		// PLAYERS POP CARD AND PUTTING IT ON TABLE
		for(int i = 0; i < players_in_game; i++){
			Table.push_back(Players[i].popCard());
		}

		cout << endl << "--------------------- CURRENT CARDS IN TABLE ------------------------" << endl;
		displayCardsOnTable();

		// RULES OF THE GAME
		// CHECK HEAD CARD RULES
		player_turn_winner = -1;
		for(unsigned int i = 0; i < Table.size(); i++){
			if(Table[i].getAttribute(0) == "ST") // ST PLAYER, BUT CONTINUE SEARCHING FOR X1 CARDS
				player_turn_winner = i;


			if(Table[i].getAttribute(0).at(1) == '1'){ // CARD X1 SELECTED
				if(player_turn_winner == -1)
					player_turn_winner = i;
				x1_cards_count++;
			}
		}

		if(player_turn_winner == -1 || x1_cards_count > 1) { // IF NOT HAVE PLAYER WINNER, USE POINTS RULES
			if(player_turn_winner == -1)
				player_turn_winner = 0;    // SETTING THE FIRST PLAYER IS WINNER
				att_of_the_winner = convertToFloat(Table[player_turn_winner].getAttribute(att_choosen)); // THE CARD WINNER POINTS
			for(unsigned int i = 1; i < Table.size(); i++){

				if(att_of_the_winner < convertToFloat(Table[i].getAttribute(att_choosen))){
					if(x1_cards_count > 1 && Table[i].getAttribute(0).at(1) == '1'){
						att_of_the_winner = convertToFloat(Table[i].getAttribute(att_choosen));
						player_turn_winner = i;
					} else if(x1_cards_count == 0) {
						att_of_the_winner = convertToFloat(Table[i].getAttribute(att_choosen));
						player_turn_winner = i;
					}
				}

			}		
		}
		// ADD CARD FOR THE WINNER
		for(unsigned int i = 0; i < Table.size(); i++){
			Players[player_turn_winner].addCard(Table[i]);
		}


		cout << endl << "--------------------- PLAYERS CARDS AFTER THE TURN ENDS ------------------------" << endl;
		displayPlayers();

		// CHECK HOW MANY PLAYERS ARE CONTINUES PLAYING THE GAME
		players_in_game = 0;
		int i=0;
		int tamv = Players.size();
		while (i < tamv ){
			if(Players[i].nCards() <= 0) {
				Players.erase(Players.begin()+i);
				tamv = Players.size();
				i = -1;
			}
			i++;
		}

		players_in_game = Players.size();

		// VERIFY WHATS THE NEXT PLAYER
		if(currentPlayer + 1 <= players_in_game-1)
			currentPlayer++;
		else
			currentPlayer = 0;

		if(players_in_game == 1)
			break; // FINISH GAME

		Table.resize(0);
		x1_cards_count = 0;

		nRound++;
	}
	return nRound;
}