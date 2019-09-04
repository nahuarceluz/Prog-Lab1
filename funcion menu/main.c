#include <stdio.h>
#include <stdlib.h>

char menu();

int main()
{
    int seguir;

    switch(menu())
    {
    case 'a':
        printf("Usted eligio sumar:\n");
        system("pause");
        break;
    case 'c':
        printf("Usted eligio salir\n");
        seguir = 'n';
        break;
    }
}

char menu()
{
    char seguir = 's';
    char opcion;

    do
    {
        system("cls");
        printf("---Menu de opciones---\n");
        printf("a. Sumar\n");
        printf("b. Restar\n");
        printf("c. Salir\n");

        printf("Ingrese una opcion valida: ");
        scanf("%c", &opcion);

    }while (seguir = 's');
}
