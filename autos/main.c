#include <stdio.h>
#include <stdlib.h>
#include "autos.h"

#define TAM 3

int main()
{
    eAutos coche [TAM] =
    {
    {102, "Renault", "Doce", 15000, 1980},
    {100, "Chevrolet", "Corsa", 30000, 2006},
    {101, "Ford", "Fiesta", 60000, 1996},
    };
    printf("Desordenados\n");
    mostrarAlumnos(coche, TAM);

    printf("\nOrdenados\n");
    ordenarAlumnos(coche, TAM);
    mostrarAlumnos(coche, TAM);
}


