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
	bool TemOxigenio() const;
	void Fogo();
	void Brecha();
	void CC();
};

class Propulsor: public Sala{
	
public:
	//...
};

#endif