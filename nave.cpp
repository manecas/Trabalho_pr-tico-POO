#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

#include "sala.h"
#include "unidades.h"
#include "nave.h"

Nave::Nave()
{
	for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 5; c++) {
			salas[l][c] = nullptr;
		}
	}

	//salas por defeito
	salas[0][0] = new Propulsor;
	salas[1][1] = new Sala(SALA_MAQUINAS);
	salas[1][2] = new Sala(SUPORTE_VIDA);
	salas[1][3] = new Sala(CONTROLO_ESCUDO);
	salas[1][4] = new Sala(PONTE);
	salas[2][0] = new Propulsor;
}

Nave::~Nave()
{
	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {

		if (salas[l][c] == nullptr) continue;
		//std::cout << salas[l][c]->getAsString();

		delete salas[l][c];
	} }
	/*delete salas[0][0];
	delete salas[0][1];
	delete salas[0][2];
	delete salas[0][3];

	delete salas[1][1];
	delete salas[1][2];
	delete salas[1][3];
	delete salas[1][4];

	delete salas[2][0];
	delete salas[2][1];
	delete salas[2][2];
	delete salas[2][3];*/
	//std::cout << "DestrutorNave" << std::endl;
}

void Nave::config(string n, int dificuldade)
{
	distPercorrer = 100;//4000 + 1000 * dificuldade;
	nome = n;
}

void Nave::updateDistPercorrer() {
	int total = 0;

	for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 5; c++) {
			//
			if (salas[l][c] == nullptr) continue;
			//
			if (salas[l][c]->getTipo() == "Propulsor")
				total += salas[l][c]->getIntegridade();
			//
		}
	}

	distPercorrer -= total;
}

void Nave::getAllTripulacao(vector<Unidades*>& u) const
{
	vector<Unidades*> u1;
	unsigned int x = 0;

	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		if (salas[l][c] == nullptr) continue;

		salas[l][c]->getTripulacao(u1);

		for (x = 0; x < u1.size(); x++)
			u.push_back(u1[x]);

	} }
}

void Nave::getAllInimigos(vector<Unidades*>& u) const
{
	vector<Unidades*> u1;
	unsigned int x = 0;

	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		if (salas[l][c] == nullptr) continue;

		salas[l][c]->getInimigos(u1);

		for (x = 0; x < u1.size(); x++)
			u.push_back(u1[x]);

	} }
}

void Nave::getAllUnidades(vector<Unidades*>& u) const {

	vector<Unidades*> u1;
	unsigned int x = 0;

	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		if (salas[l][c] == nullptr) continue;

		salas[l][c]->getTripulacao(u1);

		for (x = 0; x < u1.size(); x++)
			u.push_back(u1[x]);

		salas[l][c]->getInimigos(u1);

		for (x = 0; x < u1.size(); x++)
			u.push_back(u1[x]);

	} }
}

Sala * Nave::getSala(int x, int y) const {

	if(x >= 0 && x < 3 && y >= 0 && y < 5)
		return salas[x][y];

	return nullptr;
}

Sala * Nave::getSalaByTipo(string tipo) const {

	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		//
		if (salas[l][c] == nullptr) continue;
		//
		if (salas[l][c]->getTipo() == tipo)
			return salas[l][c];
		//
	} }
	return nullptr;
}

Sala * Nave::getSalaAdjacente(Sala* sala, char d) const {
	int l, c;
	for (l = 0 ; l < 3; l++) {
		for (c = 0 ; c < 5; c++) {
			//
			if (salas[l][c] == sala) break;
		}
		if (salas[l][c] == sala) break;
	}

	switch (d) {
	case 'n':
		return salas[l - 1][c];
	case 's':
		return salas[l + 1][c];
	case 'e':
		return salas[l][c + 1];
	case 'o':
		return salas[l][c - 1];
	}

	return nullptr;
}

int Nave::getDistPercorrer() const {
	return distPercorrer;
}

bool Nave::isNaveDestruida() const {

	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		//
		if (salas[l][c] == nullptr) continue;
		if (salas[l][c]->getIntegridade() <= 0)
			return true;
	} }
	return false;
}
