#include <stdio.h>
#include <string.h>

void a() 
{
    // a) ¿Por qué la palabra necesita 6 caracteres si tiene 5 letras? ¿Por qué no se muestran 20
    // caracteres en el tercer nombre?

    char n1[5]="Carla", n2[6]="Carla", n3[20]="Carla";
    printf("%s\n%s\n%s\n",n1,n2,n3);

    // La palabra tambien necesita el espacio para un caracter especial
    // Que se llama "null terminator" \0, lo que hace basicamente, es decir donde
    // Se terminan los caracteres en una variable.
    // En el 3 nombre, se muestran 5 caracteres, porque 20 - es el tamano de buffer
    // Es decir, la cantidad de caracteres totales que puede guardar
}

void b() 
{
    // b) ¿Por qué para la misma variable se imprime la palabra, una letra y un número?
    
    char n[6]="Carla";
    printf("%s\n",n);
    printf("%c\n",n[0]);
    printf("%i\n",n[0]);
    // Porque printf convierte los datos que le dan basado
    // en el la plantilla que le da como el primer argumento
}

void c() 
{
    // c) ¿Por qué los resultados no son 6 y 20?
    char n1[6]="Carla", n2[20]="Carla";
    int l1,l2;

    l1=strlen(n1);
    l2=strlen(n2);

    printf("%i\n%i\n",l1,l2);
    // Porque strlen devuelve la cantidad de caracteres en un string
    // Y no el tamano del buffer
}

void d() 
{
    // d) El siguiente código es incorrecto. ¿Cómo debe ser el código para que la variable se cargue con
    // el segundo nombre?

    char n[10]="Carla";
    // n="Pepe";

    strcpy(n, "Pepe");
    printf("%s\n",n);
}

void e() 
{
    // e) El siguiente código es incorrecto. ¿Cómo debe ser el código siguiente para que n3 contenga
    // “Fragata Campeón”?

    char n1[]="Fragata";
    char n2[]="Campeón";
    // char n3[20];
    // n3=n1+n2;

    // printf("%s",n3);
    printf("%s %s\n", n1, n2);
}


void f() 
{

    // f) El siguiente código es incorrecto. ¿Cómo debe ser el código siguiente para que “Azul” sea igual
    // a “Azul”?
    char n1[]="Azul";
    char n2[]="Azul";
    // if (n1==n2) { 
    if (strcmp(n1, n2) == 0) {
        printf("Iguales\n");
    }
    else { 
        printf("Distintos\n");
    }
}

void g() 
{
    // g) ¿Por qué se acorta la palabra?
    char n[]="Primavera";
    n[4]='\0';
    printf("%s\n",n);
    // Porque el '\0' o "null terminator" se usa
    // para mostrar donde se terminan los caracteres del buffer
    // de un string, sino, al declarar un string con el tamano de 10 caracteres
    // Y usando unicamente 5 caracteres, el resto de string seria corrompido
}

int main() 
{
    a();
    b();
    c();
    d();
    e();
    f();
    g();

    return 0;
}