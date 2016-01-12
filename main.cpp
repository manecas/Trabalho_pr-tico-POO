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
using std::ostringstream;

#include "consola.h"
//tem de ficar em primeiro senao faz conflito
//com nome de um typedef da API do windows
//que está incluido em windows.h que está na consola.h
#include "sala.h"
#include "unidades.h"
#include "nave.h"
#include "turnos.h"
#include "graficos.h"


void definirTripulacao(Consola& consola, Nave& nave, int tbeliches) {

	int tCapitao = 0, tRobot = 0, tTripulantes = (3 + tbeliches), nl = 0;
	Sala* sala = nave.getSala(1, 4);
	if (nave.getSalaByTipo(ROBOTICA) != nullptr) {
		Unidades* uni = new Robot;
		sala->addUnidade(uni);
		tRobot = 1;
	}
	if (nave.getSalaByTipo(ALUJAMENTOCAP) != nullptr) {
		Unidades* uni = new Capitao;
		sala->addUnidade(uni);
		tCapitao = 1;
	}
	consola.setScreenSize(40, 150);
	consola.clrscr();
	consola.gotoxy(60, 15);
	cout << "A sua nave tem " << tTripulantes << " tripulantes.";
	consola.gotoxy(60, 16);
	cout << "Unidades:";
	if (tCapitao) {
		consola.gotoxy(60, 17);
		cout << "1 Capitao";
		nl++;
	}
	//
	if (tRobot) {
		consola.gotoxy(60, 17 + nl);
		cout << "1 Robot";
		nl++;
	}
	//
	tTripulantes -= (tCapitao + tRobot); //so membros
	consola.gotoxy(60, 17 + nl);
	cout << tTripulantes << " Membro(s)";

	for (int t = 0; t != tTripulantes; t++) {
		Unidades* uni = new Membro;
		sala->addUnidade(uni);
	}
	consola.gotoxy(60, 19 + nl);
	cout << "Pressione qualquer tecla para continuar";
	consola.getch();
}
void definirSalasAdicionais(Consola& consola, Nave& nave) {
	/*int salasPorDefinir = 6, salaAlterar[2], tBeliches = 0;
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
		consola.gotoxy(110, 3);
		cout << "Voce tem disponivel as seguintes salas:" << endl;
		for (int x = 0; x < 9; x++) {
			consola.gotoxy(110, 4 + x);
			cout << "                            ";
		}
		for (int n = 0, x = 0; n != 9; n++) {
			if (temAlujCap && n == 7) continue;
			if (temRobotica && n == 8) continue;
			//
			consola.gotoxy(110, 4 + (x++));
			cout << n + 1 << " -> " << nomeSalas[n];
		}

		consola.gotoxy(5, 23);
		cout << "A(s) sala(s) ";

		for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 5; c++) {
			//
			if (nave.getSala(l, c) == nullptr) {
				if (!idSalas[l][c]) continue;
				cout << idSalas[l][c] << " ";
			}
		} }

		cout << "ainda nao estao definidas!			";
		consola.gotoxy(5, 24);
		cout << "Introduza os dados no formato <posicao sala> <id modelo sala>";
		consola.gotoxy(5, 25);
		cout << "                ";
		consola.gotoxy(5, 25);
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
				novaSala = new Sala(RAIO_LASER);
				break;
			case 4:
				novaSala = new Sala(AUTOREPARADOR);
				break;
			case 5:
				novaSala = new Sala(SEGINTERNA);
				break;
			case 6:
				sala = new Enfermaria;
				break;
			case 7:
				novaSala = new Sala(SALAARMAS);
				break;
			case 8:
				novaSala = new Sala(ALUJAMENTOCAP);
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
		atualizarTextoSala(consola, nave, posSalas[salaAlterar[0]][0], posSalas[salaAlterar[0]][1]);
	} while (--salasPorDefinir > 0);

	//adicionar tripulacao
	definirTripulacao(consola, nave, tBeliches);*/

	
	//para testar a nave de forma rápida
	
	nave.configSala(0, 1, new Propulsor);
	nave.configSala(0, 2, new Beliches);
	nave.configSala(0, 3, new Beliches);
	nave.configSala(2, 1, new Robotica);
	nave.configSala(2, 2, new Enfermaria);
	nave.configSala(2, 3, new Propulsor);

	definirTripulacao(consola, nave, 2);
}
void apresentarTutorial(Consola& c) {

}
void iniciarJogo(Consola& c, Nave& nave) {
	
	char tecla;
	string nome;
	int dificuldade = 1;

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

	//perguntar se desejar ver tutorial
	c.gotoxy(50, 10);
	cout << "Deseja ver um tutorial?";
	c.gotoxy(48, 12);
	cout << "(Enter) -> Sim | (Esc) -> Nao";

	tecla = c.getch();
	if (tecla == c.ENTER)
		apresentarTutorial(c);

	c.clrscr();
	c.gotoxy(45, 10);
	cout << "Introduza um nome para a sua nave: ";
	do {
		c.gotoxy(55, 12);
		getline(cin, nome);
	} while (nome.empty());
	//
	c.gotoxy(30, 10);
	cout << "Nivel de dificuldade da missao? (Use as teclas esquerda e direita)";
	c.gotoxy(55, 12);
	cout << "                   "; //limpar o nome da nave

	do {
		c.gotoxy(55, 12);
		if (dificuldade > 1)
			cout << "< ";
		else
			cout << "  ";
		cout << dificuldade << " >";

		tecla = c.getch();

		if (tecla == c.ESQUERDA && dificuldade > 1) dificuldade--;
		if (tecla == c.DIREITA) dificuldade++;

	} while (tecla != c.ENTER);
	//

	c.setScreenSize(30, 150);
	c.setBackgroundColor(c.PRETO);
	c.setTextColor(c.BRANCO);
	c.clrscr();

	//
	nave.config(nome, dificuldade);
	desenharNave(c, nave);
	definirSalasAdicionais(c, nave);
	//
	c.setScreenSize(40, 150);
	c.setBackgroundColor(c.PRETO);
	c.clrscr();
	desenharNave(c, nave);

	c.gotoxy(110, 3);
	cout << "Suas Unidades:";
	atualizarListaUnidades();
	c.gotoxy(110, 15);
	cout << "Unidades Inimigas:";
	atualizarListaInimigos();

	c.gotoxy(5, 26);
	cout << "Output:";
	c.gotoxy(5, 23);
	cout << "Ordens:";
}

int main() {

	vector<Unidades*> u, mist;
	int p_evento = 0, t_turnos = 0;
	string* send;
	Consola c;
	Nave nave;

	iniciarJogo(c, nave);
	//
	std::srand((unsigned int)std::time(0));
	while (1) {
		ostringstream oss;
		if (nave.isNaveDestruida()) {
			//cout << "Uma sala foi destruida, perdeste o jogo!" << endl;
			//é preciso limpar o ecra e mostrar uma mensagem no meio a dizer
			//que perdeu o jogo
			break;
		}
		if (nave.getDistPercorrer() <= 0) {
			cout << "Fim da brincadeira!" << endl << "Voce ganhou" << endl;
			//mesma voida do anterior mas a dizer que ganhou
			break;
		}
		//
		u.clear();
		nave.getAllTripulacao(u);
		if (u.empty()) {
			//cout << "Todas as unidades morreram, voce perdeu o jogo!" << endl;
			//mesam coisa dos anteriores
			break;
		}
		oss << "Faltam " << nave.getDistPercorrer() << " milhas ate ao fim!";
		send = new string[1];
		send[0] = oss.str();
		atualizarOutput(c, send);
		//Viagem acaba se não houverem tripulantes nenhuns na nave
		//Inicio da turno
		inicioTurno(nave);
		//Fase de ordens
		faseDeOrdens(c, nave);
		//Final do turno
		ftEfeitosAmbientais(nave);
		ftSalas(nave);
		ftXenmorfos(nave);
		ftInimigos(nave);
		ftTripulacao(nave);

		u.clear();
		nave.getAllTripulacao(u);
		//reaparece misterioso (nao testado)
		for (vector<Unidades*>::const_iterator it = mist.begin();
			it < mist.end(); it++) {

			Sala* sala = SalaRandom(nave);
			sala->addUnidade(*it);
		}
		//desaparece misterioso (nao testado)
		for (vector<Unidades*>::const_iterator it = u.begin();
			it < u.end(); it++) {
			if ((*it)->isMisterioso()) {
				//
				(*it)->getSala()->removerUnidade((*it)->getID());
				(*it)->setSala(nullptr);
			}
		}

		//Eventos
		if (!t_turnos || t_turnos == p_evento) {
			AtaquePiratas(c, nave);
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
			p_evento = 10 + rand() % 5;
		}
		t_turnos++;
	}
	//lipar tudo o que está em memoria dinamica
	//destrutor da nave

	cout << "Fim";
	
	return 0;
}