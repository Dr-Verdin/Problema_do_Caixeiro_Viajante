#ifndef GRAFO_H
    #define GRAFO_H

    #include "item.h"

    typedef struct grafo_ GRAFO;

    GRAFO *grafo_criar(int n, int arestas);
    bool insere_aresta_grafo(GRAFO *grafo, int vertice_1, int vertice_2, int distancia);
#endif