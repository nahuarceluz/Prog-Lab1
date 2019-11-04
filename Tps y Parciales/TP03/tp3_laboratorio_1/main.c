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
    int salir = 10;
    int tam = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    Employee* empleado;

    /*do{
        switch(menuEmployee())
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data.csv", listaEmpleados);
                break;
        }
        system("pause");
    }while(option == 10);*/

    /*Employee* lista = (Employee*) malloc(sizeof(Employee));

    Employee* pEmpleado = employee_newParametros(100, "Manuel", 120, 15000);
    Employee* pEmpleado2 = employee_newParametros(101, "Juan", 155, 50000);
    Employee* pEmpleado3 = employee_newParametros(102, "Gimena", 10, 60000);

    lista = agregarEmpleado(lista, &tam, pEmpleado);
    lista = agregarEmpleado(lista, &tam, pEmpleado2);
    lista = agregarEmpleado(lista, &tam, pEmpleado3);

    mostrarEmpleados(lista, tam);*/

    controller_addEmployee(listaEmpleados, tam);

    return 0;
}
