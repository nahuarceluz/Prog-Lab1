#include <stdio.h>
#include <stdlib.h>

int buscarNumero(int numero, int vec[], int tam);

int main()
{
    int numeros[] = {2, 4, 3, 8, 6, 5, 9, 1 ,8, 23};
    int indice;

    indice = buscarNumero(45, numeros, 10);

    if(indice != -1)
    {
        printf("Esta en el indice %d\n");
    }
    else
    {
        printf("No esta en el indice %d\n");
    }
}

int buscarNumero(int numero, int vec[], int tam)
{
    int esta;

    for(int i; i<5; i++)
    {
        if(numero == vec[i])
        {
            esta = i;
            break;
        }
    }

    return esta;
}
