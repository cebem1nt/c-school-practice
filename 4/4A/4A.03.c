#include <stdio.h>

const char* ansi_fg_colors[] = {
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

const char* ansi_bg_colors[] = {
    "\033[40m", // BLACK
    "\033[44m", // BLUE
    "\033[42m", // GREEN
    "\033[46m", // CYAN
    "\033[41m", // RED
    "\033[45m", // MAGENTA
    "\033[43m", // BROWN
    "\033[47m", // LIGHTGRAY
    "\033[100m", // DARKGRAY
    "\033[104m", // LIGHTBLUE
    "\033[102m", // LIGHTGREEN
    "\033[106m", // LIGHTCYAN
    "\033[101m", // LIGHTRED
    "\033[105m", // LIGHTMAGENTA
    "\033[103m", // YELLOW
    "\033[107m"  // WHITE
};


void color_by_num(const char* str, 
                  unsigned int fg_num, unsigned int bg_num) 
{
    if (fg_num > 15 || bg_num > 15) 
    {
        fprintf(stderr, "El numero de color es incorrectro. \nAsi que no voy a imprimir tu \"%s\"\n", str);
        return;
    }

    const char* fg = ansi_fg_colors[fg_num];
    const char* bg = ansi_bg_colors[bg_num];

    char* ansi_reset = "\033[0m";
 
    printf("%s%s%s%s\n", bg, fg, str, ansi_reset);
}

int main() 
{
    int color = 2;
    
    color_by_num("Hola mundo", 5, 13);
    color_by_num("Todo bien mundo ?", 6, 7);
    color_by_num("Adios mundo", 16, 20); 
}