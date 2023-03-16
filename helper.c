#include <windows.h>
#include <stdio.h>
#include <locale.h>


void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void draw_square_hollow(int x1, int x2, int y1, int y2)
{
    int i, j;
    // setlocale(LC_CTYPE, "");
    for (i = x1; i <= x2; ++i)
    {
        for (j = y1; j <= y2; ++j)
        {
            if (i == x1 || i == x2 || j == y1 || j == y2)
            {
                gotoxy(i, j);
                // wprintf(L"\x2588");
                printf("█");
            }
            else
            {
                gotoxy(i, j);
            }
        }
        gotoxy(i, j);
    }
}

void draw_square(int x1, int x2, int y1, int y2)
{
    int i, j;
    // setlocale(LC_CTYPE, "");
    for (i = x1; i <= x2; ++i)
    {
        for (j = y1; j <= y2; ++j)
        {
            gotoxy(i, j);
            // wprintf(L"\x2588");
            printf("█");
        }
        gotoxy(i, j);
    }
}
