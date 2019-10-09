#include <stdio.h>
#include <stdlib.h>

void sumarV2(int a, int b);

int main()
{
    int numero1;
    int numero2;

    sumarV2();

    return 0;
}

//funcion sumarV2: devuelve NADA y recibe ALGO
void sumarV2(int a, int b)
{
    int rta;

    rta = a + b;

    printf("La suma es %d\n", rta);
}
