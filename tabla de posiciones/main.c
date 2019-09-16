#include <stdio.h>
#include <stdlib.h>

#define TAM 3

void mostrarEquipos(char equipo[], int partidosJugados[], int partidosGanados[], int partidosEmpatados[], int partidosPerdidos[], int puntos[], int tam);
void mostrarEquipo(char equipo, int partidosJugados, int partidosGanados, int partidosEmpatados, int partidosPerdidos, int puntos);

int main()
{
    char equipo[TAM] = "San Lorenzo";
    int partidosJugados[TAM] = {6, 6, 6};
    int partidosGanados[TAM] = {4, 4, 4};
    int partidosEmpatados[TAM] = {1, 1, 0};
    int partidosPerdidos[TAM] = {1, 1, 2};
    int puntos[TAM] = {13, 13, 12};

    mostrarEquipos(equipo, partidosJugados, partidosGanados, partidosEmpatados, partidosPerdidos, puntos, TAM);

}

void mostrarEquipos(char equipo[], int partidosJugados[], int partidosGanados[], int partidosEmpatados[], int partidosPerdidos[], int puntos[], int tam)
{
    printf("Equipo   Jugados   ganados   empatados   perdidos   puntos\n");
    for(int i=0; i<tam; i++)
    {
        mostrarEquipo(equipo[i], partidosJugados[i], partidosGanados[i], partidosEmpatados[i], partidosPerdidos[i], puntos[i]);
    }
    printf("\n\n");
}

void mostrarEquipo(char equipo, int partidosJugados, int partidosGanados, int partidosEmpatados, int partidosPerdidos, int puntos){

    printf("%s     %d         %d          %d          %d         %d     %d\n", equipo, partidosJugados, partidosGanados, partidosEmpatados, partidosPerdidos, puntos);
}
