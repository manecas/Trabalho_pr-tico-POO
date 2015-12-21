#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

#include "nave.h"

Nave::Nave(string n, int dificuldade) : nome(n)
{
	distPercorrer = 4000 + 1000 * dificuldade;

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

void Nave::getUnidades(int x, int y, vector<Unidades*>& u) const {

	salas[x][y]->getUnidades(u);
}

void Nave::getAllUnidades(vector<Unidades*>& u, bool d = false) const {

	vector<Unidades*> u1;
	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		//
		if (salas[l][c] == nullptr)
			continue;
		//
		salas[l][c]->getUnidades(u1);
		if (!u1.size())
			continue;
		//
		for (int x = 0; x != u1.size(); x++)
			if (!d) {
				u.push_back(u1[x]);
			}
			else{
				if(u1[x]->isTripulacao())
					u.push_back(u1[x]);
			}
		//
	} }
}

int Nave::getTotalUnidades() const {

	int total = 0;
	vector<Unidades*> u;

	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		//
		if (salas[l][c] == nullptr) continue;
		//
		salas[l][c]->getUnidades(u);
		total += u.size();
	} }

	/*Sala *s;
	s = **salas;

	for (; s < **salas + sizeof(**salas); s++) {
		s->getUnidades(u);
		total += u.size();
	}*/
	return total;
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
