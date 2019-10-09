#include <stdio.h>
#include <stdlib.h>

int main()
{
   char letra;
   char letraMax;
   char letraMin;
   int numero;
   int acumuladorNeg = 0;
   int acumuladorPos = 0;
   int contPos = 0;
   int contPares = 0;
   int contImpares = 0 ;
   int contCeros = 0;
   int maximo;
   int minimo;
   int flag = 0;
   float promedioPos = 0;
   int seguir;

   do
   {
       printf("Ingrese una letra: ");
       fflush(stdin);
       scanf("%c", &letra);

       printf("Ingrese un numero -100 y 100);");
       scanf("%d", &numero);

       while(!(numero >= -100 && numero <= 100))
       {
           printf("Error. Ingrese numero -100 y 100.");
           scanf("%d", &numero);
       }
            if(numero % 2 == 0)
            {
                contPares++;
            }
            else
            {
                contImpares++;
            }

            if(numero > 0)
            {
                acumuladorPos += numero;
                contPos++;
            }
            else if(numero < 0)
            {
                acumuladorNeg += numero;
            }
            else
            {
                contCeros++;
            }

            if(numero > maximo || flag == 0)
            {
                maximo == numero;
                letraMax = letra;
            }
            if(numero < minimo || flag == 0)
            {
                minimo == numero;
                letraMin = letra;
                flag = 1;
            }

        printf("Quiere continuar?: ");
        fflush(stdin);
        scanf("%c", &seguir);
   }while(seguir == 's');

   if (contPos != 0){

    promedioPos = (float) acumuladorPos / contPos;
   }
}
