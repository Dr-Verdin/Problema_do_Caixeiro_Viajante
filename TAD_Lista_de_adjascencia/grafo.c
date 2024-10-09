#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

//Estrutura que define o tipo NO que representa um dos nós da lista de adjacência*/
typedef struct no NO;
struct no{
    ITEM *item; // ponteiro para o item que armazena o número de um cidade e sua distância em relação a outra da qual esse nó esta sendo adicionado na lista de adjacência.
    NO *prox;// ponteiro para o próximo nó da lista de adjacẽncia.
    bool dado;// variável que auxilia para saber se a alocação que foi feita para guardar a distância deve ser apagada.
};

//Estrutura principal que armazena um array de ponteiros para listas de adjacência
struct grafo_{
    NO **A; // ponteiro duplo que aponta para o array de ponteiros que apontam para listas de adjacência.
    int v; // número de cidades (vértices).
};

// Função que cria o grafo com o número de vértices passado nos parâmetros da chamada.
GRAFO *grafo_criar(int vertice){
    GRAFO *grafo = (GRAFO*)malloc(sizeof(GRAFO)); 
    if(grafo == NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }else
    grafo->v = vertice; // Atribui o valor passado pelo parâmetro da função a variável v que está contida dentro da estrutura grafo_.
    grafo->A = (NO**)malloc(vertice* sizeof(NO*));
    for(int i = 0; i<vertice; i++){
        grafo->A[i] = NULL; // Inicializa as listas de adjacência como vázias.
    }
    return grafo;
}

// Função que cria uma ligação entre duas cidades (aresta) e guarda a distância entre elas.
bool grafo_insere_aresta(GRAFO *grafo, int cidade_1, int cidade_2, int distancia){
    if(grafo!=NULL){
        int *aux=(int*)malloc(sizeof(int)); //alocação de memória para a distância.

        if(aux==NULL){
            printf("Erro de alocação");
            return(false);
        }

        *aux=distancia; // Guarda a distância nessa memória alocada.

        //Cria o ITEM e o nó que vai ser adicionado na lista de adjacência da cidade_1.
        ITEM *item=item_criar(cidade_2, aux);
        NO *no_1=(NO*)malloc(sizeof(NO));

        if(no_1==NULL){
            printf("Erro de alocação");
            free(aux);
            return(false);
        }

        no_1->item=item;
        no_1->prox=NULL;
        no_1->dado=true;

        // Guarda o no_1 no final da lista de adjacência da cidade_1.
        if(grafo->A[cidade_1-1]==NULL){
            grafo->A[cidade_1-1]=no_1;
        }else{
            NO *search=grafo->A[cidade_1-1];

            while(search->prox!=NULL){
                search=search->prox;
            }
            search->prox=no_1;
        }

        //Cria o ITEM e o nó que vai ser adicionado na lista de adjacência da cidade_2 com a mesma distância guardada no no_1..
        ITEM *item2=item_criar(cidade_1, aux);
        NO *no_2=(NO*)malloc(sizeof(NO));

        if(no_2==NULL){
            printf("Erro de alocação");
            free(aux);
            aux=NULL;
            free(no_1);
            no_1=NULL;
            return(false);
        }

        no_2->item=item2;
        no_2->prox=NULL;
        no_2->dado=false;

        // Guarda o no_2 no final da lista de adjacência da cidade_2.
        if(grafo->A[cidade_2-1]==NULL){
            grafo->A[cidade_2-1]=no_2;
        }else{
            NO *search=grafo->A[cidade_2-1];

            while(search->prox!=NULL){
                search=search->prox;
            }
            search->prox=no_2;
        }

    return(true);
    }

return (false); 
}

// Função que retorna o valor da distância entre 2 cidades (cidade_1 e cidade_2).
int grafo_get_distancia(GRAFO *grafo, int cidade_1, int cidade_2){
    if(grafo!=NULL){
        NO *aux=grafo->A[cidade_1-1];

        while(aux!=NULL){
            if(item_get_chave(aux->item)==cidade_2){
                return(*((int*)item_get_dados(aux->item))); // Retorna a distancia da cidade_1 para a cidade_2 se for encontrada.
            }
            aux=aux->prox;
        }
    }
return(ERRO);// Retorna "ERRO" se não encontrar a cidade_2.
}

//Função que imprime as listas de adjacência.
void grafo_imprimir(GRAFO *grafo){
    int teste, teste2;

    if(grafo!=NULL){
        for(int i=0; i<grafo->v;i++){
            printf("%d: ", i+1);
            for(NO *aux=grafo->A[i]; aux!=NULL; aux=aux->prox){
                teste=item_get_chave(aux->item);
                teste2=*((int*)item_get_dados(aux->item));

                printf("%d(%d)->",teste, teste2); // Imprime a cidade adjacênte e a distância.
            }
            printf("FIM\n");
        }
    }else
    printf("Não existe ou já foi apagado\n"); // Se o grafo não existir imprime essa mensagem.
}

// Função que apaga tudo e libera as memórias alocadas.
void grafo_apagar(GRAFO **grafo){
    if(grafo != NULL){
        NO *aux, *temp;
        for(int i = 0;  i< (*grafo)->v; i++){
            aux = (*grafo)->A[i];
            while (aux != NULL){
                temp=aux;
                aux = aux->prox;

                if(temp->dado){
                    free(item_get_dados(temp->item)); // Se a memória que foi alocada para guardar a distância não foi desalocada é feito essa ação.
                }
                
                item_apagar(&temp->item); // Apaga o item que está guardado no nó.
                free(temp); // Apaga o nó.
            }
            (*grafo)->A[i] = NULL;      
        }
        free((*grafo)->A); //Libera o array de listas de adjacência.
        (*grafo)->A = NULL;
        free(*grafo);// Libera a estrutura que guardava a lista de ponteiros para listas de adjacência e o numero de cidades.
        *grafo = NULL;
    }
}