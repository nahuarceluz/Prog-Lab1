typedef struct
{
    int datoNombre;
    char nombre[100];
    char siguiente;
    int edad;
    char genero[50];
    int nota;
} eDatos;

int getIntEdad(int* numero, char* mensaje)
{
    int edad;

    printf("%s", mensaje);
    scanf("%d", &edad);

    return edad;
}

char getCharNombre(char* letra, char* mensaje)
{
    char nombre[50];

    printf("%s", mensaje);
    scanf("%s", &letra);

    while(nombre == nombre)
    {
        printf("Bienvenido %s!!\n"); ///Valido para que salga el bienvenido.
        break;
    }

    return nombre;
}

char mostrarNombre(char vec[])
{
    printf("Nombre: %s\n", vec);
}

void mostrarDatos(char nombre[][20], int edad[], int genero[], int nota[])
{

    printf("Nombre     Edad      Genero     Nota\n");
    for(int i=0; i < 1; i++)
    {
        mostrarDato(nombre[i], edad[i], genero[i], nota[i]);
    }
    printf("\n\n");
}

void mostrarDato(char nombre[], int edad, char genero, int nota)
{


    printf("%s  %d     %s    %d",nombre, edad, genero, nota);

}
