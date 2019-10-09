#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[20];
    char nombreMin[20];
    char nombreMax[20];
    char sexo;
    char sexoMin;
    char sexoMax;
    char seguir;
    int nota;
    int mayorNota;
    int menorNota;
    int conMujeres = 0;
    int notaTotal;
    int promedioNotas;
    int contador = 0;
    int suma = 0;
    int acumNotasF[20];
    int acumNotas[20];
    int flag = 0;
    float promedio;
    float promedioF = 0;

    do
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese sexo f/m: ");
        fflush(stdin);
        scanf("%c", &sexo);

        while(sexo != 'f' && sexo !='m')
        {
            printf("Error. Ingrese sexo f/m: ");
            fflush(stdin);
            scanf("%c", &sexo);
        }

        printf("Ingrese nota 0-10: ");
        scanf("%d", &nota);

        while(nota <0 || nota > 10)
        {
            printf("Error. Ingrese nota: ");
            fflush(stdin);
            scanf("%d", &nota);
        }

        printf("Desea continuar?: ");
        fflush(stdin);
        scanf("%c", &seguir);

    }while(seguir == 's');

    promedio = (float) acumNotas / contador;

    if(conMujeres != 0)
    {
        promedioF = acumNotasF / conMujeres;
    }
}
