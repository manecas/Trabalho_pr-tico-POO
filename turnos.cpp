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
			//repete-se nomeUnidade, assim quando o nomeUnidade é usado segunda vez
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
				if (nomeUnidade == "c" || nomeUnidade == "C"
					&& u[s]->getNome() == CAPITAO) {
					//
					encontrou = u[s];
					break;
				}
				else if (nomeUnidade == "m" || nomeUnidade == "M"
					&& u[s]->getNome() == MEMBRO) {
					//
					encontrou = u[s];
					break;
				}
				else if (nomeUnidade == "r" || nomeUnidade == "R"
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
	bool svida_operavel = false;
	if (nave.getSalaByTipo(SUPORTE_VIDA)->getIntegridade() == 100) {
		//se a sala suporte á vida nao estiver danificada 
		//dá 2 de oxigenio a todas as salas
		svida_operavel = true;
	}
	//	-> alteranativa
	//bool svida_operavel = (nave.getSalaByTipo(SUPORTE_VIDA)->getIntegridade() == 100);

	for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 5; c++) {
			if ((sala = nave.getSala(l, c)) != nullptr) {

				if (svida_operavel && !sala->getBrecha())//adicionar oxigenio ás salas
					sala->setOxigenio(2);


			}
		}
	}


	//recuperar escudo da sala de controlo de escudo
	//recuperar 5 pontos da sala de escudo (caso esteja danificada)
}
void ftXenmorfos(Nave& nave) {

}
void ftInimigos(Nave& nave) {
	//inimigos atacam tripulacao
}
void ftTripulacao(Nave& nave) {
	Sala* sala;
	vector<Unidades*> u;

	vector<Unidades*> inimigos[3][5] = { { { nullptr } } };
	vector<Unidades*> tripulacao[3][5] = { { { nullptr } } };

	//quando um tripulante está numa sala danificada e nao está em combate, repara dois pontos de dano
	//combate o inimigo
	if (nave.getSalaByTipo(SALA_MAQUINAS)->getIntegridade() == 100) {
		//ponte operada e sala das máquinas sem dano, a nave avança
		sala = nave.getSalaByTipo(PONTE);
		if (sala->isOperada())
			nave.updateDistPercorrer();
	}
	//tripulacao ataca inimigos
	//obter inimigos e tripulantes em cada sala
	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		//
		u.clear();
		nave.getSala(l, c)->getUnidades(u);
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
		for (int x = 0; x != tripulacao[l][c].size(); x++) {
			if (inimigos[l][c].size() > 0) {
				//nao é necessário verificar se e combatente (toda a tripulacao e combatente)
				//se existirem inimigos escolhe um aleatorio para lutar
				int a = rand() % inimigos[l][c].size();
				//provoca x dano no inimigo
				inimigos[l][c][x]->setPV(-tripulacao[l][c][x]->isCombatente());
				//
				inimigos[l][c].clear();
			}
		}
	} }


	//calcular danos de combate (combate acontece aqui)
	//reparar sala se nao estiver em combate
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
bool ChuvaMeteroritos(Nave& nave) {

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

	if (sala->getIntegridade() <= 0)//bem que achei estranho a nave morrer logo no primeiro evento (tinhas >= 0)
		return true;

	return false;

}
void AtaquePiratas(Nave& nave) {

}
void AtaqueXenomorfo(Nave& nave) {

}
void CampoPoCosmico(Nave& nave) {

}