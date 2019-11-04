#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
    printf("4. Listar empleados.\n");
    /*printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");

    printf("7. Ordenar empleados.\n");
    printf("8. Guardar los datos de los empleados en modo texto.\n");
    printf("9. Guardar los datos de los empleados en modo binario.\n");*/
    printf("10. Salir.\n\n");

    printf("Ingresar opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

Employee* employee_new()
{
    Employee* p = (Employee*) malloc(sizeof(Employee));

    if(p != NULL)
    {
        p->id = 0;
        strcpy(p->nombre, " ");
        p->horasTrabajadas = 0;
        p->sueldo = 0;
        p->isEmpty = 0;
    }

    return p;
}

int mostrarEmpleado(Employee* emp)
{
    int todoOk = 0;

    if(emp != NULL)
    {
        printf("%d   %10s          %d            %d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
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

int employee_setId(Employee* empleado,int id)
{
    int todoOk = 0;
    if(empleado != NULL)
    {
        empleado->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setNombre(Employee* empleado, char* nombre)
{
    int todoOk = 0;
    if(empleado != NULL && nombre != NULL && strlen(nombre) < 20)
    {
        strcpy(empleado->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* empleado, int sueldo)
{
    int todoOk = 0;
    if(empleado != NULL && sueldo > 0)
    {
        empleado->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* empleado, int horasTrabajadas)
{
    int todoOk = 0;

    if(empleado != NULL)
    {
        empleado->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibre(Employee* empleados, int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(empleados[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
