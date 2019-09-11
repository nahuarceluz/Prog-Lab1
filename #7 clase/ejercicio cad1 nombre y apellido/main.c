#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[20];
    char apellido[20];
    char nombreCompleto[41]; //como minimo 41
    char auxCad[100];
    int i=0;

    printf("Ingrese nombre: ");
    gets(nombre);
    while(strlen(auxCad) > 19)
    {
        printf("Error. Reingrese nombre: ");
        fflush(stdin);
        gets(auxCad);
    }
    printf("Ingrese apellido: ");
    gets(apellido);

    strcpy(apellido, auxCad);

    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    strlwr(nombreCompleto); //paso todo a minuscula
    nombreCompleto[0] = toupper(nombreCompleto[0]);

    while(nombreCompleto[i] != '\0');
    {
        if(nombreCompleto[i] == ' ')
        {
            nombreCompleto[i+1] = toupper(nombreCompleto[i]);
        }
        i++;
    }
    printf("%s", nombreCompleto);
}
