#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include "autos.h"

void mostrarAuto(eAutos car, eColor colores[], int tam)
{
    char colorAuto[100];

    cargarColorAuto(car.idColor, colores, tam, colorAuto);
    printf("  %2d      %10s  %10s        %2d     %2d%10s\n", car.numeroDeSerie, car.marca, car.modelo, car.precio, car.anio, colorAuto);

}

void mostrarAutos(eAutos car[], int tam, eColor colores[], int tamC)
{
    int flag = 0;
    system("cls");
    printf("**Listado de autos**\n\n");

    printf("N.Serie         Marca       Modelo       Precio    Anio     Color\n");
    printf("------------------------------------------------------------------------\n");
    for(int i=0; i<tam; i++)
    {
        if(car[i].isEmpty == 0)
        {
            mostrarAuto(car[i], colores, tamC);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        system("cls");
        printf("---No hay alumnos que mostrar---\n");
    }
}

void ordenarAutos(eAutos car[], int tam)
{
    eAutos auxCar;

    for(int i= 0; i<tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if(car[i].numeroDeSerie > car[j].numeroDeSerie)
            {
                auxCar = car[i];
                car[i] = car[j];
                car[j] = auxCar;
            }
        }
    }
}

int menu()
{
    int opcion;
    system("cls");
    printf("Menu de Opciones\n\n");
    printf("1- Alta Auto\n");
    printf("2- Baja Auto\n");
    printf("3. Modificar Auto\n");
    printf("4- Listar Autos\n");
    printf("5- Ordenar Autos\n");
    printf("6- Salir\n\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarAuto(eAutos autos[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        autos[i].isEmpty = 1;
    }
}

int buscarLibre(eAutos autos[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( autos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAuto(int numeroDeSerie, eAutos autos[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( autos[i].isEmpty == 0 && autos[i].numeroDeSerie == numeroDeSerie)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

eAutos newAuto(int numeroDeSerie, char marca[], char modelo[], int precio, int anio, int id)
{
    eAutos nuevoAuto;
    nuevoAuto.numeroDeSerie = numeroDeSerie;
    strcpy(nuevoAuto.marca, marca);
    strcpy(nuevoAuto.modelo, modelo);
    nuevoAuto.precio = precio;
    nuevoAuto.anio = anio;
    nuevoAuto.idColor = id;
    nuevoAuto.isEmpty = 0;

    return nuevoAuto;
}

int altaAuto(eAutos autos[], int tam, eColor colores[], int tamC)
{
    int numeroDeSerie;
    char marca[20];
    char modelo[40];
    int precio;
    int anio;
    int id;
    int esta;
    int indice;
    int todoOk = 0;

    system("cls");
    printf("**** Alta Autos ****\n\n");

    indice = buscarLibre(autos, tam);

    if( indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas autos\n");
    }
    else
    {
        printf("Ingrese Numero de Serie: ");
        scanf("%d", &numeroDeSerie);

        esta = buscarAuto(numeroDeSerie, autos, tam);

        if( esta != -1)
        {
            printf("\nLegajo ya registrado\n");
            mostrarAuto(autos[esta], colores, tamC);
            system("pause");
        }
        else
        {
            printf("Ingrese marca: ");
            fflush(stdin);
            gets(marca);

            printf("Ingrese modelo: ");
            fflush(stdin);
            gets(modelo);

            printf("Ingrese precio: ");
            fflush(stdin);
            scanf("%d", &precio);

            printf("Ingrese anio: ");
            scanf("%d", &anio);

            mostrarColores(colores, tamC);
            printf("\nIngrese color a elegir: ");
            scanf("%d", &id);
            printf("Alta exitosa!!\n");

            autos[indice] = newAuto(numeroDeSerie, marca, modelo, precio, anio, id);
            todoOk = 1;
        }
    }
    return todoOk;
}

int bajaAuto(eAutos autos[], int tam, eColor colores[], int tamC)
{

    int todoOk = 0;
    int indice;
    int numeroDeSerie;
    char confirma;

    system("cls");
    printf("**** Baja Alumno ****\n\n");

    printf("Ingrese numero de serio: ");
    scanf("%d", &numeroDeSerie);

    indice = buscarAuto(numeroDeSerie, autos, tam);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese legajo\n");
        system("pause");
    }
    else
    {
        printf("N.Serie         Marca       Modelo       Precio    Anio     Color\n");
        mostrarAuto(autos[indice], colores, tamC);
        printf("------------------------------------------------------------------------\n");
        printf("\nConfirma eliminacion?: ");
        fflush(stdin);
        confirma = getchar();
        if( confirma == 's')
        {
            autos[indice].isEmpty = 1;
            printf("\n\nSe ha eliminado el auto de nuestros registros\n");
            todoOk = 1;
        }
        else
        {
            printf("\n\nSe ha cancelado la baja\n");
        }

    }
    return todoOk;
}


int modificarAuto(eAutos autos[], int tam, eColor colores[], int tamC)
{

    int todoOk = 0;
    int indice;
    int numeroDeSerie;
    char marca[20];
    char modelo[40];
    int precio;
    int anio;
    int opcion;
    int nota;
    int salir = 'n';


    system("cls");
    printf("**** Modificar Auto ****\n\n");

    printf("Ingrese id de serie: ");
    scanf("%d", &numeroDeSerie);

    indice = buscarAuto(numeroDeSerie, autos, tam);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese auto\n");
    }
    else
    {
        printf("N.Serie         Marca       Modelo       Precio    Anio     Color\n");
        printf("------------------------------------------------------------------------\n");
        mostrarAuto(autos[indice], colores, tamC);
        system("pause");

        do
        {
            switch(menuModificar())
            {
            case 1:
                printf("Ingrese numero de serie: ");
                scanf("%d", &numeroDeSerie);
                autos[indice].numeroDeSerie = numeroDeSerie;
                printf("Se actualizo el numero de serie correctamente\n");
                todoOk = 1;
                break;
            case 2:
                printf("Ingrese marca: ");
                scanf("%s", &marca);
                strcpy(autos[indice].marca, marca);
                //autos[indice].marca = marca;
                printf("Se actualizo la marca del auto\n");
                todoOk = 1;
                break;
            case 3:
                printf("Ingrese modelo: ");
                scanf("%s", &modelo);
                strcpy(autos[indice].modelo, modelo);
                printf("Se actualizo el modelo del auto\n");
                todoOk = 1;
                break;
            case 4:
                printf("Ingrese precio: ");
                scanf("%d", &precio);
                autos[indice].precio = precio;
                printf("Se actualizo el precio correctamente\n");
                todoOk = 1;
                break;
            case 5:
                printf("Ingrese anio: ");
                scanf("%d", &anio);
                autos[indice].anio = anio;
                printf("Se actualizo el anio correctamente\n");
                todoOk = 1;
                break;
            case 6:
                mostrarAutos(autos, tam, colores, tamC);
                break;
            case 7:
                printf("Bye bye\n");
                salir = getchar();
                break;
            }
            system("pause");
        }
        while(salir == 'n');
    }
}

int menuModificar()
{
    int opcion;

    system("cls");
    printf("Bienvenido al submenu para modificar los datos de los autos.\n");
    printf("1. Modificar numero de serie\n");
    printf("2. Modificar marca\n");
    printf("3. Modificar modelo\n");
    printf("4. Modificar precio\n");
    printf("5. Modificar anio\n");
    printf("6. Listar Autos\n");
    printf("7. Salir\n\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int cargarColorAuto(int id, eColor color[], int tam, char descripcion[])
{
    int todoOk = 0;

    for(int i=0; i<tam; i++){
        if( id == color[i].id)
        {
            strcpy(descripcion, color[i].color);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

int hardcodearAutos(eAutos autos[], int tam, int cantidad)
{
    int cont = 0;

    eAutos suplentes[]=
    {
        {102, "Renault", "Doce", 15000, 1980, 1, 0},
        {100, "Chevrolet", "Corsa", 30000, 1999 , 2, 0},
        {101, "Ford", "Fiesta", 60000, 1996, 1, 0}

    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            autos[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

void mostrarColor(eColor colores)
{
    printf(" %d  %10s\n", colores.id, colores.color);
}

void mostrarColores(eColor colores[], int tam)
{
    printf("\nId     Descripcion\n");
    printf("---------------------\n");
    for(int i=0; i < tam; i++){
        mostrarColor(colores[i]);
    }
}
