#include <stdio.h>
#include <stdlib.h>
#include <string.h> //guarda funciones de tipo de cadena. ejemplo: strcpy

void mostrarVectorChar(char vec[], int tam);

int main()
{
    //STRCPY: copia de datos.
    //Ejemplo:
    /*char nombre[10];
    strcpy(nombre, "Juan"); //strcpy (DESTINO, MENSAJE (LO QUE LE QUIERO PASAR));*/

    //Ejemplo 2:
    /*char nombre[10];
    strcpy(nombre, "Juan Ignacio Alberto");
    printf("%s", nombre);*/
    //mostrarVectorChar(nombre, 10);
    //si le paso menos tamaño que la cant de letras de la var, se desborda el vector. Se queda sin espacio en memoria

    //STRLEN: dice la cantidad de caracteres.
    //Ejemplo 1:
    /*char nombre[10];
    char auxCad[100];
    int cantidad;
    printf("Ingrese nombre: ");
    gets(nombre);
    cantidad = strlen(nombre);
    printf("%s tiene %d caracteres", nombre, cantidad);
    //mostrarVectorChar(nombre, 10);*/

    //Ejemplo 2:
    /*char nombre[10];
    char auxCad[100];
    int cantidad;
    printf("Ingrese nombre: ");
    gets(nombre);
    while(strlen(auxCad) > 9)
    {
        printf("Error. Nombre demasiado largo.");
        gets(auxCad);
    }
        strcpy(nombre, auxCad);
        printf("%s\n", nombre);*/

        //STRNCPY:  muestra hasta donde le lego con el tamño(9);
        //Ejemplo:
        /*char nombre[10];
        strncpy(nombre, "juan alberto matias", 9);
        puts(nombre);*/

        //STRCMP: compara dos cadenas. Devuelve tres valores:
        //-1: n1 esta ANTES que n2 en el diccionario.
        //0: son iguales.
        //1: n1 esta DESPUES que n2 en el diccionario.
        //Ejemplo:
        /*char n1[10] = "Juan";
        char n2[10] = "juana";
        int x;

        x = strcmp(n1, n2);
        printf("%d", x);*/


        //STRICMP = no hace diferencia entre MAYUSCULA y minuscula.


        //STRCAT: une dos cadenas.
        //Ejemplo:
        char n1[10] = "Juan";
        char n2[10] = "a";
        //char n3[20]; //no tiene que ser menor a 19 porque se desborda;
        strcat(n1, n2);
        printf("%s\n", n1);

        return 0;
}

void mostrarVectorChar(char vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%c ", vec[i]);
    }
    printf("\n\n");
}
