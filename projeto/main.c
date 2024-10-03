#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

/*
PROBLEMAS:
- vetor caminho ou no vetor menor_caminho: não está imprimindo corretamente no 4 e no 12 (mas as distancias estão corretas)
- tempo: demorado, principalmente no 12
*/

// Função recursiva para buscar o menor caminho
void findPath(int cidade_atual, int cidade_inicial, long int acumulador_distancia, int caminho[], int caminho_len, int qtd_cidades, GRAFO *grafo, int *menor_distancia, int menor_caminho[]) {
    // Se já passou por todas as cidades
    if (caminho_len == qtd_cidades) {
        // Verifica se a última cidade é a cidade de origem
        int distancia_retorno = grafo_get_distancia(grafo, cidade_atual, cidade_inicial);
        if (distancia_retorno != -1) { // Se há caminho de volta
            long int total_distancia = acumulador_distancia + distancia_retorno;
            if (total_distancia < *menor_distancia) { // se a distância total for menor
                *menor_distancia = total_distancia; // atualiza a menor distância
                // Copia o caminho para menor_caminho
                for (int i = 0; i < caminho_len; i++) {
                    menor_caminho[i] = caminho[i];
                }
                menor_caminho[caminho_len] = cidade_inicial; // Adiciona a cidade inicial ao final
            }
            return;
        }
    } else {
        // Se não passou por todas as cidades ainda
        for (int prox_cidade = 1; prox_cidade <= qtd_cidades; prox_cidade++) {
            int distancia = grafo_get_distancia(grafo, cidade_atual, prox_cidade);
            if (distancia != -1) { // VErifica se há caminho
                int cidade_visitada = 0;
                for (int i = 0; i < caminho_len; i++) {
                    if (caminho[i] == prox_cidade) { // Verifica se a cidade já foi visitadq
                        cidade_visitada = 1;
                        break;
                    }
                }

                if (!cidade_visitada) { // se a cidade não foi visitada
                    caminho[caminho_len] = prox_cidade; // Adiciona a próxima cidade ao caminho
                    findPath(prox_cidade, cidade_inicial, acumulador_distancia + distancia, caminho, caminho_len + 1, qtd_cidades, grafo, menor_distancia, menor_caminho);
                }
            }
        }
    }
}

// Função que chama a função recursiva
void startPath(int cidade_atual, int cidade_objetivo, int qtd_cidades, int *menor_distancia, int menor_caminho[], GRAFO *grafo){
    int arestas, cidade1, cidade2, distancia; 
    scanf(" %d", &arestas);

    if (arestas < 0) {
        printf("ERRO: Numero de arestas invalido.\n");
        return;
    }

    for(int i = 0; i < arestas; i++){
        scanf(" %d %d %d", &cidade1, &cidade2, &distancia);
        grafo_insere_aresta(grafo, cidade1, cidade2, distancia);
    }

    int caminho[qtd_cidades];
    caminho[0] = cidade_atual; // inicia o caminho com a cidade atual
    findPath(cidade_atual, cidade_objetivo, 0, caminho, 1, qtd_cidades, grafo, menor_distancia, menor_caminho); // chama a função recursiva
}

// Função Principal
int main(void){ 
    int qtd_cidades; // quantidade de cidades
    scanf(" %d", &qtd_cidades);
    if(qtd_cidades > 12){
        printf("ERRO: O número de cidades ultrapassou o limite permitido.\n");
        return 1;
    }
    GRAFO *grafo = grafo_criar(qtd_cidades);

    int cidade_origem; // cidade de partida = cidade de cheagada
    scanf(" %d", &cidade_origem);

    int menor_distancia = 3200000; // inicializa com um valor muito alto
    int menor_caminho[qtd_cidades]; // para armazenar o menor caminho

    // chama a função para a cidade inicial
    startPath(cidade_origem, cidade_origem, qtd_cidades, &menor_distancia, menor_caminho, grafo);

    // exibe a cidade de origem, a menor caminho encontrado e a menor distancia
    printf("Cidade Origem: %d\n", cidade_origem);
    printf("Rota: ");
    for (int i = 0; i <= qtd_cidades; i++) {
        printf("%d", menor_caminho[i]); // ajusta o indice na hora da impressão
        if(i != qtd_cidades){
            printf(" - ");
        }
    }
    printf("\nMenor Distância: %d\n", menor_distancia);

    grafo_imprimir(grafo);

    grafo_apagar(&grafo);

    return 0;
}