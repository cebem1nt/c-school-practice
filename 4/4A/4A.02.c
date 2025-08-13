#include <stdio.h>

const char* ansi_colors[] = {
    "\033[30m", // BLACK
    "\033[34m", // BLUE
    "\033[32m", // GREEN
    "\033[36m", // CYAN
    "\033[31m", // RED
    "\033[35m", // MAGENTA
    "\033[33m", // BROWN
    "\033[37m", // LIGHTGRAY
    "\033[90m", // DARKGRAY
    "\033[94m", // LIGHTBLUE
    "\033[92m", // LIGHTGREEN
    "\033[96m", // LIGHTCYAN
    "\033[91m", // LIGHTRED
    "\033[95m", // LIGHTMAGENTA
    "\033[93m", // YELLOW
    "\033[97m"  // WHITE
};


void color_by_num(const char* str, unsigned int num) 
{
    if (num > 15) 
    {
        fprintf(stderr, "El numero de color es incorrectro: %i,\nAsi que no voy a imprimir tu \"%s\"\n", num, str);
        return;
    }

    const char* color = ansi_colors[num];
    char* ansi_reset = "\033[0m";
 
    printf("%s%s%s\n", color, str, ansi_reset);
}

int main() 
{
    int color = 2;
    
    color_by_num("Hola mundo", 5);
    color_by_num("Adios mundo", 16); 
}