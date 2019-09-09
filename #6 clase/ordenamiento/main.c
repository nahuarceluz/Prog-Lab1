#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mostrarVectorInt(int vec[], int tam);
void ordenarVectorInt(int vec[], int tam, int criterio);

int main()
{

    int vec[TAM] = {7, 5, 8, 1, 3};
    int aux;


    printf("Vector sin ordenar\n\n");
    mostrarVectorInt(vec, TAM);

    ordenarVectorInt(vec, TAM, 0); //ordeno el vector de manera ascendente
    printf("Vector  de menor a mayor\n\n");
    mostrarVectorInt(vec, TAM);

    ordenarVectorInt(vec, TAM, 1); ////ordeno el vector de manera descendente
    printf("Vector de mayor a menor\n\n");
    mostrarVectorInt(vec, TAM);
}

void mostrarVectorInt(int vec[], int tam)
{

    for( int i=0; i < tam; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n\n");
}

void ordenarVectorInt(int vec[], int tam, int criterio)
{
    int aux;

    if(criterio == 0)
    {
        for(int i = 0; i < TAM-1; i++)
        {
            for(int j = i + 1; j < TAM; j++)
            {
                if( vec[j] < vec[i])
                {
                    aux = vec[j];
                    vec[j] = vec[i];
                    vec[i] = aux;
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < TAM-1; i++)
        {
            for(int j = i + 1; j < TAM; j++)
            {
                if( vec[j] > vec[i])
                {
                    aux = vec[j];
                    vec[j] = vec[i];
                    vec[i] = aux;
                }
            }
        }
    }
}
