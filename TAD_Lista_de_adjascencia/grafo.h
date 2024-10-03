#ifndef GRAFO_H
    #define GRAFO_H

    #include "item.h"
    #define ERRO -1

    typedef struct grafo_ GRAFO;

    GRAFO *grafo_criar(int vertice);
    bool grafo_insere_aresta(GRAFO *grafo, int cidade_1, int cidade_2, int distancia);
    int grafo_get_distancia(GRAFO *grafo, int cidade_1, int cidade_2);
    void grafo_imprimir(GRAFO *grafo);
    void grafo_apagar(GRAFO **grafo);
#endif