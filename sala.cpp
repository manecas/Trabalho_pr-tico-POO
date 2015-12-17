#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::vector;
using std::string;
using std::ostringstream;
using std::endl;

#include "sala.h"
#include "unidades.h"


void Enfermaria::curar()
{
	vector<Unidades*> unidades;
	getUnidades(unidades);
	for (int u = 0; u != unidades.size(); u++) {
		if (unidades[u]->isTripulacao())
			unidades[u]->setPV(1);
	}
}

Sala::~Sala() {

	for (int x = 0; x != unidades.size(); x++)
		delete unidades[x];

	unidades.clear();
}

void Sala::setIntegridade(int i, bool d) {

	if (d)
		integridade = i;
	else
		integridade += i;

	//alternativa (operadores ternários)
	//(d) ? integridade = i : integridade += i;

	if (integridade > 100)
		integridade = 100;
}

void Sala::setOxigenio(int o, bool d) {

	if (d)
		oxigenio = o;
	else
		oxigenio += o;

	//alternativa (operadores ternários)
	//(d) ? oxigenio = o : oxigenio += o;

	if (oxigenio > 100)
		oxigenio = 100;

	if (oxigenio < 0)
		oxigenio = 0;
}

void Sala::addUnidade(Unidades * u) {

	unidades.push_back(u);
	u->setSala(*this); //*this para enviar o endereço
}

bool Sala::isOperada() const {

	if (!unidades.size())
		return false;


	for (int u = 0; u != unidades.size(); u++) {
		if (unidades[u]->isInimigo())
			return false;
	}

	return true;
}

string Sala::getAsString() const {

	ostringstream oss;
	oss << "Tipo: " << tipo << " Integridade:" << integridade
		<< " Oxigenio:" << oxigenio << endl;

	for (int u = 0; u != unidades.size(); u++) {
		oss << unidades[u]->getAsString();
	}

	return oss.str();
}
