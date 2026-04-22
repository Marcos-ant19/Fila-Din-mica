#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdbool.h>

typedef struct No{
    char letra;
    struct No* prox;
}No;

typedef struct Fila{
    No* inicio;
    No* fim;
    int qtd;
}Fila;

Fila* criar_fila();
bool isEmpty(Fila* f);
void inserir(Fila* f, char valor);
char remover(Fila* f);
int size(Fila* f);
void clear(Fila* f);
void imprimir(Fila* f);

typedef struct Node{
   char valor;
   struct Node* pro;
}Node;

typedef struct Pilha{
    Node* topo;
}Pilha;

Pilha* criar_pilha();
int is_Empty(Pilha* p);
void push(Pilha* p, char valor);
char pop(Pilha* p);
void inverter(Fila* f);

#endif // FILA_H_INCLUDED
