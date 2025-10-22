#include <stdio.h>
#include "auxiliares.h"

bool esValido(Posicion vecino, char mapa[filas][columnas], bool visitados[filas][columnas])
{
  return (vecino.x > 0 && vecino.y > 0) && (vecino.x < filas && vecino.y < columnas) && mapa[vecino.x][vecino.y] != pared && !visitados[vecino.x][vecino.y];
}

void inicializarPadres(Posicion padres[filas][columnas])
{
  for (int i = 0; i < filas; i++)
  {
    for (int j = 0; j < columnas; j++)
    {
      padres[i][j].x = -1;
      padres[i][j].y = -1;
    }
  }
}

void mostrarCamino(char mapa[filas][columnas], int pasos, Posicion camino[])
{
  char mapaCamino[filas][columnas];

  for (int i = 0; i < filas; i++)
  {
    for (int j = 0; j < columnas; j++)
    {
      mapaCamino[i][j] = mapa[i][j];
    }
  }

  for (int i = 1; i < pasos - 1; i++)
  {
    mapaCamino[camino[i].x][camino[i].y] = recorrido;
  }

  for (int i = 0; i < filas; i++)
  {
    for (int j = 0; j < columnas; j++)
    {
      printf("%c ", mapaCamino[i][j]);
    }
    printf("\n");
  }
}