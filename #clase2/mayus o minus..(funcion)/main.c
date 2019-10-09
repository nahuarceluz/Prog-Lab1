#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
   char letra = 'A';

   //letra = toupper(letra); //muestra MAYUS
   letra = tolower(letra); //muetra MINUS
   printf("%c\n", letra);

   return 0;
}
