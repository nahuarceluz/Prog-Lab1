#include <stdio.h>
#include <stdlib.h>

int sumarV1 (int a, int b); //prototipo de la funcion sumar

int main()
{
    int numero1;
    int numero2;
    int suma;

    printf("Ingrese numero: ");
    scanf("%d", &numero1);

    printf("Ingrese numero: ");
    scanf("%d", &numero2);

   suma = sumarV1(numero1, numero2); //Llamada de la funcion. Le paso dos enteros. //Las variables son parametros actuales.


    printf("La suma es es %d.\n\n", suma);
    return 0;

}

//funcion sumarV1: devuelve ALGO y recibe ALGO.
int sumarV1 (int a, int b) //Desarrollo de la funcion. Recibe DOS enteros. //Las variables son parametros formales.

{
    int rta;

    rta = a + b;

    return rta;
}
