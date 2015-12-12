#ifndef NAVE_H
#define NAVE_H

#include "sala.h"

class Nave {
	string nome;
	Sala *salas[3][5];
public:
	Nave(string n);
	~Nave();
	void ConfigurarSala(int x, int y, Sala *sala);
	int mPercorrer();
	vector<Unidades*> UnidadesNaSala(int x, int y);
};

#endif