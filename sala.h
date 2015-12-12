#ifndef SALA_H
#define SALA_H

class Unidades;

class Sala {
	int integridade;
	int oxigenio;
	int saude;
	string tipo;
	vector<Unidades*> unidades;
public:
	Sala(string t);
	~Sala();
	void Reparar();
	void Danificar();
	void RecebeOxigenio();
	void UsaOxigenio();
	void Fogo();
	void Brecha();
	void CC();

	//
	int ObterIntegridade()const;
	bool Operada()const;
	bool TemOxigenio() const;
	vector<Unidades*> UnidadesNaSala();
	virtual string TipoSala() const;
	virtual int ObterForca() const;
};

class Propulsor : public Sala {
public:
	Propulsor() : Sala("Propulsor") { }
	string TipoSala() const;
};

class Escudo : public Sala {
	int Forca;
public:
	Escudo() : Sala("Controlo de Escudo") { }
	string TipoSala() const;
	int ObterForca()const { return Forca; }
};


#endif
