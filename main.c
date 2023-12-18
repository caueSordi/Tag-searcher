#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Add the missing header file for string functions
#include "arvore.h"
#include "lista.h"

#define t_tamanho 20

int main()
{
  char line[t_tamanho];

  List *L = Cria_lista();

  ArvBin* root = cria_ArvBin();

  FILE *fp = fopen("arq.txt", "r");

  if (fp == NULL)
  {
    printf("erro");
  }
  else
  {
    char c = 'x';

    fgets(line, t_tamanho, fp);

    line[strcspn(line, "\r\n")] = 0;

    line[strlen(line)] = '\0';

    while (strncmp(line, &c, 1) != 0)
    {
      Info nova_info;
      strcpy(nova_info.tag, line);
      nova_info.status = atoi(fgets(line, t_tamanho, fp));



      fgets(line, t_tamanho, fp);
      line[strcspn(line, "\r\n")] = 0;
      line[strlen(line)] = '\0';
    }

    fclose(fp);
  }

  char *option;
  char *tag;
  char command[15];
  fflush(stdin);

  fgets(command, 15, stdin);
  command[strcspn(command, "\r\n")] = 0;

  option = strtok(command, " ");
  tag = strtok(NULL, " ");

  switch (atoi(option))
  {
    case 0:
    {
      printf("NL:%d NA:%d\n", List_GetSize(L), totalNO_ArvBin(root));
      break;
    }
    case 1:
    {
      int pos_lista, treePos;

      pos_lista = List_Search(L, tag);
      treePos = consulta_ArvBin(root, tag);

      if ((treePos > 0) && (pos_lista > 0))
      {
        printf("S:0 NL:%d NA:%d\n", pos_lista, treePos);
      }
      else
      {
        printf("S:-1 NL:%d NA:%d\n", -pos_lista, -treePos);
      }
      break;
    }
    case 2:
    {
      imprime_lista(L);
      break;
    }
    case 3:
    {
      preOrdem_ArvBin(root);
      break;
    }
  }

  return 0;
}
