#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include "autos.h"

void mostrarAuto(eAutos car)
{
    printf("  %2d      %10s  %10s        %2d     %2d\n", car.numeroDeSerie, car.modelo, car.marca, car.precio, car.anio);

}

void mostrarAutos(eAutos car[], int tam)
{
    int flag = 0;
    system("cls");
    printf("**Listado de autos**\n\n");

    printf("N.Serie         Marca       Modelo       Precio    Anio\n");
    for(int i=0; i<tam; i++)
    {
        if(car[i].isEmpty == 0)
        {
            mostrarAuto(car[i]);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        system("cls");
        printf("\n---No hay alumnos que mostrar---\n");
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
    printf("3- Listar Autos\n");
    printf("4- Ordenar Autos\n");
    printf("5- Salir\n\n");

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

eAutos newAuto(int numeroDeSerie, char marca[], char modelo[], int precio, int anio)
{
    eAutos nuevoAuto;
    nuevoAuto.numeroDeSerie = numeroDeSerie;
    strcpy(nuevoAuto.marca, marca);
    strcpy(nuevoAuto.modelo, modelo);
    nuevoAuto.precio = precio;
    nuevoAuto.anio = anio;
    nuevoAuto.isEmpty = 0;

    return nuevoAuto;
}

int altaAuto(eAutos autos[], int tam)
{
    int numeroDeSerie;
    char marca[20];
    char modelo[40];
    int precio;
    int anio;
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
            mostrarAuto(autos[esta]);
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

            autos[indice] = newAuto(numeroDeSerie, marca, modelo, precio, anio);
            todoOk = 1;
        }
    }
    return todoOk;
}

int bajaAuto(eAutos autos[], int tam)
{

    int todoOk = 0;
    int indice;
    int numeroDeSerie;
    char confirma;

    system("cls");
    printf("**** Baja Alumno ****\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &numeroDeSerie);

    indice = buscarAuto(numeroDeSerie, autos, tam);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese legajo\n");
        system("pause");
    }
    else
    {
        mostrarAuto(autos[indice]);
        printf("\nConfirma eliminacion?: ");
        fflush(stdin);
        confirma = getchar();
        if( confirma == 's')
        {
            autos[indice].isEmpty = 1;
            printf("\n\nSe ha eliminado el alumno\n");
            todoOk = 1;
        }
        else
        {
            printf("\n\nSe ha cancelado la baja\n");
        }
        system("pause");
    }
    return todoOk;
}


/*int modificarAuto(eAutos autos[], int tam)
{

    int todoOk = 0;
    int indice;
    int numeroDeSerie;
    int opcion;
    int nota;


    system("cls");
    printf("**** Modificar Auto ****\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &numeroDeSerie);

    indice = buscarAuto(numeroDeSerie, autos, tam);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese legajo\n");
        system("pause");
    }
    else
    {
        mostrarAuto(autos[indice]);

        printf("Modificar\n\n");
        printf("Nota parcial 1\n");
        printf("Nota parcial 2\n");

        printf("Ingrese opcion:");
        scanf("%d", &opcion);

        if( opcion == 1)
        {
            printf("Ingrese nota 1: ");
            scanf("%d", &nota);
            // falta validar nota
            alumnos[indice].nota1 = nota;
            alumnos[indice].promedio = (float) (alumnos[indice].nota1 + alumnos[indice].nota2)/2;
            printf("Se actualizo la nota");
            todoOk = 1;
        }
        else if( opcion == 2)
        {
            printf("Ingrese nota 2: ");
            scanf("%d", &nota);
             // falta validar nota
            alumnos[indice].nota2 = nota;
            alumnos[indice].promedio = (float) (alumnos[indice].nota1 + alumnos[indice].nota2)/2;
            printf("Se actualizo la nota");
            todoOk = 1;

        }
        else
        {
            printf("No es una opcion valida\n");
        }

        system("pause");
    }
    return todoOk;
}*/
