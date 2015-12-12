#include <iostream>
#include <vector>
#include <string>


using std::vector;
using std::string;

#include "sala.h"
#include "unidades.h"

Sala::Sala(string t) : tipo(t)
{
	integridade = 100;
	oxigenio = 100;
}
Sala::~Sala()
{

}
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
//Sala auto-reparador - 5 dano
//blob - 6 dano
//capitão, membro da tripulação - 1
void Sala::Reparar()
{

}
void Sala::UsaOxigenio()
{
	oxigenio--;
}
string Propulsor::TipoSala() const
{
	return Sala::TipoSala();
}

void Enfermaria::Curar()
{
	vector<Unidades*> unidades = UnidadesNaSala();
	for (int u = 0; u != unidades.size(); u++) {
		if (unidades[u]->ObterNome() == "Capitao" ||
			unidades[u]->ObterNome() == "Tripulante" ||
			unidades[u]->ObterNome() == "Robot") {
			unidades[u]->GanhaVida();
		}
	}
}
