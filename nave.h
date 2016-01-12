#ifndef NAVE_H
#define NAVE_H

/*#include "sala.h"
#include "unidades.h"*/

class Nave {
	int distPercorrer;
	string nome;
	Sala *salas[3][5];
public:
	Nave();
	~Nave();
	//
	void	config(string n, int dificuldade);
	void	configSala(int x, int y, Sala* sala)			{ salas[x][y] = sala; }
	void	updateDistPercorrer();
	//
	void	getAllTripulacao(vector<Unidades*>& u)		const;
	void	getAllInimigos(vector<Unidades*>& u)		const;
	void	getAllUnidades(vector<Unidades*>& u)		const;
	Sala*	getSala(int x, int y)						const;
	Sala*	getSalaByTipo(string tipo)					const;
	Sala*	getSalaAdjacente(Sala* sala, char d)		const;
	int		getDistPercorrer()							const;
	bool	isNaveDestruida()							const;
};


#endif