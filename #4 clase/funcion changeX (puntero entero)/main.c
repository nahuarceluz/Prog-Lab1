#include <stdio.h>
#include <stdlib.h>

void changeX(int*); //modifica la variable x de la funcion int main.
//int*: tipo de dato que solo guarda enteros.

int main()
{
    int x;
    //x = 5; //aunque le asigne 3, se va a mostrar lo que le ingrese.

    changeX(&x); //Le paso a la funcion la direccion de memoria de la variable.

    printf("%d", x); //lo muestro pasandole la variable de tipo entero declarada.

    return 0;
}

void changeX(int* puntero)
{
    int numero;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    *puntero = numero; //Lo que ingrese en numero, se va a guardar como un puntero entero en *puntero.
}
