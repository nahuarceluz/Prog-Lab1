#include <stdio.h>
#include <stdlib.h>

int getIntRange(char*, char*, int, int, int, int);

int main()
{
    printf("%d - perfecto!\n", getIntRange("Ingrese nota: ", "Error. Ingrese nota: ", 18, 65, 3, -1));

    return 0;
}

int getIntRange(char* mensaje, char* mensajeError, int min, int max, int intentos, int retornoError)
{
    int numero;

    printf("%s", mensaje);
    scanf("%d", &numero);
    while(numero < min || numero > max)
    {
        printf("%s", mensajeError);
        scanf("%d", &numero);
    }
    while(numero < intentos)
    {
        printf("Usted alcanzo el limite de intentos!", retornoError);
    }


    return numero;
}
