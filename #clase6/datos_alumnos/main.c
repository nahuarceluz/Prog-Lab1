#include <stdio.h>
#include <stdlib.h>

#define TAM 3

void mostrarAlumnos(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void mostrarAlumno(int leg, int age, char sex, int n1, int n2, float prom);
void ordenarAlumnos(int leg[], int age[], char sexo[], int n1[], int n2[], float prom[], int tam, int criterio);
void ordenarAlumnosSexLeg( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);

int main()
{
    int legajos[TAM];
    int edades[TAM];
    char sexos[TAM];
    int notap1[TAM];
    int notap2[TAM];
    float promedios[TAM];

    for(int i = 0; i < TAM; i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajos[i]);

        printf("Ingrese edad: ");
        scanf("%d", &edades[i]);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexos[i]);

        printf("Ingrese nota primer parcial: ");
        scanf("%d", &notap1[i]);

        printf("Ingrese nota segundo parcial: ");
        scanf("%d", &notap2[i]);

        promedios[i] = (float) (notap1[i] + notap2[i]) / 2;
    }

    mostrarAlumnos(legajos, edades, sexos, notap1, notap2, promedios, TAM);
    ordenarAlumnos(legajos, edades, sexos, notap1, notap2, promedios, TAM, 0);

    mostrarAlumnos(legajos, edades, sexos, notap1, notap2, promedios, TAM);
    ordenarAlumnosSexLeg(legajos, edades, sexos, notap1,notap2, promedios, TAM);

    return 0;
}

void mostrarAlumnos(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam)
{
    printf("Legajo   Edad   Sexo   Nota1   Nota2   Promedio\n\n");

    for(int i = 0; i < tam; i++)
    {
        mostrarAlumno(leg[i], age[i], sex[i], n1[i], n2[i], prom[i]);
    }
    printf("\n\n");
}

void mostrarAlumno(int leg, int age, char sex, int n1, int n2, float prom)
{
    printf("%d       %d       %c       %d       %d       %.2f\n", leg, age, sex, n1, n2, prom);
}

void ordenarAlumnos(int leg[], int age[], char sexo[], int n1[], int n2[], float prom[], int tam, int criterio)
{
    int auxInt;
    float auxFloat;
    char auxChar;

    for(int i = 0; i < TAM-1; i++)
    {
        for(int j = i + 1; j < TAM; j++)
        {
            if(sexo[j] < leg[i] && criterio == 0)
            {
                auxInt = leg[j];
                leg[j] = leg[i];
                leg [i] = auxInt;

                auxInt = age[j];
                age[j] = age[i];
                age[i] = auxInt;

                auxChar = sexo[j];
                sexo[j] = sexo[i];
                sexo[i] = auxChar;

                auxInt = n1[j];
                n1[j] = n1[i];
                n1[i] = auxInt;

                auxInt = n2[j];
                n2[j] = n2[i];
                n2[i] = auxInt;

                auxFloat = prom[j];
                prom[j] = prom[i];
                prom[i] = auxFloat;

            }
        }
    }
}

void ordenarAlumnosSexLeg( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam){

    int auxInt;
    float auxFloat;
    char auxChar;
    int swap = 0;

    for(int i=0; i < tam-1; i++){
        for(int j = i +1; j < tam; j++){

            if( sex[i] > sex[j]){
                    swap = 1;
            }
            else if( sex[i] == sex[j] && leg[i] > leg[j]){

                    swap = 1;
            }

            if( swap ){

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = age[i];
                age[i] = age[j];
                age[j] = auxInt;

                auxChar = sex[i];
                 sex[i] = sex[j];
                 sex[j] = auxChar;

                auxInt = n1[i];
                 n1[i] = n1[j];
                 n1[j] = auxInt;

                auxInt = n2[i];
                 n2[i] = n2[j];
                 n2[j] = auxInt;

              auxFloat = prom[i];
               prom[i] = prom[j];
               prom[j] = auxFloat;
            }

            swap = 0;
        }
    }
}
