#include "../lib/et21conio.h"
#include <stdio.h>

int main()
{
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


    for (int i = 0; i < 7; i++) {
        textcolor(i);
        printf("%s", colors[i]);
    }

    return 0;
}
