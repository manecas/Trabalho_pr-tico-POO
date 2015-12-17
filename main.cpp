#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;
using std::vector;

#include "nave.h"
#include "unidades.h"

//eventos
int MeteoritosAposLaser(int num) {

	for (int i = 0; i < num; i++)
		if (rand() % 1 == 0)
			num -= 1;

	return num;
}

Sala *SalaRandom(Nave& nave) {

	int l, c;

	do {
		l = rand() % 3;
		c = rand() % 5;

	} while (nave.getSala(l, c) == nullptr);

	return nave.getSala(l,c);
}

void ChuvaMeteroritos(Nave& nave) {

	int N_meteoritos;
	Sala* sala;
	//ponte operada
	sala = nave.getSalaByTipo(PONTE);

	if (sala->isOperada())		N_meteoritos = 4 + rand() % 4;
	else						N_meteoritos = 6 + rand() % 6;
		
	if (nave.getSalaByTipo(RAIO_LASER) != nullptr) {
		//acho que podes por o codigo de MeteoritosAposLaser aqui, nao é assim tao grande
		//MeteoritosAposLaser(N_meteoritos);

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
		tmpSala->setIntegridade(sala->getIntegridade() - 10 * N_meteoritos);
		tmpSala->setBrecha(true);
	}
}

void AtaquePiratas(Nave& nave) {


}

void AtaqueXenomorfo(Nave& nave) {

}

void CampoPoCosmico(Nave& nave) {

}
//fim eventos
void definirTripulacao(Nave& nave) {

	Sala* sala;
	vector<Unidades*> u;
	int tCapitao = 0, tRobot = 0;
	nave.getAllUnidades(u);
	//
	if ((sala = nave.getSalaByTipo(ROBOTICA)) != nullptr) {
		//
		for (int a = 0; a != u.size(); a++) {
			if (u[a]->getNome() == MEMBRO) {
				delete u[a];
				u[a] = new Robot;
				tRobot = 1;
				break;
			}
		}
	}
	if ((sala = nave.getSalaByTipo(ALUJAMENTOCAP)) != nullptr) {
		//
		for (int a = 0; a != u.size(); a++) {
			if (u[a]->getNome() == MEMBRO) {
				delete u[a];
				u[a] = new Capitao;
				tCapitao = 1;
				break;
			}
		}
	}
	cout << "A sua nave tem " << u.size() << " tripulantes." << endl;
	cout << "Unidades:" << endl;
	if (tCapitao)
		cout << "1 Capitao" << endl;
	//
	if (tRobot)
		cout << "1 Robot" << endl;
	//
	cout << (u.size() - tCapitao - tRobot) << " Membro(s)" << endl;
}

void definirSalasAdicionais(Nave& nave) {
	int salasPorDefinir = 6, salaAlterar[2], tBeliches = 0;
	bool temAlujCap = false, temRobotica = false;
	Sala* sala;
	int idSalas[3][5] = {
		{1,	2,	3,	4,	0},
		{0,	5,	6,	7,	8},
		{9,	10,	11,	12,	0}
	};
	/*para obter o x, y será*/
	int posSalas[12][2] = {
		{ 0, 0 },{ 0, 1 },{ 0, 2 },{ 0, 3 },
		{ 1, 1 },{ 1, 2 },{ 1, 3 },{ 1, 4 },
		{ 2, 0 },{ 2, 1 },{ 2, 2 },{ 2, 3 }
	};

	char* nomeSalas[9] = { 
		PROPULSOR, BELICHES,
		RAIO_LASER, AUTOREPARADOR,
		SEGINTERNA,ENFERMARIA,
		SALAARMAS, ALUJAMENTOCAP, ROBOTICA };

	do {
		cout << "A(s) sala(s) ";

		for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 5; c++) {
			//
			if (nave.getSala(l, c) == nullptr) {
				if (!idSalas[l][c]) continue;
				cout << idSalas[l][c] << " ";
			}
		} }

		cout << "ainda nao estao definidas!" << endl;
		cout << "Voce tem disponivel as seguintes salas:" << endl;
		for (int n = 0; n != 9; n++) {
			if (temAlujCap && n == 7) continue;
			if (temRobotica && n == 8) continue;
			//
			cout << n + 1 << " -> " << nomeSalas[n] << endl;
		}

		cout << "Introduza os dados no formato <posicao sala> <id modelo sala>" << endl;

		cin >> salaAlterar[0] >> salaAlterar[1];
		salaAlterar[0] --;

		sala = nave.getSala(posSalas[salaAlterar[0]][0], posSalas[salaAlterar[0]][1]);
		if (sala != nullptr) {
			cout << "Essa sala ja esta definida!" << endl;
		}
		else {
			switch (salaAlterar[1]) {
			case 1:
				sala = new Propulsor;
				break;
			case 2:
				sala = new Beliches;
				tBeliches++;
				break;
			case 3:
				//raio laser
				break;
			case 4:
				//auto reparador
				break;
			case 5:
				//seguranca interna
				break;
			case 6:
				sala = new Enfermaria;
				break;
			case 7:
				//sala armas
				break;
			case 8:
				//alujamento capitao
				temAlujCap = true;
				break;
			case 9:
				sala = new Robotica;
				temRobotica = true;
				break;
			}
		}
		//e necessário condifgSala porque ainda nao foi nada definido
		nave.configSala(posSalas[salaAlterar[0]][0], posSalas[salaAlterar[0]][1], sala);

	} while (--salasPorDefinir > 0);

	//adicionar tripulacao
	for (int t = 0; t != 3 + tBeliches; t++) //ficam todos na ponte
		nave.getSala(1, 4)->addUnidade(new Membro);



	/*se quiseres testar a nave sem ter de definir salas bloqueia o resto do codigo e compila este
	
	nave.configSala(0, 1, new Propulsor);
	nave.configSala(0, 2, new Beliches);
	nave.configSala(0, 3, new Beliches);
	nave.configSala(2, 1, new Robotica);
	nave.configSala(2, 2, new Enfermaria);
	nave.configSala(2, 3, new Propulsor);
	
	for (int t = 0; t != 3 + 2; t++)
		nave.getSala(1, 4)->addUnidade(new Membro);*/
}

int main(void) {
	/*
	http://www.bogotobogo.com/cplusplus/upcasting_downcasting.php
	
	Unidades* b2 = new Capitao;
	Capitao* d = dynamic_cast<Capitao*>(b2);
	Capitao* c = (Capitao*)b2;
	d->Respirar();
	c->Respirar();
	//http://en.cppreference.com/w/cpp/language/dynamic_cast */

	Sala* sala;
	vector<Unidades*> u;
	string nome, comando;
	int dificuldade, mApercorrer, p_evento = 0, t_turnos = 0;
	//
	cout << "Introduza um nome para a sua nave: " << endl;
	getline(cin, nome);
	//
	cout << "Nivel de dificuldade da missao?" << endl;
	cin >> dificuldade;
	//
	Nave nave(nome);
	definirSalasAdicionais(nave);
	definirTripulacao(nave);
	//
	cout << "Vamos dar inicio a viagem!" << endl;
	mApercorrer = 4000 + 1000 * dificuldade;
	std::srand((unsigned int)std::time(0));
	while (1) {
		cout << "Faltam " << mApercorrer << " milhas ate ao fim!" << endl;

		if(mApercorrer <= 0){
			cout << "Fim da brincadeira!" << endl << "Voce ganhou" << endl;
			break;
		}





		//Inicio da turno
		nave.getAllUnidades(u);
		//
		for (int x = 0; x != u.size(); x++) {
			//
			if (u[x]->isRespira())//repirar
				u[x]->getSala()->setOxigenio(-1);
			//
			if (u[x]->isFlamejante())//flamejantes
				u[x]->getSala()->setOxigenio(-5);
		}
			






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

				//pesquisar pela unidade referida

				//verificar se o movimento é válido
			}
		}




		//Final do turno

		//(aqui os acontecimentos devem acontecer pela seguinte ordem)
		//1 – Efeitos ambientais (e.g.; Fogo, curto-circuito) 
		//2 - Salas
		//3 – Xenomorfos
		//4 – Inimigos
		//5 – Tripulação

		//1 – Efeitos ambientais (e.g.; Fogo, curto-circuito) 
		for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 5; c++) {
			if ((sala = nave.getSala(l, c)) != nullptr) {


				if (sala->getFogo()) {
					if (rand() % 1 == 0)//fogo na sala tem 50% de probabilidade de causar 10 pontos de dano
						sala->setIntegridade(-10);

					//e 5% de probabilidade de pegar fogo a salas adjacentes
					//if (rand() % 20 == 0)
					//ou
					//if (rand() % 100 < 5)
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


		//2 - Salas
		bool svida_operavel = false;
		if (nave.getSalaByTipo(SUPORTE_VIDA)->getIntegridade() == 100) {
			//se a sala suporte á vida nao estiver danificada 
			//dá 2 de oxigenio a todas as salas
			svida_operavel = true;
		}
		/*
		-> alteranativa
		bool svida_operavel = (nave.getSalaByTipo(SUPORTE_VIDA)->getIntegridade() == 100);
		*/
		for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 5; c++) {
			if ((sala = nave.getSala(l, c)) != nullptr) {

				if (svida_operavel && !sala->getBrecha())//adicionar oxigenio ás salas
					sala->setOxigenio(2);
					
				
			}
		} }

			
			//recuperar escudo da sala de controlo de escudo
			//recuperar 5 pontos da sala de escudo (caso esteja danificada)


			


		//tripulacao
			//quando um tripulante está numa sala danificada e nao está em combate, repara dois pontos de dano
			//combate o inimigo
		if (nave.getSalaByTipo(SALA_MAQUINAS)->getIntegridade() == 100) {
			//ponte operada e sala das máquinas sem dano, a nave avança
			sala = nave.getSalaByTipo(PONTE);
			if (sala->isOperada())
				mApercorrer -= nave.getDistPercorrer();
		}


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
