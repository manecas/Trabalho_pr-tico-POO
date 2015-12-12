#ifndef CARACT_H
#define CARACT_H

class Respira {
public:
	Respira() { }
	void Respirar();
};

class Flamejante {
public:
	Flamejante() { }
	~Flamejante() { }
	void Flamejar();
};

class Toxico
{
public:
	Toxico() { }
	~Toxico() { }
	void Toxifica();
};

//indeciso

//misterioso

class Regenerador {
	int x;
public:
	Regenerador(int x) : x(x) { }
	~Regenerador() { }
	void Regenera();
};

class Exoesqueleto {
	int x;
public:
	Exoesqueleto(int x) : x(x) { }
	~Exoesqueleto() { }
};

//robotico

class Reparador {
	int x;
public:
	Reparador(int x) : x(x) { }
	void Reparar();
};

class Combatente {
	int x;
public:
	Combatente(int x) : x(x) { }
	void Combate();
};

class Xenomorfo {
	int x;
public:
	Xenomorfo(int x) : x(x) { }
	~Xenomorfo() { }
};

class Casulo {
	int x;
public:
	Casulo(int x) : x(x) { }
	~Casulo() { }
};



#endif