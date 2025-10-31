#ifndef MAPA_H
#define MAPA_H
#include "cola.h"
#define pared '*'
#define libre '.'
#define recorrido '+'
#define rob 'R'
#define dest 'D'

extern int filas;
extern int columnas;

void inicializarMapa(char mapa[filas][columnas], Posicion robot, Posicion destino);
void imprimirMapa(char mapa[filas][columnas]);

#endif

