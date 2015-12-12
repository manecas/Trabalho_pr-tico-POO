#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;
using std::vector;

#include "nave.h"
#include "unidades.h"

void ChuvaMeteroritos(Nave& nave) {

}



int main(void) {





	/*Unidades* b2 = new Capitao;
	Capitao* d = dynamic_cast<Capitao*>(b2);
	Capitao* c = (Capitao*)b2;
	d->Respirar();
	c->Respirar();
	//http://en.cppreference.com/w/cpp/language/dynamic_cast */



	


	string nome, comando;
	int dificuldade, m_percorridas = 0, p_evento = 0, t_turnos = 0;

	cout << "Introduza um nome para a sua nave: " << endl;
	getline(cin, nome);

	cout << "Nivel de dificuldade da missao?" << endl;
	cin >> dificuldade;

	Nave nave(nome);

	//preparar a viagem
	//definir salas opcionais

	//definir tripulacao

	std::srand((unsigned int)std::time(0));
	while (1) {
		cout << ((4000 + 1000)*dificuldade - m_percorridas) <<
			" milhas ate ao fim!" << endl;

		if( (4000 + 1000)*dificuldade <= m_percorridas){
			cout << "Fim da brincadeira!" << endl << "Voce ganhou" << endl;
			break;
		}
		//Inicio da turno
		//repirar
		/*for (int l = 0; l < 3; l++) {
			for (int c = 0; c < 5; c++) {
				
				vector<Unidades*> unidades = nave.UnidadesNaSala(l, c);

				for (std::vector<Unidades*>::iterator it = unidades.begin();
				it < unidades.end(); it++) {
					//(*it)->PerdeVida();
				}


			}
		}*/

		//Fase de ordens

		while (1) {
			cout << "Introduza comando para nova ordem:";
			//cin.ignore();
			getline(cin, comando);
			if (comando == "sair") break;
		}

		//Final do turno
		//adicionar oxigenio ás salas
		//recuperar escudo da sala de controlo de escudo

		m_percorridas += nave.mPercorrer();//verificar se alguem esta na Ponte

		//Eventos
		if (!t_turnos || t_turnos == p_evento) {
			switch (rand() % 4)
			{
			case 0:
				//
				ChuvaMeteroritos(nave);
				break;
			case 1:
				//
				break;
			case 2:
				//
				break;
			case 3:
				//
				break;
			}
			//evento
			cout << "Evento" << endl;

			p_evento += 5 + std::rand() % 5;
		}
		t_turnos++;
	}



	return 0;
}
