#include <stdio.h>
#include <stdlib.h>

int factorial (int);

int main()
{
    printf("El factorial del numero es %d", factorial(5));
    //para sacar el factorial de un numero grande se pone %lli (long long int)
}
int factorial (int x)
{
    int factorial = 1;

    if(x > 1)
    {
        factorial = x * factorial(x-1);
    }

    return factorial;

    //int factorial = 1;

    /*while(x > 1)
    {
        factorial = factorial * x;
        x--;

        return factorial;
    }*/
}
