#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

#include "caract.h"
#include "unidades.h"
#include "sala.h"

Unidades::Unidades(string n, int max) :
	nome(n), MAX_PV(max), PV(max) { }

void Unidades::GanhaVida()
{
	PV++;
}

string Unidades::ObterNome() const
{
	return nome;
}
