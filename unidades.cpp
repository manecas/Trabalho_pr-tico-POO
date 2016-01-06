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

Unidades::~Unidades() {
	//quando a unidade é destruida é necessário remove-la da sala!
	sala->removerUnidade(nome);
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

void Unidades::setSala(Sala* s) {

	if(s != nullptr)
		sala = s;
}

string Unidades::getAsString() const {

	ostringstream oss;
	bool tripulante = false;
	if (nome == MEMBRO || nome == CAPITAO || nome == ROBOT)
		tripulante = true;

	if (sala == nullptr)
		oss << "*erro*" << endl;
	else {
		oss << "Nome:" << nome << " PV:" << PV;

		if (tripulante)
			oss << " ID: " << ID;
		
		oss << " Sala:" << sala->getAsString();
	}
	return oss.str();
}
