#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::ostringstream;
using std::endl;

#include "unidades.h"
#include "sala.h" //se nao include, a variavel sala em sala->getAsString() é considerada incompleta

bool Unidades::isTripulante() const {

	if (nome == CAPITAO || nome == MEMBRO || nome == ROBOT)
		return true;

	return false;
}

bool Unidades::isInimigo() const {

	if (!isTripulante())
		return true;

	return false;
}

string Unidades::getAsString() const {

	ostringstream oss;
	oss << "Nome:" << nome << " PV:" << PV
		<< " Sala:" << endl;// << sala->getAsString() << endl;
	return oss.str();
}
