#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList** pArrayListEmployee)
{
    int indice;
    int todoOk = 0;
    int tam = 0;
    Employee* empleados;

    int id;
    char* nombre[128];
    int horasTrabajadas;
    int sueldo;

    system("cls");
    printf("****Alta Empleado****\n\n");

    indice = buscarLibre(pArrayListEmployee, tam);

    if( indice == -1)
    {
        printf("Sistema Completo.\n");
    }
    else
    {
        printf("Ingrese Id: ");
        scanf("%d", &id);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese horas de trabajo: ");
        scanf("%d", &horasTrabajadas);

        printf("Ingrese sueldo: ");
        scanf("%d", &sueldo);

        pArrayListEmployee[indice] = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
        todoOk = 1;
        printf("Alta completa!\n");
    }
    return todoOk;
}
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee, int tam)
{
    int todoOk = 0;

    if(pArrayListEmployee != NULL)
    {

        printf("Id        Nombre      H.Trabajadas      Sueldo\n\n");
        for(int i=0; i < tam; i++)
        {
            mostrarEmpleado(pArrayListEmployee + i);
        }
        todoOk = 1;
    }

    return todoOk;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

