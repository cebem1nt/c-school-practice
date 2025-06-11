#include <windows.h>
#include <string.h>
#include <stdio.h>

int get_center_column()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    return (csbi.srWindow.Right - csbi.srWindow.Left + 1) / 2;
}

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
    int center_x = get_center_column();
    char *hola = "HOLA";

    for (int i = 0; i < 4; i++) {
        gotoxy(center_x, i);
        printf("%c\n", hola[i]);
    }

    return 0;
}

