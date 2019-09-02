#include <stdio.h>
#include <stdlib.h>

int getIntRange(int min, int max);

int main()
{
    printf("%d - bien!\n", getIntRange(18, 65));

    return 0;
}

int getIntRange(int min, int max)
{
    int numero;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    while(numero < min || numero > max)
    {
        printf("Error. Ingrese un numero: ");
        scanf("%d", &numero);
    }

    return numero;
}
