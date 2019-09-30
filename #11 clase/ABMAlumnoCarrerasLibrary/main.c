#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "carrera.h"
#include "alumno.h"

#define TAM 10
#define TAMC 3

int menu();
int menuInformes();
void InformesAlumnos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarAlumnosDeUnaCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarAlumnosCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int idCarrera);
void mostrarAlumnoXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarAlumnosPorCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
int mostrarCarreraConMasInscriptos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int idCarrera);

int main()
{
    int legajo = 20000;
    eCarrera carreras[TAMC]={{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};
    eAlumno lista[TAM];
    char salir = 'n';

    inicializarAlumnos( lista, TAM);

    legajo = legajo + hardcodearAlumnos(lista, TAM, 9);

    do
    {
        switch( menu())
        {
        case 1:
            if(altaAlumno(lista, TAM, legajo, carreras, TAMC))
            {
                legajo++;
            }
            break;

        case 2:
            bajaAlumno(lista, TAM, carreras, TAMC);
            break;

        case 3:
            ModificarAlumno(lista, TAM, carreras, TAMC);
            break;

        case 4:
            mostrarAlumnos(lista, TAM, carreras, TAMC);
            break;

        case 5:
            ordenarAlumnos(lista, TAM);
            break;

        case 6:
            InformesAlumnos(lista, TAM, carreras, TAMC);
            break;

        case 7:
            mostrarCarreras(carreras, TAMC);
            break;

        case 8:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Alumnos *******\n\n");
    printf("1-Alta alumno\n");
    printf("2-Baja alumno\n");
    printf("3-Modificar alumno\n");
    printf("4-Listar alumnos\n");
    printf("5-Ordenar alumnos\n");
    printf("6-Informes alumno\n");
    printf("7-Mostrar Carreras\n");
    printf("8-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("****** Informes *******\n\n");
    printf("1- Mostrar Alumnos por una Carrera\n");
    printf("2- Mostrar Alumnos por Carrera\n");
    printf("3- Mostrar Cantidad de Alumnos por Carrera\n");
    printf("4- Mostrar la Carrera con mas Inscriptos\n");
    printf("5- Mostrar Mejor Promedio por Carrera\n");
    printf("6- Mostrar Alumnos Varones\n");
    printf("7- Mostrar Mujeres de Alguna Carrera\n");
    printf("8- Mostrar Alumnos mayores a 30 de Licenciatura\n");
    printf("9- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void InformesAlumnos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC){
    char salir = 'n';
    system("cls");
    printf("***** Informes Alumnos ****\n\n");

    do
    {
        switch( menuInformes())
        {
        case 1:
            printf("Informe 1\n");
            mostrarAlumnosDeUnaCarrera(alumnos, tam, carreras, tamC);
            break;
        case 2:
            printf("Informe 2\n");
            mostrarAlumnoXCarrera(alumnos, tam, carreras, tamC);
            break;
        case 3:
            printf("Informe 3\n");
            mostrarAlumnosPorCarrera(alumnos, tam, carreras, tamC);
            break;

        case 4:
            printf("Informe 4\n");
            break;

        case 5:
            printf("Informe 5\n");
            break;

        case 6:
            printf("Informe 6\n");
            break;

        case 7:
            printf("Informe 7\n");
            break;

        case 8:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getchar();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');
}

void mostrarAlumnosDeUnaCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
    int idCarrera;
    system("cls");
    printf("*****Carreras*****\n\n");

    mostrarCarreras(carreras, tamC);
        printf("Elija una carrera: ");
        scanf("%d", &idCarrera);
    mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, idCarrera);
}

void mostrarAlumnosCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int idCarrera)
{
    char desc[20];
    int flag = 0;
    cargarDescCarrera(idCarrera, carreras, 20, desc);

    printf("Carrera: %s\n\n", desc);

    for(int i=0; i<tam; i++)
    {
        if(alumnos[i].isEmpty == 0 && alumnos[i].idCarrera == idCarrera)
        {
            mostrarAlumno(alumnos[i], carreras, tamC);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("No hay alumnos cursando %s", desc);
    }
}

void mostrarAlumnoXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
    system("cls");
    printf("****Listado de Alumnos por Carrera\n\n");
    for(int i=0; i<tamC; i++)
    {
        mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);
    }
    printf("\n\n");
}

void mostrarAlumnosPorCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
    int contador = 0;
    char desc;
    system("cls");
    printf("***Cantidad de Alumnos por Carrera***\n\n");

    for(int i=0; i<tamC; i++)
    {
        cargarDescCarrera(carreras[i].id, carreras, tamC, desc);
        printf("Carrera: %s\n", desc); //imprimo una carrera.

        for(int j=0; j<tam; i++) //con este for busco los alumnos que estan en esa carrera.
        {
            if(alumnos[j].isEmpty == 0 && alumnos[j].idCarrera == carreras[i].id)
            {
                contador++;
            }
        }
        printf("Cantidad: %d\n", contador);
        contador = 0;
    }
}

int mostrarCarreraConMasInscriptos(eAlumno alumnos[], int tam, int idCarrera)
{
    int cant = 0;

    for(int i=0; i<tam; i++)
    {

    }
}
