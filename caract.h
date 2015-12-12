#ifndef CARACT_H
#define CARACT_H

class Respira {
public:
	Respira();
	~Respira();
	void Respirar();
};

class Reparador {
	int x;
public:
	Reparador(int x): x(x) { }
	~Reparador();

	void Reparar();
};

class Combatente {
	int x;
public:
	Combatente(int x) : x(x) { }
	~Combatente();

	void Combate();
};
#endif