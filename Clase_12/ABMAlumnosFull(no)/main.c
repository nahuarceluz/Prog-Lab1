#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "carrera.h"
#include "alumno.h"
#include "comida.h"
#include "almuerzo.h"
#include "alumnos-carrera.h"

#define TAM 10
#define TAMC 3
#define TAMCOM 5
#define TAMAL 20

int menu();
int menuInformes();

int main()
{
    int legajo = 20000;
    int idAlmuerzo = 60000;
    eCarrera carreras[TAMC]= {{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};
    eComida comidas[TAMCOM] = {{5000,"Bife", 250},{5001,"Fideos", 180},{5002,"Pizza", 200}, {5003, "Arroz", 160}, {5004, "Milanesa", 220}};
    eAlumno lista[TAM];
    eAlmuerzo almuerzos[TAMAL];
    char salir = 'n';

    inicializarAlumnos(lista, TAM);
    inicializarAlmuerzos(almuerzos, TAMAL);

    legajo = legajo + hardcodearAlumnos(lista, TAM, 9);
    idAlmuerzo = idAlmuerzo + hardcodearAlmuerzos(almuerzos, TAMAL, 10);

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
            mostrarComidas(comidas, TAMCOM);
            break;
        case 9:
            mostrarAlmuerzos(almuerzos, TAMAL, comidas, TAMCOM);
            break;
        case 10:
            if(altaAlmuerzo(almuerzos, TAMAL, idAlmuerzo, lista, TAM, comidas, TAMCOM, carreras, TAMC))
            {
                idAlmuerzo++;
            }
            break;
        case 12:
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
    printf("1. Alta alumno\n");
    printf("2. Baja alumno\n");
    printf("3. Modificar alumno\n");
    printf("4. Listar alumnos\n");
    printf("5. Ordenar alumnos\n");
    printf("6. Informes alumno\n");
    printf("7. Mostrar Carreras\n");
    printf("8. Mostrar Comidas\n");
    printf("9. Mostrar Almuerzos\n");
    printf("10. Alta Almuerzo\n");
    printf("12. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("****** Informes *******\n\n");
    printf("1. Mostrar Alumnos de una Carrera\n");
    printf("2. Mostrar Alumnos por Carrera\n");
    printf("3. Mostrar Cantidad de alumnos por Carrera\n");
    printf("4. Mostrar La Carrera con mas incriptos\n");
    printf("5. Mostrar Mejor Promedio por Carrera\n");
    printf("6. Mostrar Alumnos Varones\n");
    printf("7. Mostrar Mujeres de Alguna Carrera\n");
    printf("8. Mostrar Alumnos mayores a 30 de Licenciatura\n");
    printf("9. Mostrar Almuerzos de una fecha determinada\n");
    printf("10. Listar alumnos que comieron una determinada comida\n");
    printf("11. Listar cantidad de almuerzos por carrera\n");
    printf("12. Carrera amante de las milanesas\n");
    printf("13. Informe deuda alumno seleccionado\n");
    printf("20-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    //     printf("4-Mostrar Mejor Promedio General\n");
    return opcion;
}

void InformesAlumnos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, eAlmuerzo almuerzos, int tamA)
{
    char salir = 'n';
    system("cls");
    printf("***** Informes Alumnos ****\n\n");

    do
    {
        switch( menuInformes())
        {
        case 1:
            mostrarAlumnosDeUnaCarrera(alumnos, tam, carreras, tamC);
            break;

        case 2:
            mostrarAlumnosXCarrera(alumnos, tam, carreras, tamC);
            break;

        case 3:
            mostrarCantidadAlumnosXCarrera(alumnos, tam, carreras, tamC);
            break;

        case 4:
            carreraMasCursada(alumnos, tam, carreras, tamC);
            break;

        case 5:
            mejoresPromediosXCarrera(alumnos, tam, carreras, tamC);
            break;

        case 6:
            printf("Informe 6\n");
            break;

        case 7:
            printf("Informe 7\n");
            break;

        case 8:
            printf("Informe 7\n");
            break;
        case 9:
            mostrarAlmuerzoEnXFecha()
            break;

        case 10:
            listarAlumnosDeUnaComida(alumnos, tam, comidas, tComida, almuerzos, tAlmuerzo, carreras, tamC)
        case 20:
            printf("Confirma salida?: ");
            salir = getchar();
            break;
        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');
}







