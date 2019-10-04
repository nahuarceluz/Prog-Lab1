#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "empleados.h"

#define TAM 4

int main()
{
    int salir = 'n';
    //eEmpleado lista[TAM];
    int id = 100;
    //inicializarEmpleados(lista, TAM);

    eEmpleado lista[TAM] =
    {
        {105, "Juan", "Perez", 14.6, 3},
        {103, "Roberto", "Gonzalez", 20.3, 1},
        {101, "Eugenio", "Ortiz", 60.5, 4},
        {104, "Ana", "Fernandez", 45, 2},
        {100, "Lucrecia", "Lopez", 96, 5},
    };

    do
    {
        switch(menuEmpleados())
        {
        case 1:
            if(altaEmpleado(lista, TAM, id))
            {
                id++;
            }
            break;
        case 2:
            modificarEmpleado(lista, TAM);
            break;
        case 3:
            bajaEmpleado(lista, TAM);
            break;
        case 4:
            informarEmpleados(lista, TAM);
            break;
        case 5:
            printf("5. Bye bye\n");
            salir = getchar();
            break;
        default:
            printf("Opcion invalida");
            break;
        }
        system("pause");

    }
    while(salir == 'n');
}
