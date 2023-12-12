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
void adiciona_ultimo_lista ( List *L, TypeData val )
{
    Node *p Cria_no(val);
    p ->ant = L-> fim;
    if(lista_vazia(L))
    {
        L-> inicio;
    }
        else
        L= fim -> prox =p;

        L -> fim = L_> cursor = p;
        L -> tamanho++;
    
}

voif Lista_adiciona_em_ordem(List *L, TypeData val)
{
    if(L != NULL)
    {
        if(L ->cursor == NULL || lista_vazia(L))
        {
            adiciona_primeiro_lista(L, val);
        } 
        else 
        {
            Node *atual = L -> inicio; //atual = current
            while (atual != NULL)
            {
                L -> cursor = atual;

                if(strncmp(atual ->val.tag, val.tag,tamanho_tag)>0)
                {
                    lista_adiciona_antes_cursor(L,val);
                    return;
                }
                else if(atial ==L -> fim)
                {
                    lista_adiciona_antes_cursor(L, val);
                    return;
                }
                atual = atual ->prox;

            }

        }

    }
    else
    printfd("'\n\n -> Lista vazia em adiçao ordenada<-- \n\n");
    // que percaria de função longa

}




void lista_adiciona_antes_cursor( List *L, Typedata val)
{
    if(L!= NULL)
    {
        if (L-> cursor ==NULL || lista_vazia(L) || L -> cursor == L-> inicio);
        adiciona_primeiro_lista(L,val);
    }
    else 
    {
         Node *p = Cria_no(val);

         p->prox =L-> cursor;
         p-> ant = L -> cursor -> ant;
         L-> cursor -> ant -> prox =p;
         L -> cursor = p;

         L -> tamanho++;
    }
    else 
    printf("Lista Nulla, sistema hackeado pela revolução")
}

void lista_adiciona_depois_cursor (List * L , Typedata val)
{
    if ( L != NULL)
    {
        if ( L ->cursor ==NULL || lista_vazia(L)|| L-> cursor == L -> fim)
        {
            adiciona_ultimo_lista(L, val);
        }
        else 
        {
            Node *p = Cria_no(val);

            p-> prox = L -> cursor -> prox;
            p ->ant= L -> cursor;
            L-> cursor ->prox ->ant = p;
            L -> cursor =p;

            L -> tamanho++;
        }
    }
    elseprint(" LISTA NULA ");
}


// mexe com posição
void adiciona_posicao (List * L , TypeData val,int posicao, boll antes)
{
    if(posicao<L -> tamanho)
    {
        Node *p = L-> inicio;
        for (int i = 0, i< posicao,i++)
        {
            p = p-> prox;
        }
        if(antes)
        lista_adiciona_antes_cursor(L, val);
        else 
        lista_adiciona_depois_cursor(L, val);

    }
    else 
    printf("Posicao indiposnivel/ nao registrada")
}

//

void remove_lista ( List *L, TypeData val)
{
    if( lista_vazia(L))
    {
        Node *p = L -> inicio;

        if(strncmp(L->inicio -> val.tag,val.tag,tamanho_tag)==0)
        {
            L -> inicio =p -> prox;

            if(L-> fim == p)

            L->fim=L-> cursor = NULL;
            
            else
            {
                L-> inicio -> ant - > NULL;
                L-> cursor =L -> inicio;
            }
            free(p);
            L ->tamanho--;

        }
        else
        {
            p=p-> prox;

            while ( p!= NULL)
            {
                if(strncmp(p-> val.tag,val.tag, tamanho_tag)==0)
                {
                    p -> ant -> prox =p -> prox;
                    if (L -> fim ==p)
                    {
                        L-> fim = p -> ant;
                    } 
      else
                    {
                        p -> ant -> prox = p -> ant;
                    }

                    L -> cursor = p -> ant;
                    free(p);
                    p = NULL;
                    L -> tamanho--;
                }
                else{

                    p=p-> prox;
                }
            }
        }
    }
}

