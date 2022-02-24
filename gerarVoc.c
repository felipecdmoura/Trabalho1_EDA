#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc_TF_IDF.c"

// Struct para o vetor de string do vocabulario; possui o vetor em si,  e o tamanho dele, para uso de loops e afins.
typedef struct
{
    char **words;
    int size;
} Vocabulary;

// Funcao para remover a pontuacao de um texto
void removePunct(FILE *arq, FILE *temp)
{
    char ch;
    while ((ch = fgetc(arq)) != EOF)
    {
        // Todas as pontuacoes a serem removidas:
        if (ch != '?' &&
            ch != '.' &&
            ch != ',' &&
            ch != '!' &&
            ch != '"' &&
            ch != '\'' &&
            ch != '(' &&
            ch != ')' &&
            ch != '[' &&
            ch != ']' &&
            ch != '{' &&
            ch != '}' &&
            ch != ':' &&
            ch != ';' &&
            ch != '-' &&
            ch != '_')
        {
            fputc(ch, temp);
        }
    }
}

// Funcao que copia apenas palavras com mais de 3 letras, de um documento para o outro.
void rmvSmallWords(FILE *temp1, FILE *temp2)
{
    char str[20];
    while (!feof(temp1))
    {
        fscanf(temp1, "%s", str);

        if (strlen(str) >= 3) // Vericfica se a string tem tamanho maior que 3.
        {
            fputs(str, temp2); // Se tiver mais que 3 letras, copia para o outro documento.
            fputc(' ', temp2);
        }
    }
}

// Funcao que retorna uma variavel do tipo struc Vocabulario, apenas palavras nao repetidas com mais de 2 letras.
Vocabulary genVoc(Vocabulary voc, FILE *arq1, FILE *arq2, FILE *arq3, FILE *arq4, FILE *arq5)
{

    char str[20];
    char *strPnt;
    int ver, tempSize;
    int count = 0;
    voc.size = 0;

    FILE *temp1 = fopen("arqTemp1.txt", "w"); // Gera um arquivo temporario para receber todas as palavras dos 5 docs, porem sem pontuacao.
    FILE *temp2 = fopen("arqTemp2.txt", "w"); // Gera um arquivo temporario para receber apenas as palavras com mais de 2 letas,  do temp1.

    // Verifica se temp1 abriu corretamente.
    if (temp1 == NULL)
    {
        printf("Arquivo nao aberto corretamente!");
        // return voc;
    }

    // Verifica se temp1 abriu corretamente.
    if (temp2 == NULL)
    {
        printf("Arquivo nao aberto corretamente!");
        // return voc;
    }

    // Remocao da pontuacao dos 5 documentos, ao mesmo tempo em que copia para o temp1.
    removePunct(arq1, temp1);
    fputc(' ', temp1);
    removePunct(arq2, temp1);
    fputc(' ', temp1);
    removePunct(arq3, temp1);
    fputc(' ', temp1);
    removePunct(arq4, temp1);
    fputc(' ', temp1);
    removePunct(arq5, temp1);

    fclose(temp1);
    temp1 = fopen("arqTemp1.txt", "r"); // Fecha e abre o temp1 em forma de leitura.

    rmvSmallWords(temp1, temp2); //  Retira palavras de temp1 com menos de 3 letras, e copia para o temp2.

    fclose(temp2);
    temp2 = fopen("arqTemp2.txt", "r"); // Fecha e abre o temp2 em forma de leitura.

    tempSize = count_DocWords(temp2); // Conta a quantidade de palavras de temp2.

    voc.words = (char **)malloc(sizeof(char *) * tempSize); // Aloca a quantidade de palavras a serem armazenadas em voc.words, baseado na quantidades de palavras do temp2.
    voc.words[0] = malloc(sizeof(char) * 20);               // Aloca a primeira string vo vetor de strings, para evitar erro no primeiro loop de busca de palavras iguais, que ocorre abaixo.
    rewind(temp2);                                          // Reseta o vetor de temp2 para o comeco do arquivo, para evitar problemas.

    while (!feof(temp2))
    {
        ver = 0;
        fscanf(temp2, "%s", str);

        // For que compara a str atual, com as outras ja alocadas no vetor de strings.
        for (size_t i = 0; i < tempSize; i++)
        {
            if (i >= count)
            {
                break;
            }

            if (strcmp(str, voc.words[i]) == 0)
            {
                ver = 1; // Caso ache alguma palavra igual, o verificador recebe 1.
                break;
            }
        }

        if (ver != 1) // O processo de alocacao da string para o vetor de strings, so segue se o verificador nao for 1.
        {
            if (count == 0) // If que visa solucionar problema que estava dando no primeiro loop, quando count == 0.
            {
                strcpy(voc.words[count], str);
                ver = 0;
                voc.size++;
                count++;
            }
            else
            {
                voc.words[count] = malloc(sizeof(char) * strlen(str));
                strcpy(voc.words[count], str);
                ver = 0;
                voc.size++;
                count++;
            }
        }
    }

    fclose(temp1);
    fclose(temp2);
    return voc;
}
