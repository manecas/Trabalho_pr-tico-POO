#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;
using std::vector;

#include "nave.h"
#include "unidades.h"


int main(void) {

	string nome;
	int dificuldade, m_percorridas = 0;

	cout << "Introduza um nome para a sua nave: " << endl;
	getline(cin, nome);

	cout << "Nível de dificuldade da missão?" << endl;
	cin >> dificuldade;

	Nave nave(nome);
	//nave.ConfigurarSala(0, 0, new Propulsor());

	while (1) {
		
		if( (4000 + 1000)*dificuldade >= m_percorridas){
			
		}
		//Inicio da turno

		//Fase de ordens

		//Final do turno
		for (int l = 0; l < 3; l++) {
			for (int c = 0; c < 5; c++) {
			}
		}

		//Eventos
	}



	return 0;
}
