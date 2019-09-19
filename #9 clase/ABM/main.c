#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3


typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
    int isEmpty; ///Esta vacio
} eAlumno;

void mostrarAlumno(eAlumno x);
void mostrarAlumnos(eAlumno vec[], int tam);
void ordenarAlumnos(eAlumno vec[], int tam);
int menu();
void inicializarAlumnos(eAlumno alumnos[], int tam);
int buscarLibre(eAlumno alumnos[], int tam);
int buscarAlumnos(int legajo, eAlumno alumnos[], int tam);
int altaAlumno(eAlumno alumnos[], int tam);
eAlumno newAlumno(int legajo, char nombre[], char sexo, int edad, int n1, int n2, eFecha fecha);
int bajaAlumno(eAlumno alumnos[], int tam);

int main()
{
    eAlumno lista[TAM];
    char salir  = 'n';
    int opcion = 0;

    inicializarAlumnos(lista, TAM);

    do
    {
        system("cls");
        printf("**Menu de opciones**\n");
        printf("1. Alta alumno\n");
        printf("2. Baja alumno\n");
        printf("3. Modificar alumno\n");
        printf("4. Listar alumnos\n");
        printf("5. Ordenar alumnos\n");
        printf("6. Informes\n");
        printf("7. Salir\n\n");

        printf("Ingrese opcion: ");
        scanf("%d", &opcion);


        switch(opcion)
        {
        case 1:
            printf("Alta alumno\n");
            altaAlumno(lista, TAM);
            system("pause");
            break;
        case 2:
            printf("Baja alumno\n");
            bajaAlumno(lista, TAM);
            system("pause");
            break;
        case 3:
            printf("Modoficar alumno\n");
            modoficarAlumno(lista, TAM);
            system("pause");
            break;
        case 4:
            printf("Listar alumnos.\n");
            mostrarAlumnos(lista, TAM);
            system("pause");
            break;
        case 5:
            printf("Ordenar alumnos.\n");
            system("pause");
            break;
        case 6:
            printf("Informes.\n");
            system("pause");
            break;
        case 7:
            printf("Usted eligio salir.\n");
            salir = 'n';
            break;
        default:
            printf("Opcion invalida\n");
        }
    }
    while(salir == 's');

}


void mostrarAlumno(eAlumno x)
{
    printf("  %d  %s  %d  %c  %d %d %.2f %02d/%02d/%d\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio);
}

void mostrarAlumnos(eAlumno vec[], int tam)
{
    int flag = 0;

    printf(" Legajo Nombre Edad Sexo Nota1 Nota2 Promedio FIngreso\n");
    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarAlumno(vec[i]);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        system("pause");
        printf("No hay alumnos que mostrar.");
    }

    printf("\n\n");
}

void ordenarAlumnos(eAlumno vec[], int tam)
{

    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vec[i].legajo > vec[j].legajo)
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
}

void inicializarAlumnos(eAlumno alumnos[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        alumnos[i].isEmpty = 1;
    }
}

int buscarLibre(eAlumno alumnos[], int tam)
{
    int indice = -1; ///si esta lleno, me devuelve -1.

    for(int i=0; i < tam; i++)
    {
        if(alumnos[i].isEmpty == 1) ///Para encontrar un lugar libre.
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAlumnos(int legajo, eAlumno alumnos[], int tam)
{
    int indice = -1; ///si esta lleno, me devuelve -1.

    for(int i=0; i < tam; i++)
    {
        if(alumnos[i].isEmpty == 0) ///Para encontrar un lugar libre.
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAlumno(eAlumno alumnos[], int tam)
{
    int todoOk = 0;
    int indice;
    int esta;
    int legajo;
    int edad;
    int n1;
    int n2;
    char sexo;
    char nombre[20];
    eFecha fecha;
    float promedio;

    indice = buscarLibre(alumnos, tam);

    if(indice == -1)
    {
        printf("Lista llena, No se pudo agregar el alumno ingresado.\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarAlumnos(legajo, alumnos, tam);

        if(esta != -1)
        {
            printf("Legajo ya registrado..\n");
            mostrarAlumno(alumnos[esta]);
            system("pause");
        }
        else
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nombre);

            printf("Ingrese edad: ");
            scanf("%d", &edad);

            printf("Ingrese sexo ");
            fflush(stdin);
            scanf("%c", &sexo);

            printf("Ingrese nota parcial 1: ");
            scanf("%d", &n1);

            printf("Ingrese nota parcial 2: ");
            scanf("%d", &n2);

            printf("Ingrese fecha ingreso: dd/mm/aaaa: ");
            scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

            alumnos [indice] = newAlumno(legajo, nombre, sexo, edad, n1, n2, fecha);
            todoOk = 1;
        }
    }

    return todoOk;
}

eAlumno newAlumno(int legajo, char nombre[], char sexo, int edad, int n1, int n2, eFecha fecha) ///Validacion:
{
    eAlumno nuevoAlumno;

    nuevoAlumno.legajo = legajo;
    strcpy(nuevoAlumno.nombre, nombre);
    nuevoAlumno.edad = edad;
    nuevoAlumno.sexo = sexo;
    nuevoAlumno.nota1 = n1;
    nuevoAlumno.nota2 = n2;
    nuevoAlumno.promedio = (float) (n1 + n2) / 2;
    nuevoAlumno.fechaIngreso = fecha;
    nuevoAlumno.isEmpty = 0;

    return nuevoAlumno;
}

int bajaAlumno(eAlumno alumnos[], int tam)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumnos(legajo, alumnos, tam);

    if(indice == -1)
    {
        printf("El alumno no esta registrado.");
    }
    else
    {
        mostrarAlumno(alumnos[indice]);
        printf("Confirma eliminacion?: ");
        fflush(stdin);
        confirma = getche();
        if(confirma == 's')
        {
            alumnos[indice].isEmpty = 1; ///le hacemos la baja logica.
            printf("Se ha eliminado el alumno.\n");
            todoOk = 1;
        }
        else
        {
            printf("Se ha cancelado la baja.");
        }
        system("pause");
    }

    return todoOk;
}

int modoficarAlumno(eAlumno alumnos[], int tam)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumnos(legajo, alumnos, tam);

    if(indice == -1)
    {
        printf("El alumno no esta registrado.");
    }
    else
    {
        mostrarAlumno(alumnos[indice]);
        printf("Confirma modificacion?: ");
        fflush(stdin);
        confirma = getche();
        if(confirma == 's')
        {
            altaAlumno(alumnos, tam);
            alumnos[indice].isEmpty = 1; ///le hacemos la baja logica.
            printf("Se ha modificado el alumno.\n");
            todoOk = 1;
        }
        else
        {
            printf("Se ha cancelado la modificacion.");
        }
        system("pause");
    }

    return todoOk;
}
