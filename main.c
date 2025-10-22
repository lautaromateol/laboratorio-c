#include <stdio.h>
#include "cola.h"
#include "mapa.h"
#include "auxiliares.h"

int main()
{
    char mapa[filas][columnas];
    Posicion padres[filas][columnas];
    bool visitados[filas][columnas] = {false};

    Posicion robot = {1, 1};
    Posicion destino = {3, 3};

    inicializarPadres(padres);
    inicializarMapa(mapa, robot, destino);
    imprimirMapa(mapa);

    Cola* cola = crearCola();
    encolar(cola, robot);
    visitados[robot.x][robot.y] = true;

    while (!estaVacia(cola))
    {
        Posicion actual = desencolar(cola);

        if (actual.x == destino.x && actual.y == destino.y)
        {
            printf("Destino encontrado.\n");
            break;
        }

        int vx[] = {-1, 1, 0, 0};
        int vy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++)
        {
            Posicion vecino = {actual.x + vx[i], actual.y + vy[i]};
            if (esValido(vecino, mapa, visitados))
            {
                padres[vecino.x][vecino.y] = actual;
                visitados[vecino.x][vecino.y] = true;
                encolar(cola, vecino);
            }
        }
    };

    Posicion camino[filas * columnas];
    int pasos = 0;
    camino[pasos++] = destino;
    int i = destino.x;
    int j = destino.y;
    while (padres[i][j].x != -1 && padres[i][j].y != -1)
    {
        camino[pasos++] = padres[i][j];
        i = padres[i][j].x;
        j = padres[i][j].y;
    }

    for (int i = pasos - 1; i >= 0; i--)
    {
        printf("(%d, %d)\n", camino[i].x, camino[i].y);
    }

    mostrarCamino(mapa, pasos, camino);

    liberarCola(cola);
    return 0;
}
