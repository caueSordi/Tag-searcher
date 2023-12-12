#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maximo 100

typedef struct _info Info;
typedef struct no_duplo;
typedef struct lista_dupla;

typedef Info TypeData;

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







bool lista_vazia(List *L);


#endif // LIST_H_INCLUDED