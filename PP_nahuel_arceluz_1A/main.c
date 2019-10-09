#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 4

typedef struct
{
    int id;
    char procesador[100];
    char marca[100];
    int precio;
    int isEmpty;

}eNotebook;

void mostrarDato(eNotebook pc);
void mostrarDatos(eNotebook pc[], int tam);
void ordenarNotebook(eNotebook pc[], int tam);

int main()
{
   eNotebook pc[TAM] =
   {
    {107, "Intel", "HP", 3000},
    {103, "Duo", "Epson", 1500},
    {100, "Core", "HP", 500},
    {105, "Proce", "Epson", 7000}
   };

   ordenarNotebook(pc, TAM);
   mostrarDatos(pc, TAM);


   aplicarDescuento();
}
void mostrarDato(eNotebook pc)
{
    printf("%d  %10s    %10s        %d\n", pc.id, pc.procesador, pc.marca, pc.precio);
}

void mostrarDatos(eNotebook pc[], int tam)
{
    printf("Id     Procesador       Marca       Precio\n");
    for(int i=0; i<tam; i++)
    {
        mostrarDato(pc[i]);
    }
}

void ordenarNotebook(eNotebook pc[], int tam)
{
    eNotebook auxPrecio;
    eNotebook auxInt;


    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(pc[i].marca, pc[j].marca) > 0)
            {
                auxInt = pc[i];
                pc[i] = pc[j];
                pc[j] = auxInt;
            }
            else if (pc[i].marca == pc[j].marca && pc[i].precio > pc[j].precio)
            {
                auxPrecio = pc[i];
                pc[i] = pc[j];
                pc[j] = auxPrecio;
            }
        }
    }
}


int aplicarDescuento(int precio)
{
    printf("\nIngrese el precio del producto: ");
    scanf("%d", &precio);

    if(precio == precio)
    {
        precio = precio / 5;
    }
    printf("El precio es: %d", precio);

    return precio;
}
