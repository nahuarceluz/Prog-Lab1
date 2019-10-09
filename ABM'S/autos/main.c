#include <stdio.h>
#include <stdlib.h>
#include "autos.h"

#define TAM 1
#define TAMC 2

int main()
{
    eColor color[TAMC] = {{1, "Rojo"}, {2, "Azul"}, {3, "Verde"}};
    eAutos coche [TAM];

    hardcodearAutos(coche, TAM, 1);

    //inicializarAuto(coche, TAM);

    char salir = 's';

    do
    {
        switch(menu())
        {
        case 1:
            altaAuto(coche, TAM, color, TAMC);
            break;
        case 2:
            bajaAuto(coche, TAM, color, TAMC);
            break;
        case 3:
            modificarAuto(coche, TAM, color, TAMC);
            break;
        case 4:
            mostrarAutos(coche, TAM, color, TAMC);
            break;
        case 5:
            ordenarAutos(coche, TAM, color, TAMC);
            mostrarAutos(coche, TAM, color, TAMC);
            break;
        case 6:
            salir = getchar();
            printf("Bye\n");
            break;
        }
        system("pause");

    }
    while(salir == 's');
}


