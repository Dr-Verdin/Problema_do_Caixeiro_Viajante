#include <stdio.h>
#include <stdlib.h>
#include "listas_adj.h"

//Estrutura que define o tipo NO que representa um dos nós da lista de adjacência*/
typedef struct no NO;
struct no{
    ITEM *item; // ponteiro para o item que armazena o número de um cidade e sua distância em relação a outra da qual esse nó esta sendo adicionado na lista de adjacência.
    NO *prox;// ponteiro para o próximo nó da lista de adjacẽncia.
    bool dado;// variável que auxilia para saber se a alocação que foi feita para guardar a distância deve ser apagada.
};

//Estrutura principal que armazena um array de ponteiros para listas de adjacência
struct listasAdj{
    NO **A; // ponteiro duplo que aponta para o array de ponteiros que apontam para listas de adjacência.
    int v; // número de cidades (vértices).
};

// Função que cria que aloca a estutura LADJ com o número de cidades passado nos parâmetros da chamada.
LADJ *ListaAdj_criar(int vertice){
    LADJ *listas = (LADJ*)malloc(sizeof(LADJ)); 
    if(listas == NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }else
    listas->v = vertice; // Atribui o valor passado pelo parâmetro da função a variável v que está contida dentro da estrutura listasAdj.
    listas->A = (NO**)malloc(vertice* sizeof(NO*));
    for(int i = 0; i<vertice; i++){
        listas->A[i] = NULL; // Inicializa as listas de adjacência como vázias.
    }
    return listas;
}

// Função que cria uma ligação entre duas cidades (aresta) e guarda a distância entre elas.
bool ListaAdj_insere_caminho(LADJ *listas, int cidade_1, int cidade_2, int distancia){
    if(listas!=NULL){
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
        if(listas->A[cidade_1-1]==NULL){
            listas->A[cidade_1-1]=no_1;
        }else{
            NO *search = listas->A[cidade_1-1];

            while(search->prox != NULL){
                search = search->prox;
            }
            search->prox=no_1;
        }

        //Cria o ITEM e o nó que vai ser adicionado na lista de adjacência da cidade_2 com a mesma distância guardada no no_1.
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
        if(listas->A[cidade_2-1]==NULL){
            listas->A[cidade_2-1]=no_2;
        }else{
            NO *search = listas->A[cidade_2-1];

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
int ListaAdj_distancia(LADJ *listas, int cidade_1, int cidade_2){
    if(listas!=NULL){
        NO *aux=listas->A[cidade_1-1];

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
void ListaAdj_imprimir(LADJ *listas){
    int teste, teste2;

    if(listas!=NULL){
        for(int i=0; i<listas->v;i++){
            printf("%d: ", i+1);
            for(NO *aux=listas->A[i]; aux!=NULL; aux=aux->prox){
                teste=item_get_chave(aux->item);
                teste2=*((int*)item_get_dados(aux->item));

                printf("%d(%d)->",teste, teste2); // Imprime a cidade adjacênte e a distância.
            }
            printf("FIM\n");
        }
    }else
    printf("Não existe ou já foi apagado\n"); // Se não existir a estrutura que guarda as listas de adjacência imprime essa mensagem.
}

// Função que apaga tudo e libera as memórias alocadas.
void ListaAdj_apagar(LADJ **listas){
    if(listas != NULL){
        NO *aux, *temp;
        for(int i = 0;  i< (*listas)->v; i++){
            aux = (*listas)->A[i];
            while (aux != NULL){
                temp=aux;
                aux = aux->prox;

                if(temp->dado){
                    free(item_get_dados(temp->item)); // Se a memória que foi alocada para guardar a distância não foi desalocada é feito essa ação.
                }
                
                item_apagar(&temp->item); // Apaga o item que está guardado no nó.
                free(temp); // Apaga o nó.
            }
            (*listas)->A[i] = NULL;      
        }
        free((*listas)->A); //Libera o array de listas de adjacência.
        (*listas)->A = NULL;
        free(*listas);// Libera a estrutura que guardava a lista de ponteiros para listas de adjacência e o numero de cidades.
        *listas = NULL;
    }
}
