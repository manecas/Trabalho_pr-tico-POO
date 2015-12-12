#ifndef UNIDADES_H
#define UNIDADES_H

#include "caract.h"
class Sala;

class Unidades {
	int PV;
	int MAX_PV;
	Sala *sala;
	string nome;
public:
	Unidades(string n, int max);
	virtual ~Unidades() { }
	void PerdeVida();
	void GanhaVida();

	void Mover();

	virtual void Respirar() { }

	string ObterNome() const;
};

class Capitao : public Respira, public Unidades, public Reparador {
public:
	Capitao() : Respira(), Unidades("Capitao", 6), Reparador(1) { }
	virtual ~Capitao() { }
	void Respirar() { Respira::Respirar(); }
};

#endif