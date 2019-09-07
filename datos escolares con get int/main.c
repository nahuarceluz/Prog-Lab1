#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nota;
    int nota2;
    char alumno[50];

    getIntDatos("Ingrese alumno: ", "Ingrese primera nota: ", "Ingrese segunda nota: ");

    printf("Alumno: %s\n", alumno);
    printf("Nota 1: %d\n", nota);
    printf("Nota 2: %d\n", nota2);
}

int getIntDatos(char* nombre, char* mensaje, char* mensaje2)
{
    int nota;
    int nota2;
    char alumno[50];

    printf("%s", nombre);
    fflush(stdin);
    scanf("%s", &alumno);

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &nota);

    printf("%s", mensaje2);
    fflush(stdin);
    scanf("%s", &nota2);
}
