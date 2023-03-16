#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
// #include <locale.h>

#include "ansi.h"
#include "helper.h"
#include "main.h"


int main()
{
    system("cls");
    // setlocale(LC_CTYPE, "");
    int second, minute, hour;
    draw_clock_border();
    while (1)
    {
        clock_t t;
        t = clock();
        time_t rawtime;
        struct tm *timeinfo;

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        hour = timeinfo->tm_hour;
        minute = timeinfo->tm_min;
        second = timeinfo->tm_sec;

        gotoxy(0, 2);
        printf("%s", asctime(timeinfo));

        draw_second(second % 2);
        draw_hour_five((int)(hour / 5));
        draw_hour_one(hour % 4);
        draw_minute_five((int)(minute / 5));
        draw_minute_one(minute % 5);

        t = clock() - t;
        gotoxy(0, 27);
        printf("Rendered in: %.2f ms.", ((float)t/CLOCKS_PER_SEC)*1000);


        Sleep(950);

    }
}

void draw_clock_border()
{
    // Top
    draw_square_hollow(12, 18, 3, 9);

    // Big square
    draw_square_hollow(4, 26, 9, 25);

    // T1
    draw_square_hollow(4, 10, 9, 13);
    // T2
    draw_square_hollow(10, 15, 9, 13);
    // T3
    draw_square_hollow(15, 20, 9, 13);
    // T4
    draw_square_hollow(20, 26, 9, 13);

    // T1
    draw_square_hollow(4, 10, 13, 17);
    // T2
    draw_square_hollow(10, 15, 13, 17);
    // T3
    draw_square_hollow(15, 20, 13, 17);
    // T4
    draw_square_hollow(20, 26, 13, 17);

    int i;
    for (i = 4; i < 26; i+=2)
    {
        draw_square_hollow(i, i+2, 17, 21);
    }

    // B1
    draw_square_hollow(4, 10, 21, 25);
    // B2
    draw_square_hollow(10, 15, 21, 25);
    // B3
    draw_square_hollow(15, 20, 21, 25);
    // B4
    draw_square_hollow(20, 26, 21, 25);
}

void draw_second(int status)
{
    if (status)
    {
        printf(YEL);
        draw_square(13, 17, 4, 8);
        printf(RESET);
        return;
    }
    printf(BLK);
    draw_square(13, 17, 4, 8);
    printf(RESET);
}

void draw_minute_one(int status)
{
    printf(YEL);
    switch (status)
    {
    case 4:
        draw_square(21, 25, 22, 24);
    case 3:
        draw_square(16, 19, 22, 24);
    case 2:
        draw_square(11, 14, 22, 24);
    case 1:
        draw_square(5, 9, 22, 24);
        break;
    case 0:
        printf(BLK);
        draw_square(21, 25, 22, 24);
        draw_square(16, 19, 22, 24);
        draw_square(11, 14, 22, 24);
        draw_square(5, 9, 22, 24);
        break;
    default:
        break;
    }
    printf(RESET);
}

void draw_minute_five(int status)
{
	int i;
    printf(YEL);
    switch (status)
    {
    case 11:
        draw_square(25, 25, 18, 20);
    case 10:
        draw_square(23, 23, 18, 20);
    case 9:
        printf(RESET);
        printf(RED);
        draw_square(21, 21, 18, 20);
        printf(RESET);
    case 8:
        printf(YEL);
        draw_square(19, 19, 18, 20);
    case 7:
        draw_square(17, 17, 18, 20);
    case 6:
        printf(RESET);
        printf(RED);
        draw_square(15, 15, 18, 20);
        printf(RESET);
    case 5:
        printf(YEL);
        draw_square(13, 13, 18, 20);
    case 4:
        draw_square(11, 11, 18, 20);
    case 3:
        printf(RESET);
        printf(RED);
        draw_square(9, 9, 18, 20);
        printf(RESET);
    case 2:
        printf(YEL);
        draw_square(7, 7, 18, 20);
    case 1:
        draw_square(5, 5, 18, 20);
        break;
    case 0:
        printf(BLK);
        for (i = 5; i < 26; i+=2)
        {
            draw_square(i, i, 18, 20);
        }
        break;
    default:
        break;
    }
    printf(RESET);
}

void draw_hour_one(int status)
{
    printf(RED);
    switch (status)
    {
    case 4:
        draw_square(21, 25, 14, 16);
    case 3:
        draw_square(16, 19, 14, 16);
    case 2:
        draw_square(11, 14, 14, 16);
    case 1:
        draw_square(5, 9, 14, 16);
        break;
    case 0:
        printf(BLK);
        draw_square(21, 25, 14, 16);
        draw_square(16, 19, 14, 16);
        draw_square(11, 14, 14, 16);
        draw_square(5, 9, 14, 16);
        break;
    default:
        break;
    }
    printf(RESET);
}

void draw_hour_five(int status)
{
    printf(RED);
    switch (status)
    {
    case 4:
        draw_square(21, 25, 10, 12);
    case 3:
        draw_square(16, 19, 10, 12);
    case 2:
        draw_square(11, 14, 10, 12);
    case 1:
        draw_square(5, 9, 10, 12);
        break;
    case 0:
        printf(BLK);
        draw_square(21, 25, 10, 12);
        draw_square(16, 19, 10, 12);
        draw_square(11, 14, 10, 12);
        draw_square(5, 9, 10, 12);
        break;
    default:
        break;
    }
    printf(RESET);
}
