#include <stdio.h>
#include <stdlib.h>

int factorial (int);

int main()
{
    int numero;
    printf("Ingrese numero: ");
    scanf("%d", &numero);
    numero = factorial(numero);
    printf("El factorial del  numero es %d.\n", numero);
    //para sacar el factorial de un numero grande se pone %lli (long long int)
}
int factorial (int x)
{
    int fact;

    if(x == 1)
    {
        return 1;
    }

    fact = x * factorial(x-1);
    return fact;

    //int factorial = 1;

    /*while(x > 1)
    {
        factorial = factorial * x;
        x--;

        return factorial;
    }*/
}
