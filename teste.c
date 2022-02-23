/* Receives strings from keyboard and writes them to file */
#include <stdio.h>
main( )
{
  FILE *fOriginal, *fCopia;
  char ch;
  fOriginal = fopen ("Arquivo1.txt", "r" );
  if (fOriginal == NULL )
  {
    puts ( "Não foi possivel abrir o arquivo!!!" ) ;
    exit(0) ;
  }
  fCopia = fopen ("Copia_Arquivo1.txt", "w" );
  if (fCopia == NULL )
  {
    puts ( "Não foi possivel gravar o arquivo!!!" ) ;
    exit(0) ;
  }
  while ( 1 )
  {
    ch = fgetc(fOriginal);
    if(ch==EOF)
      break;
    fputc (ch, fCopia);
  }
  fclose (fOriginal);
  fclose (fCopia);
  return 0;
}