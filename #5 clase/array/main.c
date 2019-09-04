#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros[] = {5, 2, 8, 4, 1};

    for(int i = 0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]); //muestra el valor del primer indice.
        //printf("%d,", numeros[i]); //acceso secuencial.
    }

    printf("Se cargo secuencialmente todo el array numeros\n\n");
    system("pause");
    //getch(); //Se usa para parar el programa..

    for(int i = 0; i<5; i++)
    {
        printf("%d ", numeros[i]);
    }

    //printf("%d", numeros[3]); //muestra el numero 4, por su posicion.

    return 0;
}
