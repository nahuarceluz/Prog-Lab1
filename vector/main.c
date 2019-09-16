#include <stdio.h>
#include <stdlib.h>

#define TAM 8

int main()
{
    int numeros[] = {1, 2, 3, 5, 7, 3, 7, 2, 1};
    //char letras[] = {'N', 'a', 'h', 'u', 'e', 'l', '\0'};
    char letras [] = {"nahuel"};

    for(int i = 0; i < 1; i++)
    {
        printf("El alumno se llama %s\n\n", letras);
    }

    for(int i = 0; i <TAM ; i++)
    {
        printf("%d ", numeros[i]);
    }


    return 0;
}
