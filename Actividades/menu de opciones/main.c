#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    char opcion;
    char seguir = 's';
    char salir;

    int nota;
    int nota2;
    int acumulador = 0;
    float promedio;

    do
    {
      system("cls"); //limpiar pantalla
      printf("----Menu de Opciones----\n\n");
      printf("1. Ingresar notas.\n");
      printf("2. Mostrar notas ingresas.\n");
      printf("3. Sacar promedio de las notas ingresadas.\n");
      printf("4. Ver notas aprobadas.\n");
      printf("5. Salir\n");
      printf("Ingrese opcion: ");
      //opcion = getche;
      scanf("%c", &opcion);

      switch(opcion)
      {
      case '1':
        printf("Usted eligio ingresar notas.\n");
        printf("Ingrese primera nota: ");
        scanf("%d", &nota);
        printf("Ingrese segunda nota: ");
        scanf("%d", &nota2);
        system("pause"); //para pausar el programa.
        break;
      case '2':
        printf("Usted eligio mostrar notas ingresadas.\n");
        printf("Nota 1: %d\n", nota);
        printf("Nota 2: %d\n", nota2);
        system("pause");
        break;
      case '3':
        printf("Usted eligio sacar promedio de las notas ingresadas.\n");

        for (int i=0; i<2; i++)
        {
            printf("Ingrese numero: ");
            scanf("%d", &nota);

            acumulador = acumulador + nota;
        }
        promedio = (float) acumulador / 5;
        printf("El promedio de las notas ingresas es: %.2f\n", promedio);
        system("pause");
        break;
      case '4':
        printf("Notas aprobadas:\n");
        if(nota >=7 || nota2 >=7)
        {
            printf("Nota aprobada.\n.");
        }
        else
        {
            printf("Nota desaprobada.\n");
        }
        system("pause");
        break;
      case '5':
        printf("Usted eligio salir.\n");
        seguir = 'n';
        break;
      default:
        printf("Opcion invalida.\n");
        system("pause");
        break;
      }
    }while(seguir == 's');
}
