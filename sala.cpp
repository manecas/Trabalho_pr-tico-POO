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
	u->setSala(this); //esquece o *this, this já é um ponteiro
}

void Sala::removerUnidade(string n) {
	for (int x = 0; x != unidades.size(); x++) {
		if (unidades[x]->getNome() == n) {
			unidades.erase(unidades.begin() + x);
			break;
		}
	}
}

void Sala::moverUnidade(string nome, Sala * sala) {
	int x;
	for (x = 0; x != unidades.size(); x++) {
		if (unidades[x]->getNome() == nome)
			break;
	}
	sala->addUnidade(unidades[x]);
	unidades.erase(unidades.begin() + x);
}

bool Sala::isOperada() const {

	if (!unidades.size())
		return false;


	for (int u = 0; u != unidades.size(); u++) {
		if (!unidades[u]->isTripulacao())
			return false;
	}

	return true;
}

string Sala::getAsString() const {

	ostringstream oss;
	oss << "Tipo: " << tipo << " Integridade:" << integridade
		<< " Oxigenio:" << oxigenio << endl;

	/*for (int u = 0; u != unidades.size(); u++) {
		oss << unidades[u]->getAsString();
	}
*/

	return oss.str();
}

Sala & Sala::operator=(const Sala & sala)
{
	integridade = sala.integridade;
	oxigenio = sala.oxigenio;
	tipo = sala.tipo;

	for (int a = 0; a != sala.unidades.size(); a++)
		unidades[a] = sala.unidades[a];

	fogo = sala.fogo;
	cc = sala.cc;
	brecha = sala.brecha;

	return *this;
}

void Escudo::setForca(int f, bool d) {

	if (d)
		Forca = f;
	else
		Forca += f;

	if (Forca > 100)
		Forca = 100;

	if (Forca < 0)
		Forca = 0;
}

void Escudo::setEscudo(bool ativo) {

	if (ativo) {
		Forca = tmpForca;
	}
	else {
		tmpForca = Forca;
		Forca = 0;
	}
}
