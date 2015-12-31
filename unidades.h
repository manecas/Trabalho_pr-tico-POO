#ifndef UNIDADES_H
#define UNIDADES_H

#define CAPITAO		"Capitao"
#define MEMBRO		"Membro da Tripulacao"
#define ROBOT		"Robot"
//
#define PIRATA		"Pirata"
//
#define GEIGERMORFO	"Geigermorfo"
#define CASULO		"Casulo de Geigermorfo"
#define BLOB		"Blob"
#define MXY			"Mxyzypykwi"

class Sala;

class Unidades {
	static int lastID;
	int ID;
	int PV;
	int MAX_PV;
	int armado;
	Sala *sala;
	string nome;
public:
	Unidades() { }
	Unidades(string n, int max) : MAX_PV(max), PV(max), nome(n), sala(nullptr), armado(0), ID(lastID++) { }
	virtual ~Unidades();
	//
	void	setPV(int pv, bool d = false);
	void	setSala(Sala* s);
	void	setArmado(int a)		{ armado = a; }
	//
	int		getID()					const { return ID; }
	int		getPV()					const { return PV; }
	Sala*	getSala()				const { return sala; }
	string	getNome()				const { return nome; }
	string	getAsString()			const;
	//
	virtual int isRespira()			{ return 0; }
	virtual int isFlamejante()		{ return 0; }
	virtual int isToxico()			{ return 0; }
	virtual int isIndeciso()		{ return 0; }
	virtual int isMisterioso()		{ return 0; }
	virtual int isRegenerador()		{ return 0; }
	virtual int isExoesqueleto()	{ return 0; }
	virtual int isRobotico()		{ return 0; }
	virtual int isReparador()		{ return 0; }
	virtual int isCombatente()		{ return 0; }
	virtual int isXenomorfo()		{ return 0; }
	virtual int isCasulo()			{ return 0; }
	virtual int isMutatis()			{ return 0; }
	virtual int isHipnotizador()	{ return 0; }
	virtual int isOperador()		{ return 0; }
	virtual int isTripulacao()		{ return 0; }
	virtual int isInimigo()			{ return 0; }
	virtual int isMove()			{ return 0; }
	virtual int isArmado()			{ return armado; }
};

class Capitao : public Unidades {
public:
	Capitao() : Unidades(CAPITAO, 6) { }
	~Capitao() { }
	int isRespira()					{ return 1; }
	int isExoesqueleto()			{ return 1; }
	int isReparador()				{ return 2; }
	int isCombatente()				{ return 2; }
	int isOperador()				{ return 1; }
	int isTripulacao()				{ return 1; }
};

class Membro : public Unidades {
public:
	Membro() : Unidades(MEMBRO, 5) { }
	~Membro() { }
	int isRespira()					{ return 1; }
	int isReparador()				{ return 2; }
	int isCombatente()				{ return 1; }
	int isOperador()				{ return 1; }
	int isTripulacao()				{ return 1; }
};

class Robot : public Unidades {
public:
	Robot() : Unidades(ROBOT, 8) { }
	~Robot() { }
	int isExoesqueleto()			{ return 1; }
	int isCombatente()				{ return 2; }
	int isTripulacao()				{ return 1; }
};

//Inimigos

class Pirata : public Unidades {
public:
	Pirata() : Unidades(PIRATA, 4) { }
	~Pirata() { }
	int isRespira()					{ return 1; }
	int isInimigo()					{ return 1; }
	int isMove()					{ return 15; }
};

//xenomorfos

class Geigermorfo : public Unidades {
public:
	Geigermorfo() : Unidades(GEIGERMORFO, 4) { }
	~Geigermorfo() { }
};

class Casulo : public Unidades {
public:
	Casulo() : Unidades(CASULO, 6) { }
	~Casulo() { }
};

class Blob : public Unidades {
public:
	Blob() : Unidades(BLOB, 8) { }
	~Blob() { }
};

class Mxy : public Unidades {
public:
	Mxy() : Unidades(MXY, 8) { }
	~Mxy() { }
};

#endif