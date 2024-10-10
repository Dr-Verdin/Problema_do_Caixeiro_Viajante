#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(void){
    int vertices, arestas, aux1, aux2, dist;

    scanf("%d %d", &vertices, &arestas);

    GRAFO *grafo=grafo_criar(vertices);

    for(int i=0; i<arestas; i++){

        scanf("%d %d %d", &aux1, &aux2, &dist);

        grafo_insere_aresta(grafo, aux1, aux2, dist);
    }

    scanf(" %d %d", &aux1, &aux2);

    dist=grafo_get_distancia(grafo, aux1, aux2);

    if(dist>0){
        printf("distancia entre a cidade %d e a %d: %d\n", aux1, aux2, dist);
    }else
    printf("Não existe caminho entre as cidades\n");

    grafo_imprimir(grafo);

    grafo_apagar(&grafo);

    grafo_imprimir(grafo);

return (0);
}