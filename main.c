#include <stdio.h>
#include "cola.h"
#include "mapa.h"
#include "auxiliares.h"

int main()
{
    int robot_x;
    int robot_y;
    int destino_x;
    int destino_y;

    robot_x = leerCoordenadas("Coordenada en X del robot", 1, filas - 2);
    robot_y = leerCoordenadas("Coordenada en Y del robot", 1, columnas - 2);
    destino_x = leerCoordenadas("Coordenada en X del destino", 1, filas - 2);
    destino_y = leerCoordenadas("Coordenada en Y del destino", 1, columnas - 2);

    if (robot_x == destino_x && robot_y == destino_y)
    {
        printf("El robot y el destino no pueden tener las mismas coordenadas.");
        destino_x = leerCoordenadas("Nueva coordenada en X del destino", 1, filas - 2);
        destino_y = leerCoordenadas("Nueva coordenada en Y del destino", 1, columnas - 2);
    }

    char mapa[filas][columnas];
    Posicion padres[filas][columnas];
    bool visitados[filas][columnas];

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            visitados[i][j] = false;
        }
    }

    Posicion robot = {robot_x, robot_y};
    Posicion destino = {destino_x, destino_y};

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

        /*
        actual: (1, 2)
        vecinos: (1, 3)
        */

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

    if (!visitados[destino.x][destino.y])
    {
        printf("No se pudo encontrar un camino al destino.\n");
        liberarCola(cola);
        return 1;
    }

    Posicion camino[filas * columnas];
    int pasos = 0;
    camino[pasos++] = destino;
    int i = destino.x;
    int j = destino.y;
    while (i != -1 && j != -1)
    {
        camino[pasos++] = (Posicion){i, j};
        Posicion temp = padres[i][j];
        i = temp.x;
        j = temp.y;
    }

    for (int i = pasos - 1; i >= 0; i--)
    {
        printf("(%d, %d)\n", camino[i].x, camino[i].y);
    }

    mostrarCamino(mapa, pasos, camino);

    liberarCola(cola);
    return 0;
}
