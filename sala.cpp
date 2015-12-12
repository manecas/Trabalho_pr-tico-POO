#include <iostream>
#include <vector>
using std::vector;

#include "sala.h"
#include "unidades.h"

Sala::Sala()
{

}

Sala::~Sala()
{

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

