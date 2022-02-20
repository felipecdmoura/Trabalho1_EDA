#include <stdio.h>
#include <stdlib.h>
/*
int main(void)
{
 char url[]="tripadvisor_hotel_reviews.csv", //passando o arquivo para o vetor char
      ch;
 int num=0;
 FILE *arq;
  
 arq = fopen(url, "r"); //lendo o arquivo//
 if(arq == NULL){
   printf("Erro, nao foi possivel abrir o arquivo\n");
 }

 else{
  while( (ch=fgetc(arq))!= '4' ){
   //if(ch == '\n'){
    printf("%c", ch);  
     //num++;
   //}
  }
 }
 //printf("Existem %d linhas no arquivo\n", num);
 fclose(arq);
 
 return 0;
}
*/
#include <stdio.h>

int main(void)
{
 char url[]="tripadvisor_hotel_reviews.csv",
      ch1;
  int rating;
 FILE *arq;
 
 arq = fopen(url, "r");
 if(arq == NULL)
   printf("Erro, nao foi possivel abrir o arquivo\n");
 else
  while( (fscanf(arq,"%c %d", &ch1, &rating))!='2' )
   printf("%c %d\n", ch1, rating);
 
 fclose(arq);
 
 return 0;
}