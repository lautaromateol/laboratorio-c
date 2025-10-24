#ifndef AUXILIARES_H
#define AUXILIARES_H
#include "cola.h"
#include "mapa.h"

int leerCoordenadas(const char* mensaje, int min, int max);
bool esValido(Posicion vecino, char mapa[filas][columnas], bool visitados[filas][columnas]);
void inicializarPadres(Posicion padres[filas][columnas]);
void mostrarCamino(char mapa[filas][columnas], int pasos, Posicion camino[]);

#endif