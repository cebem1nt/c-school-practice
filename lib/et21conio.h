#ifndef ET21CONIO_H_INCLUDED
#define ET21CONIO_H_INCLUDED

    #define BLACK         0
    #define BLUE          1
    #define GREEN         2
    #define CYAN          3
    #define RED           4
    #define MAGENTA       5
    #define BROWN         6
    #define LIGHTGRAY     7
    #define DARKGRAY      8
    #define LIGHTBLUE     9
    #define LIGHTGREEN   10
    #define LIGHTCYAN    11
    #define LIGHTRED     12
    #define LIGHTMAGENTA 13
    #define YELLOW       14
    #define WHITE        15

    // Borra la pantalla y deja el cursor en el origen de coordenadas
    extern void clrscr();

    // Imprime la cadena de caracteres 'str' en las coordenadas de pantalla 'columna' y 'fila'
    extern void cputsxy(int columna, int fila, char * str);

    // Mueve el cursor a las coordenadas indicadas por 'columna' y 'fila'
    extern void gotoxy(int columna, int fila);

    /* Establece el color 'color' en lo que sigue para el fondo de los caracteres que se impriman.
     * Se mantiene hasta que no se establezca uno nuevo. Ver la tabla de códigos de color en el archivo
     * "Detalle de las funciones de conIO2 */
    extern void textbackground(int color);

    /* Establece el color 'color' en lo que sigue para los caracteres que se impriman.
     * Se mantiene hasta que no se establezca uno nuevo. Ver la tabla de códigos de color en el archivo */
    extern void textcolor(int color);

#endif // ET21CONIO_H_INCLUDED
