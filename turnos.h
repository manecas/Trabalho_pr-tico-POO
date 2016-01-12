#ifndef TURNOS_H
#define TURNOS_H

void inicioTurno(Nave& nave);

void faseDeOrdens(Consola& consola, Nave& nave);

void ftEfeitosAmbientais(Nave& nave);
void ftSalas(Nave& nave);
void ftXenmorfos(Nave& nave);
void ftInimigos(Nave& nave);
void ftTripulacao(Nave& nave);

Sala *SalaRandom(Nave& nave);
void ChuvaMeteroritos(Nave& nave);
void AtaquePiratas(Consola& c, Nave& nave);
void AtaqueXenomorfo(Nave& nave);
void CampoPoCosmico(Nave& nave);

#endif