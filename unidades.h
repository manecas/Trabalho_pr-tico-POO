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
	~Unidades();
	void PerdeVida();
	void GanhaVida();
};

class Capitao : public Unidades, public Reparador {
public:
	Capitao() : Unidades(6), Reparador(1) {

	}
};

#endif