#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "mapa.h"

int filas;
int columnas;

void inicializarMapa(char mapa[filas][columnas], Posicion robot, Posicion destino)
{
  static int inicializado = 0;
  if (!inicializado)
  {
    srand(time(NULL));
    inicializado = 1;
  }

  for (int i = 0; i < filas; i++)
  {
    for (int j = 0; j < columnas; j++)
    {
      mapa[i][j] = libre;
    }
  }

  for (int i = 0; i < filas; i++)
  {
    mapa[i][0] = pared;
    mapa[i][columnas - 1] = pared;
  }

  for (int j = 0; j < columnas; j++)
  {
    mapa[0][j] = pared;
    mapa[filas - 1][j] = pared;
  }

  for (int i = 0; i < filas; i++)
  {
    for (int j = 0; j < columnas; j++)
    {
      if (i == robot.x && j == robot.y)
      {
        mapa[i][j] = rob;
      }
      else if (i == destino.x && j == destino.y)
      {
        mapa[i][j] = dest;
      }
    }
  }

  for (int i = 1; i < filas - 1; i++)
  {
    for (int j = 1; j < columnas - 1; j++)
    {
      if ((i == robot.x && j == robot.y) || (i == destino.x && j == destino.y))
      {
        continue;
      }
      else
      {
        if (rand() % 100 < 20)
        {
          mapa[i][j] = pared;
        }
      }
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