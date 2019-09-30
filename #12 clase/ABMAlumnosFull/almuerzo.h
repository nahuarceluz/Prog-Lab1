#include "alumno.h"
#include "comida.h"

#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

typedef struct
{
    int id;
    int legajo;
    int idComida;
    eFecha fecha;
    int isEmpty;

}eAlmuerzo;


#endif // ALMUERZO_H_INCLUDED

void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam);
int hardcodearAlmuerzos(eAlmuerzo vec[], int tam, int cantidad);
void mostrarAlmuerzo(eAlmuerzo x, eComida comidas[], int tam);
void mostrarAlmuerzos(eAlmuerzo vec[], int tam,  eComida comidas[], int tamC);
eAlmuerzo newAlmuerzo(int leg, int id, int idComida, eFecha fecha);
int altaAlmuerzo(eAlmuerzo almuerzos[], int tAlmuerzos, int idAlmuerzo, eAlumno alumnos[], int tAlumno, eComida comidas[], int tComida, eCarrera carreras[], int tCarrea);
int buscarLibreAlmuerzo(eAlmuerzo vec[], int tam);
int compararFecha(eFecha f1, eFecha f2);
void listarAlumnosDeUnaComida(eAlumno alumnos[], int tAlumno, eComida comidas[], int tComida, eAlmuerzo almuerzos[], int tAlmuerzo, eCarrera carreras[], int tCarrera);
