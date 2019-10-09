#include <stdio.h>
#include <stdlib.h>

int sumar1(int a, int b); //prototipo de la funcion. Devuelve un entero y recibe dos enteros.

int main()
{
    int numero1;
    int numero2;
    int suma;

    printf("Ingrese numero: ");
    scanf("%d", &numero1);

    printf("Ingrese numero: ");
    scanf("%d", &numero2);

    suma = sumar1(numero1, numero2); //Llamada de la funcion. Le paso dos enteros.

    printf("La suma de los numeros es %d.\n", suma);
    return 0;
}

int sumar1(int a, int b) //desarrollo de la funcion
{
    for (int i=0; i<5; i++)
    {
        printf("Ingrese numero: ");
        scanf("%d", &numero);

        acumulador = acumulador + numero;
    }
}
