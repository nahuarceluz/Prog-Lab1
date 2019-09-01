#include <stdio.h>
#include <stdlib.h>

char menu();

int main()

switch(menu())
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
        system("pause");
        break;
      default:
        printf("Opcion invalida.\n");
        system("pause");
        break;
      }

return 0;

char menu()
{
    char seguir == 's';
    char opcion;

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

     }while(seguir == 'n');
}
