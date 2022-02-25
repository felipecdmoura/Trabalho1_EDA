#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calcTF_IDF.h"
// void calc_TF_IDF(float *tf_idf, float *idf, char *voc, FILE *doc, int vocVectSize);
int count_WordPerDoc(char word[20], FILE *doc);
int count_DocWords(FILE *doc);

// Calcula determinada o TF-IDF de  determinada palavra em determinado documento.
/* void calc_TF_IDF(float *tf_idf, float *idf, char *voc, FILE *doc, int vocVectSize)
{
    int wordPerDoc, docWords;
    float tf;

    for (int i = 0; i < vocVectSize; i++)
    {
        wordPerDoc = count_WordPerDoc(voc[i], doc);
        docWords = count_DocWords(doc);

        tf = wordPerDoc / docWords; // Calculo do TF = n. de vezes que a palavra aparece no doc / n. de palavras no doc.
        tf_idf[i] = tf * idf[i];    // Calcula o TF-IDF  e armazena no vetor.
    }
} */

// Conta quantas vezes determiada palavra aparece em determinado documento
int count_WordPerDoc(char word[20], FILE *doc)
{
    char str[20];
    int count = 0; // Contador do numero de vezes que word aparece no texto doc.

    while (!feof(doc))
    {
        fscanf(doc, "%s ", str);    // Palavra retirada do texto em sequencia.
        if (strcmp(str, word) == 0) // Compara se a palavra retirada do texto e igual a inserida como parametro na funcao(word).
        {
            count++;
        }
    }

    return count;
}

// Conta quantas palavras um documento possui
int count_DocWords(FILE *doc)
{
    int nWord = 0;   // Numero de palavras contidas no texto doc.
    int verWord = 0; // Verifica se a letra anterior era uma letra, para assim contar como uma palavra. Util para, no caso de dois espacos seguidos, contar apenas uma palavra.
    char ch;         // Caractere retirado do texto em sequencia.

    while ((ch = fgetc(doc)) != EOF)
    {
        if (ch == ' ' || ch == '\t' || ch == '\0' || ch == '\n') // Se o caractere lido for um desses, e muito provavel que uma palavra acabou de terminar.
        {
            if (verWord)
            {
                verWord = 0;
                nWord++;
            }
        }
        else
        {
            verWord = 1;
        }
    }

    // Este if faz com que o programa some a ultima palavra do texto.
    if (ch == EOF && verWord)
    {
        nWord++;
    }

    return nWord;
}