#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "marca.h"

void mostrarMarca(eMarca marcas)
{
    printf("%d  %10s\n", marcas.id, marcas.descripcion);
}

void mostrarMarcas(eMarca marcas[], int tMarca)
{
    printf("\nId     Descripcion\n");
    printf("---------------------\n");
    for(int i=0; i <tMarca; i++)
    {
        mostrarMarca(marcas[i]);
    }
}

int harcodearMarcas(eMarca marcas[], int tam, int cantidad)
{
    eMarca suplentes[] =
    {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"}
    };

    int cont = 0;

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            marcas[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

int cargarMarcaAuto(int idMarca, eMarca marcas[], int tMarca, char descripcion[])
{
    int todoOk = 0;

    for(int i=0; i<tMarca; i++)
    {
        if( idMarca == marcas[i].id)
        {
            strcpy(descripcion, marcas[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}
