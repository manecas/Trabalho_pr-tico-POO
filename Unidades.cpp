#include <iostream>

#include "caract.h"
#include "unidades.h"

Unidades::Unidades(int max) : MAX_PV(max), PV(max) { }

Capitao::Capitao() : Unidades(6), Reparador(1) { }
