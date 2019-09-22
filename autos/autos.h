typedef struct
{
    int numeroDeSerie;
    char marca[20];
    char modelo[40];
    int precio;
    int anio;
} eAutos;

void mostrarAuto(eAutos x);
void mostrarAutos(eAutos vec[], int tam);
void ordenarAutos(eAutos vec[], int tam);
void inicializarAlumnos(eAutos alumnos[], int tam);
int buscarLibre(eAutos alumnos[], int tam);
int buscarAuto(int numeroDeSerie, eAutos alumnos[], int tam);
eAutos newAuto(int numeroDeSerie, char marca[], char modelo[], int precio, int anio);
int altaAuto(eAutos autos[], int tam);
int bajaAuto(eAutos autos[], int tam);
int menu();

/*int modificarAuto(eAutos autos[], int tam);*/
