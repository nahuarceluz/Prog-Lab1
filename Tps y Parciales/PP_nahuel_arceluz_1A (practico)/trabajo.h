#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#define FUNCIONES_H_INCLUDED

#include "color.h"
#include "marca.h"
#include "servicio.h"
#include "auto.h"

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int id;
    char patente[20];
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED

int buscarLibreTrabajo(eTrabajo trabajos[], int tTrabajo);
eTrabajo newTrabajo(int id, char patente[], int idServicio, eFecha fecha);
void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tServicios);
void mostrarTrabajos(eTrabajo trabajos[], int tTrabajo, eServicio servicios[], int tServicio);
int harcodearTrabajo(eTrabajo trabajo[], int tTrabajo, int cantidad);
int altaTrabajo(eTrabajo trabajos[], int tTrabajo, int idTrabajo, eAuto autos[], int tAutos, eMarca marcas[], int tMarcas, eColor colores[], int tColores, eServicio servicios[], int tServicio);
void inicializarTrabajo(eTrabajo trabajos[], int tTrabajo);
