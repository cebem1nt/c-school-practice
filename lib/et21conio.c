#include <stdio.h>
#include "et21conio.h"
#include <stdbool.h>
#include <windows.h>
#include <stdlib.h>

#define TEXT_COLOR      0
#define TEXT_BACKGROUND 1

char colors[16][13] = {
                         "BLACK",
                         "BLUE",
                         "GREEN",
                         "CYAN",
                         "RED",
                         "MAGENTA",
                         "BROWN",
                         "LIGHTGRAY",
                         "DARKGRAY",
                         "LIGHTBLUE",
                         "LIGHTGREEN",
                         "LIGHTCYAN",
                         "LIGHTRED",
                         "LIGHTMAGENTA",
                         "YELLOW",
                         "WHITE"
                      };

// typedef unsigned short WORD;
WORD wAttributes[16][2] = {
/*       "BLACK"          */ {0x00, 0x00},
/*       "BLUE",          */ {0x01, 0x10},
/*       "GREEN",         */ {0x02, 0x20},
/*       "CYAN",          */ {0x03, 0x30},
/*       "RED",           */ {0x04, 0x40},
/*       "RED",           */ //{FOREGROUND_RED | FOREGROUND_INTENSITY, BACKGROUND_RED | BACKGROUND_INTENSITY},
/*       "MAGENTA",       */ {0x05, 0x50},
/*       "BROWN",         */ {0x06, 0x60},
/*       "LIGHTGRAY",     */ {0x07, 0x70},
/*       "DARKGRAY",      */ {0x08, 0x80},
/*       "LIGHTBLUE",     */ {0x09, 0x90},
/*       "LIGHTGREEN",    */ {0x0A, 0xA0},
/*       "LIGHTCYAN",     */ {0x0B, 0xB0},
/*       "LIGHTRED",      */ {0x0C, 0xC0},
/*       "LIGHTMAGENTA",  */ {0x0D, 0xD0},
/*       "YELLOW",        */ {0x0E, 0xE0},
/*       "WHITE"          */ {0x0F, 0xF0},
                          };

void gotoxy(int columna, int fila)
{
    COORD c;
    c.X = columna;
    c.Y = fila;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void cputsxy(int columna, int fila, char* str)
{
    gotoxy(columna, fila);
    printf("%s", str);
}

void clrscr()
{
    system("cls");
}

int esUnCodigoDeColorValido(int color)
{
    return (color >= 0) && (color <= 15);
}

void mostrarMensajeDeError()
{
    printf("ERROR: No existe el color solicitado");
}

void hacerCambioDeColorPara(int target, int color)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // p - previous , n - new
    WORD pwAttributes;
    WORD nwAttributes = wAttributes[color][target];
    WORD alignedWAttributes;

    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        pwAttributes = csbi.wAttributes;
    } else {
      // If we could not get csbi, something definitely went wrong.
      return;
    }

    if (target == 0) {
        // Foreground change: set new fg and keep bg
        alignedWAttributes = (pwAttributes & 0xF0) | (nwAttributes & 0x0F);
    } else if (target == 1) {
        // Background change: set new bg and keep fg
        alignedWAttributes = (pwAttributes & 0x0F) | (nwAttributes & 0xF0);
    } else {
        // If someone too curious would run this with incorrect target
        return;
    }

    // Debug
    // printf("\n0x%02x\n", pwAttributes);
    // printf("\n0x%02x\n", nwAttributes);
    // printf("\n0x%02x\n", alignedWAttributes);

    SetConsoleTextAttribute(hConsole, alignedWAttributes);
}

void textbackground(int color)
{
    if (esUnCodigoDeColorValido(color)) {
//        mostrarMensajeDeColorCambiadoPara("FONDO", color);
        hacerCambioDeColorPara(TEXT_BACKGROUND, color);
    } else {
        mostrarMensajeDeError();
    }

}

void textcolor(int color)
{
    if (esUnCodigoDeColorValido(color)) {
//        mostrarMensajeDeColorCambiadoPara("TEXTO", color);
        hacerCambioDeColorPara(TEXT_COLOR, color);
    } else {
        mostrarMensajeDeError();
    }
}

void mostrarMensajeDeColorCambiadoPara(char* target, int color)
{
    printf(" * Se ha modificado el color del %s a: %s *\n", target, colors[color]);
}

void mostrarTodosColores()
{
    printf("Se van a probar diferentes codigos hexa:\n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
    printf("Cambiado el color 0x00 \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00 | FOREGROUND_INTENSITY);
    printf("Cambiado el color 0x00 | FOREGROUND_INTENSITY \n");


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01);
    printf("Cambiado el color 0x01 \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01 | FOREGROUND_INTENSITY);
    printf("Cambiado el color 0x01 | FOREGROUND_INTENSITY \n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
    printf("Cambiado el color 0x02 \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02 | FOREGROUND_INTENSITY);
    printf("Cambiado el color 0x02 | FOREGROUND_INTENSITY \n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x03);
    printf("Cambiado el color 0x03 \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x03 | FOREGROUND_INTENSITY);
    printf("Cambiado el color 0x03 | FOREGROUND_INTENSITY \n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
    printf("Cambiado el color 0x04 \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04 | FOREGROUND_INTENSITY);
    printf("Cambiado el color 0x04 | FOREGROUND_INTENSITY \n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
    printf("Cambiado el color 0x05 \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05 | FOREGROUND_INTENSITY);
    printf("Cambiado el color 0x05 | FOREGROUND_INTENSITY \n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
    printf("Cambiado el color 0x06 \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06 | FOREGROUND_INTENSITY);
    printf("Cambiado el color 0x06 | FOREGROUND_INTENSITY \n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
    printf("Cambiado el color 0x07 \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07 | FOREGROUND_INTENSITY);
    printf("Cambiado el color 0x07 | FOREGROUND_INTENSITY \n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08);
    printf("Cambiado el color 0x08 \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08 | FOREGROUND_INTENSITY);
    printf("Cambiado el color 0x08 | FOREGROUND_INTENSITY \n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
    printf("Cambiado el color 0x09 \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09 | FOREGROUND_INTENSITY);
    printf("Cambiado el color 0x09 | FOREGROUND_INTENSITY \n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
    printf("Cambiado el color 0x0A \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A | FOREGROUND_INTENSITY);
    printf("Cambiado el color 0x0A | FOREGROUND_INTENSITY \n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
    printf("Cambiado el color 0x0B \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B | FOREGROUND_INTENSITY);
    printf("Cambiado el color 0x0B | FOREGROUND_INTENSITY \n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
    printf("Cambiado el color 0x0C \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C | FOREGROUND_INTENSITY);
    printf("Cambiado el color 0x0C | FOREGROUND_INTENSITY \n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0D);
    printf("Cambiado el color 0x0D \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0D | FOREGROUND_INTENSITY);
    printf("Cambiado el color 0x0D | FOREGROUND_INTENSITY \n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
    printf("Cambiado el color 0x0E \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E | FOREGROUND_INTENSITY);
    printf("Cambiado el color 0x0E | FOREGROUND_INTENSITY \n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
    printf("Cambiado el color 0x0F \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F | FOREGROUND_INTENSITY);
    printf("Cambiado el color 0x0F | FOREGROUND_INTENSITY \n");
}

/* Recursos relacionados para cambios de colores en consola:
 * - https://learn.microsoft.com/en-us/windows/console/console-screen-buffers#character-attributes
 * - https://learn.microsoft.com/en-us/windows/console/setconsoletextattribute
 * - https://www.studytonight.com/c/programs/misc/changing-text-background-color
 */
void mostrarTodosLosEjemplosWeb()
{
//        SetConsoleTextAttribute();
    //BACKGROUND_RED| BACKGROUND_GREEN| BACKGROUND_BLUE| BACKGROUND_INTENSITY
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_BLUE);
    printf("\nFor example, the combination results in cyan text on a blue background.");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
    printf("\nFor example, the combination results in bright cyan text on a blue background.");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
    printf("\nFor example, the following combination produces black text on a white background.");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_INTENSITY);
    printf("\n\nStudytonight just showed you how to put colors to your code!!");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN);
    printf("\n\nIsn't this Awesome?");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED);
    printf("\n\nYou just did something that only 1 out of 10 coders are familiar of :)\n");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    printf("\n\nYou are doing great!!");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_INTENSITY);
    printf("\n\nThe best is yet to come!");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    printf("\n\nWhat are you waiting for?? Just play with it!!");

    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
}
