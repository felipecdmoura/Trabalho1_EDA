#include <stdio.h>
#include <stdlib.h>
#define MAX_LINHA 21000

void separaArquivo(){

  FILE *arq = fopen("tripadvisor_hotel_reviews.csv", "r");
  FILE *novoarq = fopen("arquivo.txt", "w");

  char linha[2000];

  while (fgets(linha, sizeof(linha), arq))
  {
     char *token;

     token = strtok(linha, ",");

     while (token != NULL)
     {
       printf("%s", token);
       //fputs(token, novoarq);
       token = strtok(NULL, ",");
     }
    printf("\n"); 
  }

}
