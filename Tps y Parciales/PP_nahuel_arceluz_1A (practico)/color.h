#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];

}eColor;


#endif // COLOR_H_INCLUDED

int cargarColorAuto(int idColor, eColor color[], int tColor, char descripcion[]);
int harcodearColores(eColor colores[], int tColor, int cantidad);
void mostrarColor(eColor colores);
void mostrarColores(eColor colores[], int tam);
