#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void day2_1(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day2.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[99];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    char* c2 = '\0';
    int x = 0, y = 0;
    while (fgets(ret, 99, fptr) != NULL) { // standard C I/O file reading loop
        c1 = ret;
        if (0 == strncmp(c1, "forward", sizeof("forward") - 1))
        {
            x += atoi(strchr(c1, ' '));
        }
        else if (0 == strncmp(c1, "down", sizeof("down") - 1))
        {
            y += atoi(strchr(c1, ' '));
        }
        else if (0 == strncmp(c1, "up", sizeof("up") - 1))
        {
            y -= atoi(strchr(c1, ' '));
        }

    }

    fclose(fptr);

    printf("Tot: %i, x: %i, y: %i", x*y, x, y);

    return;
}

void day2_2(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day2.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[99];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    char* c2 = '\0';
    long int x = 0, aim = 0, y = 0, tmp;
    while (fgets(ret, 99, fptr) != NULL) { // standard C I/O file reading loop
        c1 = ret;
        if (0 == strncmp(c1, "forward", sizeof("forward") - 1))
        {
            tmp = atoi(strchr(c1, ' '));
            x += tmp;
            y += tmp * aim;
        }
        else if (0 == strncmp(c1, "down", sizeof("down") - 1))
        {
            aim += atoi(strchr(c1, ' '));
        }
        else if (0 == strncmp(c1, "up", sizeof("up") - 1))
        {
            aim -= atoi(strchr(c1, ' '));
        }

    }

    fclose(fptr);

    printf("Tot: %i, x: %i, y: %i, aim: %i", x * y, x, y, aim);

    return;
}