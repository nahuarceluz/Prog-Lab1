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

int mostrarEmpleado(Employee* emp)
{
    int todoOk = 0;

    if(emp != NULL)
    {
        printf("%d   %10s       %d        %d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
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
    if(empleado != NULL && id >= 10000 && id <= 20000)
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

    if(empleado != NULL && horasTrabajadas < 100000)
    {
        empleado->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getId(Employee* empleado, int* id)
{
    int todoOk = 0;

    if(empleado != NULL && id != NULL)
    {
        *id = empleado->id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getNombre(Employee* empleado, char* nombre)
{
    int todoOk = 0;

    if(empleado != NULL && nombre != NULL)
    {
        strcpy(nombre, empleado->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_getHorasTrabajadas(Employee* empleado, int* horasTrabajadas)
{
    int todoOk = 0;

    if(empleado != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = empleado->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getSueldo(Employee* empleado, int* sueldo)
{
    int todoOk = 0;

    if(empleado != NULL && sueldo != NULL)
    {
        *sueldo = empleado->sueldo;
        todoOk = 1;
    }
    return todoOk;
}
