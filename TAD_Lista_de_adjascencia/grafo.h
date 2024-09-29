#ifndef GRAFO_H
    #define GRAFO_H

    #include "item.h"

    typedef struct grafo_ GRAFO;

    GRAFO *grafo_criar(int n);
    bool insere_aresta_grafo(GRAFO *grafo, int vertice_1, int vertice_2, int distancia);
    ITEM *busca_aresta_grafo(GRAFO *grafo, int cidade_1, int cidade_2);
    void imprimir(GRAFO *grafo);
#endif