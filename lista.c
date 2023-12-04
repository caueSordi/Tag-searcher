#include "lista.h"
#define tamanho_tag 9

// strct

typedef struct inf
{
    ins status;
    char tag[tamanho_tag];
} info;

typedef struct _doubly_node
{
    TypeData val;
    struct _doubly_node *ant;
    struct _doubly_node *prox;

} Node;

typedef struct _doubly_List
{
    Node *começo;
    Node *fim;
    Node *cursor;
    int tamanho;

} List;
//funcoes

