#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eMarca;

#endif // MARCA_H_INCLUDED

void mostrarMarca(eMarca marcas);
void mostrarMarcas(eMarca marcas[], int tMarca);
int harcodearMarcas(eMarca marcas[], int tam, int cantidad);
int cargarMarcaAuto(int idMarca, eMarca marcas[], int tMarca, char descripcion[]);


