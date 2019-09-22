#include <stdio.h>
#include <stdlib.h>

#define TAM 3
#define COLUMNAS 20

void mostrarEquipo(char equipo[], int partidosJugados, int partidosGanados, int partidosEmpatados, int partidosPerdidos, int puntos);
void mostrarEquipos(char equipo[][20], int partidosJugados[], int partidosGanados[], int partidosEmpatados[], int partidosPerdidos[], int puntos[], int tam);

int main()
{
    char equipo[TAM][COLUMNAS] = {"Boca Juniors", "San Lorenzo", "Talleres"};
    int partidosJugados[TAM] = {6, 6, 6};
    int partidosGanados[TAM] = {4, 4, 4};
    int partidosEmpatados[TAM] = {2, 1, 1};
    int partidosPerdidos[TAM] = {0, 1, 1};
    int puntos[TAM] = {14, 13, 13};

    mostrarEquipos(equipo, partidosJugados, partidosGanados, partidosEmpatados, partidosPerdidos, puntos, TAM);

    return 0;
}

void mostrarEquipos(char equipo[][20], int partidosJugados[], int partidosGanados[], int partidosEmpatados[], int partidosPerdidos[], int puntos[], int tam)
{
    printf("Equipo          Jugados   ganados   empatados   perdidos   puntos\n");
    for(int i=0; i<tam; i++)
    {
        mostrarEquipo(equipo[i], partidosJugados[i], partidosGanados[i], partidosEmpatados[i], partidosPerdidos[i], puntos[i]);
    }
    printf("\n\n");
}

void mostrarEquipo(char equipo[], int partidosJugados, int partidosGanados, int partidosEmpatados, int partidosPerdidos, int puntos)
{

    printf("%s       %d         %d          %d          %d         %d     %d\n", equipo, partidosJugados, partidosGanados, partidosEmpatados, partidosPerdidos, puntos);
}
