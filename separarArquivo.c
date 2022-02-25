#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "separarArquivo.h"

#define MAX_LINHA 21000

void separaArquivo(FILE *arq)
{

  // Abre/Cria 5 documentos para separar as reviews por nota
  FILE *n1 = fopen("Nota1.txt", "w");
  FILE *n2 = fopen("Nota2.txt", "w");
  FILE *n3 = fopen("Nota3.txt", "w");
  FILE *n4 = fopen("Nota4.txt", "w");
  FILE *n5 = fopen("Nota5.txt", "w");

  char linha[MAX_LINHA]; // Variavel de grande tamanho, que recebera cada linha do csv.
  char notaNum;          // Variavel que recebera a nota de cada review.

  while (fgets(linha, sizeof(linha), arq))
  {
    notaNum = linha[strlen(linha) - 2]; // Como o antepenultimo caracter de uma linha se refere sempre a nota da review, aloca esse caractere em notaNum.

    // Desigina a linha lida para cada arquivo, separando o csv por nota, baseado na nota lida na mesma linha.
    switch (notaNum)
    {
    case '1':
      fputs(linha, n1);
      break;

    case '2':
      fputs(linha, n2);
      break;

    case '3':
      fputs(linha, n3);
      break;

    case '4':
      fputs(linha, n4);
      break;

    case '5':
      fputs(linha, n5);
      break;

    default:
      break;
    }
  }

  free(linha);
  fclose(n1);
  fclose(n2);
  fclose(n3);
  fclose(n4);
  fclose(n5);
}
