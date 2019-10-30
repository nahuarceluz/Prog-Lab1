#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* archivo = fopen("clarin.txt", "w");
    char mensaje[200] = "Quiénes estaban en el palco VIP. Alberto Fernández fue a Tucumán a darse un baño de peronismo puro y sin kirchneristas";
    if(archivo == NULL)
    {
        printf("Hubo un problema al crear el archivo\n");
        system("pause");
        exit(1);
    }

    fprintf(archivo, "%s", mensaje);

    ///

    FILE* numeros = fopen("soy.txt", "w");

    char nombre[100] = "Soy nahuel y tengo ";
    char anios[100] = "20 anios\n";
    char vivo[100] = "Y vivo en centenario....";

    if(numeros == NULL)
    {
        printf("Hubo un problema al crear el archivo\n");
        system("pause");
        exit(1);
    }

    fprintf(numeros, "%s", nombre);
    fprintf(numeros, "%s", anios);
    fprintf(numeros, "%s", vivo);

    ///

    FILE* hola = fopen("saludo.txt", "w");
    char saludando[100] = "Buenos dias a todos!";

    if(hola == NULL)
    {
        printf("Hubo un problema al crear el archivo\n");
        system("pause");
        exit(1);
    }

    fprintf(hola, "%s", saludando);

    ///

    FILE* suma = fopen("sumando.txt", "w");

    if(suma == NULL)
    {
        printf("Hubo un problema al crear el archivo\n");
        system("pause");
        exit(1);
    }

    int numero = 2;
    int numero2 = 2;
    int resultado = 4;

    fprintf(suma, "%d + %d es %d", numero, numero2, resultado);




}
