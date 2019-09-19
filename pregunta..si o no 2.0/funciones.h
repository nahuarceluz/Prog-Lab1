typedef struct
{
    int datoNombre;
    char nombre[100];
    char siguiente;
    int edad;
    char genero[50];
    int nota;
}eDatos;

int getIntEdad(int*, char* );
char getCharNombre(char* letra, char* mensaje);
char mostrarNombre(char vec[]);
void mostrarDato(char nombre, int edad, char genero, int nota);
