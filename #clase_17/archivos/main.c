#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE* f = fopen("archivo.txt", "r");
    char mensaje[30] = "Esto es un mensaje";
    char cadena[30];
    char auxChar;
    ///FILE* f = fopen("nombre del archivo", "modo en que se abre");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    //fwrite(mensaje, sizeof(char), strlen(mensaje), f);
    //fprintf(f, "Hola mundo");
    //fprintf(f, "%s", mensaje);



    ///Para levantar el mensaje.

    //fscanf(f, "%s", cadena);

    while(!feof(f))
    {
        fgets(cadena, 29, f);
        printf("%s", cadena);
    }

    while(!feof(f))
    {
        auxChar = fgetc(f);
        //printf("%s", cadena);
        //printf("%c", cadena); ///Leo de a un caracter
        fread(cadena, sizeof(char), 29, f);
        printf("%s", cadena);
    }

    fclose(f);

    return 0;
}
