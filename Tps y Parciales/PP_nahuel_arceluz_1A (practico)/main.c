#include <stdio.h>
#include <stdlib.h>

#define TAUTO 3
#define TTRABAJO 3
#define TCOLOR 5
#define TMARCA 5
#define TSERVICIO 4

#include "color.h"
#include "marca.h"
#include "servicio.h"
#include "trabajo.h"
#include "auto.h"

int main()
{
    int salir = 'n';

    //harcodearAutos(coche, TAUTO, 3)
    eAuto coche[TAUTO];
    inicializarAuto(coche, TAUTO);

    eColor color[TCOLOR];
    harcodearColores(color, TCOLOR, 5);

    eMarca marca[TMARCA];
    harcodearMarcas(marca, TMARCA, 5);

    eServicio servicio[TSERVICIO];
    harcodearServicios(servicio, TSERVICIO, 4);

    eTrabajo trabajo[TTRABAJO];
    inicializarTrabajo(trabajo, TTRABAJO);
    int idTrabajo = 100;
    //idTrabajo = idTrabajo + harcodearTrabajo(trabajo, TTRABAJO, 2);

    do
    {
        switch(menuAuto())
        {
        case 1:
            altaAuto(coche, TAUTO, marca, TMARCA, color, TCOLOR);
            break;
        case 2:
            modificarAuto(coche, TAUTO, marca, TMARCA, color, TCOLOR);
            break;
        case 3:
            bajaAuto(coche, TAUTO, marca, TMARCA, color, TCOLOR);
            break;
        case 4:
            ordenarAutos(coche, TAUTO, marca, TMARCA, color, TCOLOR);
            mostrarAutos(coche, TAUTO, marca, TMARCA, color, TCOLOR);
            break;
        case 5:
            mostrarMarcas(marca, TMARCA);
            break;
        case 6:
            mostrarColores(color, TCOLOR);
            break;
        case 7:
            mostrarServicios(servicio, TSERVICIO);
            break;
        case 8:
            if(altaTrabajo(trabajo, TTRABAJO, idTrabajo, coche, TAUTO, marca, TMARCA, color, TCOLOR, servicio, TSERVICIO));
            {
                idTrabajo++;
            }
            break;
        case 9:
            mostrarTrabajos(trabajo, TTRABAJO, servicio, TSERVICIO);
            break;
        case 10:
            printf("Menu finalizado\n");
            salir = getchar();
            break;
        default:
            printf("Opcion invalida..\n");
            break;
        }
        system("pause");
    }while(salir == 'n');
}
