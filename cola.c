#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

Cola* crearCola()
{
  Cola* nuevaCola = (Cola*)malloc(sizeof(Cola));

  nuevaCola->inicio = NULL;
  nuevaCola->final = NULL;

  return nuevaCola;
};

void encolar(Cola* cola, Posicion posicion)
{
  Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));

  nuevoNodo->pos = posicion;
  nuevoNodo->siguiente = NULL;

  if (cola->inicio == NULL)
  {
    cola->inicio = nuevoNodo;
    cola->final = nuevoNodo;
  }
  else
  {
    cola->final->siguiente = nuevoNodo;
    cola->final = nuevoNodo;
  };
};

bool estaVacia(Cola* cola) {
  return cola->inicio == NULL;
}

Posicion desencolar(Cola* cola) {
  Nodo* nodoAEliminar = cola->inicio;
  Posicion pos = nodoAEliminar->pos;
  cola->inicio = nodoAEliminar->siguiente;

  if(estaVacia(cola)) {
    cola->final = NULL;
  };

  free(nodoAEliminar);

  return pos;
};

void liberarCola(Cola* cola) {
    while (!estaVacia(cola)) {
        desencolar(cola);
    }
    free(cola);
}