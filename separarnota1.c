#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  //abrindo arquivo que recebera o csv em text
  FILE *novoarq = fopen("arquivo.txt", "r");

  //abrindo arquivo que receberá avaliações Nota1
  FILE *notaum = fopen("Nota1.txt", "w");

    char linhaum[2000];

  while (fgets(linhaum, sizeof(linhaum), novoarq)){
     char *token;

     token = strtok(linhaum, "1");

     while (token != NULL)
     {
       //printf("%s", token);
       fputs(token, notaum);
       token = strtok(NULL, "1");
     }
    //printf("\n"); 
  }
    return 0;
}
