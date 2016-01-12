#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

#include "consola.h"
#include "unidades.h"
#include "sala.h"
#include "nave.h"
#include "graficos.h"

#define PIXEIS_MARGEM_S_NAVE	40
#define PIXEIS_POR_SALA_A		95
#define PIXEIS_POR_SALA_L		150
#define COR_NAVE				RGB(255, 255, 255)

void atualizarOutput(Consola& c, string* o, int tam) {
	static vector<string> output;

	for (int x = 0; x < 10; x++) {
		c.gotoxy(5, 27 + x);
		for (int y = 0; y < 100; y++)
			cout << " ";
	}
	//
	for (int t = 0; t < tam; t++)
		output.push_back(o[t]);

	std::vector<string>::const_reverse_iterator rit = output.rbegin();
	std::vector<string>::const_reverse_iterator lim =
		(output.size() > 10) ? (output.rbegin() + 10) : (output.rend());

	for (int l = 0; rit < lim; rit++, l++) {
		c.gotoxy(5, 27 + l);
		cout << *rit;
	}
	delete []o;
}
void atualizarListaUnidades() {

}
void atualizarListaInimigos() {

}
void atualizarTextoSala(Consola& consola, Nave& nave, int l, int c) {
	int x, y;
	Sala* sala = nave.getSala(l, c);
	int idSalas[3][5] = {
		{ 1,	2,	3,	4,	0 },
		{ 0,	5,	6,	7,	8 },
		{ 9,	10,	11,	12,	0 }
	};

	x = 6 + 19 * c;
	y = 3 + 6 * l;

	if (sala == nullptr) {
		if (idSalas[l][c] == 0) return;

		consola.gotoxy(x, y);
		cout << "(?)";
		return;
	}

	string nomeSala = sala->getTipo();
	std::size_t pos;

	if ( (pos = nomeSala.find(" ")) != string::npos ) {
		consola.gotoxy(x, y);
		cout << nomeSala.substr(0, pos);
		consola.gotoxy(x, y + 1);
		cout << nomeSala.substr(pos+1, string::npos) << "(" << idSalas[l][c] << ")";
	}
	else {
		consola.gotoxy(x, y);
		cout << nomeSala << "(" << idSalas[l][c] << ")";
	}
	
	consola.gotoxy(x, y + 2);
	cout << "I:" << sala->getIntegridade() << " <-> O:" << sala->getOxigenio();
	consola.gotoxy(x, y + 3);
	cout << "Unidade/Inimigo";
	//este texto só é suposto aparecer, se existirem unidades
	//ou inimigos nas salas
	//mas depois fazemos
}
void desenharSala(Consola& c, int mx, int my, int l, int a) {
	c.drawLine(
		mx,
		my,
		mx + l,
		my,
		COR_NAVE);

	c.drawLine(
		mx,
		my,
		mx,
		my + a,
		COR_NAVE);

	c.drawLine(
		mx,
		my + a,
		mx + l,
		my + a,
		COR_NAVE);

	c.drawLine(
		mx + l,
		my,
		mx + l,
		my + a,
		COR_NAVE);
}
void desenharNave(Consola& c, Nave& nave) {
	//primeira linha
	desenharSala(c,
		PIXEIS_MARGEM_S_NAVE,
		PIXEIS_MARGEM_S_NAVE,
		PIXEIS_POR_SALA_L,
		PIXEIS_POR_SALA_A);

	desenharSala(c,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_L,
		PIXEIS_MARGEM_S_NAVE,
		PIXEIS_POR_SALA_L,
		PIXEIS_POR_SALA_A);

	desenharSala(c,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_L * 2,
		PIXEIS_MARGEM_S_NAVE,
		PIXEIS_POR_SALA_L,
		PIXEIS_POR_SALA_A);

	desenharSala(c,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_L * 3,
		PIXEIS_MARGEM_S_NAVE,
		PIXEIS_POR_SALA_L,
		PIXEIS_POR_SALA_A);

	//segunda linha
	desenharSala(c,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_L,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_A,
		PIXEIS_POR_SALA_L,
		PIXEIS_POR_SALA_A);

	desenharSala(c,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_L * 2,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_A,
		PIXEIS_POR_SALA_L,
		PIXEIS_POR_SALA_A);

	desenharSala(c,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_L * 3,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_A,
		PIXEIS_POR_SALA_L,
		PIXEIS_POR_SALA_A);

	desenharSala(c,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_L * 4,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_A,
		PIXEIS_POR_SALA_L,
		PIXEIS_POR_SALA_A);

	//terceira linha
	desenharSala(c,
		PIXEIS_MARGEM_S_NAVE,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_A * 2,
		PIXEIS_POR_SALA_L,
		PIXEIS_POR_SALA_A);

	desenharSala(c,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_L,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_A * 2,
		PIXEIS_POR_SALA_L,
		PIXEIS_POR_SALA_A);

	desenharSala(c,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_L * 2,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_A * 2,
		PIXEIS_POR_SALA_L,
		PIXEIS_POR_SALA_A);

	desenharSala(c,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_L * 3,
		PIXEIS_MARGEM_S_NAVE + PIXEIS_POR_SALA_A * 2,
		PIXEIS_POR_SALA_L,
		PIXEIS_POR_SALA_A);

	for (int l = 0; l < 3; l++) {
		for (int c1 = 0; c1 < 5; c1++) {
			atualizarTextoSala(c, nave, l, c1);
		}
	}
}