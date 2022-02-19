#include <stdio.h>
#include <stdlib.h>

int main(void)
{
 char url[]="tripadvisor_hotel_reviews.csv", //passando o arquivo para o vetor char
      ch;
 int num=0;
 FILE *arq;
  
 arq = fopen(url, "r"); //lendo o arquivo//
 if(arq == NULL)
   printf("Erro, nao foi possivel abrir o arquivo\n");
 else
  while( (ch=fgetc(arq))!= EOF )
   if(ch == '2')
     num++;
 
 printf("Existem %d linhas no arquivo\n", num);
 fclose(arq);
 
 return 0;
}
