#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void ordenarVector(int vec[], int tam, int criterio);


int main()

{
    /*char alumno [] = {"apellido"};

    printf("%s\n", alumno);

    float promedio [14] = {1.2, 1.4, 6.5};
    printf("%.2f\n", promedio[2]);

    int a = 0;
    int b = 1;

    if(a||b)
    {
        printf("Hola\n");
    }
    else
    {
        printf("Chauuuu\n");
    }

    ///VALIDACIONES:
    char producto [5][20];

    while(producto == producto)
    {
        printf("Ingrese un producto: ");
        scanf("%s", &producto[4]);
        break;
    }
    printf("El cliente ingreso el producto: %s\n", producto[4])

    int numero;
    printf("ingrese producto: ");
    scanf("%s", &producto);

    printf("Ingrese numero: ");
    scanf("%d", &numero);

    if(numero == 1)
    {
       printf("El producto ingresado es: %s!", producto);
    }
    else
    {
        printf("Error al mostrar..\n");
    }*/

    int numero[TAM] = {5, 2, 7, 9, 3, 6, 1, 4, 8, 10};


    printf("Vector de menor a mayor: \n");
    ordenarVector(numero, TAM, 0);
    mostrarVector(numero, TAM);

    printf("\nVector de mayor a menor: \n");
    ordenarVector(numero, TAM, 1);
    mostrarVector(numero, TAM);
}

void mostrarVector(int vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%d ", vec[i]);
    }
}

void ordenarVector(int vec[], int tam, int criterio)
{
    int aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(vec[i] < vec[j] && criterio)
            {
                aux = vec[j];
                vec[j] = vec[i];
                vec[i] = aux;
            }
            else if (vec[i] > vec[j] && !criterio)
            {
                aux = vec[j];
                vec[j] = vec[i];
                vec[i] = aux;
            }

        }
    }
}
