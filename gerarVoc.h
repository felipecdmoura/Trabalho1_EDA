#ifndef GERARVOC_H
#define GERARVOC_H

#include<stdio.h>
#include"VocStruct.h"

void removePunct(FILE *arq, FILE *temp);
void rmvSmallWords(FILE *temp1, FILE *temp2);
Vocabulary genVoc(Vocabulary voc, FILE *arq1, FILE *arq2, FILE *arq3, FILE *arq4, FILE *arq5);

#endif /* GERARVOC_H */