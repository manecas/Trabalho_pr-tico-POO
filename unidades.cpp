#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::ostringstream;
using std::endl;

#include "unidades.h"
#include "sala.h" //se nao include, a variavel sala em sala->getAsString() é considerada incompleta

Unidades::~Unidades() {
	//quando a unidade é destruida é necessário remove-la da sala!
	sala->removerUnidade(nome);
	//std::cout << "Unidade " << nome << " destruida" << endl;
}

void Unidades::setPV(int pv, bool d) {
	if (d)
		PV = pv;
	else
		PV += PV;

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
	if (sala == nullptr)
		oss << "shit" << endl;
	else {
		oss << "Nome:" << nome << " PV:" << PV
			<< " Sala:" << sala->getAsString();
	}
	return oss.str();
}
