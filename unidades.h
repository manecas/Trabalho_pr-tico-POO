#ifndef UNIDADES_H
#define UNIDADES_H

#define CAPITAO		"Capitao"
#define MEMBRO		"Tripulante"
#define ROBOT		"Robot"

#include "caract.h"
class Sala;

class Unidades {
	int PV;
	int MAX_PV;
	Sala *sala;
	string nome;
public:
	Unidades() { }
	Unidades(string n, int max) : MAX_PV(max), PV(max), nome(n) { }
	~Unidades() { }

	void	setPV(int pv)			{ PV = pv; }
	//void	setSala(int x, int y)	{ }
	void	setSala(Sala* s)		{ sala = s; }

	int		getPV()			const { return PV; }
	Sala*	getSala()		const { return sala; }
	string	getNome()		const { return nome; }

	bool	isTripulante()	const;
	bool	isInimigo()		const;


	string	getAsString()	const;

	/*void PerdeVida();
	void GanhaVida();
	void Mover();
	string ObterNome() const { return nome; };*/
};

class Capitao : public Unidades, public Respira, public Reparador, public Tripulacao {
public:
	Capitao() : Unidades("Capitao", 6), Respira(), Reparador(1), Tripulacao() { }
	~Capitao() { }
};

class Membro : public Unidades, public Respira, public Reparador, public Tripulacao {
public:
	Membro() : Unidades("Membro da Tripulacao", 5), Respira(), Reparador(1), Tripulacao() { }
	~Membro() { }
};

class Robot : public Unidades, public Tripulacao {
public:
	Robot() : Unidades("Robot", 8), Tripulacao() { }
	~Robot() { }
};

//Inimigos

class Pirata : Unidades {
public:
	Pirata() : Unidades("Pirata", 4) { }
	~Pirata() { }
};

//xenomorfos

#endif