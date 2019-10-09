#include <stdio.h>
#include <stdlib.h>

void mostrarVectorInt(int vec[], int tam);
void mostrarVectorChar(char vec[], int tam);
void mostrarVectorFloat(float vec[], int tam);

int main()
{
    int numeros[] = {23, - 21, - 43, - 54, - 28, - 21, - 66, - 88, - 32, - 50};
    char x[] = {'a', 'e', 'i', 'o', 'u', '\0'};
    char nombre[] = {'J', 'u', 'a', 'n', '\0'};
    float reales[] = {23.5, - 56.34, - 55.1, - 89.7, - 90.9};

    //mostrarVectorInt(numeros, 10); //la variable va sin [].
    //mostrarVectorChar(x, 5); //muestra aeiou
    //mostrarVectorChar(nombre, 4); //muestra Juan
    mostrarVectorFloat(reales, 5); //muestra 23.5....

    return 0;
}

void mostrarVectorInt(int vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("%d", vec[i]);
    }
    printf("\n\n");
}

void mostrarVectorChar(char vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("%c", vec[i]);
    }
    printf("\n\n");
}

void mostrarVectorFloat(float vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("%.2f", vec[i]);
    }
    printf("\n\n");
}
