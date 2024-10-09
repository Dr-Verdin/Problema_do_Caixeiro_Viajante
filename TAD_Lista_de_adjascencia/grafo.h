#ifndef GRAFO_H
    #define GRAFO_H

    // Inclui a biblioteca "item.h", nela está definido o tipo de dado ITEM que é utilizado no TAD.
    #include "item.h"
    #define ERRO -1 // Define -1 como um valor para representar um ERRO.

    // Definição da estrutura de dados GRAFO. Essa estrutura é opaca para o usuario.
    typedef struct grafo_ GRAFO;

    GRAFO *grafo_criar(int vertice); // Ao ser chamada essa função retorna um ponteiro que aponta para uma estrutura GRAFO que foi alocada e setada com o número da vertices passado nos parâmetros.
    bool grafo_insere_aresta(GRAFO *grafo, int cidade_1, int cidade_2, int distancia); // Ao ser chamada a função cria uma ligação não direcionada entre as duas cidades passadas pelos parâmetros e retorna true se conseguiu e false se não.
    int grafo_get_distancia(GRAFO *grafo, int cidade_1, int cidade_2);// Retorna a distancia entre duas cidades passadas nos parâmetros ou -1 caso não exista conexão entre elas.
    void grafo_imprimir(GRAFO *grafo); // Imprime todas as listas de adjacência.
    void grafo_apagar(GRAFO **grafo); // Apaga/desaloca tudo que foi alocado.
#endif