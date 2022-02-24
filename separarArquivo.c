#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINHA 21000
char parse(char* string, char* mensagem);

int main(){ 
  FILE *arq = fopen("arquivo.txt", "r");
  FILE *n1 = fopen("Nota1.txt", "w");
  FILE *n2 = fopen("Nota2.txt", "w");
  FILE *n3 = fopen("Nota3.txt", "w");
  FILE *n4 = fopen("Nota4.txt", "w");
  FILE *n5 = fopen("Nota5.txt", "w");


  //declarando vetor que receberá cada linha do csv
  char option;
  printf("Ponto de parada\n");
  char mensagem[10000]; 
  printf("Ponto de parada\n");
  char linha[10000];
  printf("Ponto de parada\n");
  int count = 0;
  printf("Ponto de parada\n");
  
  do{
    printf("Ponto de parada");
    fscanf(arq, "%[^\n] ", linha);
    //fgets(linha, sizeof(linha), arq);
    option = parse(linha, mensagem);
    printf("%c %s\n", option, mensagem);
    
    switch(option){
        case '1':
            fputs(mensagem, n1);
            fputs("\n", n1);
            break;
        case '2':
            fputs(mensagem, n2);
            fputs("\n", n2);
            break;
        case '3':
            fputs(mensagem, n3);
            fputs("\n", n3);
            break;
        case '4':
            fputs(mensagem, n4);
            fputs("\n", n4);
            break;
        case '5':
            fputs(mensagem, n5);
            fputs("\n", n5);
            break;
    }
  }while(/*!feof(arq)*/ arq != EOF);
  
  
  fclose(arq);
  fclose(n1);
  fclose(n2);
  fclose(n3);
  fclose(n4);
  fclose(n5);
  

  return 0;
}

char parse(char* string, char *mensagem){
  int posicao = 0;
  mensagem[posicao] = string[posicao];
  posicao++;
  while (string[posicao] != '"')
  {
    mensagem[posicao] = string[posicao];
    posicao++;
  }
  mensagem[posicao] = string[posicao];
  posicao++;
  mensagem[posicao] = '\0';
  posicao++;
  
  return string[posicao];
}