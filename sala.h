#ifndef SALA_H
#define SALA_H

#include <vector>
using std::vector;

//nomes salas

#define PROPULSOR		"Propulsor"
#define RAIO_LASER		"Raio Laser"
#define CONTROLO_ESCUDO	"Controlo de Escudo"
#define PONTE			"Ponte" //qual é que é o nome mesmo?
#define ENFERMARIA		"Enfermaria"

class Unidades;

class Sala {
	int integridade;
	int oxigenio;
	int saude;
	string tipo;
	vector<Unidades*> unidades;

	bool fogo;
	bool brecha;
	bool cc;
public:
	Sala(string t) : tipo(t), integridade(100), oxigenio(100),
		fogo(false), brecha(false), cc(false) { }
	~Sala() { }

	void	setIntegridade(int i)	{ integridade = i; }
	void	setOxigenio(int o)		{ oxigenio = o; }
	void	setFogo(bool f)			{ fogo = f; }
	void	setBrecha(bool b)		{ brecha = b; }
	void	setCC(bool c)			{ cc = c; }
	void	addUnidade(Unidades* u) { unidades.push_back(u); }

	int		getIntegridade()	const { return integridade; }
	int		getOxigenio()		const { return oxigenio; }
	string	getTipo()			const { return tipo; }
	bool	getFogo()			const { return fogo; }
	bool	getBrecha()			const { return brecha; }
	bool	getCC()				const { return cc; }

	void	getUnidades(vector<Unidades*>& u) //para nao retornar o vector de forma abusiva
								const { u = unidades; }

	string	getAsString()		const;
	/*
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
	virtual int ObterForca() const;*/
};

class Propulsor : public Sala {
public:
	Propulsor() : Sala(PROPULSOR) { }
};

class Escudo : public Sala {
	int Forca;
	//vai ser necessário outra variavel para salvar a forca, temporariamente, enquanto o escudo for desativado por a sala estar danificada!
public:
	Escudo() : Sala(CONTROLO_ESCUDO) { }

	int		getForca()	const { return Forca; }
};
class Enfermaria : public Sala {
public:
	Enfermaria() : Sala(ENFERMARIA) { }
	~Enfermaria() { }
	void Curar(); // curar todos os tripulantes na sala
};

#endif
