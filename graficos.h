#ifndef GRAFICOS_H
#define GRAFICOS_H

void atualizarOutput(Consola& c, string* o, int tam = 1);
void atualizarListaUnidades();
void atualizarListaInimigos();
void atualizarTextoSala(Consola& consola, Nave& nave, int x, int y);
void desenharSala(Consola& c, int mx, int my, int l, int a);
void desenharNave(Consola& c, Nave& nave);

#endif