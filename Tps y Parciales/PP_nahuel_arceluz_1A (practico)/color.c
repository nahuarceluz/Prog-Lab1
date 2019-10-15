#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"

int cargarColorAuto(int idColor, eColor color[], int tColor, char descripcion[])
{
    int todoOk = 0;

    for(int i=0; i<tColor; i++)
    {
        if(idColor == color[i].id)
        {
            strcpy(descripcion, color[i].nombreColor);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

int harcodearColores(eColor colores[], int tColor, int cantidad)
{
    eColor suplentes[] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"}
    };

    int cont = 0;

    if( cantidad <= 10 && tColor >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            colores[i] = suplentes[i];
            cont++;
        }
    }

}

void mostrarColor(eColor colores)
{
    printf("%d  %10s\n", colores.id, colores.nombreColor);
}

void mostrarColores(eColor colores[], int tam)
{
    printf("\nId     Descripcion\n");
    printf("---------------------\n");
    for(int i=0; i < tam; i++)
    {
        mostrarColor(colores[i]);
    }
}
