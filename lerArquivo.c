#include <stdio.h>
#include <stdlib.h>
#define MAX_LINHA 21000

/*int main(void)
{
 char url[]="tripadvisor_hotel_reviews.csv",//passando o arquivo para o vetor char
      ch;
 int num=0;
 FILE *arq;
  
 arq = fopen(url, "r"); //lendo o arquivo//
 if(arq == NULL){
   printf("Erro, nao foi possivel abrir o arquivo\n");
 }

 else{
  for(num =0; (ch=fgetc(arq)) != EOF; num++ ){
  
  }
 //printf("Existem %d linhas no arquivo\n", num);
 fclose(arq);
 
 return 0;
}*/

/*int main(int argc, char const *argv[])
{
  //char url[] = "tripadvisor_hotel_reviews.csv";
  FILE *arq;
  char *sub;

  arq = fopen("tripadvisor_hotel_reviews.csv", "r");

  sub = strtok(arq, "\n");

  while(sub != NULL){
    printf("%c", sub);


  }

  fclose(arq);



  return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *pt;
    FILE* fp = fopen("tripadvisor_hotel_reviews.csv", "r");

    pt = strtok(fp, "\n");
    while(pt){
        printf("review: %s\n", pt);
        pt = strtok(NULL, "!. ");
    }
    

    return 0;
}