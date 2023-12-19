#include "lista.h"


//funcoes

Node *Cria_no(TypeData val)
{
    Node*node =(Node*)calloc(1,sizeof(Node));
    
strncpy(node ->val.tag,val.tag,tamanho_tag);
node -> val.tag[strlen(node -> val.tag)] = '\0';
node ->  val.status = val.status;

return node;
}


List *Cria_lista()
{
    List *L = (List*)calloc(1 , sizeof(List));

L -> cursor = NULL;
L ->inicio = NULL;
L -> tamanho = 0;
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
  {
    L -> inicio  -> ant=p;
  }
    L->inicio = L ->cursor=p;
    L->tamanho++;
}
void adiciona_ultimo_lista ( List *L, TypeData val )
{
    Node *p = Cria_no(val);
    p ->ant = L-> fim;
    if(lista_vazia(L))
    {
        L-> inicio=p;
    }
        else
        L -> fim -> prox =p;

        L -> fim = L-> cursor = p;
        L -> tamanho++;
    
}

void Lista_adiciona_em_ordem(List *L, TypeData val)
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
                else if(atual ==L -> fim)
                {
                    lista_adiciona_antes_cursor(L, val);
                    return;
                }
                atual = atual ->prox;

            }

        }

    }
    else
    printf("'\n\n -> Lista vazia em adiçao ordenada<-- \n\n");
    // que percaria de função longa

}




void lista_adiciona_antes_cursor( List *L, TypeData val)
{
    if(L!= NULL)
    {
        if (L-> cursor ==NULL || lista_vazia(L) || L -> cursor == L-> inicio)
        {
        adiciona_primeiro_lista(L,val);
        }
        
        { Node *p = Cria_no(val);
         p->prox =L-> cursor;
         p-> ant = L -> cursor -> ant;
         L-> cursor -> ant -> prox =p;
         L -> cursor = p;
         L -> tamanho++;
         }
    }
    
    else 
    {
    printf("Lista Nulla");
    }
}

void lista_adiciona_depois_cursor (List * L , TypeData val)
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
    else 
    printf(" LISTA NULA ");
}


// mexe com posição
void adiciona_posicao (List * L , TypeData val,int posicao, bool antes)
{
    if(posicao<L -> tamanho)
    {
        Node *p = L-> inicio;
        for (int i = 0; i< posicao;i++)
        {
            p = p-> prox;
        }
        if(antes)
        lista_adiciona_antes_cursor(L, val);
        else 
        lista_adiciona_depois_cursor(L, val);

    }
    else 
    printf("Posicao indiposnivel/ nao registrada");
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
                // Remove the incorrect code that assigns NULL to L->inicio->ant
                L->inicio->ant = NULL;
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

void imprime_dados(List *L)
{
    Node *p = L->inicio;

    while (p != NULL)
    {
        printf("%s %d \n ", p->val.tag,p->val.status);
        p= p->prox;
    }
    
}
bool lista_vazia(List *L)
{
    return (L-> tamanho<=0);
}
int qual_tamanho(List *L)
{
    return L-> tamanho;
}
void imprime_lista(List *L)
{
    Node *p =L-> inicio;

    printf("\nL ->");
    while (p!= NULL)
    {
        printf(" %s ->", p->val.tag);
        p = p->prox;

    }
    printf(" NULL");
    printf ("\n BEGIN %s",L-> inicio ->val.tag);
    printf("\n FIM %s", L->fim->val.tag);
    printf("\n CURSOR %s", L->cursor ->val.tag);
    printf("\n tamanho %d", qual_tamanho(L));
}

