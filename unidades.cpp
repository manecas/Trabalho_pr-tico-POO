#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::ostringstream;
using std::endl;
using std::vector;

#include "caract.h"
#include "unidades.h"
#include "sala.h"

int Unidades::lastID = 0;

Unidades::Unidades(const Unidades& u)
{
	ID = u.ID;
	PV = u.PV;
	MAX_PV = u.MAX_PV;
	armado = u.armado;
	indeciso = u.indeciso;
	sala = u.sala;
	nome = u.nome;
}

void Unidades::setPV(int pv, bool d) {
	if (d)
		PV = pv;
	else
		PV += pv;
	
	//(d) ? PV = pv : PV += pv;

	if (PV > MAX_PV)
		PV = MAX_PV;

	if (PV <= 0)
		delete this;
}

void Unidades::mover(Sala* s) {

	if (sala != nullptr)
		sala->removerUnidade(ID);

	sala = s;

	if(sala != nullptr)
		sala->addUnidade(this);
}

string Unidades::getAsString() const {

	ostringstream oss;
	bool tripulante = false;
	if (nome == MEMBRO || nome == CAPITAO || nome == ROBOT)
		tripulante = true;

	if (sala == nullptr)
		oss << "Nome:" << nome << " PV:" << PV;
	else {
		oss << "Nome:" << nome << " PV:" << PV;

		if (tripulante)
			oss << " ID: " << ID;
		
		oss << " Sala:" << sala->getAsString();
	}
	return oss.str();
}

int * Unidades::isInimigo()
{
	int* a = new int[2];
	a[0] = 0;
	a[1] = 0;
	return a;
}

int * Pirata::isInimigo()
{
	int* a = new int[2];
	a[0] = 1;
	a[1] = 2;
	return a;
}
