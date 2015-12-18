#ifndef NAVE_H
#define NAVE_H

#include "sala.h"

class Nave {
	string nome;
	Sala *salas[3][5];
public:
	Nave(string n);
	~Nave() { }
	//
	void	configSala(int x, int y, Sala* sala)			{ salas[x][y] = sala; }
	//
	void	getUnidades(int x, int y, vector<Unidades*>& u)	const;
	void	getAllUnidades(vector<Unidades*>& u)			const;
	int		getTotalUnidades()								const;
	Sala*	getSala(int x, int y)							const;
	Sala*	getSalaByTipo(string tipo)						const;
	Sala*	getSalaAdjacente(Sala* sala, char d)			const;
	int		getDistPercorrer()								const;
};


#endif