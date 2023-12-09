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

