#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int acumulador = 0;
    int contador = 0;
    float promedio;

    for (int i=0; i<5; i++)
        {
            printf("Ingrese numero: ");
            scanf("%d", &numero);

            acumulador = acumulador + numero;
        }

        promedio = (float) acumulador / 5;

        printf("La suma de los numeros es %d y el promedio es %.2f\n", acumulador, promedio);
}
