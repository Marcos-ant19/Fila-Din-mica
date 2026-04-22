#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "fila.h"

Fila* criar_fila(){
    Fila* f = malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->qtd = 0;

    return f;
}
bool isEmpty(Fila* f){
    return f->inicio == NULL;

void inserir(Fila* f, char valor){
    No* novo = malloc(sizeof(No));
    novo->letra = valor;
    novo->prox = NULL;
    if(isEmpty(f)){
        f->fim = novo;
        f->inicio = novo;
    }else{
        f->fim->prox = novo;
        f->fim = novo;
    }
    f->qtd++;
}

char remover(Fila* f){
    if(f->inicio != NULL){
        No* aux = f->inicio;
        char c = aux->letra;
    if(f->inicio == NULL){
        f->fim = NULL;
    }

    f->inicio = aux->prox;
    free(aux);
    f->qtd--;
    return c;
    }
}

void imprimir(Fila* f){
    No* aux = f->inicio;
    while(aux != NULL){
        printf("%c ", aux->letra);
        aux = aux->prox;
    }
    printf("\n");
}

char pop(Pilha* p){
    int valor;
    if(is_Empty(p)){
        printf("Pilha vazia!\n");
        return '0';
    }
    Node* aux = p->topo;
    valor = aux->valor;
    p->topo = aux->pro;
    free(aux);
    return valor;
}

int size(Fila* f){
    return f->qtd;
}

void clear(Fila* f){
    No* aux = f->inicio;

    while(aux != NULL){
        No* temp = aux;
        aux = aux->prox;
        free(temp);
    }
    f->inicio = NULL;
    f->fim = NULL;
    f->qtd = 0;

    printf("Fila Limpa...\n");
}

Pilha* criar_pilha(){
    Pilha* p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int is_Empty(Pilha* p){
    return p->topo == NULL;
}

void push(Pilha* p, char valor){
   Node* novo = malloc(sizeof(Node));

   novo->valor = valor;
   novo->pro = p->topo;

   p->topo = novo;
}


void inverter(Fila* f){
    Pilha* aux = criar_pilha();
    while(!isEmpty(f)){
        push(aux, remover(f));
    }
    while(!is_Empty(aux)){
        inserir(f, pop(aux));
    }
    imprimir(f);
}

void palavra(Fila* f){
    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    for(int i = 0;palavra[i] != '\0';i++){
    inserir(f, palavra[i]);
    }
}
