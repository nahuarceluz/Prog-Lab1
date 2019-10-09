#include <stdio.h>
#include <stdlib.h>

float calcularSupCirculo(float radio);

int main()
{
    float radio;
    float superficie;

    printf("Ingrese radio: ");
    scanf("%f", &radio);

    superficie = calcularSupCirculo(radio);

    printf("La superficie es %.2f\n\n");

    return 0;
}

float calcularSupCirculo(float radio)
{
    float resultado;

    resultado = 3.14 * radio * radio;

    return resultado;
}
