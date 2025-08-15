#include <stdio.h>

int main() 
{
    int a;
    a = 54;

    printf("El valor de a es: %i\n",a);

    // &a sera un puntero a variable a, pero aca 
    // lo imprime de una manera incorrecta
    printf("El valor de &a es: %i\n",&a);
    printf("El valor de &a es: %p (puntero)\n",&a);

    int *dir;
    dir = &a;

    // Lo mismo, dir sera un puntero, o direcion.
    // dir va a guardar un puntero a la variable a
    printf("El valor de dir es:%i \n",dir); // Forma incorrecta, te tira cualquier cosa*
    printf("El valor de dir es: %p (puntero)\n",dir);

    //* Mejor dicho, no qualquier cosa, va a tratar de convertir un puntero
    // A un intero, punteros por si son numeros en forma hexidecimal y va a 
    // convertir ese numero hexidecimal a un int

    // El valor de direcion de memoria que guarda dir
    // O de forma simple, valor de a
    printf("El valor de *dir es:%i\n",*dir);

    // Por curiosidad, pero va a dar si, porque ambos puntan a misma direcion de memoria
    printf("Son iguales los puneros?: (dir == &a) %s\n", dir == &a ? "y si, que pensabas?" 
                                                                   : "flaco, esta mal algo, abandona tu windows q se yo"); 

    // &a y *dir se van a asignar "at runtime", porque
    // Estan asignadas basado el espacio de memoria usada

    // ¿Cuanto vale a? ¿Por qué cambió su valor?
    *dir=28;
    printf("El valor de a es: %i\n",a);

    // Y porque dir es un puntero a una variable, 
    // al escribirlo con un asterisco, trabajas con el valor de la variable
    // a cual se punta el puntero, en ese caso, cambiamos el valor de la variable (a) 

    return 0;
}
