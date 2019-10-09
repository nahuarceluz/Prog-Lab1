#include <stdio.h>
#include <stdlib.h>

//void mostrarVectorChar(char* vec, int tam);
void mostrarVectorChar(char vec[], int tam);

int main()
{
    char sexos[5];
    int contadorF = 0;
    int contadorM = 0;

    for(int i; i<5; i++)
    {
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%s", &sexos[i]);

        while(sexos[i] != 'f' && sexos[i] != 'm')
        {
            printf("Error. Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &sexos[i]);
        }
    }

    for(int i=0; i<5; i++)
    {
        printf("%c", sexos[i]);
    }

    printf("\n\n");


    for(int i=0; i<5; i++)
    {
        if(sexos[i] == 'f')
        {
            contadorF++;
        }
        else
        {
            contadorM++;
        }
    }

    printf("Cantidad de masculinos: %d\n", contadorM);
    printf("Cantidad de femeninos: %d\n", contadorF);

    return 0;


}

/*void mostrarVectorChar(char vec[], int tam) //forma profesocial, correcta.
{
    for(int i=; i<tam; i++)
    {
        printf("%c", &vec[i]);
    }
}*/
