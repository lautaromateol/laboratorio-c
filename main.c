#include <stdio.h>
#include "cola.h"
#include "mapa.h"

int main() {
    printf("=== PROBANDO LA COLA ===\n");
    Cola* cola = crearCola();
    
    Posicion p1 = {1, 1};
    Posicion p2 = {2, 2};
    Posicion p3 = {3, 3};
    
    printf("Encolando posiciones...\n");
    encolar(cola, p1);
    encolar(cola, p2);
    encolar(cola, p3);
    
    printf("Desencolando...\n");
    while (!estaVacia(cola)) {
        Posicion pos = desencolar(cola);
        printf("Posicion: (%d, %d)\n", pos.x, pos.y);
    }
    
    liberarCola(cola);
    
    // Probar el mapa
    printf("\n=== MAPA ===\n");
    char mapa[filas][columnas];
    Posicion robot = {1, 1};
    Posicion destino = {3, 3};
    
    inicializarMapa(mapa, robot, destino);
    imprimirMapa(mapa);
    
    return 0;
}