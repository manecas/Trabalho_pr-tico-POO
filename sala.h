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
#define SEGINTERNA		"Sistema de Seguranca Interno"
#define ENFERMARIA		"Enfermaria"
#define SALAARMAS		"Sala de Armas"
#define ALUJAMENTOCAP	"Alujamento do Capitao"
#define ROBOTICA		"Oficina Robotica"

class Unidades;

class Sala {
	int integridade;
	int oxigenio;
	string tipo;
	vector<Unidades*> unidades;

	bool fogo;
	bool brecha;
	bool cc;
public:
	Sala(string t) : tipo(t), integridade(100), oxigenio(100),
		fogo(false), brecha(false), cc(false) { }
	virtual ~Sala();

	void	setIntegridade(int i, bool d = false);
	void	setOxigenio(int o, bool d = false);
	void	setFogo(bool f)							{ fogo = f; }
	void	setBrecha(bool b)						{ brecha = b; }
	void	setCC(bool c)							{ cc = c; }
	void	addUnidade(Unidades* u);
	void	removerUnidade(string n);
	void	moverUnidade(string nome, Sala* sala);

	int		getIntegridade()	const { return integridade; }
	int		getOxigenio()		const { return oxigenio; }
	string	getTipo()			const { return tipo; }
	bool	getFogo()			const { return fogo; }
	bool	getBrecha()			const { return brecha; }
	bool	getCC()				const { return cc; }

	void	getUnidades(vector<Unidades*>& u) //para nao retornar o vector de forma abusiva
								const { u = unidades; }

	bool	isOperada()			const;

	string	getAsString()		const;
	Sala&	operator=(const Sala& sala);
};

class Escudo : public Sala {
	int Forca;
	int tmpForca;
	//vai ser necessário outra variavel para salvar a forca, temporariamente, enquanto o escudo for desativado por a sala estar danificada!
public:
	Escudo() : Sala(CONTROLO_ESCUDO) { }
	~Escudo()	{ Sala::~Sala(); }
	void		setForca(int f, bool d = false);
	int			getForca() const { return Forca; }
	void		setEscudo(bool ativo);
};

class Propulsor : public Sala {
public:
	Propulsor() : Sala(PROPULSOR) { }
	~Propulsor() { Sala::~Sala(); }
};

class Beliches : public Sala {
public:
	Beliches() : Sala(BELICHES) { }
	~Beliches() { Sala::~Sala(); }
};
//raio-laser
//autoreparador
//sistema de seguraca interna
class Enfermaria : public Sala {
public:
	Enfermaria() : Sala(ENFERMARIA) { }
	~Enfermaria() { Sala::~Sala(); }
};
//sala armas
//alujamento capitao
class Robotica : public Sala {
public:
	Robotica() : Sala(ROBOTICA) { }
	~Robotica() { Sala::~Sala(); }
};

#endif
