#ifndef SALA_H
#define SALA_H

class Unidades;

class Sala {
	int integridade;
	int oxigenio;
	int saude;
	vector<Unidades*> unidades;
public:
	Sala();
	~Sala();
	void Reparar();
	void Danificar();
	void UsaOxigenio();
	void Fogo();
	void Brecha();
	void CC();

	//
	int ObterIntegridade()const;
	bool Operada()const;
	bool TemOxigenio() const;
};

class Propulsor : public Sala {
public:
	Propulsor() { }
	void Voar() { }
};

#endif
