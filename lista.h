
#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho_tag 9

#define maximo 100

// strct
typedef struct _info
{
    int status;

    char tag [tamanho_tag];
} Info;

typedef Info TypeData;


typedef struct no_duplo
{
    TypeData val;
    struct no_duplo *ant;
    struct no_duplo *prox;

}Node;

typedef struct lista_dupla
{
    Node *inicio;
    Node *fim;
    Node *cursor;
    int tamanho;

} List;



Node *Cria_no (TypeData val);
List *Cria_lista();
void destroi_lista(List ** _L_ref);

void adiciona_primeiro_lista(List *L, TypeData val);
void adiciona_ultimo_lista (List *L, TypeData val);
void Lista_adiciona_em_ordem(List *L, TypeData val);

void lista_adiciona_antes_cursor(List * L ,TypeData val);
void lista_adiciona_depois_cursor( List *L, TypeData val);
 void remove_lista(List *L, TypeData val);

void imprime_dados(List *L);
void imprime_lista(List *L);
bool lista_vazia(List *L);

int qual_tamanho(List *L);






bool lista_vazia(List *L);


#endif 
