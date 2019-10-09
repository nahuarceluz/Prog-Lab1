#include <stdio.h>
#include <stdlib.h>

void mostrarNombres(char matriz[][20]); //dejo libre la cantidad de filas..

int main()
{
    char nombres[5][20];

    for(int i=0; i<5; i++)
    {
        printf("Ingrese un nombre: ");
        fflush(stdin);
        gets(nombres[i]);

        mostrarNombres(nombres, 5);
    }

    return 0;
}

void mostrarNombres(char matriz[][20])
{
    for(int i=0; i<5; i++)
    {
        printf("%s\n", nombres[i]);
    }
    printf("\n");
}
