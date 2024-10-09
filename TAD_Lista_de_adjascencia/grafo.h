#ifndef GRAFO_H
    #define GRAFO_H

    // Inclui a biblioteca "item.h", nela está definido o tipo de dado ITEM que é utilizado no TAD.
    #include "item.h"
    #define ERRO -1 // Define -1 como um valor para representar um ERRO.

    // Definição da estrutura de dados LADJ. Essa estrutura é opaca para o usuario.
    typedef struct listasAdj LADJ;

    LADJ *ListaAdj_criar(int vertice); // Ao ser chamada essa função retorna um ponteiro que aponta para uma estrutura LADJ que foi alocada e setada com o número da vertices passado nos parâmetros.
    bool ListaAdj_insere_caminho(LADJ *listas, int cidade_1, int cidade_2, int distancia); // Ao ser chamada a função cria uma ligação não direcionada entre as duas cidades passadas pelos parâmetros e retorna true se conseguiu e false se não.
    int ListaAdj_distancia(LADJ *listas, int cidade_1, int cidade_2);// Retorna a distancia entre duas cidades passadas nos parâmetros ou -1 caso não exista conexão entre elas.
    void ListaAdj_imprimir(LADJ *listas); // Imprime todas as listas de adjacência.
    void ListaAdj_apagar(LADJ **ListaAdj_distancia); // Apaga/desaloca tudo que foi alocado.
#endif