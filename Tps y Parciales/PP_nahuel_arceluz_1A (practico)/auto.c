#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"
#include "marca.h"
#include "servicio.h"
#include "auto.h"

int menuAuto()
{
    int opcion;
    system("cls");
    printf("Menu de Opciones\n\n");
    printf("1- Alta Auto\n");
    printf("2- Modificar Auto\n");
    printf("3- Baja Auto\n");
    printf("4- Listar Autos\n");
    printf("5- Listar Marcas\n");
    printf("6- Listar Colores\n");
    printf("7- Listar Servicios\n");
    printf("8- Alta Trabajo\n");
    printf("9- Listar Trabajos\n");
    printf("10- Salir\n\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarAuto(eAuto autos[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        autos[i].isEmpty = 1;
    }
}

int buscarLibreAuto(eAuto autos[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(autos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAuto(char patente[], eAuto autos[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(autos[i].isEmpty == 0 && strcmp(autos[i].patente, patente) == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAutoId(int id, eAuto autos[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(autos[i].isEmpty == 0 && autos[i].idAuto == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

eAuto newAuto(int idAuto, char patente[], int idMarca, int idColor, int modelo)
{
    eAuto nuevoAuto;
    nuevoAuto.idAuto = idAuto;
    strcpy(nuevoAuto.patente, patente);
    nuevoAuto.idMarca = idMarca;
    nuevoAuto.idColor = idColor;
    nuevoAuto.modelo = modelo;
    nuevoAuto.isEmpty = 0;

    return nuevoAuto;
}

int altaAuto(eAuto autos[], int tAuto, eMarca marcas[], int tMarcas, eColor colores[], int tColores)
{
    int idAuto;
    char patente[51];
    int idMarca;
    int idColor;
    int modelo;
    int esta;
    int indice;
    int todoOk = 0;

    system("cls");
    printf("**** Alta Autos ****\n\n");

    indice = buscarLibreAuto(autos, tAuto);

    if( indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas autos\n");
    }
    else
    {
        printf("Ingrese id auto: ");
        scanf("%d", &idAuto);

        esta = buscarAutoId(idAuto, autos, tAuto);

        if( esta != -1)
        {
            printf("Auto ya registrado. Vuelvalo a intentar..\n");
        }
        else
        {
            printf("Ingrese patente: ");
            scanf("%s", &patente);

            mostrarMarcas(marcas, tMarcas);
            printf("\nIngrese marca: ");
            fflush(stdin);
            scanf("%d", &idMarca);

            mostrarColores(colores, tColores);
            printf("Ingrese un color: ");
            fflush(stdin);
            scanf("%d", &idColor);

            printf("Ingrese modelo: ");
            fflush(stdin);
            scanf("%d", &modelo);

            autos[indice] = newAuto(idAuto, patente, idMarca, idColor, modelo);
            todoOk = 1;
            printf("\nEl alta de su vehiculo se ha realizado correctamente\n");
        }
    }
    return todoOk;
}

void mostrarAuto(eAuto car, eMarca marcas[], int tMarca, eColor color[], int tColor)
{
    char descColor[100];
    char descMarca[100];

    cargarMarcaAuto(car.idMarca, marcas, tMarca, descMarca);
    cargarColorAuto(car.idColor, color, tColor, descColor);
    printf("%d %10s  %10s%10s      %d\n", car.idAuto, car.patente, descMarca, descColor, car.modelo);
}

void mostrarAutos(eAuto autos[], int tAuto, eMarca marcas[], int tMarca, eColor color[], int tColor)
{
    int flag = 0;
    system("cls");
    printf("**Listado de autos**\n\n");

    printf("Id     Patente       Marca     Color     Modelo\n");
    printf("------------------------------------------------------------------------\n");
    for(int i=0; i<tAuto; i++)
    {
        if(autos[i].isEmpty == 0)
        {
            mostrarAuto(autos[i], marcas, tMarca, color, tColor);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        system("cls");
        printf("---No hay autos que mostrar---\n");
    }
}

int bajaAuto(eAuto autos[], int tAuto, eMarca marcas[], int tMarcas, eColor colores[], int tColores)
{

    int todoOk = 0;
    int indice;
    char confirma;
    char patente[100];

    system("cls");
    printf("**** Baja Auto ****\n\n");

    printf("Ingrese patente del auto: ");
    scanf("%s", &patente);

    indice = buscarAuto(patente, autos, tAuto);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese auto\n");
    }
    else
    {
        printf("Id     Patente     Marca       Color    Modelo\n");
        printf("----------------------------------------------------\n");
        mostrarAuto(autos[indice], marcas, tMarcas, colores, tColores);
        printf("\nConfirma eliminacion?: ");
        fflush(stdin);
        confirma = getchar();
        if( confirma == 's')
        {
            autos[indice].isEmpty = 1;
            printf("\nSe ha eliminado el auto de nuestros registros\n");
            todoOk = 1;
        }
        else
        {
            printf("Se ha cancelado la baja\n");
        }

    }
    return todoOk;
}

int modificarAuto(eAuto autos[], int tAuto, eMarca marcas[], int tMarcas, eColor colores[], int tColores)
{

    int todoOk = 0;
    int indice;
    int idColor;
    int modelo;
    int salir = 'n';
    char patente[100];

    system("cls");
    printf("***** Modificar Datos del auto *****\n\n");
    printf("Ingrese patente del auto: ");
    scanf("%s", &patente);

    indice = buscarAuto(patente, autos, tAuto);

    if( indice == -1)
    {
        printf("No existe un alumno con ese legajo\n\n");

    }
    else
    {
        printf("Id     Patente     Marca       Color    Modelo\n");
        printf("----------------------------------------------------\n");
        mostrarAuto(autos[indice], marcas, tMarcas, colores, tColores);
        system("pause");

        do
        {
            switch(menuModificarAuto())
            {
            case 1:
                mostrarColores(colores, tColores);
                printf("Ingrese id-Color: ");
                scanf("%d", &idColor);
                autos[indice].idColor = idColor;
                printf("Se actualizo el color correctamente\n");
                todoOk = 1;
                system("pause");
                break;
            case 2:
                printf("Ingrese modelo: ");
                scanf("%d", &modelo);
                autos[indice].modelo = modelo;
                printf("Se actualizo el modelo del auto correctamente\n");
                todoOk = 1;
                system("pause");
                break;
            case 6:
                mostrarAutos(autos, tAuto, marcas, tMarcas, colores, tColores);
                system("pause");
                break;
            case 7:
                printf("Bye bye\n");
                salir = getchar();
                break;
            }
        }
        while(salir == 'n');

    }
    return todoOk;
}

int menuModificarAuto()
{
    int opcion;

    system("cls");
    printf("Bienvenido al submenu para modificar los datos de los autos.\n");
    printf("1. Modificar color\n");
    printf("2. Modificar modelo\n");
    printf("6. Listar Autos\n");
    printf("7. Salir\n\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void ordenarAutos(eAuto autos[], int tAutos, eMarca marcas[], int tMArcas, eColor colores[], int tColor)
{
    eAuto auxMarca;
    eAuto auxPatente;

    for(int i= 0; i <tAutos-1 ; i++)
    {
        for(int j= i+1; j<tAutos; j++)
        {
            if(autos[i].idMarca < autos[j].idMarca && autos[i].isEmpty == 0 && autos[j].isEmpty == 0)
            {
                auxMarca = autos[i];
                autos[i] = autos[j];
                autos[j] = auxMarca;
            }
            else if(autos[i].idMarca == autos[j].idMarca && strcmp(autos[i].patente, autos[j].patente) > 0)
            {
                auxPatente = autos[i];
                autos[i] = autos[j];
                autos[j] = auxPatente;
            }
        }
    }
}

int harcodearAutos(eAuto autos[], int tAuto, int cantidad)
{
    eAuto suplentes[] =
    {
        {100, "HFH565", 1000, 5001, 2012},
        {101, "ABC100", 1003, 5004, 2008},
        {106, "RWR678", 1000, 5000, 1998},
        {140, "ABC103", 1002, 5003, 2003},
        {140, "GCV343", 1000, 5000, 1990},
    };

    int cont = 0;

    if( cantidad <= 10 && tAuto >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            autos[i] = suplentes[i];
            cont++;
        }
    }

}
