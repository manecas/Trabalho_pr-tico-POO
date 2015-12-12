#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

#include "nave.h"

Nave::Nave(string n):nome(n)
{
	salas[0][0] = new Propulsor;
	salas[2][0] = new Propulsor;
}

Nave::~Nave()
{

}

void Nave::ConfigurarSala(int x, int y, Sala* sala)
{
	salas[x][y] = sala;
}
