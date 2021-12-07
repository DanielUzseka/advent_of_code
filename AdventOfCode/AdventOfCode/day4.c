#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void day4_1(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day4.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[350];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    char* c2 = '\0';
    int nums[100];
    int i = 0;
    int bingo[100][5][5];
    int x = 0, y = 0, cnt = 0;
    int hitCount[100][10] = { 0 };
    int map[100][5] = { 0 };
    
    fgets(ret, 350, fptr);

    c1 = strtok(ret, ",");
    while (c1 != NULL) 
    {
        nums[i++] = atoi(c1);
        c1 = strtok(NULL, ",");
    }

    //first empty line
    fgets(ret, 99, fptr);

    while (fgets(ret, 99, fptr) != NULL) { // standard C I/O file reading loop
        //c1 = ret;
        if ('\n' == ret[0])
        {
            cnt++;
            y = 0;
            //new bingo map
        }
        else
        {
            c1 = strtok(ret, " ");
            x = 0;
            //bingo[cnt][y][x++] = atoi(c1);
            while (c1 != NULL)
            {
                bingo[cnt][y][x++] = atoi(c1);
                c1 = strtok(NULL, " ");
            }
            y++;
        }
    }
    int found = 0;
    int a, b, c, d;

    for (a = 0; a < sizeof(nums); a++)
    {
        for (b = 0; b < 100; b++)
        {
            for (c = 0; c < 5; c++)
            {
                for (d = 0; d < 5; d++)
                {
                    if (nums[a] == bingo[b][c][d])
                    {
                        hitCount[b][c]++;
                        hitCount[b][d + 5]++;
                        if (5 == hitCount[b][c])
                        {
                            found = 1;
                        }
                        else if (5 == hitCount[b][d + 5])
                        {
                            found = 2;
                        }
                        map[b][c] |= 1 << d;
                    }
                    if (0 != found) break;
                }
                if (0 != found) break;
            }
            if (0 != found) break;
        }
        if (0 != found) break;
    }

    int sum = 0;
    for (int j = 0; j < 5; j++)
    {
        for (int k = 0; k < 5; k++)
        {
            if ((map[b][j] & (1 << k)) == 0)
                sum += bingo[b][j][k];
        }
    }

    printf("Totoal: %i", nums[a] * sum);

    return;
}

void day4_2(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day4.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[350];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    char* c2 = '\0';
    int nums[100];
    int i = 0;
    int bingo[100][5][5];
    int x = 0, y = 0, cnt = 0;
    int hitCount[100][10] = { 0 };
    int map[100][5] = { 0 };
    int enable[100] = { 0 };
    int enableCount = 0;

    fgets(ret, 350, fptr);

    c1 = strtok(ret, ",");
    while (c1 != NULL)
    {
        nums[i++] = atoi(c1);
        c1 = strtok(NULL, ",");
    }

    //first empty line
    fgets(ret, 99, fptr);

    while (fgets(ret, 99, fptr) != NULL) { // standard C I/O file reading loop
        //c1 = ret;
        if ('\n' == ret[0])
        {
            cnt++;
            y = 0;
            //new bingo map
        }
        else
        {
            c1 = strtok(ret, " ");
            x = 0;
            //bingo[cnt][y][x++] = atoi(c1);
            while (c1 != NULL)
            {
                bingo[cnt][y][x++] = atoi(c1);
                c1 = strtok(NULL, " ");
            }
            y++;
        }
    }
    int found = 0;
    int a, b, c, d;

    for (a = 0; a < sizeof(nums); a++)
    {
        for (b = 0; b < 100; b++)
        {
            if (0 == enable[b])
            {
                for (c = 0; c < 5; c++)
                {
                    for (d = 0; d < 5; d++)
                    {
                        if (nums[a] == bingo[b][c][d])
                        {
                            hitCount[b][c]++;
                            hitCount[b][d + 5]++;
                            if ((5 == hitCount[b][c]) || (5 == hitCount[b][d + 5]))
                            {
                                enableCount++;
                                enable[b] = 1;
                            }
                            map[b][c] |= 1 << d;
                            if (100 == enableCount)
                                found = 1;
                        }
                        if (0 != found) break;
                    }
                    if (0 != found) break;
                }
                if (0 != found) break;
            }
        }
        if (0 != found) break;
    }

    int sum = 0;
    for (int j = 0; j < 5; j++)
    {
        for (int k = 0; k < 5; k++)
        {
            if ((map[b][j] & (1 << k)) == 0)
                sum += bingo[b][j][k];
        }
    }

    printf("Totoal: %i", nums[a] * sum);

    return;
}