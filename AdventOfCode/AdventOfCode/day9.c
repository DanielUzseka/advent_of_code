#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void day9_1(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day9.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[4000];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int i = 0, j = 0;
    int sum = 0;
    int map[100][100];

    while (fgets(ret, 120, fptr) != NULL) {
        c1 = ret;
        c1 = strtok(c1, "\n");
        for (i = 0; i < 100; i++)
            map[j][i] = (int)(c1[i] - '0');
        j++;
    }

    for (j = 1; j < 99; j++)
        for (i = 1; i < 99; i++)
            if((map[j][i] < map[j+1][i]) && (map[j][i] < map[j-1][i]) && (map[j][i] < map[j][i+1]) && (map[j][i] < map[j][i-1]))
                sum += map[j][i] + 1;
    
    j = 0;
    
    for (i = 1; i < 99; i++)
        if ((map[j][i] < map[j + 1][i]) && (map[j][i] < map[j][i + 1]) && (map[j][i] < map[j][i - 1]))
            sum += map[j][i] + 1;
    
    j = 99;
    
    for (i = 1; i < 99; i++)
        if ((map[j][i] < map[j - 1][i]) && (map[j][i] < map[j][i + 1]) && (map[j][i] < map[j][i - 1]))
            sum += map[j][i] + 1;
    
    i = 0;
    
    for (j = 1; j < 99; j++)
        if ((map[j][i] < map[j + 1][i]) && (map[j][i] < map[j - 1][i]) && (map[j][i] < map[j][i + 1]))
            sum += map[j][i] + 1;
    
    i = 99;
    
    for (j = 1; j < 99; j++)
        if ((map[j][i] < map[j + 1][i]) && (map[j][i] < map[j - 1][i]) && (map[j][i] < map[j][i - 1]))
            sum += map[j][i] + 1;
    
    i = 0; j = 0;
    
    if ((map[j][i] < map[j + 1][i]) && (map[j][i] < map[j][i + 1]))
        sum += map[j][i] + 1;
    
    i = 99; j = 99;
    
    if ((map[j][i] < map[j - 1][i]) && (map[j][i] < map[j][i - 1]))
        sum += map[j][i] + 1;
    
    i = 0; j = 99;
    
    if ((map[j][i] < map[j - 1][i]) && (map[j][i] < map[j][i + 1]))
        sum += map[j][i] + 1;
    
    i = 99; j = 0;
    
    if ((map[j][i] < map[j + 1][i]) && (map[j][i] < map[j][i - 1]))
        sum += map[j][i] + 1;

    printf("Total: %i", sum);

    return;
}


void day9_2(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day9.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[4000];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int i = 0, j = 0;
    int sum = 0;
    int map[100][100];
    int lowPoints[500][2];
    int visited[100][100] = { 0 };
    int pointCnt = 0;
    int frontier[150][2];
    int frontierCnt = 0;
    int frontierTail = 0;
    int neighbours[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
    int maxes[3] = { 0 };

    while (fgets(ret, 120, fptr) != NULL) {
        c1 = ret;
        c1 = strtok(c1, "\n");
        for (i = 0; i < 100; i++)
            map[j][i] = (int)(c1[i] - '0');
        j++;
    }

    for (j = 1; j < 99; j++)
    {
        for (i = 1; i < 99; i++)
        {
            if ((map[j][i] < map[j + 1][i]) && (map[j][i] < map[j - 1][i]) && (map[j][i] < map[j][i + 1]) && (map[j][i] < map[j][i - 1]))
            {
                sum += map[j][i] + 1;
                lowPoints[pointCnt][0] = j;
                lowPoints[pointCnt++][1] = i;
            }
        }
    }

    j = 0;

    for (i = 1; i < 99; i++)
    {
        if ((map[j][i] < map[j + 1][i]) && (map[j][i] < map[j][i + 1]) && (map[j][i] < map[j][i - 1]))
        {
            sum += map[j][i] + 1;
            lowPoints[pointCnt][0] = j;
            lowPoints[pointCnt++][1] = i;
        }
    }

    j = 99;

    for (i = 1; i < 99; i++)
    {
        if ((map[j][i] < map[j - 1][i]) && (map[j][i] < map[j][i + 1]) && (map[j][i] < map[j][i - 1]))
        {
            sum += map[j][i] + 1;
            lowPoints[pointCnt][0] = j;
            lowPoints[pointCnt++][1] = i;
        }
    }

    i = 0;

    for (j = 1; j < 99; j++)
    {
        if ((map[j][i] < map[j + 1][i]) && (map[j][i] < map[j - 1][i]) && (map[j][i] < map[j][i + 1]))
        {
            sum += map[j][i] + 1;
            lowPoints[pointCnt][0] = j;
            lowPoints[pointCnt++][1] = i;
        }
    }

    i = 99;

    for (j = 1; j < 99; j++)
    {
        if ((map[j][i] < map[j + 1][i]) && (map[j][i] < map[j - 1][i]) && (map[j][i] < map[j][i - 1]))
        {
            sum += map[j][i] + 1;
            lowPoints[pointCnt][0] = j;
            lowPoints[pointCnt++][1] = i;
        }
    }

    i = 0; j = 0;

    if ((map[j][i] < map[j + 1][i]) && (map[j][i] < map[j][i + 1]))
    {
        sum += map[j][i] + 1;
        lowPoints[pointCnt][0] = j;
        lowPoints[pointCnt++][1] = i;
    }

    i = 99; j = 99;

    if ((map[j][i] < map[j - 1][i]) && (map[j][i] < map[j][i - 1]))
    {
        sum += map[j][i] + 1;
        lowPoints[pointCnt][0] = j;
        lowPoints[pointCnt++][1] = i;
    }

    i = 0; j = 99;

    if ((map[j][i] < map[j - 1][i]) && (map[j][i] < map[j][i + 1]))
    {
        sum += map[j][i] + 1;
        lowPoints[pointCnt][0] = j;
        lowPoints[pointCnt++][1] = i;
    }

    i = 99; j = 0;

    if ((map[j][i] < map[j + 1][i]) && (map[j][i] < map[j][i - 1]))
    {
        sum += map[j][i] + 1;
        lowPoints[pointCnt][0] = j;
        lowPoints[pointCnt++][1] = i;
    }

    for (i = 0; i < pointCnt; i++)
    {
        memset(visited, 0, sizeof(visited));
        frontierTail = 0;
        frontierCnt = 0;
        frontier[frontierCnt][0] = lowPoints[i][0];
        frontier[frontierCnt++][1] = lowPoints[i][1];
        visited[lowPoints[i][0]][lowPoints[i][1]] = 1;
        while (frontierCnt > frontierTail)
        {
            int y = frontier[frontierTail][0];
            int x = frontier[frontierTail][1];
            frontierTail++;
            
            for (int a = 0; a < 4; a++)
            {
                int yNew = y + neighbours[a][0];
                int xNew = x + neighbours[a][1];
                if ((yNew >= 0) && (yNew <= 99) && (xNew >= 0) && (xNew <= 99))
                {
                    if ((0 == visited[yNew][xNew]) && (map[yNew][xNew] != 9))
                    {
                        frontier[frontierCnt][0] = yNew;
                        frontier[frontierCnt][1] = xNew;
                        visited[yNew][xNew] = 1;
                        frontierCnt++;
                        for (int b = i + 1; b < pointCnt; b++)
                        {
                            if ((yNew == lowPoints[b][0]) && (xNew == lowPoints[b][1]))
                            {
                                for (int c = b; c < pointCnt - 1; c++)
                                {
                                    lowPoints[c][0] = lowPoints[c + 1][0];
                                    lowPoints[c][0] = lowPoints[c + 1][0];
                                }
                                b--;
                                pointCnt--;
                            }
                        }
                    }
                }
            }
        } //while

        if (maxes[0] < frontierTail)
        {
            maxes[2] = maxes[1]; maxes[1] = maxes[0]; maxes[0] = frontierTail;
        }
        else if(maxes[1] < frontierTail)
        {
            maxes[2] = maxes[1]; maxes[1] = frontierTail;
        }
        else if (maxes[2] < frontierTail)
        {
            maxes[2] = frontierTail;
        }
    
    }

    printf("Total: 1. %i, 2. %i, 3. %i", maxes[0], maxes[1], maxes[2]);

    return;
}