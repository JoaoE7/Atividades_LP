/** @file KenoUI.cpp
 *		   @brief Arquivo principal do jogo
 *         Contem a interface gráfica e toda a mecânica do jogo
 */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>  
#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <sstream>
using namespace std;
#include "kenobet.h"

using std::string;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define XOFFSET 330;
#define YOFFSET 60;

// VARIÁVEIS GLOBAIS
KenoBet keno; // OBJETO KENO
float money = 0; // DINHEIRO GANHO AO FINAL DAS APOSTAS
int bet = 100; // APOSTA
int nround = 1; // NUMERO DE RODADAS

// VARIAVEIS AUXILIARES
int total_rounds;
float lost_value = 0;
int current_sorted_number_id = 0;
int round_aux = 1;
float cond = 0, num;

// TABELA DE POTUAÇÃO
float HitsTable[15][16]={ 0, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
						  0, 1, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
						  0, 1, 2, 16, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
						  0, 0.5, 2, 6, 12, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
						  0, 0.5, 1, 3, 15, 50, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
						  0, 0.5, 1, 2, 3, 30, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1,
						  0, 0.5, 0.5, 1, 6, 12, 36, 100, -1, -1, -1, -1, -1, -1, -1, -1,
						  0, 0.5, 0.5, 1, 3, 6, 19, 90, 720, -1, -1, -1, -1, -1, -1, -1,
						  0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200, -1, -1, -1, -1, -1, -1,
						  0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800, -1, -1, -1, -1, -1,
						  0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000, -1, -1, -1, -1,
	                      0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000, -1, -1, -1,
	                      0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000, -1, -1,
						  0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500, -1,
						  0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500 ,10000 };

// COR DAS VARIAVEIS NA INTERFACE
int Numbers_Sprite_render[80];
// 0 = amarelo | 1 = vermelho | 2 = verde
sf::Font font;

vector <int> vetor;

bool can_change_status = true;
bool turn_has_started = false;

sf::Sprite bg;
string line1Draw  = "";
string line2Draw  = "";
string payouts    = "";
string roundsHits = "";
string dialog     = "";

// DEFINE O VALOR DE DINHEIRO E RESETA QUALQUER APOSTA FEITA
void startDefinitions() {
	keno.setWage(10000.0);
	keno.reset();
}

// GERA RANDOMICAMENTE 20 VALORES NÃO REPETIDOS
void sortValues() {
	for (int j = 0; j < 20; ) {
		srand(time(0)*rand());
		num = 1 + rand() % 80;
		for (unsigned int k = 0; k < vetor.size(); k++) {
			if (num == vetor[k]) {
				cond = 1;
			}
		}
		if (cond == 0) {
			vetor.push_back(num);
			j = j + 1;
		}
		cond = 0;
	}
	sort(vetor.begin(), vetor.end());
}

// RESETA AS APOSTAS E AS SELEÇÕES NA INTERFACE
void clearCurrentGame() {
	for (int i = 0; i < 80; i++) {
		Numbers_Sprite_render[i] = 0;
	}
	keno.reset();
	current_sorted_number_id = 0;
	line1Draw = "";
	line2Draw = "";
}

// VERIFICA SE UM NÚMERO QUE FOI APOSTADO ESTÁ NOS NÚMEROS RANDOMICOS
void checkHits(int valueSorted) {
	for (int i = 0; i < keno.getSpots().size(); i++) {
		if (valueSorted == keno.getSpots()[i]) {
			Numbers_Sprite_render[keno.getSpots()[i]-1] = 2;
		}
	}
}


void setLineDraw(int id) {
	string aux_;
	if (vetor[id - 1] < 10)
		aux_ = "0" + std::to_string(vetor[id - 1]);
	else
		aux_ = std::to_string(vetor[id - 1]);

	if (id <= 10) 
		line1Draw += aux_ + "   ";
	else 
		line2Draw += aux_ + "   ";
	checkHits(vetor[id - 1]);
}


void drawSortedNumbers(sf::RenderWindow *wind) {
	sf::Text text;
	int font_size = 13;
	text.setFont(font);
	text.setCharacterSize(font_size);
	text.setStyle(sf::Text::Bold);
	// draw line1
	text.setColor(sf::Color::Red);
	text.setPosition(379, 396);
	text.setString(line1Draw);
	wind->draw(text);
	// draw line2
	text.setColor(sf::Color::Red);
	text.setPosition(379, 428);
	text.setString(line2Draw);
	wind->draw(text);
}

// MOSTRA UM TEXTO NA INTERFACE
void setDialog(int dialogId) {
	if (dialogId == 1) 
		dialog = "\nWelcome to Keno Pixel\nGood Luck! =)";
	if (dialogId == 2) {
		std::stringstream ss;
		ss << std::fixed << std::setprecision(2) << lost_value;
		std::string str = ss.str();
		std::stringstream ss2;
		ss2 << std::fixed << std::setprecision(2) << money;
		std::string str2 = ss2.str();
		dialog = "You spent in this game a total of $" + str + ".\nHooray, you won $" + str2 + " dollars.\nSelect your numbers and play again ;-)";
	}
}

// PEQUENA PARADA
void slepCDFrame() {
	std::this_thread::sleep_for(std::chrono::milliseconds(300));
}

// CHAMA OUTRA FUNÇÃO PARA MODIFICAR A INTERFACE
void Run_Graphic_Changes() {
	current_sorted_number_id++;
	setLineDraw(current_sorted_number_id);
}

// INICIA AS VARIÁVEIS E O JOGO
void StartGame() {
	sortValues();
	roundsHits = "";
	turn_has_started = true;
	round_aux = nround;
	total_rounds = nround;
	money = 0;
	float credit_aux;
	lost_value = bet * nround;
	credit_aux = keno.getWage() - lost_value;
	keno.setWage(credit_aux);
}

// ATUALIZA AS VARIÁVEIS DEPOIS DE UMA RODADA
void finish_round() {
	money += bet * HitsTable[keno.getSpots().size() -1][keno.getHits(vetor).size()];
	round_aux--;
	roundsHits += " " + std::to_string(total_rounds - round_aux) + "        " + std::to_string(keno.getHits(vetor).size()) + " \n";
	if (round_aux == 0) {
		float credit_aux = keno.getWage() + money;
		keno.setWage(credit_aux);
		setDialog(2);
		clearCurrentGame();
		can_change_status = true;
	}
	else {
		// começar outro
		vetor.resize(0);
		sortValues();
		line1Draw = "";
		line2Draw = "";
		current_sorted_number_id = 0;
		for (int i = 0; i < 80; i++) {
			if (Numbers_Sprite_render[i] == 2)
				Numbers_Sprite_render[i] = 1;
		}
		turn_has_started = true;
	}
}

// DETERMNNA AS CARACTERISTICAS DE CADA ELEMENTO
void drawInfos(sf::RenderWindow *wind) {
	sf::Text text;
	int font_size = 20;

	// CREDIT
	std::stringstream ss;
	ss << std::fixed << std::setprecision(1) << keno.getWage();
	std::string str = ss.str();
	text.setCharacterSize(font_size);
	text.setString("$" + str);
	text.setPosition(620, 485);
	text.setColor(sf::Color::Black);
	text.setFont(font);
	text.setStyle(sf::Text::Bold);
	wind->draw(text);

	// MONEY
	std::stringstream ss2;
	ss2 << std::fixed << std::setprecision(1) << money;
	std::string str2 = ss2.str();
	text.setString("$" + str2);
	text.setPosition(620, 545);
	wind->draw(text);

	// ROUND
	string aux_round;
	if (nround < 10)
		aux_round = "0" + std::to_string(nround);
	else
		aux_round = std::to_string(nround);
	text.setString(aux_round);
	text.setPosition(368, 485);
	text.setColor(sf::Color::White);
	wind->draw(text);

	// BET
	string aux_bet;
	text.setString(std::to_string(bet));
	text.setPosition(360, 548);
	text.setCharacterSize(16);
	text.setColor(sf::Color::White);
	wind->draw(text);

	// ROUND HITS
	text.setString(roundsHits);
	text.setCharacterSize(16);
	text.setPosition(190, 175);
	text.setColor(sf::Color::Yellow);
	wind->draw(text);

	// PAYOUT
	text.setString(payouts);
	text.setCharacterSize(12);
	text.setPosition(18, 175);
	text.setColor(sf::Color::Yellow);
	wind->draw(text);

	// DIALOG
	text.setString(dialog);
	text.setCharacterSize(12);
	text.setPosition(20, 490);
	text.setColor(sf::Color::Black);
	wind->draw(text);

}

// MOSTRA A TABELA DE PONTUAÇÃO DE ACORDO COM O NUMÉRO DE APOSTAS
void setPayouts() {
	payouts = "";
	for (int i = 0; i <= 15; i++) {
		if (HitsTable[keno.getSpots().size() -1][i] != -1.0f) {
			std::stringstream ss;
			ss << std::fixed << std::setprecision(1) << HitsTable[keno.getSpots().size() - 1][i];
			std::string str = ss.str();
			payouts += " " + std::to_string(i) + "   ->    "  + str + " \n";
		}
	}
}

// DETERMINA AS CARACTERISTICAS DA TABELA DOS 80 NÚMEROS
void DrawNumbersSelection(sf::RenderWindow *wind)
{
	int x_offset = XOFFSET;
	int y_offset = YOFFSET;
	int x_offset_variant = 40;
	int y_offset_variant = 40;
	int font_size = 20;
	int aux = 1;

	sf::Text text;

	for (int i = 1; i <= 80; i++) {
		text.setCharacterSize(font_size);
		text.setString(std::to_string(i));
		text.setPosition(x_offset, y_offset);

		if(Numbers_Sprite_render[i-1] == 0)
			text.setColor(sf::Color::Yellow);
		else 
			if (Numbers_Sprite_render[i - 1] == 1)
				text.setColor(sf::Color::Red);
		else
			if (Numbers_Sprite_render[i - 1] == 2)
				text.setColor(sf::Color::Green);

		text.setFont(font);
		text.setStyle(sf::Text::Bold);
		wind->draw(text);
		x_offset += x_offset_variant;
		if (aux == 10) {
			x_offset = XOFFSET;
			y_offset += y_offset_variant;
			aux = 0;
		}
		aux++;
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), ".:: Keno Game ::. Welcome!", 4);
	clearCurrentGame();
	startDefinitions();

	setDialog(1);

	// CARREGA A FONTE
	if (!font.loadFromFile("visual/arial.ttf"))
	{
		
	}
	

	// CARREGA BACKGROUND
	sf::Texture texture;
	if (texture.loadFromFile("visual/bg.png"))
	{
		bg.setTexture(texture);
	}

	
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
			switch (event.type)
			{
				case sf::Event::Closed: 
				{
					window.close();
					break;
				}
				case sf::Event::MouseButtonReleased:
				{
					if (event.mouseButton.button == sf::Mouse::Left) {
						if (can_change_status) {
							// ------------------------------------------- CHANGE NUMBERS EVENT
							if (event.mouseButton.x >= 330 && event.mouseButton.y >= 60 &&
								event.mouseButton.x <= 330 + (10 * 40) && event.mouseButton.y <= 60 + (8 * 40)) {

								sf::Vector2i mouseP;
								mouseP.x = event.mouseButton.x; mouseP.y = event.mouseButton.y;

								int aux = 1;
								int x_offset = XOFFSET;
								int y_offset = YOFFSET;
								bool finish = false;
								bool isLess = false;
								for (int i = 1; i <= 8; i++) {
									for (int j = 1; j <= 10; j++) {

										if (mouseP.x >= 330 + (j - 1 * 40) && mouseP.y >= 60 + (i - 1 * 40) &&
											mouseP.x <= 330 + (j * 40) && mouseP.y <= 60 + (i * 40)) {
											if (keno.getSpots().size() < 15) {
												
												if (!Numbers_Sprite_render[aux - 1])
													Numbers_Sprite_render[aux - 1] = 1;
												else {
													Numbers_Sprite_render[aux - 1] = 0;
													isLess = true;
												}

												if (!finish) {
													if(!isLess)
														keno.addNumber(aux);
													else
														keno.removeNumber(aux); // remover numero

													setPayouts();
													// adicionar retirada de elemento
													finish = true;
												}
												break;
											}
										}
										aux++;
									}
									if (finish) {

										//sf::sleep(sf::milliseconds(1000));
										break;
									
									}
								}
							}


							// ------------------------------------------- CHANGE ROUND EVENT
							if (event.mouseButton.x >= 330 && event.mouseButton.y >= 485 &&
								event.mouseButton.x <= 360 && event.mouseButton.y <= 510) {
								if (nround > 1)
									nround--;
							}
							else 
							if (event.mouseButton.x >= 400 && event.mouseButton.y >= 485 &&
								event.mouseButton.x <= 430 && event.mouseButton.y <= 510) {
								if (nround < 10)
									nround++;
							}


							// ------------------------------------------- CHANGE BET EVENT
							if (event.mouseButton.x >= 315 && event.mouseButton.y >= 445 &&
								event.mouseButton.x <= 350 && event.mouseButton.y <= 570) {
								if (bet > 100)
									bet -= 100;
							}
							else
							if (event.mouseButton.x >= 415 && event.mouseButton.y >= 550 &&
								event.mouseButton.x <= 445 && event.mouseButton.y <= 570) {
								if (bet+100 <= keno.getWage())
									bet+=100;
							}


							// ------------------------------------------- PLAY BUTTON
							if (event.mouseButton.x >= 450 && event.mouseButton.y >= 500 &&
								event.mouseButton.x <= 590 && event.mouseButton.y <= 540) {
								if (keno.getSpots().size() >= 1 && bet * nround <= keno.getWage()) {
									can_change_status = false;
									StartGame();
								}
							}
						}
					}
					break;
				}
			}
		}

		window.clear();

		if (turn_has_started) {
			Run_Graphic_Changes();
			slepCDFrame();
			if (current_sorted_number_id > 20) {
				turn_has_started = false;
				finish_round();
			}
		}

		window.draw(bg);
		drawSortedNumbers(&window);
		DrawNumbersSelection(&window);
		drawInfos(&window);

        window.display();
    }

    return 0;
}