#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
     int legajo;
     char nombre[20];
     int edad;
     char sexo;
     int nota1;
     int nota2;
     float promedio;
     eFecha fechaDeIngreso;

}eAlumno;

int main()
{
    eAlumno alumno1 = {1234, "Jose", 10, 'm', 10, 2, 6,{12, 5, 2019}};
    eAlumno alumno2;

    /*printf("Ingrese nombre: ");
    gets(alumno1.nombre);

    printf("Ingrese legajo: ");
    scanf("%d", &alumno1.legajo);

    printf("Ingrese edad: ");
    scanf("%d", &alumno1.edad);

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &alumno1.sexo);

    printf("Ingrese nota 1: ");
    scanf("%d", &alumno1.nota1);

    printf("Ingrese nota 2: ");
    scanf("%d", &alumno1.nota2);

    alumno1.promedio = (float) (alumno1.nota1 + alumno1.nota2) / 2;

    printf("Ingrese fecha de ingreso: ");
    scanf("%d", &alumno1.fechaDeIngreso.dia);

    printf("Ingrese mes de ingreso: ");
    scanf("%d", &alumno1.fechaDeIngreso.mes);

    printf("Ingrese anio de ingreso: ");
    scanf("%d", &alumno1.fechaDeIngreso.anio);

    printf("Nombre: %s\n", alumno1.nombre);
    printf("Legajo: %d\n", alumno1.legajo);
    printf("Edad: %d\n", alumno1.edad);
    printf("Sexo: %c\n", alumno1.sexo);
    printf("Nota 1: %d\n", alumno1.nota1);
    printf("Nota 2: %d\n", alumno1.nota2);
    printf("Promedio: %.2f\n", alumno1.promedio);
    printf("Fecha de ingreso: %02d/%02d/%02d", alumno1.fechaDeIngreso.dia, alumno1.fechaDeIngreso.mes, alumno1.fechaDeIngreso.anio);*/
