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


/*
int Sala::ObterIntegridade() const
{
	return integridade;
}
bool Sala::Operada() const
{
	const int dano = 100 - integridade;

	if (dano == 0) //Falta coisas
		return true;

	return false;
}
bool Sala::TemOxigenio() const
{
	return (oxigenio > 0); 
}
vector<Unidades*> Sala::UnidadesNaSala()
{
	return unidades;
}
string Sala::TipoSala() const
{
	return tipo;
}
int Sala::ObterForca() const
{
	return 0;
}
//Sala auto-reparador - 5 dano
//blob - 6 dano
//capitão, membro da tripulação - 1
void Sala::Reparar()
{

}

void Sala::Danificar()
{
}
void Sala::UsaOxigenio()
{
	oxigenio--;
}
void Sala::Brecha()
{
}*/

void Enfermaria::Curar()
{
	vector<Unidades*> unidades;
	getUnidades(unidades);
	for (int u = 0; u != unidades.size(); u++) {
		if (unidades[u]->isTripulante()) {
			//dar vida
			unidades[u]->setPV(unidades[u]->getPV() + 1);
		}
	}
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
