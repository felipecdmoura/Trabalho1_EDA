#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINHA 21000

int main(){ 
  //abrindo arquivo csv
  //FILE *arq = fopen("tripadvisor_hotel_reviews.csv", "r");

  //abrindo arquivo que recebera o csv em text
  FILE *novoarq = fopen("arquivo.txt", "r");

  //abrindo arquivo que receberá avaliações Nota1
  FILE *notaum = fopen("Nota1.txt", "w");

  //declarando vetor que receberá cada linha do csv
  char linha[2000];
  char linha2[2000];

  while (fgets(linha, sizeof(linha), novoarq)){
     char *token;
     if(linha == '2'){ 
        token = strtok(linha, linha);
     }

     while (token != NULL)
     {
       fputs(token, notaum);
       token = strtok(NULL, linha);
     }
    printf("\n"); 
  }

  fclose(novoarq);
  fclose(notaum);

  return 0;

}
    
