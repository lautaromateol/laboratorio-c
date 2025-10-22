#ifndef MAPA_H
#define MAPA_H
#include "cola.h"

#define filas 5
#define columnas 5
#define pared '*'
#define libre '.'
#define recorrido '+'
#define rob 'R'
#define dest 'D'

void inicializarMapa(char mapa[filas][columnas], Posicion robot, Posicion destino);
void imprimirMapa(char mapa[filas][columnas]);

#endif

