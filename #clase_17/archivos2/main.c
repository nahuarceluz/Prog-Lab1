#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[20];
    float sueldo;

} eEmpleado;

int mostrarEmpleados(eEmpleado** empleado, int tam);
eEmpleado** agrandarLista(eEmpleado* empleado, int tam);

int main()
{
    eEmpleado unEmpleado = {123, "Julia", 34567};
    int cantidad;

    mostrarEmpleado(&unEmpleado);

    /*FILE* f = fopen("data.bin", "wb");
    if(f == NULL)
    {
        exit(1);
    }

    cantidad = fwrite(&unEmpleado, sizeof(eEmpleado), 1, f);
    if(cantidad < 1)
    {
        printf("\nHubo un problema para guardar este archivo.\n");
    }
    else
    {
        printf("\nArchivo guardado correctamente");
    }
    fclose(f);*/

    ///Lectura

    eEmpleado otroEmpleado;

    FILE* f = fopen("data.bin", "rb");
    if(f == NULL)
    {
        exit(1);
    }

    cantidad = fread(&otroEmpleado, sizeof(eEmpleado), 1, f);

    if(cantidad == 1)
    {
        printf("\nArchivo leido correctamente\n");
    }
    else
    {
        printf("\nError.. No se pudo leer el archivo\n");
    }
    mostrarEmpleado(&otroEmpleado);
}

int mostrarEmpleado(eEmpleado* empleado) ///
{
    int todoOk = 0;

    if(empleado != NULL)
    {
        printf("%d  %10s %.2f", empleado->id, empleado->nombre, empleado->sueldo);
        todoOk = 1;
    }

    return todoOk;
}

