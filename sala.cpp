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
	
	unsigned int x, t = tripulacao.size(), i = inimigos.size();

	for (x = 0; x < t; x++)
		delete tripulacao[0];
	for (x = 0; x < i; x++)
		delete inimigos[0];

	//std::cout << "DestrutorSala '" << tipo << "'" << std::endl;
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

	if (integridade < 0)
		integridade = 0;
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

void Sala::addUnidade(Unidades * u, bool t) {
	if(t)
		tripulacao.push_back(u);
	else
		inimigos.push_back(u);

	u->setSala(this);
}

void Sala::removerUnidade(int id) {
	unsigned int x;

	for (x = 0; x < tripulacao.size(); x++) {
		if (tripulacao[x]->getID() == id) {
			tripulacao.erase(tripulacao.begin() + x);
			return;
		}
	}

	if (x == tripulacao.size()) {
		for (x = 0; x < inimigos.size(); x++) {
			if (inimigos[x]->getID() == id) {
				inimigos.erase(inimigos.begin() + x);
				return;
			}
		}
	}
}

void Sala::moverUnidade(int id, Sala * sala) {
	unsigned int x;
	for (x = 0; x < tripulacao.size(); x++) {
		if (tripulacao[x]->getID() == id)
			break;
	}
	if (x < tripulacao.size()) {
		sala->addUnidade(tripulacao[x]);
		tripulacao.erase(tripulacao.begin() + x);
	}
	else {
		for (x = 0; x < inimigos.size(); x++) {
			if (inimigos[x]->getID() == id)
				break;
		}
		if (x < inimigos.size()) {
			sala->addUnidade(inimigos[x]);
			inimigos.erase(inimigos.begin() + x);
		}
	}
}

void Sala::getUnidades(vector<Unidades*>& u) const
{
	unsigned int x;
	vector<Unidades*> u1;
	u = tripulacao;

	for (x = 0; x < inimigos.size(); x++)
		u.push_back(inimigos[x]);
}

bool Sala::isOperada() const {

	if (tripulacao.size() != 0 && !inimigos.size())
		return true;

	return false;
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

	for (int a = 0; a != sala.tripulacao.size(); a++) {

		if (tripulacao[a]->getNome() == CAPITAO)
			tripulacao[a] = new Capitao(sala.tripulacao[a]);

		else if (tripulacao[a]->getNome() == MEMBRO)
			tripulacao[a] = new Membro(sala.tripulacao[a]);

		else if (tripulacao[a]->getNome() == ROBOT)
			tripulacao[a] = new Robot(sala.tripulacao[a]);
		//completar para todas

		tripulacao[a]->setSala(this);
	}

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
