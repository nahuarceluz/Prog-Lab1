#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int datoNombre;
    char nombre[100];
    char siguiente;
    int edad;
    char genero[50];
    int nota;
    //AGREGAR: menu de opciones y flag.

    do
    {
        printf("Bienvenido. Para comenzar el registro, presiona la tecla s: ");
        scanf("%c", &siguiente);
        if(siguiente == 's')
        {
            /*printf("Igrese nombre: ");
            fflush(stdin);
            gets(nombre);*/

            datoNombre = getCharNombre(nombre, "Ingrese nombre: ");

            printf("Desea continuar? s/n: ");
            scanf("%s", &siguiente);
            if(siguiente == 's')
            {
                /*printf("Igrese nombre: ");
                fflush(stdin);
                scanf("%d", &edad);*/
                edad = getIntEdad(edad, "Ingrese edad: ");

                printf("Desea continuar? s/n: ");
                fflush(stdin);
                scanf("%s", &siguiente);
                if(siguiente == 's')
                {
                    printf("Cual es tu genero? f/m: ");
                    fflush(stdin);
                    scanf("%s", &genero);

                    printf("Desea continuar? s/n: ");
                    fflush(stdin);
                    scanf("%s", &siguiente);
                    if(siguiente == 's')
                    {
                        printf("Ingrese nota: ");
                        fflush(stdin);
                        scanf("%d", &nota);

                        printf("El registro se completo correctamente..\n");
                        printf("Presione la stecla s para mostrar los datos ingresados..");
                        scanf("%s", &siguiente);
                        if(siguiente == 's')
                        {
                            printf("Nombre: %s\n", nombre);
                            printf("Edad: %d\n", edad);
                            printf("Genero: %s\n", genero);
                            printf("Nota: %d\n", nota);

                            printf("Gracias por usar nuestro sitio web.");
                            return 0;
                        }
                        else
                        {
                            printf("Ocurrio un error. Recargue la pagina..");
                        }
                    }
                }
                else
                {
                    printf("Tu nombre es %s y tenes %d anios.\n", nombre, edad);
                    printf("Proceso terminado.\n");
                }
            }
            else
            {
                printf("Tu nombre es %s.\n", nombre);
                printf("Proceso terminado.");
            }
        }
        else
        {
            printf("Preceso cancelado.\n");
        }


    }
    while(siguiente=='s');
}
