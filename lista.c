#include "lista.h"
#define tamanho_tag 9

// strct

typedef struct inf
{
    ins status;
    char tag[tamanho_tag];
} info;

typedef struct no_duplo
{
    TypeData val;
    struct no_duplo *ant;
    struct no_duplo *prox;

} Node;

typedef struct no_duplo
{
    Node *inicio;
    Node *fim;
    Node *cursor;
    int tamanho;

} List;
//funcoes

Node *Cria_no(TypeData val)
{
    Node*node =(Node*)calloc(1,sizeof(Node));
strncpy(node -> val.tag,val.tag,tamanho_tag);
node -> val.tag[strlen(node -> val.tag)] = '\0';
node ->  val.status = val.status;

return node;
}


Lista *Cria_lista()
{
    Lista *L = (Lista*)calloc(1 , sizeof(Lista));

L -> cursor = NULL;
L ->inicio = NULL;
L -> tamanho = NULL;
L -> fim = NULL;

return L;
}



void destroi_lista( List** _L_ref)
{
    List *L= *_L_ref;
    Node *p = L -> inicio;
    Node *aux = NULL;

    while(p != NULL)
    {
        aux=p;
        p = p -> prox;
        free(aux);
    }
    free(L);
    *_L_ref = NULL;
}

void adiciona_primeiro_lista(List*L,TypeData val)
{
    Node *p = Cria_no(val);
    p -> prox = L -> inicio;
    if(lista_vazia(L))
    
        L-> fim=p;
    
    else 
    L= inicio = ant=p;

    L->inicio = L ->cursor=p;
    L= tamanho++;
}

