#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(void){
    int vertices, arestas, aux1, aux2;

    scanf("%d %d", &vertices, &arestas);

    GRAFO *grafo=grafo_criar(vertices);

    for(int i=0; i<arestas; i++){
        int dist;

        scanf("%d %d %d", &aux1, &aux2, &dist);

        insere_aresta_grafo(grafo, aux1, aux2, dist);
    }

    imprimir(grafo);

return (0);
}