/** @file kenobet.h
 *		   @brief Arquivo que contém protótipos de funções
 *       
 */
#pragma once
#include <vector>
using namespace std;

class KenoBet {

public:
	//Construtor do KenoBet e define o numero maximo de apostas
	explicit KenoBet(unsigned int _maxNumSports = 15);
	// Adiciona um numero nas apostas se ele já não estiver
	//Retorna true se for adicionado, se não false
	bool addNumber(int _spot);
	//Adiciona a quanidade de diheiro que o usuario começa
	//Retorna true se _spot > 0, se não false
	bool setWage(float _wage);
	// remover numero nas apostas
	//Retorna true se for removido, se não false
	bool removeNumber(int _dspot);
	//Reseta as apostas, deixando o vector como empty
	void reset(void);
	//Retorna a quantidade de dinheiro
	float getWage(void) const;
	//Retorna tamanho do vetor m_spots
	size_t numChosen(void) const;
	//Retorna um vector com os valores dos acertos
	vector <int> getHits(vector<int> & _hits) const;
	//Retorna um vector das apostas
	vector <int> getSpots(void) const;

private:
	vector <int> m_spots; //Vetor de inteiros que recebe os numéros da aposta
	float m_wage; //Variável float que guarda o dinheiro
	unsigned int m_maxSpots; //Variável unsigned int que armazena o numeros máximo de apostas
};