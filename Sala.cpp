#include <iostream>
#include <vector>
using std::vector;

#include "sala.h"
#include "unidades.h"

bool Sala::TemOxigenio() const
{
	return (oxigenio > 0); 
}

//Sala auto-reparador - 5 dano
//blob - 6 dano
//capit�o, membro da tripula��o - 1
void Sala::Reparar()
{

}

void Sala::UsaOxigenio()
{
	oxigenio--;
}

