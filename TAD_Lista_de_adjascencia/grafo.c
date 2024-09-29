#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

typedef struct no NO;
struct no{
    ITEM *item;
    NO *prox;
};

struct grafo{
    NO **A;
    int v; //número de vértices
    int arestas;
};

GRAFO *grafo_criar(int n, int arestas){
    GRAFO *grafo = (GRAFO*)malloc(sizeof(GRAFO));
    if(grafo == NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }else
    grafo->v = n;
    grafo->A = (NO**)malloc(n * sizeof(NO*));
    for(int i = 0; i<n; i++){
        grafo->A[i] = NULL;
    }
    return grafo;
}

/*insere ar*/
bool insere_aresta_grafo(GRAFO *grafo, int vertice_1, int vertice_2, int distancia){
    if(grafo!=NULL){
        int *aux=(int*)malloc(sizeof(int));

        if(aux==NULL){
            printf("Erro de alocação");
            return(false);
        }

        *aux=distancia;

        ITEM item=item_criar(vertice_2, aux);
        NO *no_1=(NO*)malloc(sizeof(NO));

        if(no_1==NULL){
            printf("Erro de alocação");
            free(aux);
            return(false);
        }

        no_1->item=item;
        no_1->prox=NULL;

        if(grafo->A[vertice_1-1]==NULL){
            grafo->A[vertice_1-1]=no_1;
        }else{
            NO *search=grafo->A[vertice_1-1];

            while(search->prox!=NULL){
                search=search->prox;
            }
            search->prox=no_1;
        }

        ITEM item2=item_criar(vertice_1, aux);
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

        if(grafo->A[vertice_2-1]==NULL){
            grafo->A[vertice_2-1]=no_2;
        }else{
            NO *search=grafo->A[vertice_2-1];

            while(search->prox!=NULL){
                search=search->prox;
            }
            search->prox=no_2;
        }
        grafo->arestas++;

    return(true);
    }

return (false); 
}