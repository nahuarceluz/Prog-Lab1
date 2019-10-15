#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"
#include "marca.h"
#include "servicio.h"
#include "trabajo.h"
#include "auto.h"


int buscarLibreTrabajo(eTrabajo trabajos[], int tTrabajo)
{

    int indice = -1;

    for(int i=0; i < tTrabajo; i++)
    {
        if(trabajos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tServicios)
{
    char descServicio[100];

    cargarDescServicio(trabajo.idServicio, servicios, tServicios, descServicio);
    printf("%d    %10s     %10s      %d/%d/%d\n", trabajo.id, trabajo.patente, descServicio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
}

void mostrarTrabajos(eTrabajo trabajos[], int tTrabajo, eServicio servicios[], int tServicio)
{
    int flag = 0;
    system("cls");
    printf("**Listado de trabajos**\n\n");

    printf("Id        Patente        Servicio       Fecha\n");
    printf("------------------------------------------------\n");
    for(int i=0; i < tTrabajo; i++)
    {
        if(trabajos[i].isEmpty == 0)
        {
            mostrarTrabajo(trabajos[i], servicios, tServicio);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("No hay trabajos que mostrar\n");
    }
}

int harcodearTrabajo(eTrabajo trabajo[], int tTrabajo, int cantidad)
{
    eTrabajo suplentes [] =
    {
        {100, "ABC100", 20000, {19, 06, 2017}, 0},
        {101, "GCV343", 20001, {25, 01, 1990}, 0}
    };

    int cont = 0;

    if(cantidad <= 10 && tTrabajo >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            trabajo[i] = suplentes[i];
            cont++;
        }
    }
}

int altaTrabajo(eTrabajo trabajos[], int tTrabajo, int idTrabajo, eAuto autos[], int tAutos, eMarca marcas[], int tMarcas, eColor colores[], int tColores, eServicio servicios[], int tServicio)
{
    int todoOk = 0;
    int indice;
    char patente[20];
    int idServicio;
    eFecha fecha;

    system("cls");
    printf("*****Alta Trabajo*****\n\n");

    indice = buscarLibreTrabajo(trabajos, tTrabajo);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        mostrarAutos(autos, tAutos, marcas, tMarcas, colores, tColores);
        printf("Ingrese la patente del auto: ");
        gets(patente);

        mostrarServicios(servicios, tServicio);
        printf("Ingrese el servicio: ");
        scanf("%d", &idServicio);

        printf("Ingrese fecha(dd/mm/aaaa): ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);


        trabajos[indice] = newTrabajo(idTrabajo, patente, idServicio, fecha);
        todoOk = 1;
        printf("\nEl alta de su trabajo se ha realizado correctamente\n");
    }

    return todoOk;
}

eTrabajo newTrabajo(int id, char patente[], int idServicio, eFecha fecha)
{
    eTrabajo nuevoTrabajo;
    nuevoTrabajo.id = id;
    strcpy(nuevoTrabajo.patente, patente);
    nuevoTrabajo.idServicio = idServicio;
    nuevoTrabajo.fecha = fecha;
    nuevoTrabajo.isEmpty = 0;

    return nuevoTrabajo;
}

void inicializarTrabajo(eTrabajo trabajos[], int tTrabajo)
{
    for(int i = 0; i < tTrabajo; i++)
    {
        trabajos[i].isEmpty = 1;
    }
}
