#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    char opcion;
    char seguir = 's';
    char nombre[50];
    int edad;
    char genero[50];
    int clave;

    while(seguir == 's')
    {
      system("cls"); //limpiar pantalla
      printf("----Menu de Opciones----\n\n");
      printf("1. Ingresar nombre.\n");
      printf("2. Ingresar edad.\n");
      printf("3. Ingresar genero.\n");
      printf("4. Ingresar clave.\n");
      printf("5. Datos ingresados.\n");
      printf("6. Salir\n");
      printf("Ingrese opcion: ");
      opcion = getchar();

      switch(opcion)
      {
      case '1':
        printf("\n");
        printf("Usted elegio ingresar nombre.\n");
        printf("Ingrese nombre: ");
        scanf("%s", &nombre);
        system("pause"); //para pausar el programa.
        break;
      case '2':
        printf("\n");
        printf("Usted elegio ingresar edad.\n");
        printf("Ingrese edad: ");
        scanf("%d", &edad);
        system("pause");
        break;
      case '3':
        printf("\n");
        printf("Usted elegio ingresar genero.\n");
        printf("Ingrese genero: ");
        scanf("%s", &genero);
        system("pause");
        break;
      case '4':
        printf("\n");
        printf("Usted elegio ingresar clave.\n");
        printf("Ingrese clave: ");
        scanf("%d", &clave);
        break;
      case '5':
        printf("\n");
        printf("Datos ingresados.\n");
        printf("Nombre: %s\n", nombre);
        printf("Edad: %d\n", edad);
        printf("Genero: %s\n", genero);
        printf("Clave: %d\n", clave);
        system("pause");
        break;
      case '6':
        printf("Usted eligio salir.\n");
        return 0;
        break;
      default:
        printf("Opcion invalida.\n");
        system("pause");
        break;
      }
}
}
