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
#include "turnos.h"

<<<<<<< HEAD
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
=======
void definirTripulacao(Nave& nave, int tbeliches) {
>>>>>>> refs/remotes/origin/master

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
<<<<<<< HEAD
	else {

		Sala* tmpSala = SalaRandom(nave);
		sala->setIntegridade(sala->getIntegridade() - 10 * N_meteoritos);
		tmpSala->setBrecha(true);
=======
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
>>>>>>> refs/remotes/origin/master
	}

	if (sala->getIntegridade() <= 0)
		return true;

	return false;
}
<<<<<<< HEAD

void AtaquePiratas(Nave& nave) {



}

void AtaqueXenomorfo(Nave& nave) {

}

void CampoPoCosmico(Nave& nave) {

}

void definirTripulacao(Nave& nave) {

	int tipo, x, y;
	Unidades* unidade = new Unidades;
=======
void definirSalasAdicionais(Nave& nave) {
	/*int salasPorDefinir = 6, salaAlterar[2], tBeliches = 0;
	bool temAlujCap = false, temRobotica = false;
>>>>>>> refs/remotes/origin/master
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
	for (int t = 0; t != 3 + tBeliches; t++) //ficam todos na ponte
		nave.getSala(1, 4)->addUnidade(new Membro);

*/


	//se quiseres testar a nave sem ter de definir salas bloqueia o resto do codigo e compila este
	
	nave.configSala(0, 1, new Propulsor);
	nave.configSala(0, 2, new Beliches);
	nave.configSala(0, 3, new Beliches);
	nave.configSala(2, 1, new Robotica);
	nave.configSala(2, 2, new Enfermaria);
	nave.configSala(2, 3, new Propulsor);
	

	definirTripulacao(nave, 2);
}

int main() {

	vector<Unidades*> u;
	string nome, comando;
<<<<<<< HEAD
	int dificuldade, mApercorrer, p_evento = 0, t_turnos = 0;
	bool NaveDestruida = false;
=======
	int dificuldade, p_evento = 0, t_turnos = 0;
>>>>>>> refs/remotes/origin/master

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
<<<<<<< HEAD
		cout << mApercorrer << " milhas ate ao fim!" << endl;//assim nao sao necessario calculos aqui

		if (mApercorrer <= 0) {//e aqui
			cout << "Fim da brincadeira!" << endl << "Voce ganhou!" << endl;
			break;
		}

		if (NaveDestruida) {
			cout << "Uma sala foi destruida, perdeste o jogo!" << endl;
=======
		u.clear();
		if (nave.isNaveDestruida()) {
			cout << "Uma sala foi destruida, perdeste o jogo!" << endl;
			break;
		}
		if (nave.getDistPercorrer() <= 0) {
			cout << "Fim da brincadeira!" << endl << "Voce ganhou" << endl;
>>>>>>> refs/remotes/origin/master
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
			AtaquePiratas(nave);
			/*switch (rand() % 4)
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
			}*/
			//evento
			cout << "Evento" << endl;

			p_evento += 5 + rand() % 5;
		}
		t_turnos++;
	}


	
	return 0;
}
