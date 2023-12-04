#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*defines*/
#define F 0
#define V 1
#define tamanho_tag 9


/* structs */

struct info
{
    int status;
    char tag[tamanho_tag];
}; typedef struct info In;
typedef In tipo_dado;



struct NO{
    tipo_dado info;
    struct NO *esq;
    struct NO *dir;
}; typedef struct NO NodoArvBin;
typedef struct NO* ArvBin;




ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, tipo_dado valor);
int remove_ArvBin(ArvBin *raiz, int valor);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, char tag[10]);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);




#endif // ARVORE_H_INCLUDED
