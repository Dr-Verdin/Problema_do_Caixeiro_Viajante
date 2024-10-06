#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

typedef struct no NO;
struct no{
    ITEM *item;
    NO *prox;
    bool dado;
};

struct grafo_{
    NO **A;
    int v; 
};

GRAFO *grafo_criar(int vertice){
    GRAFO *grafo = (GRAFO*)malloc(sizeof(GRAFO));
    if(grafo == NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }else
    grafo->v = vertice;
    grafo->A = (NO**)malloc(vertice* sizeof(NO*));
    for(int i = 0; i<vertice; i++){
        grafo->A[i] = NULL;
    }
    return grafo;
}


bool grafo_insere_aresta(GRAFO *grafo, int cidade_1, int cidade_2, int distancia){
    if(grafo!=NULL){
        int *aux=(int*)malloc(sizeof(int));

        if(aux==NULL){
            printf("Erro de alocação");
            return(false);
        }

        *aux=distancia;

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

        if(grafo->A[cidade_1-1]==NULL){
            grafo->A[cidade_1-1]=no_1;
        }else{
            NO *search=grafo->A[cidade_1-1];

            while(search->prox!=NULL){
                search=search->prox;
            }
            search->prox=no_1;
        }

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

int grafo_get_distancia(GRAFO *grafo, int cidade_1, int cidade_2){
    if(grafo!=NULL){
        NO *aux=grafo->A[cidade_1-1];

        while(aux!=NULL){
            if(item_get_chave(aux->item)==cidade_2){
                return(*((int*)item_get_dados(aux->item)));
            }
            aux=aux->prox;
        }
    }
return(ERRO);
}

void grafo_imprimir(GRAFO *grafo){
    int teste, teste2;

    if(grafo!=NULL){
        for(int i=0; i<grafo->v;i++){
            printf("%d: ", i+1);
            for(NO *aux=grafo->A[i]; aux!=NULL; aux=aux->prox){
                teste=item_get_chave(aux->item);
                teste2=*((int*)item_get_dados(aux->item));

                printf("%d(%d)->",teste, teste2);
            }
            printf("FIM\n");
        }
    }else
    printf("Não existe ou já foi apagado\n");
}

void grafo_apagar(GRAFO **grafo){
    if(grafo != NULL){
        NO *aux, *temp;
        for(int i = 0;  i< (*grafo)->v; i++){
            aux = (*grafo)->A[i];
            while (aux != NULL){
                temp=aux;
                aux = aux->prox;

                if(temp->dado){
                    free(item_get_dados(temp->item));
                }
                
                item_apagar(&temp->item);
                free(temp);
            }
            (*grafo)->A[i] = NULL;      
        }
        free((*grafo)->A);
        (*grafo)->A = NULL;
        free(*grafo);
        *grafo = NULL;
    }
}