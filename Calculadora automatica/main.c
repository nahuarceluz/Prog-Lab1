#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int suma = 0;

    printf("Ingrese numero: ");
    scanf("%d", &numero);

    for (int i = 0; i < numero; i++)
    {
        if(numero >= 9)
        {
            suma = numero + 2;
        }
        else
        {
            suma = numero - 2;
        }
    }

        printf("La cuenta da %d", suma);
}
