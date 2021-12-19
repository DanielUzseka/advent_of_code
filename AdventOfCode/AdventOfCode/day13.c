#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


void day13_1(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day13.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[100];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int sum = 0;
    //unsigned short map[150][100] = { 0 };
    unsigned short(*map)[1310] = malloc(sizeof * map * 895);
    int status = 0;
    int folds[12][2];
    int cnt = 0;

    for (int i = 0; i < 895; i++)
        for (int j = 0; j < 1310; j++)
            map[i][j] = 0;


    while (fgets(ret, 100, fptr) != NULL) {
        c1 = ret;
        if (0 == status)
        {
            if (strlen(c1) > 2)
            {
                c1 = strtok(c1, ",");
                int x = atoi(c1);
                c1 = strtok(NULL, "\n");
                int y = atoi(c1);
                map[y][x] |= 1;
            }
            else
            {
                status = 1;
            }
        }
        else
        {
            c1 = strtok(c1, " ");
            c1 = strtok(NULL, " ");
            c1 = strtok(NULL, "=");
            if ('y' == c1[0])
                folds[cnt][0] = 0;
            else
                folds[cnt][0] = 1;
            c1 = strtok(NULL, "\n");
            folds[cnt++][1] = atoi(c1);
        }
    }

    if (folds[0][0] == 0)
        for (int i = folds[0][1] + 1; i < 895; i++)
            for (int j = 0; j < 1310; j++)
                map[2 * folds[0][1] - i][j] |= map[i][j];
    else
        for (int i = 0; i < 895; i++)
            for (int j = folds[0][1] + 1; j < 1310; j++)
                map[i][2 * folds[0][1] - j] |= map[i][j];

    for (int i = 0; i < 895; i++)
        for (int j = 0; j < folds[0][1]; j++)
            if (map[i][j] > 0)
                sum++;
    printf("Total: %i", sum);

    free(map);

    return;
}

void day13_2(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day13.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[100];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int sum = 0;
    //unsigned short map[150][100] = { 0 };
    unsigned short(*map)[1310] = malloc(sizeof * map * 895);
    int status = 0;
    int folds[12][2];
    int cnt = 0;

    for (int i = 0; i < 895; i++)
        for (int j = 0; j < 1310; j++)
            map[i][j] = 0;


    while (fgets(ret, 100, fptr) != NULL) {
        c1 = ret;
        if (0 == status)
        {
            if (strlen(c1) > 2)
            {
                c1 = strtok(c1, ",");
                int x = atoi(c1);
                c1 = strtok(NULL, "\n");
                int y = atoi(c1);
                map[y][x] |= 1;
            }
            else
            {
                status = 1;
            }
        }
        else
        {
            c1 = strtok(c1, " ");
            c1 = strtok(NULL, " ");
            c1 = strtok(NULL, "=");
            if ('y' == c1[0])
                folds[cnt][0] = 0;
            else
                folds[cnt][0] = 1;
            c1 = strtok(NULL, "\n");
            folds[cnt++][1] = atoi(c1);
        }
    }

    int iMax = 895;
    int jMax = 1310;

    for (int cnt = 0; cnt < 12; cnt++)
    {
        if (folds[cnt][0] == 0)
        {
            for (int i = folds[cnt][1] + 1; i < iMax; i++)
                for (int j = 0; j < jMax; j++)
                    map[2 * folds[cnt][1] - i][j] |= map[i][j];
            iMax = folds[cnt][1];
        }
        else
        {
            for (int i = 0; i < iMax; i++)
                for (int j = folds[cnt][1] + 1; j < jMax; j++)
                    map[i][2 * folds[cnt][1] - j] |= map[i][j];
            jMax = folds[cnt][1];
        }
    }

    for (int i = 0; i < iMax; i++)
    {
        for (int j = 0; j < jMax; j++)
        {
            if (map[i][j] == 0)
                printf(".");
            else
                printf("#");
        }
        printf("\n");
    }
    

    free(map);

    return;
}