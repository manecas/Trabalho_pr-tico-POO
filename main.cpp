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

bool PonteOperada(Nave& nave) {

	for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 5; c++) {
			if (nave.RetornaSala(l, c)->TipoSala() == "Ponte") {
				if (nave.RetornaSala(l, c)->Operada()) {
					return true;

				}
			}


		}
	}

	return false;
}
bool TemRaioLaser(Nave& nave) {

	for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 5; c++) {
			if (nave.RetornaSala(l, c)->TipoSala() == "Raio Laser") 
					return true;
		}
	}

	return false;
}
bool TemEscudo(Nave& nave) {

	for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 5; c++) {
			if (nave.RetornaSala(l, c)->TipoSala() == "Controlo de Escudo")
				return true;
		}
	}

	return false;
}
int MeteoritosAposLaser(int num) {

	for (int i = 0; i < num; i++)
		if (rand() % 1 == 0)
			num -= 1;

	return num;
}
bool EscudoOnOff(Nave& nave){

	for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 5; c++) {
			if (nave.RetornaSala(l, c)->ObterForca() > 0)
				return true;
		}
	}

	return false;
}
Sala *SalaRandom(Nave& nave) {

	int l, c;

	do {
		l = rand() % 3;
		c = rand() % 5;

	} while (nave.RetornaSala(l, c) != nullptr);

	return nave.RetornaSala(l,c);
}

void ChuvaMeteroritos(Nave& nave) {

	int N_meteoritos;
		
	if ( PonteOperada(nave) ) {
		N_meteoritos = 4 + rand() % 4;
		if ( TemRaioLaser(nave) ) {
			MeteoritosAposLaser(N_meteoritos);
			if ( TemEscudo(nave) ) {
				if (EscudoOnOff(nave)) {
					nave.RetornaSala(1, 3)->Danificar();
				}
				else{ 
					nave.RetornaSala(1, 3)->Danificar();
					SalaRandom(nave)->Brecha();
				}
			}
		}
	}
	else{
		N_meteoritos = 6 + rand() % 6;
		if ( TemRaioLaser(nave) ) {
			MeteoritosAposLaser(N_meteoritos);
			if ( TemEscudo(nave) ) {
				if (EscudoOnOff(nave)) {
					nave.RetornaSala(1, 3)->Danificar();
				}
				else {
					nave.RetornaSala(1, 3)->Danificar();
					SalaRandom(nave)->Brecha();
				}
			}
		}
	}		
}

void AtaquePiratas(Nave& nave) {


}

void AtaqueXenomorfo(Nave& nave) {

}

void CampoPoCosmico(Nave& nave) {

}

int main(void) {

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
		//flamejantes
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
				AtaquePiratas(nave);
				break;
			case 2:
				//
				AtaqueXenomorfo(nave);
				break;
			case 3:
				//
				CampoPoCosmico(nave);
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
