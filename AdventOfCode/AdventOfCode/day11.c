#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void day11_1(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day11.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[4000];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int i = 0, j = 0, k = 0;;
    int sum = 0;
    int map[10][10];
    int flashed[10][10] = { 0 };
    int frontier[100][2];
    int frontierCnt = 0;
    int frontierTail = 0;
    int neighbours[8][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };

    while (fgets(ret, 120, fptr) != NULL) {
        c1 = ret;
        c1 = strtok(c1, "\n");
        for (i = 0; i < 10; i++)
            map[j][i] = (int)(c1[i] - '0');
        j++;
    }

    for (i = 0; i < 100; i++)
    {
        memset(flashed, 0, sizeof(flashed));
        frontierTail = 0;
        frontierCnt = 0;
        //increase 1 by start
        for (j = 0; j < 10; j++)
        {
            for (k = 0; k < 10; k++)
            {
                map[j][k]++;
                if (map[j][k] > 9)
                {
                    frontier[frontierCnt][0] = j;
                    frontier[frontierCnt++][1] = k;
                    flashed[j][k] = 1;
                    sum++;
                }
            }
        }

        while (frontierCnt > frontierTail)
        {
            int y = frontier[frontierTail][0];
            int x = frontier[frontierTail][1];
            frontierTail++;

            for (int a = 0; a < 8; a++)
            {
                int yNew = y + neighbours[a][0];
                int xNew = x + neighbours[a][1];
                if ((yNew >= 0) && (yNew <= 9) && (xNew >= 0) && (xNew <= 9))
                {
                    if (0 == flashed[yNew][xNew])
                    {
                        map[yNew][xNew]++;
                        if (map[yNew][xNew] > 9)
                        {
                            frontier[frontierCnt][0] = yNew;
                            frontier[frontierCnt][1] = xNew;
                            flashed[yNew][xNew] = 1;
                            frontierCnt++;
                            sum++;
                        }
                    }
                }
            }
        } //while

        for (j = 0; j < 10; j++)
            for (k = 0; k < 10; k++)
                if (map[j][k] > 9)
                    map[j][k] = 0;


    }

    printf("Total: %i", sum);

    return;
}

void day11_2(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day11.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[4000];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int i = 0, j = 0, k = 0;;
    int sum = 0;
    int map[10][10];
    int flashed[10][10] = { 0 };
    int frontier[100][2];
    int frontierCnt = 0;
    int frontierTail = 0;
    int neighbours[8][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };
    int go = 1;
    int goCnt = 0;

    while (fgets(ret, 120, fptr) != NULL) {
        c1 = ret;
        c1 = strtok(c1, "\n");
        for (i = 0; i < 10; i++)
            map[j][i] = (int)(c1[i] - '0');
        j++;
    }

    while (1 == go)
    {
        memset(flashed, 0, sizeof(flashed));
        frontierTail = 0;
        frontierCnt = 0;
        sum = 0;
        //increase 1 by start
        for (j = 0; j < 10; j++)
        {
            for (k = 0; k < 10; k++)
            {
                map[j][k]++;
                if (map[j][k] > 9)
                {
                    frontier[frontierCnt][0] = j;
                    frontier[frontierCnt++][1] = k;
                    flashed[j][k] = 1;
                    sum++;
                }
            }
        }

        while (frontierCnt > frontierTail)
        {
            int y = frontier[frontierTail][0];
            int x = frontier[frontierTail][1];
            frontierTail++;

            for (int a = 0; a < 8; a++)
            {
                int yNew = y + neighbours[a][0];
                int xNew = x + neighbours[a][1];
                if ((yNew >= 0) && (yNew <= 9) && (xNew >= 0) && (xNew <= 9))
                {
                    if (0 == flashed[yNew][xNew])
                    {
                        map[yNew][xNew]++;
                        if (map[yNew][xNew] > 9)
                        {
                            frontier[frontierCnt][0] = yNew;
                            frontier[frontierCnt][1] = xNew;
                            flashed[yNew][xNew] = 1;
                            frontierCnt++;
                            sum++;
                        }
                    }
                }
            }
        } //while

        for (j = 0; j < 10; j++)
            for (k = 0; k < 10; k++)
                if (map[j][k] > 9)
                    map[j][k] = 0;
        
        if (100 == sum)
            go = 0;

        goCnt++;

    }

    printf("Total: %i", goCnt);

    return;
}