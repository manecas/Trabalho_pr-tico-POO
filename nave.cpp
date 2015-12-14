#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

#include "nave.h"

Nave::Nave(string n):nome(n)
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

int Nave::getTotalUnidades() const {

	int total = 0;
	vector<Unidades*> u;

	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		if (salas[l][c] == nullptr) continue; //temporario
		salas[l][c]->getUnidades(u);
		total += u.size(); //se for 0 simplesmente adiciona zero
	} }

	/*Sala *s;
	s = **salas;

	for (; s < **salas + sizeof(**salas); s++) {
		s->getUnidades(u);
		total += u.size();
	}*/
	return total;
}

Sala * Nave::getSalaByTipo(string tipo) const {

	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		if (salas[l][c] == nullptr) continue;//temporario
		if (salas[l][c]->getTipo() == tipo)
			return salas[l][c];
	} }
	return nullptr;
}

int Nave::distPercorrer() const {

	int total = 0;

	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		if (salas[l][c] == nullptr) continue;//temporario
		if (salas[l][c]->getTipo() == "Propulsor")
			total += salas[l][c]->getIntegridade();
	} }

	return total;
}