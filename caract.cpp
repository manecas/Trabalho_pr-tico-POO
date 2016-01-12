#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

#include "caract.h"
#include "unidades.h"
#include "sala.h"

void Respira::inicioTurno(Unidades* u)
{
	if (u->getSala() == nullptr)
		return;

	if (u->getSala()->getOxigenio() > 0)
		u->getSala()->setOxigenio(-1);
	else
		u->setPV(-1);
}

void Respira::fimTurno(Unidades* u)
{
}
