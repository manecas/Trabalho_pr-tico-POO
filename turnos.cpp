#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::string;

#include "nave.h"
#include "unidades.h"
#include "turnos.h"


//inicio do turno
void inicioTurno(Nave& nave) {
	vector<Unidades*> u;
	Sala* sala;
	int tmpVal;
	nave.getAllUnidades(u);
	for (int x = 0; x != u.size(); x++) {
		//
		sala = u[x]->getSala();
		if (u[x]->isRespira()) { //repirar
			if (sala->getOxigenio() > 0)
				sala->setOxigenio(-1);
			else
				u[x]->setPV(-1);
		}
		//
		if (u[x]->isFlamejante()) //flamejantes
			u[x]->getSala()->setOxigenio(-5);
		
		if ((tmpVal = u[x]->isMove()) != 0) {
			if (rand() % 100 < tmpVal) {
				Sala* novaSala;
				do {
					switch (rand() % 4) {
					case 0://n
						novaSala = nave.getSalaAdjacente(sala, 'n');
						break;
					case 1://s
						novaSala = nave.getSalaAdjacente(sala, 's');
						break;
					case 2://e
						novaSala = nave.getSalaAdjacente(sala, 'e');
						break;
					case 3://o
						novaSala = nave.getSalaAdjacente(sala, 'o');
						break;
					}
				} while (novaSala == nullptr);
				//
				sala->moverUnidade(u[x]->getNome(), novaSala);
			}
		}
	}
}
//fase de ordens
void faseDeOrdens(Nave& nave) {
	string comando;
	vector<Unidades*> u;
	Sala* sala;

	cout << "Introduza comando para nova ordem ('ajuda' para ver comandos): " << endl;
	while (1) {
		getline(cin, comando);
		if (comando.empty()) continue;
		if (comando == "terminar") {
			break;
		}
		else if (comando == "ajuda") {
			cout << endl << "Comandos disponiveis:" << endl
				<< "ajuda" << endl
				<< "mover <InicialNomeUnidade> <Direcao>" << endl
				<< "terminar (nao inserir mais ordens)" << endl << endl;
		}
		else if (!comando.find("mover")) {
			Unidades* encontrou = nullptr;
			string nomeUnidade, direcao;
			std::stringstream s(comando);

			//seguindo a logica que divisao por espacos e a primeira palavra e' o comando
			//repete-se nomeUnidade, assim quando o nomeUnidade � usado segunda vez
			//subestitui o primeiro valor
			s >> nomeUnidade >> nomeUnidade >> direcao;

			if (nomeUnidade.empty()) {
				cout << "Voce nao introduziu o nome da unidade para mover!" << endl;
				continue; //volta ao inicio do while sem executar o codigo daqui para baixo
			}
			if (direcao.empty()) {
				cout << "Voce nao introduziu a direcao para mover!" << endl;
				continue;
			}
			//verificar se unidade existe
			//precisa ser alterado (se existirem 2 membros, move sempre o primeiro)
			u.clear();
			nave.getAllUnidades(u);
			for (int s = 0; s != u.size(); s++) {
				if ((nomeUnidade == "c" || nomeUnidade == "C")
					&& u[s]->getNome() == CAPITAO) {
					//
					encontrou = u[s];
					break;
				}
				else if ((nomeUnidade == "m" || nomeUnidade == "M")
					&& u[s]->getNome() == MEMBRO) {
					//
					encontrou = u[s];
					break;
				}
				else if ((nomeUnidade == "r" || nomeUnidade == "R")
					&& u[s]->getNome() == ROBOT) {
					//
					encontrou = u[s];
					break;
				}

			}
			if (encontrou == nullptr) {
				cout << "Unidade nao encontrada!" << endl;
				continue;
			}
			//movimento
			if (direcao == "n" || direcao == "N"
				|| direcao == "s" || direcao == "S"
				|| direcao == "e" || direcao == "E"
				|| direcao == "o" || direcao == "O") {
				if ((sala = nave.getSalaAdjacente(encontrou->getSala(), (char)direcao[0])) != nullptr)
					encontrou->getSala()->moverUnidade(encontrou->getNome(), sala);
				else
					cout << "Movimento invalido!" << endl;
			}
		}
		else if (comando == "status") {
			u.clear();
			nave.getAllUnidades(u);
			for (int x = 0; x != u.size(); x++)
				cout << u[x]->getAsString();
		}
		cout << "Introduza comando para nova ordem ('ajuda' para ver comandos):" << endl;
	}
}
//fim do turno
void ftEfeitosAmbientais(Nave& nave) {
	Sala* sala;
	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		if ((sala = nave.getSala(l, c)) != nullptr) {


			if (sala->getFogo()) {
				if (rand() % 1 == 0)//fogo na sala tem 50% de probabilidade de causar 10 pontos de dano
					sala->setIntegridade(-10);

				//e 5% de probabilidade de pegar fogo a salas adjacentes
				//if (rand() % 20 == 0) ou if (rand() % 100 < 5)
				Sala* sala2;
				if ((sala2 = nave.getSala(l, c + 1)) != nullptr)
					if (rand() % 20 == 0) sala2->setFogo(true);
				if ((sala2 = nave.getSala(l, c - 1)) != nullptr)
					if (rand() % 20 == 0) sala2->setFogo(true);
				if ((sala2 = nave.getSala(l + 1, c)) != nullptr)
					if (rand() % 20 == 0) sala2->setFogo(true);
				if ((sala2 = nave.getSala(l - 1, c)) != nullptr)
					if (rand() % 20 == 0) sala2->setFogo(true);
			}
			if (sala->getCC()) {//25% de probabilidade de sofrer dano por estar numa sala com c-circuito
				if (rand() % 4 == 0) {
					vector<Unidades*> u;
					sala->getUnidades(u);
					for (int x = 0; x != u.size(); x++)
						u[x]->setPV(-1);
				}
			}
		}
	} }
}
void ftSalas(Nave& nave) {
	Sala* sala;
	vector<Unidades*> u;
	bool svida_operavel = false;
	if (nave.getSalaByTipo(SUPORTE_VIDA)->getIntegridade() == 100) {
		//se a sala suporte � vida nao estiver danificada 
		//d� 2 de oxigenio a todas as salas
		svida_operavel = true;
	}
	//	-> alteranativa
	//bool svida_operavel = (nave.getSalaByTipo(SUPORTE_VIDA)->getIntegridade() == 100);

	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		if ((sala = nave.getSala(l, c)) != nullptr) {

			if (svida_operavel && !sala->getBrecha())//adicionar oxigenio �s salas
				sala->setOxigenio(2);

		}
	} }
	sala = nave.getSalaByTipo(ENFERMARIA);
	if (sala->getIntegridade() == 100) {
		sala->getUnidades(u);
		for (int x = 0; x != u.size(); x++) {
			if (u[x]->isTripulacao())
				u[x]->setPV(1);
		}
	}
	if((sala = nave.getSalaByTipo(SALAARMAS)) != nullptr) {
		sala->getUnidades(u);
		for (int x = 0; x != u.size(); x++) {
			if (u[x]->isTripulacao())
				u[x]->setArmado(1);
		}
	}



	//recuperar escudo da sala de controlo de escudo
	//recuperar 5 pontos da sala de escudo (caso esteja danificada)
}
void ftXenmorfos(Nave& nave) {

}
void ftInimigos(Nave& nave) {
	//inimigos atacam tripulacao
	Sala* sala;
	vector<Unidades*> u;

	vector<Unidades*> inimigos[3][5];
	vector<Unidades*> tripOUxeno[3][5]; //inimigos (piratas) atacam tripulacao e xenomorfos
	//obter inimigos e tripulantes em cada sala
	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		//
		if ((sala = nave.getSala(l, c)) == nullptr) continue;
		u.clear();
		sala->getUnidades(u);
		//
		for (int x = 0; x != u.size(); x++) {
			if (u[x]->isTripulacao() || u[x]->isXenomorfo())	tripOUxeno[l][c].push_back(u[x]);
			else												inimigos[l][c].push_back(u[x]);
		}
	} }
	//cruzar informacao
	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		//
		if ((sala = nave.getSala(l, c)) == nullptr) continue;
		for (unsigned int x = 0; x < inimigos[l][c].size(); x++) {
			if (tripOUxeno[l][c].size() > 0) {
				//nao � necess�rio verificar se e combatente (toda a tripulacao e combatente)
				//se existirem inimigos escolhe um aleatorio para lutar
				int a = rand() % tripOUxeno[l][c].size();
				//provoca x dano no inimigo
				tripOUxeno[l][c][a]->setPV(-inimigos[l][c][x]->isInimigo());
				//
				tripOUxeno[l][c].clear();
			}
			else {
				sala->setIntegridade(-2);
				if (sala->getTipo() == CONTROLO_ESCUDO
					&& sala->getIntegridade() > 97) {
					//
					Escudo* e = (Escudo*)sala;
					e->setEscudo(false);
				}
			}
		}
	} }
}
void ftTripulacao(Nave& nave) {
	Sala* sala;
	vector<Unidades*> u;

	vector<Unidades*> inimigos[3][5];
	vector<Unidades*> tripulacao[3][5];

	//quando um tripulante est� numa sala danificada e nao est� em combate, repara dois pontos de dano
	//combate o inimigo
	if (nave.getSalaByTipo(SALA_MAQUINAS)->getIntegridade() == 100) {
		//ponte operada e sala das m�quinas sem dano, a nave avan�a
		sala = nave.getSalaByTipo(PONTE);
		if (sala->isOperada())
			nave.updateDistPercorrer();
	}
	//tripulacao ataca inimigos
	//obter inimigos e tripulantes em cada sala
	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		//
		if ((sala = nave.getSala(l, c)) == nullptr) continue;
		u.clear();
		sala->getUnidades(u);
		//
		for (int x = 0; x != u.size(); x++) {
			if (u[x]->isTripulacao())	tripulacao[l][c].push_back(u[x]);
			else						inimigos[l][c].push_back(u[x]);
		}
	} }
	//cruzar informacao
	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		//
		if ((sala = nave.getSala(l, c)) == nullptr) continue;
		for (unsigned int x = 0; x < tripulacao[l][c].size(); x++) {
			//robot numa sala com circuito nao faz nada
			if (u[x]->getNome() == ROBOT && sala->getCC()) continue;
			if (inimigos[l][c].size() > 0) {
				//nao � necess�rio verificar se e combatente (toda a tripulacao e combatente)
				//se existirem inimigos escolhe um aleatorio para lutar
				int a = rand() % inimigos[l][c].size();
				//provoca x dano no inimigo
				inimigos[l][c][a]->setPV(
					-(tripulacao[l][c][x]->isCombatente()
						+ tripulacao[l][c][x]->isArmado())
					);
				//
				inimigos[l][c].clear();
			}
			else {
				//se nao ha inimigos nao estao em combante, logo reparam a sala
				if (sala->getIntegridade() < 100)
					sala->setIntegridade(tripulacao[l][c][x]->isReparador());
				//se nao for reparador, como o robot, retorna 0, nao faz diferenca
				if (sala->getTipo() == CONTROLO_ESCUDO
					&& sala->getIntegridade() == 100) {
					//
					Escudo* e = (Escudo*)sala;
					e->setEscudo(true);
				}
			}
		}
	} }
}
//eventos
Sala *SalaRandom(Nave& nave) {

	int l, c;

	do {
		l = rand() % 3;
		c = rand() % 5;

	} while (nave.getSala(l, c) == nullptr);

	return nave.getSala(l, c);
}
void ChuvaMeteroritos(Nave& nave) {

	int N_meteoritos;
	Sala* sala;
	sala = nave.getSalaByTipo(PONTE);

	if (sala->isOperada())		N_meteoritos = 4 + rand() % 4;
	else						N_meteoritos = 6 + rand() % 6;

	if (nave.getSalaByTipo(RAIO_LASER) != nullptr) {
		for (int i = 0, x = N_meteoritos; i < x; i++) {
			if (rand() % 1 == 0)
				N_meteoritos -= 1;
		}
	}

	sala = nave.getSalaByTipo(CONTROLO_ESCUDO);
	Escudo *e = (Escudo*)sala;

	if (e->getForca() > 0) { //escudo ativo

		sala->setIntegridade(sala->getIntegridade() - 10 * N_meteoritos);
	}
	else {

		Sala* tmpSala = SalaRandom(nave);
		sala->setIntegridade(sala->getIntegridade() - 10 * N_meteoritos);
		tmpSala->setBrecha(true);
	}
}
void AtaquePiratas(Nave& nave) {

	Sala* sala;
	Escudo *e;
	int danoPiratas;
	sala = nave.getSalaByTipo(CONTROLO_ESCUDO);
	e = (Escudo*)sala;
	danoPiratas = 30 + rand() % 30;
	if (danoPiratas - e->getForca() > 0) {
		//se o escudo resistir ao ataque, s� perde forca
		e->setForca(-danoPiratas);
	}
	else {
		//se a forca de escudo nao for suficiente para resistir ao ataque
		//perde o excudo e causa um problema numa sala aleatoria
		e->setForca(-danoPiratas);
		sala = SalaRandom(nave);
		switch (rand() % 3) {
		case 0:
			sala->setBrecha(true);
			break;
		case 1:
			sala->setFogo(true);
			break;
		case 2:
			sala->setCC(true);
			break;
		}
	}
	if (nave.getSalaByTipo(RAIO_LASER) == nullptr) {
		//se nao houver uma sala raio laser, os piratas entram na nave
		sala = SalaRandom(nave);
		int p = 0;
		while (p++ < 3 + rand() % 3) {
			Unidades* pirata = new Pirata;
			sala->addUnidade(pirata);
		}
	}
}
void AtaqueXenomorfo(Nave& nave) {

}
void CampoPoCosmico(Nave& nave) {

}