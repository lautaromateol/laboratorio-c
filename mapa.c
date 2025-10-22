#include <stdio.h>
#include "mapa.h"

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