#include <stdio.h>
#include "auxiliares.h"

int leerCoordenadas(const char *mensaje, int min, int max)
{
  int valor;
  do
  {
    printf("\n%s: (%d..%d)\n", mensaje, min, max);
    scanf("%d", &valor);
    if (valor < min || valor > max)
    {
      printf("Valor invalido para la coordenada.");
    }
  } while (valor < min || valor > max);

  return valor;
}

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
    if (mapa[camino[i].x][camino[i].y] != rob && mapa[camino[i].x][camino[i].y] != dest)
    {
      mapaCamino[camino[i].x][camino[i].y] = recorrido;
    }
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