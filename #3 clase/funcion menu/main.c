#include <stdio.h>
#include <stdlib.h>

char menu();

int main()
{
    int seguir = 's';

    switch(menu())
    {
    case 'a':
        printf("Usted eligio ver esto.\n");
        system("pause");
        break;
    case 'b':
        printf("Usted no sabe programar..\n");
        system("pause");
        break;
    }
}

char menu()
{
    char seguir = 's';
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
