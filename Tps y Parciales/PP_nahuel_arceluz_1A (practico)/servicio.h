#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;

}eServicio;

#endif // SERVICIO_H_INCLUDED

int harcodearServicios(eServicio servicios[], int tServicios, int cantidad);
void mostrarServicio(eServicio servicio);
void mostrarServicios(eServicio servicios[], int tServicio);
int cargarDescServicio(int idServicio, eServicio servicio[], int tServicio, char descripcion[]);
