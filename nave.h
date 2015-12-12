#ifndef NAVE_H
#define NAVE_H

#include "sala.h"

class Nave {
	Sala *salas[3][5];
public:
	Nave();
	~Nave();
};

#endif