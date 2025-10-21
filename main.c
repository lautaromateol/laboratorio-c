#include <stdio.h>
#include <stdlib.h>
#define filas 5
#define columnas 5
#define pared '*'
#define libre '.'
#define rob 'R'
#define dest 'D'

typedef struct
{
  int x;
  int y;
} Posicion;

typedef struct Nodo
{
  Posicion pos;
  struct Nodo* siguiente;
} Nodo;

typedef struct
{
  Nodo* inicio;
  Nodo* final;
} Cola;

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

int estaVacia(Cola* cola) {
  return cola->inicio == NULL;
}

Posicion desencolar(Cola* cola) {
  Nodo* nodoAEliminar = cola->inicio;
  Posicion pos = nodoAEliminar->pos;
  cola->inicio = nodoAEliminar->siguiente;

  if(cola->inicio == NULL) {
    cola->final = NULL;
  };

  free(nodoAEliminar);

  return pos;
};

void inicializarMapa(char mapa[filas][columnas], Posicion robot, Posicion destino)
{
  for (int i = 0; i < filas; i++)
  {
    for (int j = 0; j < columnas; j++)
    {
      if (i == 0 || i == filas - 1 || j == 0 || j == columnas - 1 || (i == 2 && j == 2))
      {
        mapa[i][j] = pared;
      }
      else if (i == robot.x && j == robot.y)
      {
        mapa[i][j] = rob;
      }
      else if (i == destino.x && j == destino.y)
      {
        mapa[i][j] = dest;
      }
      else
        mapa[i][j] = libre;
    }
  }
}

void imprimirMapa(char mapa[filas][columnas])
{
  for (int i = 0; i < filas; i++)
  {
    for (int j = 0; j < columnas; j++)
    {
      printf("%c ", mapa[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  char mapa[filas][columnas];
  Posicion robot = {1, 1};
  Posicion destino = {3, 3};

  inicializarMapa(mapa, robot, destino);
  imprimirMapa(mapa);

  return 0;
}