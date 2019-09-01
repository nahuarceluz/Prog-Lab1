#include <stdio.h>
#include <stdlib.h>

void sumarV3(); //poner VOID entre los parentesis no es obligatorio.

int main()
{
    sumarV3();
    return 0;
}

//funcion sumarV3: devuelve NADA y recibe NADA

void sumarV3(void)
{
    int numero1;
    int numero2;
    int suma;

    printf("Ingrese numero: ");
    scanf("%d", &numero1);

    printf("Ingrese numero: ");
    scanf("%d", &numero2);

   suma = numero1 + numero2;

   printf("La suma es %d\n\n", suma);
}
