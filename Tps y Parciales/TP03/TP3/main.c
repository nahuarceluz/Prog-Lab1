#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int tam = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    /*do{
        switch(menuEmployee())
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data.bin", listaEmpleados);
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_ListEmployee(listaEmpleados, tam);
                break;
        }
        system("pause");
    }while(option != 10);*/

    /*controller_addEmployee(listaEmpleados, tam);
    controller_ListEmployee(listaEmpleados, tam);*/


    Employee* lista = (Employee*) malloc(sizeof(Employee));
    Employee* pEmpleado = employee_newParametros(123, "Manuel", 500, 60000);
    lista = agregarEmpleado(lista, &tam, pEmpleado);
    controller_ListEmployee(lista, tam);

    return 0;
}
