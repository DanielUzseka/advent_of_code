#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


void day14_1(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day14.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[100];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    char polymer[21];
    int sum = 0;
    int status = 0;
    char table[100][3];
    int cnt = 0;

    while (fgets(ret, 100, fptr) != NULL) {
        c1 = ret;
        if (0 == status)
        {
            if (strlen(c1) > 2)
                for (int i = 0; i < strlen(c1); i++)
                    polymer[i] = c1[i];
            else
                status = 1;
        }
        else
        {
            c1 = strtok(c1, " ");
            table[cnt][0] = c1[0];
            table[cnt][1] = c1[1];
            c1 = strtok(NULL, " ");
            c1 = strtok(NULL, "\n");
            table[cnt++][2] = c1[0];
        }
    }

    polymer[20] = '\0';
    //polymer[4] = '\0';

    char* pol_old = malloc(sizeof(char));
    char* pol_new = malloc(strlen(polymer));
    int j;
    for (j = 0; j < strlen(polymer); j++)
        pol_new[j] = polymer[j];
    pol_new[j] = '\0';
    int maxCnt;
    char letters[30] = { '\0' };
    int counters[30] = { 0 };

    int size = strlen(polymer);
    int a;

    for (int i = 0; i < 10; i++)
    {
        cnt = 0;
        a = strlen(pol_new);
        pol_old = malloc(50000);
        for (int l = 0; l < a; l++)
            pol_old[l] = pol_new[l];
        pol_old[a] = '\0';
        pol_new = malloc(50000);

        for (int l = 0; l < size; l++)
        {
            for (int k = 0; k < 100; k++)
            {
                if ((pol_old[l] == table[k][0]) && (pol_old[l + 1] == table[k][1]))
                {
                    pol_new[cnt++] = pol_old[l];
                    pol_new[cnt++] = table[k][2];
                    break;
                }
            }
        }
        pol_new[cnt++] = pol_old[size - 1];
        pol_new[cnt] = '\0';
        size = (size - 1) * 2 + 1;
    }

    cnt = 0;
    int i;
    for (i = 0; i < strlen(pol_new); i++)
    {
        bool letterFound = false;
        for (int j = 0; j < cnt; j++)
        {
            if (pol_new[i] == letters[j])
            {
                letterFound = true;
                counters[j]++;
                break;
            }
        }
        if (false == letterFound)
        {
            letters[cnt] = pol_new[i];
            counters[cnt++]++;
        }
    }
    
    free(pol_old);
    free(pol_new);

    int max = 0;
    int min = 99999;

    for (int i = 0; i < cnt; i++)
    {
        if (counters[i] > max)
            max = counters[i];
        if (counters[i] < min)
            min = counters[i];
    }
    printf("Total: %i", max - min);

    return;
}

void day14_2(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day14.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[100];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    char polymer[21];
    int sum = 0;
    int status = 0;
    char table[100][3];
    long long pairCnt[100] = { 0 };
    long long diff[100] = { 0 };
    int cnt = 0;

    while (fgets(ret, 100, fptr) != NULL) {
        c1 = ret;
        if (0 == status)
        {
            if (strlen(c1) > 2)
                for (int i = 0; i < strlen(c1); i++)
                    polymer[i] = c1[i];
            else
                status = 1;
        }
        else
        {
            c1 = strtok(c1, " ");
            table[cnt][0] = c1[0];
            table[cnt][1] = c1[1];
            c1 = strtok(NULL, " ");
            c1 = strtok(NULL, "\n");
            table[cnt++][2] = c1[0];
        }
    }

    polymer[20] = '\0';

    for (int j = 0; j < strlen(polymer) - 1; j++)
        for (int k = 0; k < 100; k++)
            if ((polymer[j] == table[k][0]) && (polymer[j + 1] == table[k][1]))
                pairCnt[k]++;

    char letters[10] = { 'O', 'F', '\0'};
    long long counters[10] = { 1, 1, 0 };


    for (int i = 0; i < 40; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (pairCnt[j] > 0)
            {
                char first[2], last[2];
                first[0] = table[j][0];
                first[1] = table[j][2];
                last[0] = table[j][2];
                last[1] = table[j][1];
                for (int k = 0; k < 100; k++)
                {
                    if ((first[0] == table[k][0]) && (first[1] == table[k][1]))
                        diff[k] += pairCnt[j];
                    if ((last[0] == table[k][0]) && (last[1] == table[k][1]))
                        diff[k] += pairCnt[j];
                }
                diff[j] -= pairCnt[j];
            }
        }
        for (int j = 0; j < 100; j++)
        {
            pairCnt[j] += diff[j];
            diff[j] = 0;
        }
    }

    cnt = 2;
    int i;
    for (i = 0; i < 100; i++)
    {
        bool letterFound = false;
        char first = table[i][0];
        char last = table[i][1];
        for (int j = 0; j < cnt; j++)
        {
            if (first == letters[j])
            {
                letterFound = true;
                counters[j] += pairCnt[i];
                break;
            }
        }
        if (false == letterFound)
        {
            letters[cnt] = first;
            counters[cnt++] += pairCnt[i];
        }
        letterFound = false;
        for (int j = 0; j < cnt; j++)
        {
            if (last == letters[j])
            {
                letterFound = true;
                counters[j] += pairCnt[i];
                break;
            }
        }
        if (false == letterFound)
        {
            letters[cnt] = last;
            counters[cnt++] += pairCnt[i];
        }
    }


    long long max = 0;
    long long min = 9999999999999;

    for (int i = 0; i < cnt; i++)
    {
        if (counters[i] > max)
            max = counters[i];
        if (counters[i] < min)
            min = counters[i];
    }
    printf("Total: %i", (max - min)/2);

    return;
}