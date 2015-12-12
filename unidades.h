#ifndef UNIDADES_H
#define UNIDADES_H

#include "caract.h"
class Sala;

class Unidades {
	int PV;
	int MAX_PV;
	Sala *sala;
public:
	Unidades(int max);
	void PerdeVida();
	void GanhaVida();

	void Mover();
};

class Capitao : public Respira, public Unidades, public Reparador {
public:
	Capitao() : Respira(), Unidades(6), Reparador(1) { }
};

#endif