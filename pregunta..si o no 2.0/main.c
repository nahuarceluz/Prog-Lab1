#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[50];
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
            printf("Como te llamas?: ");
            fflush(stdin);
            scanf("%s", &nombre);
            printf("Bienvenido otra vez %s!\n", nombre);

            printf("Desea continuar? s/n: ");
            scanf("%s", &siguiente);
            if(siguiente == 's')
            {
                printf("Cual es su edad?: ");
                fflush(stdin);
                scanf("%d", &edad);

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
                        printf("Presione la tecla s para mostrar sus datos: ");
                        scanf("%s", &siguiente);
                        if(siguiente == 's')
                        {
                            printf("\n");
                            printf("Nombre: %s\n", nombre);
                            printf("Edad: %d\n", edad);
                            printf("Genero: %s\n", genero);
                            printf("Nota: %d\n", nota);
                            return 0;
                        }
                        else
                        {
                            printf("Proceso terminado.");
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
                printf("Proceso cancelado.");
            }
        }
        else
        {
            printf("Preceso cancelado.\n");
        }


    }while(siguiente=='s');
}
