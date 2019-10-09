#include <stdio.h>
#include <stdlib.h>

int sumarV4(void);

int main()
{
    int rta;

    rta = sumarV4();

    printf("La suma es %d\n", rta);
    sumarV4();
    return 0;
}

//funcion sumarV4: devuelve ALGO y recibe NADA

int sumarV4 (void)
{
    int numero1;
    int numero2;
    int suma;

    printf("Ingrese numero: ");
    scanf("%d", &numero1);

    printf("Ingrese numero: ");
    scanf("%d", &numero2);

   suma = numero1 + numero2;

   printf("La suma %d\n", suma);

   return suma;
}
