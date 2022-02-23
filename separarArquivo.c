#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINHA 21000

int main(){ 
  //abrindo arquivo csv
  FILE *arq = fopen("tripadvisor_hotel_reviews.csv", "r");

  //abrindo arquivo que recebera o csv em text
  FILE *novoarq = fopen("arquivo.txt", "w");

  //abrindo arquivo que receberá avaliações Nota1
  //FILE *notaum = fopen("Nota1.txt", "w");

  //declarando vetor que receberá cada linha do csv
  char linha[MAX_LINHA];
  while (fgets(linha, sizeof(linha), arq)){
     char *token;

     token = strtok(linha, "\\n");

     while (token != NULL)
     {
       fputs(token, novoarq);
       token = strtok(NULL, "\\n");
     }
    printf("\n"); 
  }

  fclose(arq);
  fclose(novoarq);

  return 0;
}