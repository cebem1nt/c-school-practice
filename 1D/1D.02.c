#include "../lib/et21conio.h"
#include <windows.h>

void get_max_x_y(int* max_x, int* max_y)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    *max_x = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    *max_y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int main()
{
    int rows, columns;
    get_max_x_y(&rows, &columns);

    textcolor(RED);
    textbackground(YELLOW);

    cputsxy(columns / 2, rows / 2, "HOLA!");
    return 0;
}
