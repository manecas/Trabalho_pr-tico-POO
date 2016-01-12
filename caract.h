#ifndef CARACT_H
#define CARACT_H

class Unidades;

class Respira {
public:
	Respira() { }
	~Respira() { }
	void inicioTurno(Unidades* u);
	void fimTurno(Unidades* u);
};

#endif