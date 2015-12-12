#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

#include "nave.h"

Nave::Nave(string n):nome(n)
{

	for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 5; c++) {
			salas[l][c] = nullptr;
		}
	}

	//salas por defeito
	salas[0][0] = new Propulsor;
	salas[1][1] = new Sala("Sala das Maquinas");
	salas[1][2] = new Sala("Suporte de Vida");
	salas[1][3] = new Sala("Controlo de Escudo");
	salas[1][4] = new Sala("Ponte");
	salas[2][0] = new Propulsor;
}

Nave::~Nave()
{

}

void Nave::ConfigurarSala(int x, int y, Sala* sala)
{
	salas[x][y] = sala;
}

int Nave::mPercorrer()
{
	int total = 0;
	for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 5; c++) {
			if (salas[l][c] == nullptr) continue;//temporario
			if (salas[l][c]->TipoSala() == "Propulsor")
				total += salas[l][c]->ObterIntegridade();
		}
	}
	return total;
}

vector<Unidades*> Nave::UnidadesNaSala(int x, int y)
{
	return salas[x][y]->UnidadesNaSala();
}





// int Nave::TotalSalas(string nomeSala)
// {
// 	int total = 0;
// 	for (int l = 0; l < 3; l++) {
// 		for (int c = 0; c < 5; c++) {
// 			if (salas[l][c]->TipoSala() == nomeSala)
// 				total++;
// 		}
// 	}
// 	return total;
// }
