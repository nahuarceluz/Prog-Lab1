#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion = 0;
    char salir = 's';
    do
    {
        system("cls");
        printf("**Menu de opciones**\n");
        printf("1. Alta alumno\n");
        printf("2. Baja alumno\n");
        printf("3. Modificar alumno\n");
        printf("4. Listar alumnos\n");
        printf("5. Ordenar alumnos\n");
        printf("6. Informes\n");
        printf("7. Salir\n\n");

        printf("Ingrese opcion: ");
        scanf("%d", &opcion);


        switch(opcion)
        {
        case 1:
            printf("Alta alumno\n");

            system("pause");
            break;
        case 2:
            printf("Baja alumno\n");

            system("pause");
            break;
        case 3:
            printf("Modoficar alumno\n");
            system("pause");
            break;
        case 4:
            printf("Listar alumnos.\n");

            system("pause");
            break;
        case 5:
            printf("Ordenar alumnos.\n");
            system("pause");
            break;
        case 6:
            printf("Informes.\n");
            system("pause");
            break;
        case 7:
            printf("Usted eligio salir.\n");
            salir = 'n';
            break;
        default:
            printf("Opcion invalida\n");
        }
    }
    while(salir == 's');
}
a
