#ifndef CARACT_H
#define CARACT_H

class Respira {
public:
	Respira() { }

	void Respirar();
};

class Reparador {
	int x;
public:
	Reparador(int x): x(x) { }

	void Reparar();
};

class Combatente {
	int x;
public:
	Combatente(int x) : x(x) { }

	void Combate();
};
#endif