#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


void day15_1(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day15.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[500];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int table[100][100];
    int x = 0, y = 0;
    int neighbours[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int costs[100][100] = { 0 };
    int frontier[5000][2];
    int visited[100][100] = { 0 };
    int frontierCnt = 0;
    bool keepGoing = true;

    while (fgets(ret, 500, fptr) != NULL) {
        c1 = strtok(ret, "\n");
        x = 0;
        for (int i = 0; i < strlen(c1); i++)
            table[y][x++] = c1[i]- '0';

        y++;
    }

    frontier[frontierCnt][0] = 0;
    frontier[frontierCnt++][1] = 0;

    while (true == keepGoing)
    {
        int min = 10000;
        int xmin, ymin;
        int index;
        for (int i = 0; i < frontierCnt; i++)
        {
            x = frontier[i][1];
            y = frontier[i][0];
            if (costs[y][x] < min)
            {
                if (visited[y][x] == 0)
                {
                    xmin = x;
                    ymin = y;
                    min = costs[y][x];
                    index = i;
                }
            }
        }

        if ((costs[99][99] != 0) && (min > costs[99][99]))
            break;

        visited[ymin][xmin] = 1;

        for (int i = 0; i < 4; i++)
        {
            int xact = xmin + neighbours[i][1];
            int yact = ymin + neighbours[i][0];
            if ((xact >= 0) && (xact < 100) && (yact >= 0) && (yact < 100))
            {
                if (visited[yact][xact] == 0)
                {
                    frontier[frontierCnt][0] = yact;
                    frontier[frontierCnt++][1] = xact;
                    if ((costs[yact][xact] == 0) || (costs[yact][xact] > costs[ymin][xmin] + table[yact][xact]))
                        costs[yact][xact] = costs[ymin][xmin] + table[yact][xact];

                }
            }
        }

        for (int i = index; i < frontierCnt - 1; i++)
        {
            frontier[i][0] = frontier[i + 1][0];
            frontier[i][1] = frontier[i + 1][1];
        }
        frontierCnt--;

    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
            printf("%i ", costs[i][j]);
        printf("\n");
    }


    printf("Total cost: %i", costs[99][99]);

    return;

}

void day15_2(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day15.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[500];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int(*table)[500] = malloc(sizeof(int[500][500]));
    int x = 0, y = 0;
    int neighbours[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int(*costs)[500] = malloc(sizeof(int[500][500]));
    int(*frontier)[500] = malloc(sizeof(int[500][500]));
    int(*visited)[500] = malloc(sizeof(int[500][500]));
    int frontierCnt = 0;
    bool keepGoing = true;

    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 500; j++)
        {
            costs[i][j] = 0;
            visited[i][j] = 0;
        }
    }

    while (fgets(ret, 500, fptr) != NULL) {
        c1 = strtok(ret, "\n");
        x = 0;
        for (int i = 0; i < strlen(c1); i++)
            table[y][x++] = c1[i] - '0';

        y++;
    }

    frontier[0][0] = 1;

    for (int j = 0; j < 100; j++)
    {
        for (int i = 100; i < 500; i++)
        {
            table[i][j] = table[i % 100][j] + i / 100;
            if (table[i][j] > 9)
                table[i][j] = table[i][j] % 9;
        }
    }

    for (int i = 0; i < 500; i++)
    {
        for (int j = 100; j < 500; j++)
        {
            table[i][j] = table[i][j % 100] + j / 100;
            if (table[i][j] > 9)
                table[i][j] = table[i][j] % 9;
        }
    }

    while (true == keepGoing)
    {
        int min = 100000;
        int xmin = 0, ymin = 0;
        int index;
        for (int i = 0; i < 500; i++)
        {
            for (int j = 0; j < 500; j++)
            {
                if (frontier[i][j] == 1)
                {
                    x = j;
                    y = i;
                    if (costs[y][x] < min)
                    {
                        if (visited[y][x] == 0)
                        {
                            xmin = x;
                            ymin = y;
                            min = costs[y][x];
                            index = i;
                        }
                    }
                }
            }

        }

        if ((costs[499][499] != 0) && (min > costs[499][499]))
            break;

        visited[ymin][xmin] = 1;
        frontier[ymin][xmin] = 0;

        for (int i = 0; i < 4; i++)
        {
            int xact = xmin + neighbours[i][1];
            int yact = ymin + neighbours[i][0];
            if ((xact >= 0) && (xact < 500) && (yact >= 0) && (yact < 500))
            {
                if (visited[yact][xact] == 0)
                {
                    frontier[yact][xact] = 1;
                    if ((costs[yact][xact] == 0) || (costs[yact][xact] > costs[ymin][xmin] + table[yact][xact]))
                        costs[yact][xact] = costs[ymin][xmin] + table[yact][xact];

                }
            }
        }


    }


    printf("Total cost: %i", costs[499][499]);

    free(frontier);
    free(table);
    free(visited);
    free(costs);

    return;

}
