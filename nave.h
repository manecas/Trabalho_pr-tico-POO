#ifndef NAVE_H
#define NAVE_H

#include "sala.h"

class Nave {
	string nome;
	Sala *salas[3][5];
public:
	Nave(string n);
	~Nave() { }

	void	configSala(int x, int y, Sala* sala)		{ salas[x][y] = sala; }

	void	getUnidades(int x, int y, vector<Unidades*>& u)
											const { salas[x][y]->getUnidades(u); }
	int		getTotalUnidades()				const;
	Sala*	getSala(int x, int y)			const { return salas[x][y]; }
	Sala*	getSalaByTipo(string tipo)		const;
	int		distPercorrer()					const;

	/*void ConfigurarSala(int x, int y, Sala *sala);
	int mPercorrer();
	vector<Unidades*> UnidadesNaSala(int x, int y);
	Sala *RetornaSala(int x, int y)const;*/
};


#endif