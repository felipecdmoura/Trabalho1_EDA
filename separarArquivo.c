#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINHA 21000

void separarArquivo(){ 
  //abrindo arquivo csv
  FILE *arq = fopen("tripadvisor_hotel_reviews.csv", "r");

  //abrindo arquivo que recebera o csv em text
  FILE *novoarq = fopen("arquivo.txt", "w");

  //abrindo arquivo que receberá avaliações Nota1
  FILE *notaum = fopen("Nota1.txt", "w");

  //declarando vetor que receberá cada linha do csv
  char linha[2000];
  char linha2[2000];

  while (fgets(linha, sizeof(linha), arq)){
     char *token;

     token = strtok(linha, ",");

     while (token != NULL)
     {
       printf("%s", token);
       fputs(token, novoarq);
       token = strtok(NULL, ",");
     }
    printf("\n"); 
  }

}