#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[20];
    int edad;
    int genero;
    char siguiente;

    do
    {
        printf("Ingrese nombre: ");
        gets(nombre);

        printf("Desea continuar?");
        scanf("%c", &siguiente);
        if(siguiente == 's')
        {
            printf("Ingrese Edad: ");
            scanf("%d", &edad);

            printf("Tu nombre es %s y tenes %d anios.\n", &nombre, edad);
            break;
        }
        else
        {
            printf("Proceso terminado");
        }
    }while(siguiente=='s');
}
