#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 2
#define TAMJ 2

typedef struct
{
    int id;
    char descripcion[51];
    int importe;

}eJuego;

typedef struct
{
    int idCliente;
    char apellido[51];
    char nombre[51];
    char sexo;
    char domicilio[51];
    int idJuego;
    int isEmpty;

}eCliente;

eCliente newCliente(int idCliente, char apellido[], char nombre[], char sexo, char domicilio[]);
int altaCliente(eCliente clientes[], int tam, int idCliente);
int buscarCliente(int idCliente, eCliente clientes[], int tam);
int buscarLibre(eCliente clientes[], int tam);
void inicializarCliente(eCliente cliente[], int tam);

int main()
{
    eJuego juego[TAMJ] =
    {
        {1000, "Domino", 1500},
        {1001, "Rompecabezas", 1800},
    };

    eCliente cliente[TAM];

    /*char salir;

   do
   {
       switch(menu())
       {
    case 1:
        mostrarClientes(cliente, TAM);
        break;
    case 2:
       mostrarJuegos(juego, TAMJ);
       break;
       }
    system("pause");
   }while(salir == 'n');*/

   //mostrarJuegos(juego, TAMJ);

   hardcodearClientes(cliente, TAM, 2);
   mostrarClientes(cliente, TAM, juego, TAMJ);
}

int menu()
{
    int opcion;

    printf("Bienvenido al menu de clientes..\n");
    printf("1. Mostrar clientes\n");
    printf("2. Mostrar juegos\n\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
}

int altaCliente(eCliente clientes[], int tam, int idCliente)
{
    int todoOk = 0;
    int indice;
    int esta;
    char apellido[51];
    char nombre[51];
    char sexo;
    char domicilio[51];

    system("cls");
    printf("**** Alta Juego ****\n\n");

    indice = buscarLibre(clientes, tam);

    if( indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas clientes\n");
    }
    else
    {
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(apellido);

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nombre);

            printf("Ingrese sexo:");
            fflush(stdin);
            scanf("%c", &sexo);

            printf("Ingrese domicilio: ");
            fflush(stdin);
            scanf("%s", &domicilio);

            clientes[indice] = newCliente(idCliente, apellido, nombre, sexo, domicilio);
            todoOk = 1;
    }
    return todoOk;
}

eCliente newCliente(int idCliente, char apellido[], char nombre[], char sexo, char domicilio[])
{
    eCliente nuevoCliente;
    nuevoCliente.idCliente = idCliente;
    strcpy(nuevoCliente.apellido, apellido);
    strcpy(nuevoCliente.nombre, nombre);
    nuevoCliente.sexo = sexo;
    strcpy(nuevoCliente.domicilio, domicilio);
    nuevoCliente.isEmpty = 0;

    return nuevoCliente;
}

int buscarCliente(int idCliente, eCliente clientes[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( clientes[i].isEmpty == 0 && clientes[i].idCliente == idCliente)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarLibre(eCliente clientes[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( clientes[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void inicializarCliente(eCliente cliente[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        cliente[i].isEmpty = 1;
    }
}

void mostrarCliente(eCliente clientes, eJuego juegos[], int tam)
{
    char descripJuego[100];

    cargarJuego(clientes.idJuego, juegos, tam, descripJuego);
    printf("%d   %10s    %10s       %c       %10s    %10s\n", clientes.idCliente, clientes.nombre, clientes.apellido,clientes.sexo, clientes.domicilio, descripJuego);
}

void mostrarClientes(eCliente clientes[], int tam, eJuego juegos[], int tamJuego)
{
    int flag = 0;
    system("cls");
    printf("**** Listado de Clientes ****\n\n");

    printf("Id       Apellido       Nombre     Sexo       Domicilio       NombreJuego       IdJuego\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    for(int i=0; i < tam; i++)
    {
        if(clientes[i].isEmpty == 0)
        {
            mostrarCliente(clientes[i], juegos, tamJuego);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        system("cls");
        printf("---No hay clientes que mostrar---\n");
    }
}

int hardcodearClientes(eCliente clientes[], int tam, int cantidad)
{
    int cont = 0;

    eCliente suplentes[] =
    {
        {100, "Carlos", "Montes", 'm', "Alvarez 500", 1000, 0},
        {101, "Roberto", "Gomes", 'f', "Tucuman 1340"},
    };

    if(cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i<cantidad; i++)
        {
            clientes[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

int cargarJuego(int idJuego, eJuego juegos[], int tam, char descripcion[])
{

    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if(idJuego == juegos[i].id)
        {
            strcpy(descripcion, juegos[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

void mostrarJuego(eJuego juego)
{
    printf("%d    %10s           %d\n", juego.id, juego.descripcion, juego.importe);
}

void mostrarJuegos(eJuego juegos[], int tamJ)
{
    printf("Id        Descripcion      Importe\n");
    printf("------------------------------------\n");
    for(int i=0; i<tamJ; i++)
    {
        mostrarJuego(juegos[i]);
    }
}
