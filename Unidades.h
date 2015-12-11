#ifndef UNIDADES_H
#define UNIDADES_H

class Unidades {
	int PV;
	int MAX_PV;
public:
	Unidades(int MAX);
	~Unidades();
	void PerdeVida();
	void GanhaVida();
};

#endif