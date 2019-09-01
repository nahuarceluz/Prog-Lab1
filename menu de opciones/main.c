#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int opcion;
    char seguir = 's';
    char nombre[50];
    int edad;
    char genero;

    do
    {
            system("cls"); //limpiar pantalla
            printf("----Menu de Opciones----\n\n");
            printf("a- Sumar\n");
            printf("b- Restar\n");
            printf("c- Multiplicar\n");
            printf("d- Dividir\n");
            printf("e-Salir\n");
            printf("Ingrese opcion: ");
            //opcion = getche;
            scanf("%c", &opcion);

            switch(opcion)
            {
            case 'a':
                printf("Ustedes eligio sumar.\n");
                system("pause"); //para pausar el programa.
                break;
            case 'b':
                printf("Usted eligio restar.\n");
                system("pause");
                break;
            case 'c':
                printf("Usted eligio multiplicar.\n");
                system("pause");
                break;
            case 'd':
                printf("Usted eligio dividir.\n");
                system("pause");
                break;
            case 'e':
                printf("Usted eligio salir.\n");
                printf("Confirma salida?:  ");
                seguir == getche();
                printf("\n");
                system("pause");
                break;
            default:
                printf("Opcion invalida.\n");
                system("pause");
                break;
            }

            }while(seguir == 'n');

}
