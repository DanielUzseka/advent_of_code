#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void day5_1(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day5.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[350];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int x1, x2, y1, y2;
    __int8 map[1000][1000] = { 0 };



    while (fgets(ret, 99, fptr) != NULL) { // standard C I/O file reading loop
        //c1 = ret;

        c1 = strtok(ret, ",");
        x1 = atoi(c1);

        c1 = strtok(NULL, "->");
        y1 = atoi(c1);

        c1 = strtok(NULL, " ");
        c1 = strtok(NULL, ",");
        x2 = atoi(c1);

        c1 = strtok(NULL, "\n");
        y2 = atoi(c1);

        if (x1 == x2)
        {
            if (y1 > y2)
                for (int i = y2; i <= y1; i++)
                    map[x1][i]++;
            else
                for (int i = y1; i <= y2; i++)
                    map[x1][i]++;
        }
        else if (y1 == y2)
        {
            if (x1 > x2)
                for (int i = x2; i <= x1; i++)
                    map[i][y1]++;
            else
                for (int i = x1; i <= x2; i++)
                    map[i][y1]++;
        }
    }
    
    int sum = 0;

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
            if (map[i][j] > 1)
                sum++;
    }

    printf("Total: %i", sum);

    return;
}

void day5_2(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day5.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[350];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int x1, x2, y1, y2;
    __int8 map[1000][1000] = { 0 };



    while (fgets(ret, 99, fptr) != NULL) { // standard C I/O file reading loop
        //c1 = ret;

        c1 = strtok(ret, ",");
        x1 = atoi(c1);

        c1 = strtok(NULL, "->");
        y1 = atoi(c1);

        c1 = strtok(NULL, " ");
        c1 = strtok(NULL, ",");
        x2 = atoi(c1);

        c1 = strtok(NULL, "\n");
        y2 = atoi(c1);

        if (x1 == x2)
        {
            if (y1 > y2)
                for (int i = y2; i <= y1; i++)
                    map[x1][i]++;
            else
                for (int i = y1; i <= y2; i++)
                    map[x1][i]++;
        }
        else if (y1 == y2)
        {
            if (x1 > x2)
                for (int i = x2; i <= x1; i++)
                    map[i][y1]++;
            else
                for (int i = x1; i <= x2; i++)
                    map[i][y1]++;
        }
        else
        {
            if (x1 > x2)
            {
                if(y1 > y2)
                    for (int i = 0; i <= x1 - x2; i++)
                        map[x2 + i][y2 + i]++;
                else
                    for (int i = 0; i <= x1 - x2; i++)
                        map[x2 + i][y2 - i]++;
            }
            else
            {
                if (y1 > y2)
                    for (int i = 0; i <= x2 - x1; i++)
                        map[x1 + i][y1 - i]++;
                else
                    for (int i = 0; i <= x2 - x1; i++)
                        map[x1 + i][y1 + i]++;
            }
        }
    }

    int sum = 0;

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
            if (map[i][j] > 1)
                sum++;
    }

    printf("Total: %i", sum);

    return;
}