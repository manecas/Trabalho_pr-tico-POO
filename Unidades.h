#ifndef UNIDADES_H
#define UNIDADES_H

class Unidades {
	int PV;
	int MAX_PV;
public:
	Unidades(int max);
	~Unidades();
	void PerdeVida();
	void GanhaVida();
};

class Capitao : public Unidades, public Reparador {
public:
	Capitao();
};

#endif