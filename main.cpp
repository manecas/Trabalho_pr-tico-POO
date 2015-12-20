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

//inicio do turno

//eventos
/*bool PonteOperada(Nave& nave) {

	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		if (nave.getSala(l, c)->getTipo() != "Ponte")
			continue;

		vector<Unidades*> unidades;
		nave.getSala(l, c)->getUnidades(unidades);
		if (unidades.size() > 0)
			return true;

	} }

	return false;
}
bool TemRaioLaser(Nave& nave) {

	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		if (nave.getSala(l, c)->getTipo() == "Raio Laser")
			return true;
	} }

	return false;
}
bool TemEscudo(Nave& nave) {

	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		if (nave.getSala(l, c)->getTipo() == "Controlo de Escudo")
			return true;
	} }

	return false;
}*/
int MeteoritosAposLaser(int num) {

	for (int i = 0; i < num; i++)
		if (rand() % 1 == 0)
			num -= 1;

	return num;
}
/*bool EscudoOnOff(Nave& nave){

	for (int l = 0; l < 3; l++) {
	for (int c = 0; c < 5; c++) {
		if (nave.getSala(l, c)->getTipo() == "Controlo de Escudo") {
			Escudo *e = (Escudo*)nave.getSala(l, c); //como só a sala de escudo é que vai ter força, entao interessa mais fazer um cast que usar virtual na class sala
			if (e->getForca() > 0)
				return true;
		}
	} }

	return false;
}*/
Sala *SalaRandom(Nave& nave) {

	int l, c;

	do {
		l = rand() % 3;
		c = rand() % 5;

	} while (nave.getSala(l, c) == nullptr);

	return nave.getSala(l,c);
}

bool ChuvaMeteroritos(Nave& nave) {

	int N_meteoritos;
	Sala* sala;
	//ponte operada
	if ((sala = nave.getSalaByTipo(PONTE)) != nullptr) {

		if (sala->isOperada())		N_meteoritos = 4 + rand() % 4;
		else						N_meteoritos = 6 + rand() % 6;
	}
		
	if (nave.getSalaByTipo(RAIO_LASER) != nullptr) {
		//acho que podes por o codigo de MeteoritosAposLaser aqui, nao é assim tao grande

		for (int i = 0, x = N_meteoritos; i < x; i++)
			if (rand() % 1 == 0)
				N_meteoritos -= 1;

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

	if (sala->getIntegridade() <= 0)
		return true;

	return false;
}

void AtaquePiratas(Nave& nave) {



}

void AtaqueXenomorfo(Nave& nave) {

}

void CampoPoCosmico(Nave& nave) {

}

void definirTripulacao(Nave& nave) {

	int tipo, x, y;
	Unidades* unidade = new Unidades;
	Sala* sala;
	string charc;
	while (1) {
		cout << "A sua nave tem " << nave.getTotalUnidades() << " tripulantes." << endl
			<< "Pretende adicionar mais? (s/n)" << endl;

		cin >> charc;
		if (charc == "n")
			break;

		do {
			cout << "Qual tipo deseja adicionar?" << endl
				<< "1 - Capitao" << endl
				<< "2 - Tripulante" << endl
				<< "3 - (Sair sem adicionar)" << endl;

			cin >> tipo;

			switch (tipo) {
			case 1:
				unidade = new Capitao;
				break;
			case 2:
				unidade = new Membro;
				break;
			case 3:
				break;
			default:
				tipo = -1;
				cout << "Unidade invalida!" << endl;
				break;
			}

			if (tipo != 3) {
				do {
					cout << "Introduza a posicao no formato 'x y' da sala " <<
						"em que pretende introduzir a unidade:" << endl;
					cin >> x >> y;

					if ((sala = nave.getSala(x, y)) == nullptr)
						cout << "Sala invalida!" << endl;
					else break;

				} while (1);

				sala->addUnidade(unidade);
				//nave.configSala(x, y, sala);

			}
			//cout << unidade->getAsString().c_str();
			//cout << sala->getAsString().c_str();

		} while (tipo == -1);

	}
}

int main(void) {



	/*
	http://www.bogotobogo.com/cplusplus/upcasting_downcasting.php
	*/


	/*Unidades* b2 = new Capitao;
	Capitao* d = dynamic_cast<Capitao*>(b2);
	Capitao* c = (Capitao*)b2;
	d->Respirar();
	c->Respirar();
	//http://en.cppreference.com/w/cpp/language/dynamic_cast */

	Sala* sala;
	string nome, comando;
	int dificuldade, mApercorrer, p_evento = 0, t_turnos = 0;
	bool NaveDestruida = false;

	cout << "Introduza um nome para a sua nave: " << endl;
	getline(cin, nome);

	cout << "Nivel de dificuldade da missao?" << endl;
	cin >> dificuldade;

	Nave nave(nome);

	//preparar a viagem
	//definir salas opcionais

	definirTripulacao(nave); //definir tripulacao

	cout << "Vamos dar inicio á viagem!" << endl;
	mApercorrer = 4000 + 1000 * dificuldade;//mais simples ? (distancia até ao fim)
	std::srand((unsigned int)std::time(0));
	while (1) {
		cout << mApercorrer << " milhas ate ao fim!" << endl;//assim nao sao necessario calculos aqui

		if (mApercorrer <= 0) {//e aqui
			cout << "Fim da brincadeira!" << endl << "Voce ganhou!" << endl;
			break;
		}

		if (NaveDestruida) {
			cout << "Uma sala foi destruida, perdeste o jogo!" << endl;
			break;
		}





		//Inicio da turno
			//flamejantes
			//repirar (unidade perde vida se estiver em sala com fogo)
			






		//Fase de ordens
		while (1) {
			cout << "Introduza comando para nova ordem ('ajuda' para ver comandos):";
			//cin.ignore();
			getline(cin, comando);
			if (comando == "terminar") {
				break;
			}
			else if (comando == "ajuda") {
				cout << "Comandos disponiveis:" << endl
					<< "Ajuda" << endl
					<< "Mover <NomeUnidade> <Direcao>" << endl
					<< "Terminar (nao inserir mais ordens)" << endl;
			}
			else if (!comando.find("mover")) {
				char nomeUnidade[45], direcao[20];
				std::sscanf(comando.c_str(), "%*s %s %s", nomeUnidade, direcao);

				cout << nomeUnidade << "-" << direcao << endl;
			}
		}








		//Final do turno
			//adicionar oxigenio ás salas
			//recuperar escudo da sala de controlo de escudo
			//fogo na sala tem 50% de probabilidade de causar 10 pontos de dano
			//e 5% de probabilidade de pegar fogo a salas adjacentes
			//probabilidade de sofrer 25% de dano por estar numa sala com c-circuito
			//recuperar 5 pontos da sala de escudo (caso esteja danificada)


			//(aqui os acontecimentos devem acontecer pela seguinte ordem)
			//1 – Efeitos ambientais (e.g.; Fogo, curto-circuito) 
			//2 - Salas
			//3 – Xenomorfos
			//4 – Inimigos
			//5 – Tripulação


		//ponte operada
		if ((sala = nave.getSalaByTipo(PONTE)) != nullptr) {
			int tripulacao = 0;
			vector<Unidades*> unidades;
			sala->getUnidades(unidades);

			for (int u = 0; u != unidades.size(); u++) {
				//verificar se as unidades contêm a class tripulacao
				//basta encontrar a primeira e o ciclo termina
				//a sala é considerada operada
			}
		}
		mApercorrer -= nave.distPercorrer();
		//Eventos


		if (!t_turnos || t_turnos == p_evento) {
			switch (rand() % 4)
			{
			case 0:
				//
				NaveDestruida = ChuvaMeteroritos(nave);
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
