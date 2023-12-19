
#include "arvore.h" //inclui os Prot�tipos

//feito no studio

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada n
    free(raiz);//libera a raiz
}

int insere_ArvBin(ArvBin* raiz, tipo_dado data)

{
    if (raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if (novo == NULL)
        return 0;
    novo->dir = NULL;
    novo->esq = NULL;
strncpy(novo -> info.tag,data.tag,tamanho_tag);
novo ->info.tag[strlen(novo ->info.tag)] ;'\0';
novo -> info.status = data.status;

    if (*raiz == NULL)
        *raiz = novo;
    else {
        struct NO* atual = *raiz;
        struct NO* ant = NULL;


        while (atual != NULL)
        {
            ant = atual;
            if (strncmp(data.tag, atual->info.tag,tamanho_tag) == 0)//se zero igual ent ja tem
            {
                free(novo);
                return 0; //já tem na arvre
            }

            if (strncmp(data.tag, atual->info.tag,tamanho_tag) > 0)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if (strncmp(data.tag, atual->info.tag,tamanho_tag) > 0)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}


struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 � o n� anterior a r na ordem e-r-d
    // no1 � o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}
// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
//no one cares about the remove, amen


int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

int consulta_ArvBin(ArvBin *raiz, char tag[10])
{
    if(raiz == NULL)
        return 0;

    int qtdeNodes = 0;
    struct NO* atual = *raiz;
    while (atual != NULL) 
    {
        int comparisonResult = strcmp(tag, atual->info.tag);

        if (comparisonResult == 0) {
            return (qtdeNodes + 1);
        } else if (comparisonResult > 0) {
            atual = atual->dir;
        } else {
            atual = atual->esq;
        }

        qtdeNodes++;
    }

    return 0; // Return 0 if the tag is not found
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        printf ("%s %d\n"), ((*raiz)->info.tag,(*raiz)->info.status);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%s %d\n",(*raiz)->info.tag,(*raiz)->info.status);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info.status);
    }
}

void Procura_preOrdem_ArvBin(ArvBin *raiz, tipo_dado info, int *achou)
{
    if(raiz == NULL)
        return;
    if (*achou)
        return;
    if(*raiz != NULL)
    {
        //if (data == (*raiz)->info)
        if (strncmp(info.tag, (*raiz)->info.tag, tamanho_tag) == 0)
        {
            printf("%s %d\n",(*raiz)->info.tag, (*raiz)->info.status);
            *achou=1;
        }
        Procura_preOrdem_ArvBin(&((*raiz)->esq),info,achou);
        Procura_preOrdem_ArvBin(&((*raiz)->dir), info, achou);
    }
}
