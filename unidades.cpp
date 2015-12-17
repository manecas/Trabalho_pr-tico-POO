#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::ostringstream;
using std::endl;

#include "unidades.h"
#include "sala.h" //se nao include, a variavel sala em sala->getAsString() é considerada incompleta

void Unidades::setPV(int pv, bool d) {
	if (d)
		PV = pv;
	else
		PV += PV;

	//(d) ? PV = pv : PV += pv;

	if (PV > MAX_PV)
		PV = MAX_PV;
}

void Unidades::setSala(Sala& s) {

	//if(s != nullptr) //nao é preciso, ja que & nunca pode ser null
	sala = &s;
}

string Unidades::getAsString() const {

	ostringstream oss;
	oss << "Nome:" << nome << " PV:" << PV
		<< " Sala:" << endl;// << sala->getAsString() << endl;
	return oss.str();
}
