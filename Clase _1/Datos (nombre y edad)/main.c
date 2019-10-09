#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[20];
    int edad;

    printf("Ingresa tu nombre pelotudo: ");
    gets(nombre); //toma todo lo que yo escriba
    printf("Que nombre de mierda tenes hermano\n", nombre);

    printf("Ahora tu edad: ");
    fflush(stdin); //para limpiar la entrada estandar, borrando el enter.
    scanf("%d", &edad);
    printf("Estas hecho mierda..\n", edad);

    printf("Te llamas %s y tenes %d anios", nombre, edad);

    /*printf("Edad vale %d", edad); //no usar variables sin inicializar, te puede quedar basura de memoria.*/
}

