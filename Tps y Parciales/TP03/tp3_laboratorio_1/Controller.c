#include <stdlib.h>
#include <stdio.h>
#include "Employee.h"
#include "LinkedList.h"

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int indice;

    Employee* p;


    system("cls");
    printf("*****Alta Nuevo Empleado*****\n");


    indice = ll_indexOf(pArrayListEmployee, tam);
    if(indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese id: ");
        scanf("%d", &p->id);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(&p->nombre);

        printf("Ingrese horas de trabajo: ");
        scanf("%d", &p->horasTrabajadas);

        printf("Ingrese sueldo: ");
        fflush(stdin);
        scanf("%d", &p->sueldo);

        empleado[indice] = employee_new();
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}
