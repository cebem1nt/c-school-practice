#include <windows.h>
#include <string.h>
#include <stdio.h>

void gotoxy(int x, int y)
{
    COORD c;

    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main()
{
    char *hola = "HOLA";

    for (int i = 0; i < 4; i++) {
        gotoxy(i, i);
        printf("%c\n", hola[i]);
    }

    return 0;
}
