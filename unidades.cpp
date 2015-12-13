#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::ostringstream;
using std::endl;

#include "unidades.h"
#include "sala.h" //se nao include, a variavel sala em sala->getAsString() é considerada incompleta

string Unidades::getAsString() const {

	ostringstream oss;
	oss << "Nome:" << nome << " PV:" << PV
		<< " Sala:" << endl;// << sala->getAsString() << endl;
	return oss.str();
}
