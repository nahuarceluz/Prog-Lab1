#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[20];
    int edad;
    char genero[20];


    printf("Ingrese nombre: ");
    gets(nombre);
    printf("Ingrese edad: ");
    scanf("%d", &edad);
    printf("Ingrese genero: ");
    scanf("%s", &genero);
    printf("\n***************************");
    printf("***************************\n\n");
    printf("Su nombre es %s, tiene %d anios y su genero es %s.\n", &nombre, edad, &genero);
    printf("Bienvenido, su registro se completo correctamente.\n");

}
