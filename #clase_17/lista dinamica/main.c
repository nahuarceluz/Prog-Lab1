#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[20];
    float sueldo;

} eEmpleado;

eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int id, char* nombre, float sueldo);
int setIdEmpleado(eEmpleado* empleado, int id);
int setSueldoEmpleado(eEmpleado* empleado, float sueldo);
int setNombreEmpleado(eEmpleado* empleado, char* nombre);
int getIdEmpleado(eEmpleado* empleado, int* id);
int getSueldo(eEmpleado* empleado, float* sueldo);
int getNombreEmpleado(eEmpleado* empleado, char* nombre);
int mostrarEmpleado(eEmpleado* empleado);
int mostrarEmpleados(eEmpleado** empleado, int tam);
eEmpleado** agrandarLista(eEmpleado* empleado, int tam);

int main()
{
    int tam = 0;
    eEmpleado* auxEmpleado = NULL; ///Para evitar que se cargue basura en la variable.

    eEmpleado** lista = (eEmpleado**) malloc(sizeof(eEmpleado*));
    int auxInt;
    float auxFloat;
    char auxCad[100];
    if(lista == NULL)
    {
        printf("No se pudo asignar memoria.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    printf("Ingrese id: ");
    scanf("%d", &auxInt);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(auxCad);

    printf("Ingrese sueldo: ");
    scanf("%f", &auxFloat);

    auxEmpleado = newEmpleadoParam(auxInt, auxCad, auxFloat);
    if(auxEmpleado == NULL)
    {
        printf("No se pudo crear al empleado.\n");
    }
    else
    {
        printf("Empleado creado con exito\n");

        *(lista + tam) = auxEmpleado;

        if(agrandarLista(lista, tam + 1) != NULL)
        {
            printf("Empleado agregado a la lista\n");
            tam++;
        }
    }
    system("pause");

    mostrarEmpleados(lista, tam);


    return 0;
}

eEmpleado* newEmpleado()
{
    eEmpleado* nuevo;
    nuevo = (eEmpleado*) malloc(sizeof(eEmpleado));

    if(nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->sueldo = 0;
    }
    return nuevo;
}

eEmpleado* newEmpleadoParam(int id, char* nombre, float sueldo)
{
    eEmpleado* nuevo = newEmpleado();

    if(nuevo != NULL)
    {
        if(setIdEmpleado(nuevo, id) && setNombreEmpleado(nuevo, nombre) && setSueldoEmpleado(nuevo, sueldo))
        {
            printf("Empleado creado correctamente\n");
        }
    }

    return nuevo;
}

int setIdEmpleado(eEmpleado* empleado, int id) ///Recibe un puntero a empleado y lo que le quiero pàsar
{
    int todoOk = 0;

    if(empleado != NULL && id >= 10000 && id <= 20000)
    {
        empleado->id = id;
        todoOk = 1;
    }

    return todoOk;
}

int setSueldoEmpleado(eEmpleado* empleado, float sueldo) ///Recibe un puntero a empleado y lo que le quiero pàsar
{
    int todoOk = 0;

    if(empleado != NULL && sueldo > 0)
    {
        empleado->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}

int setNombreEmpleado(eEmpleado* empleado, char* nombre) ///Recibe un puntero a empleado y lo que le quiero pàsar
{
    int todoOk = 0;

    if(empleado != NULL && nombre != NULL && strlen(nombre) < 20)
    {
        strcpy(empleado->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}

int getIdEmpleado(eEmpleado* empleado, int* id) ///Le paso el punto de empleado y el puntero de id.
{
    int todoOk = 0;

    if(empleado != NULL && id != NULL)
    {
        *id = empleado->id; ///Guarda el valor con el operador de indiferencia.
        todoOk = 1;
    }
    return todoOk;
}

int getSueldo(eEmpleado* empleado, float* sueldo) ///Le paso el punto de empleado y el puntero de sueldo
{
    int todoOk = 0;

    if(empleado != NULL && sueldo != NULL)
    {
        *sueldo = empleado->sueldo; ///Guarda el valor con el operador de indiferencia.
        todoOk = 1;
    }
    return todoOk;
}

int getNombreEmpleado(eEmpleado* empleado, char* nombre) ///Le paso el punto de empleado y el puntero de nombre
{
    int todoOk = 0;

    if(empleado != NULL && nombre != NULL)
    {
        strcpy(nombre, empleado->nombre); ///Guardo el dato en el puntero nombre.
        todoOk = 1;
    }
    return todoOk;
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

int mostrarEmpleados(eEmpleado** empleado, int tam)
{
    int todoOk = 0;

    if(empleado != NULL && tam > 0)
    {
        printf("Id     Nombre       Sueldo\n");
        for(int i = 0; i<tam; i++)
        {
            mostrarEmpleado(*(empleado + i));
        }
        todoOk = 1;
    }

    return todoOk;
}

eEmpleado** agrandarLista(eEmpleado* empleado, int tam)
{
    eEmpleado* aux = (eEmpleado**) realloc(empleado, sizeof(eEmpleado*) + tam);
    if(aux != NULL)
    {
        empleado = aux;
    }

    return empleado;
}
