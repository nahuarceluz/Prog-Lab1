typedef struct
{
    int numeroDeSerie;
    char marca[20];
    char modelo[40];
    int precio;
    int anio;
} eAutos;

void mostrarAlumno(eAutos x);
void mostrarAlumnos(eAutos vec[], int tam);
void ordenarAlumnos(eAutos vec[], int tam);
