#include <stdio.h>
#include <stdlib.h>
#include "autos.h"

#define TAM 3

int main()
{
    char salir = 's';
    /*eAutos coche [TAM] =
    {
        {102, "Renault", "Doce", 15000, 1980},
        {100, "Chevrolet", "Corsa", 30000, 2006},
        {101, "Ford", "Fiesta", 60000, 1996}
    };*/

    eAutos coche[TAM];
    inicializarAuto(coche, TAM);

    do
    {
        switch(menu())
        {
        case 1:
            altaAuto(coche, TAM);
            break;
        case 2:
            bajaAuto(coche, TAM);
            break;
        case 3:
            mostrarAutos(coche, TAM);
            break;
        case 4:
            ordenarAutos(coche, TAM);
            mostrarAutos(coche, TAM);
            break;
        case 5:
            salir = getchar();
            printf("Bye\n");
            break;
        }
        system("pause");

    }
    while(salir == 's');
}


