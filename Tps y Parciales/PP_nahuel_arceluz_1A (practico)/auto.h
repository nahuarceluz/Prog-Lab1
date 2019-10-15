#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED


typedef struct
{
    int idAuto;
    char patente[51];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;

}eAuto;

#endif // AUTO_H_INCLUDED

int menuAuto();
void inicializarAuto(eAuto autos[], int tam);
int buscarLibreAuto(eAuto autos[], int tam);
int buscarAuto(char patente[], eAuto autos[], int tam);
int buscarAutoId(int id, eAuto autos[], int tam);
eAuto newAuto(int idAuto, char patente[], int idMarca, int idColor, int modelo);
int altaAuto(eAuto autos[], int tAuto, eMarca marcas[], int tMarcas, eColor colores[], int tColores);
void mostrarAuto(eAuto car, eMarca marcas[], int tMarca, eColor color[], int tColor);
void mostrarAutos(eAuto autos[], int tAuto, eMarca marcas[], int tMarca, eColor color[], int tColor);
int bajaAuto(eAuto autos[], int tAuto, eMarca marcas[], int tMarcas, eColor colores[], int tColores);
int modificarAuto(eAuto autos[], int tAuto, eMarca marcas[], int tMarcas, eColor colores[], int tColores);
int menuModificarAuto();
void ordenarAutos(eAuto autos[], int tAutos, eMarca marcas[], int tMArcas, eColor colores[], int tColor);



