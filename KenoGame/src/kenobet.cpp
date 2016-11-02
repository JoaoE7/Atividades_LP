/** @file kenobet.cpp
 *		   @brief Arquivo com as funções da classe KenoBet
 *         Implementação de todas as funções    
 */
#include "kenobet.h"
#include <vector>
#include <algorithm>

using namespace std;

//Construtor do KenoBet e define o numero maximo de apostas
KenoBet::KenoBet(unsigned int x) {
	return;
}
//Retorna tamanho do vetor m_spots
size_t
KenoBet::numChosen(void) const {
	size_t z = m_spots.size();
	return z;
}

// Adiciona um numero nas apostas se ele já não estiver
//Retorna true se for adicionado, se não false
bool
KenoBet::addNumber(int _spot) {
	int cond = 0;
	if (_spot > 0 && _spot < 81 && numChosen() < 15) {
		for (unsigned int i = 0; i < numChosen(); i++) {
			if (_spot == m_spots[i]) {
				cond = 1;
			}
		}
		if (cond == 0) {
			m_spots.push_back(_spot);
			return 1;
		}
	}

	return 0;
}

//Adiciona a quanidade de diheiro que o usuario começa
//Retorna true se _spot > 0, se não false
bool
KenoBet::setWage(float _wage) {
	if (_wage >= 0) {
		m_wage = _wage;
		return 1;
	}
	return 0;
}

//Reseta as apostas, deixando o vector como empty
void
KenoBet::reset(void) {
	m_spots.resize(0);
}

//Retorna a quantidade de dinheiro
float
KenoBet::getWage(void) const {
	return m_wage;
}

//Retorna um vector com os valores dos acertos
vector <int>
KenoBet::getHits(vector<int> & _hits) const {
	vector<int> hits;
	for (unsigned int j = 0; j < numChosen(); j++) {
		for (unsigned int i = 0; i < _hits.size(); i++) {
			if (_hits[i] == m_spots[j]) {
				hits.push_back(m_spots[j]);
			}
		}
	}
	return hits;
}

//Remover numero nas apostas
//Retorna true se for removido, se não false
bool
KenoBet::removeNumber(int _dspot) {
	if (numChosen() > 0) {
		for (unsigned int i = 0; i < numChosen(); i++) {
			if (m_spots[i] == _dspot) {
				m_spots[i] = m_spots[numChosen() - 1];
				m_spots.resize(numChosen()-1);
			}
		}
		sort(m_spots.begin(), m_spots.end());
		return 1;
	}
	return 0;
}

//Retorna um vector das apostas
vector <int>
KenoBet::getSpots(void) const {
	return m_spots;
}

