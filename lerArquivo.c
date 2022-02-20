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

int main(int argc, char *argv[])
{   
    // abre arquivo
    FILE* fp = fopen("tripadvisor_hotel_reviews.csv", "r");
    if (fp == NULL) 
    {
        printf("Falha ao abrir o arquivo");
        return(1);
    }

    // separa linhas
    char linha[MAX_LINHA];
    char *campo;
    while (fgets(linha, MAX_LINHA, fp) != EOF) 
    {
        printf("Linha: %s", linha);

        // separa tokens
        printf("Campos:\n");
        campo = strtok(linha,"\n");
        while( campo != NULL ) 
        {
            printf( "--> %s\n", campo);
            campo = strtok(NULL, "\n");
        }
    }

    fclose(fp);
    return(0);
}

