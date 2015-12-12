#ifndef SALA_H
#define SALA_H

class Sala {
	int integridade;
	int oxigenio;
	int saude;
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
	bool TemOxigenio() const;
};

class Propulsor : public Sala {

public:
	Propulsor();
	~Propulsor();
};

#endif
