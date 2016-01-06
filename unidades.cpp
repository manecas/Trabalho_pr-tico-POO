#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::ostringstream;
using std::endl;
using std::vector;

#include "unidades.h"
#include "sala.h"

Unidades::Unidades(const Unidades& u)
{
	ID = u.ID;
	PV = u.PV;
	MAX_PV = u.MAX_PV;
	armado = u.armado;
	indeciso = u.indeciso;
	sala = u.sala;
	nome = u.nome;
}

Unidades::~Unidades() {
	//quando a unidade é destruida é necessário remove-la da sala!
	sala->removerUnidade(ID);
	//std::cout << "Unidade " << nome << " destruida" << endl;
}

void Unidades::setPV(int pv, bool d) {
	if (d)
		PV = pv;
	else
		PV += pv;
	
	//(d) ? PV = pv : PV += pv;

	if (PV > MAX_PV)
		PV = MAX_PV;

	if (PV <= 0)
		delete this;
}

void Unidades::setSala(Sala* s, bool force) {
	//a condicao "s != nullptr" era para proteger de forma a nao colocar
	//unidades em salas invalidas, no entanto, uma vez que existem
	//os misteriosos vamos precisas de ocultar essas unidades
	//para isso adicionei o parametro "force", caso "force" seja verdadeiro
	//a unidade vai para a sala, mesmo sendo invalida e assim é mais
	//facil de atualizar a lista de unidades nas salas
	if(s != nullptr && !force || force)
		sala = s;

}

string Unidades::getAsString() const {

	ostringstream oss;
	bool tripulante = false;
	if (nome == MEMBRO || nome == CAPITAO || nome == ROBOT)
		tripulante = true;

	if (sala == nullptr)
		oss << "Nome:" << nome << " PV:" << PV;
	else {
		oss << "Nome:" << nome << " PV:" << PV;

		if (tripulante)
			oss << " ID: " << ID;
		
		oss << " Sala:" << sala->getAsString();
	}
	return oss.str();
}

int * Unidades::isInimigo()
{
	int* a = new int[2];
	a[0] = 0;
	a[1] = 0;
	return a;
}

int * Pirata::isInimigo()
{
	int* a = new int[2];
	a[0] = 1;
	a[1] = 2;
	return a;
}
