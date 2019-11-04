#include <stdlib.h>
#include <stdio.h>
#include "Employee.h"
#include "LinkedList.h"

int menuEmployee()
{
    int opcion;

    system("cls");
    printf("****Menu de opciones: Empleados****\n\n");
    printf("1. Cargar los datos de los empleados en modo texto.\n");
    printf("2. Cargar los datos de los empleados en modo binario.\n");
    printf("3. Alta Empleado.\n");
    printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados.\n");
    printf("7. Ordenar empleados.\n");
    printf("8. Guardar los datos de los empleados en modo texto.\n");
    printf("9. Guardar los datos de los empleados en modo binario.\n");
    printf("10. Salir.\n\n");

    printf("Ingresar opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

Employee* employee_new()
{
    Employee* empleado = (Employee*) malloc(sizeof(Employee));

    if(empleado != NULL)
    {
        empleado->id = 0;
        strcpy(empleado->nombre, " ");
        empleado->horasTrabajadas = 0;
        empleado->sueldo = 0;
    }

    return empleado;
}

int mostrarEmpleado(Employee* empleado)
{
    int todoOk = 0;

    if(empleado != NULL)
    {

        printf("%d   %10s          %d            %d\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
        todoOk = 1;
    }

    return todoOk;

}

int mostrarEmpleados(Employee* empleado, int tam)
{
    int todoOk = 0;

    if(empleado != NULL)
    {
        printf("Id        Nombre      H.Trabajadas      Sueldo\n\n");
        for(int i=0; i < tam; i++)
        {
            mostrarEmpleado(empleado+i);
        }
        todoOk = 1;
    }

    return todoOk;
}

Employee* employee_newParametros(int id, char* nombre, int horasTrabajadas, int sueldo)
{
    Employee* nuevoEmpleado;

    nuevoEmpleado = employee_new();

    if(nuevoEmpleado != NULL)
    {

        nuevoEmpleado->id = id;
        strcpy(nuevoEmpleado->nombre, nombre);
        nuevoEmpleado->horasTrabajadas = horasTrabajadas;
        nuevoEmpleado->sueldo = sueldo;
    }

    return nuevoEmpleado;
}

Employee* agregarEmpleado(Employee* empleado, int* tam, Employee* emp)
{
    Employee* aux;

    if(empleado != NULL && tam != NULL && emp != NULL)
    {
        *(empleado + *tam) = *emp;

        aux = realloc( empleado, (*tam +2) *  sizeof(Employee) );

        if( aux != NULL)
        {
            empleado = aux;
            (*tam)++;
        }
    }

    return empleado;
}
