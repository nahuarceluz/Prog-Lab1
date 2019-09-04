#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*int elementos[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(int i = 0; i<10; i++)
    {
        printf("%d,", elementos[i]);
    }*/

    int numeros[5];
    int indice;
    int mayor;
    int flag = 0;

    for(int i; i < 5; i++)
    {
        printf("Ingrese un numero positivo: ");
        scanf("%d", &numeros[i]);

        while(numeros[i] <= 0)
        {
            printf("Error. Ingrese un numero positivo: ");
            scanf("%d", &numeros[i]);
        }
    }
    for(int i; i < 5; i++)
    {
        printf("%d", numeros[i]);
    }

    for(int i; i < 5; i++)
    {
        if(numeros[i] > mayor || flag == 0)
            mayor = numeros[i];
        flag = 1;
    }

    printf("EL mayor numero ingresado es %d y esta en el indice ", mayor);

    for(int i; i < 5; i++) //Se utiliza para buscar si hay dos numeros mayores igual.
    {
        if(numeros[i] == mayor)
        {
            printf("%d", i);
        }
    }

}
