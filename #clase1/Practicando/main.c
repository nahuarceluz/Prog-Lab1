#include <stdio.h> //librerias guardadas en la computadora..
#include <stdlib.h> //si tiene # significa directivas del procesador
// return 0; = la función llegó al final
int main()
{
    //mostramos un dato
    int numero1 = 2019; //declaro una variable y guardo el valor..
    int numero2 = 21;
    char letra = 'A';
    char nombre [20] = "Juan";
    float precio = 123.75;

    printf("Estamos en el anio %d y hoy es %d\n", numero1, numero2); //caracteres con acentos no esta guardado
    //hay dos mascaras y dos variables. Van en el mismo orden. numero = %d y numero2 = %d
    printf("La letra es %c\n", letra);
    printf("Su nombre es %s\n", nombre);
    printf("El precio es %.2f\n\n", precio); //para sacarle los ceros se pone %.2f..


    //pedimos un dato
    int numero;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    printf("Usted ingreso el numero %d\n", numero);

    return 0;
}
