#ifndef SALA_H
#define SALA_H

//#include <vector>
//using std::vector;

//nomes salas
#define PONTE			"Ponte"
#define SUPORTE_VIDA	"Suporte de Vida"
#define CONTROLO_ESCUDO	"Controlo de Escudo"
#define SALA_MAQUINAS	"Sala das Maquinas"
#define PROPULSOR		"Propulsor"
#define BELICHES		"Beliches"
#define RAIO_LASER		"Raio Laser"
#define AUTOREPARADOR	"Auto-Reparador"
#define SEGINTERNA		"Sistema de Seg. Interno"
#define ENFERMARIA		"Enfermaria"
#define SALAARMAS		"Sala de Armas"
#define ALUJAMENTOCAP	"Alujamento do Capitao"
#define ROBOTICA		"Oficina Robotica"

class Unidades;

class Sala {
	friend class Unidades;//temporario
	int integridade;
	int oxigenio;
	string tipo;
	//
	bool fogo;
	bool brecha;
	bool cc;
	//
	vector<Unidades*> tripulacao;
	vector<Unidades*> inimigos;
protected://temporario
	void	addUnidade(Unidades* u);
	void	removerUnidade(int id);
public:
	Sala(string t) : tipo(t), integridade(100), oxigenio(100),
		fogo(false), brecha(false), cc(false) { }
	virtual ~Sala();

	//
	void	setIntegridade(int i, bool d = false);
	void	setOxigenio(int o, bool d = false);
	void	setFogo(bool f)							{ fogo = f; }
	void	setBrecha(bool b)						{ brecha = b; }
	void	setCC(bool c)							{ cc = c; }
	//
	int		getIntegridade()	const { return integridade; }
	int		getOxigenio()		const { return oxigenio; }
	string	getTipo()			const { return tipo; }
	bool	getFogo()			const { return fogo; }
	bool	getBrecha()			const { return brecha; }
	bool	getCC()				const { return cc; }
	//
	bool	isOperada()			const;

	//
	/*void	addUnidade(Unidades* u);
	void	removerUnidade(int id);*/
	void	getUnidades(vector<Unidades*>& u)		const;
	void	getTripulacao(vector<Unidades*>& u)		const { u = tripulacao; }
	void	getInimigos(vector<Unidades*>& u)		const { u = inimigos; }
	

	
	//
	string	getAsString()		const;
	Sala&	operator=(const Sala& sala);
	//
	virtual void	setForca(int f, bool d = false) { return; }
	virtual void	setEscudo(bool ativo)			{ return; }
	virtual int		getForca()				const { return 0; }
};

class Escudo : public Sala {
	int Forca;
	int tmpForca;
public:
	Escudo() : Sala(CONTROLO_ESCUDO), Forca(100), tmpForca(100) { }
	~Escudo()	{ }
	void		setForca(int f, bool d = false);
	void		setEscudo(bool ativo);

	int			getForca()			const { return Forca; }
};

class Propulsor : public Sala {
public:
	Propulsor() : Sala(PROPULSOR) { }
	~Propulsor() { }
};

class Beliches : public Sala {
public:
	Beliches() : Sala(BELICHES) { }
	~Beliches() { }
};
//raio-laser
//autoreparador
//sistema de seguraca interna
class Enfermaria : public Sala {
public:
	Enfermaria() : Sala(ENFERMARIA) { }
	~Enfermaria() { }
};
//sala armas
//alujamento capitao
class Robotica : public Sala {
public:
	Robotica() : Sala(ROBOTICA) { }
	~Robotica() { }
};

#endif
