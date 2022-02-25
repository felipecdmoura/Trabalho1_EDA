#ifndef CALCTF_IDF_H
#define CALCTF_IDF_H

#include<stdio.h>

int count_WordPerDoc(char word[20], FILE *doc);
int count_DocWords(FILE *doc);
void calc_TF_IDF(float *tf_idf, float *idf, char *voc, FILE *doc, int vocVectSize);

#endif /* CALCTF_IDF_H */