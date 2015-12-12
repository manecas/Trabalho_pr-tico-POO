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
};

class Propulsor : public Sala {
public:
	Propulsor() : Sala("Propulsor") { }
	virtual string TipoSala() const;
};

class Enfermaria : public Sala {
public:
	Enfermaria() : Sala("Enfermaria") { }
	~Enfermaria() { }
	void Curar(); // curar todos os tripulantes na sala
};

#endif
