#ifndef COLA_H
#define COLA_H
#include <stdbool.h>

typedef struct {
  int x;
  int y;
} Posicion;

typedef struct Nodo {
  Posicion pos;
  struct Nodo* siguiente;
} Nodo;

typedef struct {
  Nodo* inicio;
  Nodo* final;
} Cola;

Cola* crearCola();
void encolar(Cola* cola, Posicion posicion);
Posicion desencolar(Cola* cola);
bool estaVacia(Cola* cola);
void liberarCola(Cola* cola);

#endif