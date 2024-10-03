#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(void){
    int vertices, arestas, aux1, aux2, dist;

    scanf("%d %d", &vertices, &arestas);

    GRAFO *grafo=grafo_criar(vertices);

    for(int i=0; i<arestas; i++){

        scanf("%d %d %d", &aux1, &aux2, &dist);

        insere_aresta_grafo(grafo, aux1, aux2, dist);
    }

    scanf(" %d %d", &aux1, &aux2);

    dist=get_distancia(grafo, aux1, aux2);

    printf("distancia entre a cidade %d e a %d: %d\n", aux1, aux2, dist);

    imprimir(grafo);

    grafo_apagar(&grafo);

    imprimir(grafo);

return (0);
}