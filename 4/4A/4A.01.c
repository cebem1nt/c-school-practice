#include <stdio.h>

void letras_rojas(const char* str) 
{
    // Done with ansi codes, which is supported by all modern terminals
    char* ansi_red = "\033[31m";
    char* ansi_reset = "\033[0m";

    printf("%s%s%s\n", ansi_red, str, ansi_reset);
}

int main() 
{
    letras_rojas("Hola mundo!");
    return 0;
}