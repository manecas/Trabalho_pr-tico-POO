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

#include "consola.h"
//tem de ficar em primeiro senao faz conflito
//com nome de um typedef da API do windows
//que está incluido em windows.h que está na consola.h
#include "nave.h"
#include "unidades.h"
#include "turnos.h"

int Unidades::lastID = 0;

void definirTripulacao(Nave& nave, int tbeliches) {

	int tCapitao = 0, tRobot = 0, tTripulantes = (3 + tbeliches);
	if (nave.getSalaByTipo(ROBOTICA) != nullptr) {
		Unidades* uni = new Robot;
		nave.getSala(1, 4)->addUnidade(uni);
		tRobot = 1;
	}
	if (nave.getSalaByTipo(ALUJAMENTOCAP) != nullptr) {
		Unidades* uni = new Capitao;
		nave.getSala(1, 4)->addUnidade(uni);
		tCapitao = 1;
	}
	cout << "A sua nave tem " << tTripulantes << " tripulantes." << endl;
	cout << "Unidades:" << endl;
	if (tCapitao)
		cout << "1 Capitao" << endl;
	//
	if (tRobot)
		cout << "1 Robot" << endl;
	//
	tTripulantes -= (tCapitao + tRobot); //so membros
	cout << tTripulantes << " Membro(s)" << endl;

	for (int t = 0; t != tTripulantes; t++) {
		Unidades* uni = new Membro;
		nave.getSala(1, 4)->addUnidade(uni);
	}
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
	//para obter o x, y será
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
	definirTripulacao(nave, tBeliches);

	/*
	//para testar a nave de forma rápida
	
	nave.configSala(0, 1, new Propulsor);
	nave.configSala(0, 2, new Beliches);
	nave.configSala(0, 3, new Beliches);
	nave.configSala(2, 1, new Robotica);
	nave.configSala(2, 2, new Enfermaria);
	nave.configSala(2, 3, new Propulsor);

	definirTripulacao(nave, 2);*/
}

int main() {

	vector<Unidades*> u;
	string nome, comando;
	int dificuldade, p_evento = 0, t_turnos = 0;
	Consola c;

	c.setTextColor(c.VERDE_CLARO);
	c.gotoxy(10, 10);
	cout << "Bem-vindo a esta aventura!";
	c.gotoxy(10, 11);
	cout << "O seu objetivo e chegar com a nave ate ao fim da viagem!";
	c.gotoxy(10, 13);
	cout << "Para tal, deve escolher, de forma sabia, cada uma das salas";
	c.gotoxy(10, 14);
	cout << "adicionais da nave. Boa sorte";
	c.gotoxy(10, 17);
	cout << "Carrega numa tecla para continuar";

	c.getch();

	c.setBackgroundColor(c.BRANCO_CLARO);
	c.setTextColor(c.PRETO);
	c.clrscr();

	cout << "Introduza um nome para a sua nave: " << endl;
	getline(cin, nome);
	//
	cout << "Nivel de dificuldade da missao?" << endl;
	cin >> dificuldade;
	//
	Nave nave(nome, dificuldade);
	definirSalasAdicionais(nave);
	//
	cout << "Vamos dar inicio a viagem!" << endl;
	std::srand((unsigned int)std::time(0));
	while (1) {
		u.clear();
		if (nave.isNaveDestruida()) {
			cout << "Uma sala foi destruida, perdeste o jogo!" << endl;
			break;
		}
		if (nave.getDistPercorrer() <= 0) {
			cout << "Fim da brincadeira!" << endl << "Voce ganhou" << endl;
			break;
		}
		//
		nave.getAllUnidades(u);
		if (!u.size()) {
			cout << "Todas as unidades morreram, voce perdeu o jogo!" << endl;
			break;
		}
		cout << "Faltam " << nave.getDistPercorrer() << " milhas ate ao fim!" << endl;
		//Viagem acaba se não houverem tripulantes nenhuns na nave
		//Inicio da turno
		inicioTurno(nave);
		//Fase de ordens
		faseDeOrdens(nave);
		//Final do turno
		ftEfeitosAmbientais(nave);
		ftSalas(nave);
		ftXenmorfos(nave);
		ftInimigos(nave);
		ftTripulacao(nave);

		//Eventos
		if (!t_turnos || t_turnos == p_evento) {
			CampoPoCosmico(nave);
			/*switch (rand() % 4)
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
			}*/
			//evento
			p_evento = 5 + rand() % 5;
		}
		t_turnos++;
	}


	
	return 0;
}
