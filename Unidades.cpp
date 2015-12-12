#include <iostream>
#include <vector>
using std::vector;

#include "caract.h"
#include "unidades.h"
#include "sala.h"

Unidades::Unidades(int max) : MAX_PV(max), PV(max) { }

Capitao::Capitao() : Unidades(6), Reparador(1) { }
