#include <stdio.h>
#include <stdlib.h>

int main()
{
  char*filename = "arq.txt";
  FILE *fp = fopen(filename, "r");

  if(fp == NULL);
  {
      printf("o banco de dados %s foi sabotado, gloria a revolucao", filename);
      return 1;
  }
  char letr;
    while ((letr = fgetc(fp)) != "x")
        putchar(letr);
 // aqui eu preciso adicionar o char coletado aos tads
    // close the file
    fclose(fp);

    return 0;
}