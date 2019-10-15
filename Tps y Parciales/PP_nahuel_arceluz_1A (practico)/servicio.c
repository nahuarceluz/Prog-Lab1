#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "servicio.h"

int harcodearServicios(eServicio servicios[], int tServicios, int cantidad)
{
    eServicio suplentes[] =
    {
        {20000, "Lavado", 240},
        {20001, "Pulido", 300},
        {20002, "Encerado", 400},
        {20003, "Completo", 600}
    };

    int cont = 0;

    if(cantidad <= 10 && tServicios >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            servicios[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

void mostrarServicio(eServicio servicio)
{
    printf("%d  %10s       %d\n", servicio.id, servicio.descripcion, servicio.precio);
}

void mostrarServicios(eServicio servicios[], int tServicio)
{
    printf("\nId     Descripcion    Precio\n");
    printf("-------------------------------------\n");
    for(int i=0; i<tServicio; i++)
    {
        mostrarServicio(servicios[i]);
    }
}

int cargarDescServicio(int idServicio, eServicio servicio[], int tServicio, char descripcion[])
{
    int todoOk = 0;

    for(int i=0; i<tServicio; i++)
    {
        if(idServicio == servicio[i].id)
        {
            strcpy(descripcion, servicio[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}
