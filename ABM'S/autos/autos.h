typedef struct
{
    int id;
    char color[51];

}eColor;

typedef struct
{
    int numeroDeSerie;
    char marca[20];
    char modelo[40];
    int precio;
    int anio;
    int idColor;
    int isEmpty;
} eAutos;

void mostrarAuto(eAutos car, eColor colores[], int tam);
void mostrarAutos(eAutos car[], int tam, eColor colores[], int tamC);
void inicializarAuto(eAutos autos[], int tam);
int buscarLibre(eAutos alumnos[], int tam);
int buscarAuto(int numeroDeSerie, eAutos alumnos[], int tam);
eAutos newAuto(int numeroDeSerie, char marca[], char modelo[], int precio, int anio);
int altaAuto(eAutos autos[], int tam, eColor colores[], int tamC);
int bajaAuto(eAutos autos[], int tam, eColor colores[], int tamC);
int modificarAuto(eAutos autos[], int tam, eColor colores[], int tamC);


int menu();

/*int modificarAuto(eAutos autos[], int tam);*/
