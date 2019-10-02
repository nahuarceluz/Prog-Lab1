#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "almuerzo.h"
#include "comida.h"
#include "alumno.h"

void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        almuerzos[i].isEmpty = 1;
    }
}

int hardcodearAlmuerzos(eAlmuerzo vec[], int tam, int cantidad)
{
    int cont = 0;

    eAlmuerzo suplentes[] =
    {
        { 60000, 20005, 5004, {30, 9, 2019}, 0},
        { 60001, 20003, 5004, {30, 9, 2019}, 0},
        { 60002, 20001, 5002, {30, 9, 2019}, 0},
        { 60003, 20000, 5000, {30, 9, 2019}, 0},
        { 60004, 20009, 5004, {30, 9, 2019}, 0},
        { 60005, 20003, 5005, {1, 10, 2019}, 0},
        { 60006, 20002, 5004, {1, 10, 2019}, 0},
        { 60007, 20005, 5004, {1, 10, 2019}, 0},
        { 60008, 20008, 5002, {2, 10, 2019}, 0},
        { 60009, 20000, 5003, {2, 10, 2019}, 0},
        { 60010, 20010, 5001, {3, 10, 2019}, 0},
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

void mostrarAlmuerzo(eAlmuerzo x, eComida comidas[], int tam)
{
    char descComida[20];

    cargarDescComida(x.idComida, comidas, tam, descComida);
    printf("%d         %d    %10s      %02d/%02d/%d \n",
           x.id,
           x.legajo,
           descComida,
           x.fecha.dia,
           x.fecha.mes,
           x.fecha.anio);
}

void mostrarAlmuerzos(eAlmuerzo vec[], int tam,  eComida comidas[], int tamC)
{
    int flag = 0;
    system("cls");
    printf("**Listado almuerzos**\n\n");

    printf("IdAlmuerzo     Legajo      Comida       Fecha\n\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarAlmuerzo(vec[i], comidas, tamC);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay almuerzos que mostrar\n");
    }

    printf("\n\n");
}



eAlmuerzo newAlmuerzo(int leg, int id, int idComida, eFecha fecha)
{

    eAlmuerzo al;
    al.id = id;
    al.legajo = leg;
    al.idComida = idComida;
    al.fecha.dia;
    al.fecha.mes;
    al.fecha.anio;

    return al;
}

int buscarLibreAlmuerzo(eAlmuerzo vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAlmuerzo(eAlmuerzo almuerzos[], int tAlmuerzos, int idAlmuerzo, eAlumno alumnos[], int tAlumno, eComida comidas[], int tComida, eCarrera carreras[], int tCarrea)
{
    int todoOk = 0;
    int indice;
    int legajo;
    int idComida;
    eFecha fecha;

    system("cls");

    printf("*****Alta Comida*****\n\n");

    indice = buscarLibreAlmuerzo(almuerzos, tAlmuerzos);

    if(indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        mostrarAlumnos(alumnos, tAlumno, carreras, tCarrea);
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        mostrarComidas(comidas, tComida);
        printf("Ingrese id Comida: ");
        scanf("%d", &idComida);

        printf("Ingrese fecha: ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);


        almuerzos[indice] = newAlmuerzo(idAlmuerzo, legajo, idComida, fecha);
        todoOk = 1;
        printf("Alta almuerzo exitosa!!\n\n");
    }

    return todoOk;
}

void mostrarAlmuerzoEnXFecha(eAlumno almuerzos[], int tam, eComida comidas, int tamC)
{
    eFecha fecha;

    system("cls");
    printf("**Informe - Almuerzo por fecha\n\n");

    printf("Ingrese fecha: ");
    scanf("%d/%d/&d", &fecha.dia, &fecha.mes, &fecha.anio);

    for(int i=0; i<tam; i++)
    {
        if(almuerzos[i].isEmpty == 0 && compararFecha(fecha, almuerzos[i].fecha)
        {
            mostrarAlmuerzos(almuerzos[i], tam, comidas[i], tamC);
        }
    }

    if(flag == 0)
    {
        printf("No hay almuerzos en la fecha ingresada..\n");
    }
}

int compararFecha(eFecha f1, eFecha f2)
{
    int sonIguales = 0;

    if(f1.dia == f2.dia && f1.mes == f2.mes && f1.anio == f2.anio)
    {
        sonIguales = 1;
    }
    return sonIguales;
}

void listarAlumnosDeUnaComida(eAlumno alumnos[], int tAlumno, eComida comidas[], int tComida, eAlmuerzo almuerzos[], int tAlmuerzo, eCarrera carreras[], int tCarrera)
{
    int idComida;
    int flag = 0;

    system("pause");
    printf("***Listado de comida**\n\n");

    mostrarComidas(comidas, tComidas);
    printf("Indique id comida: ");
    scanf("%d", &idComida);

    for(int i=0; i<tAlmuerzo; i++)
    {
        if(almuerzos[i].isEmpty == 0 && almuerzos[i].idComida == idComida)
        {
            for(int j=0; i<tAlumnos; j++)
            if(alumnos[j].isEmpty == 0 && alumnos[j].legajo == almuerzos[i].)
            {
                mostrarAlumnos(alumnos[j], carrerasm tCarrera);
                flag == 1;
            }
        }
    }

    if(flag == 0)
    {
        printf("Nadie comio de esa comida\n");
    }
}
