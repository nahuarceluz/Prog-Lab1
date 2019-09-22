typedef struct
{
    int numeroDeSerie;
    char marca[20];
    char modelo[40];
    int precio;
    int anio;
} eAutos;

void mostrarAlumno(eAutos x)
{
    printf("  %2d      %10s  %10s        %2d     %2d\n", x.numeroDeSerie, x.marca, x.modelo, x.precio, x.anio);

}

void mostrarAlumnos(eAutos vec[], int tam)
{
    printf("N.Serie         Marca       Modelo       Precio    Anio\n\n");
    for(int i=0; i < tam; i++)
    {
        mostrarAlumno(vec[i]);
    }
}

void ordenarAlumnos(eAutos vec[], int tam)
{

    eAutos auxCar;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vec[i].numeroDeSerie > vec[j].numeroDeSerie)
            {
                auxCar = vec[i];
                vec[i] = vec[j];
                vec[j] = auxCar;
            }
        }
    }
}
