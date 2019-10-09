#include <stdio.h>
#include <stdlib.h>

#define TAM 2

typedef struct
{
    int idCliente;
    char apellido[51];
    char nombre[51];
    char sexo;
    char domicilio[51];
    int isEmpty;

}eCliente;

eCliente newCliente(int idCliente, char apellido[], char nombre[], char sexo, char domicilio[]);
int altaCliente(eCliente clientes[], int tam, int idCliente);
int buscarCliente(int idCliente, eCliente clientes[], int tam);
int buscarLibre(eCliente clientes[], int tam);
void inicializarCliente(eCliente cliente[], int tam);

int main()
{
    eCliente cliente[TAM] =
    {
        {100, "Carlos", "Montes", 'm', "Alvarez 500"},
        {101, "Ana", "Gomes", 'f', "Tucuman 1240"},
    };

    //inicializarCliente(cliente, TAM);

    mostrarClientes(cliente, TAM);
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

void mostrarCliente(eCliente clientes)
{
    printf("%d   %10s    %10s       %c       %10s\n", clientes.idCliente, clientes.nombre, clientes.apellido,clientes.sexo, clientes.domicilio);
}

void mostrarClientes(eCliente clientes[], int tam)
{
    int flag = 0;
    system("cls");
    printf("**** Listado de Clientes ****\n\n");

    printf("Id       Apellido       Nombre     Sexo       Domicilio\n");
    printf("-----------------------------------------------------------\n");
    for(int i=0; i < tam; i++)
    {
        if(clientes[i].isEmpty == 0)
        {
            mostrarCliente(clientes[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        system("cls");
        printf("---No hay clientes que mostrar---\n");
    }
}
