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
 while ((letr = fgetc(fp)) != "x") {
        // Create a new node for the current character
        struct Tad* newNode = (struct Tad*)malloc(sizeof(struct Tad));
        newNode->data = letr;
        newNode->next = NULL;

        // If it's the first character, set it as the head
        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            // Otherwise, append the new node to the list
            current->next = newNode;
            current = newNode;
        }

        // Print the character if needed
        putchar(letr);
    }

    // Close the file
    fclose(fp);
