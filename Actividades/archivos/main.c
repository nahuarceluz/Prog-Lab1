#include <stdio.h>
#include <stdlib.h>

int main()
{
    char mensaje[100] = "Practicando archivos...";
    FILE* lista = fopen("listado.txt", "w");

    if(lista == NULL)
    {
        printf("No se pudo crear el archivo\n");
        system("pause");
        exit(1);
    }

    //fprintf(lista, "%s", mensaje);
    fgets(mensaje, 1, lista);
}
