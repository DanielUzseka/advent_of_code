#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

void day7_1(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day7.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[4000];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int start[1200] = { 0 };
    int i = 0;
    unsigned long long sum = 0;

    fgets(ret, 4000, fptr);

    c1 = strtok(ret, ",");
    while (c1 != NULL)
    {
        start[i++] = atoi(c1);
        c1 = strtok(NULL, ",");
    }

    qsort(start, i, sizeof(int), compare);

    int median = start[i / 2];
    int diff;
    int fuel = 0;

    for (int j = 0; j < i; j++)
    {
        diff = abs(median - start[j]);
        fuel += diff;
    }

    printf("Total: %i", fuel);

    return;
}

void day7_2(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day7.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[4000];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int start[1200] = { 0 };
    int i = 0;
    unsigned long long sum = 0;

    fgets(ret, 4000, fptr);

    c1 = strtok(ret, ",");
    while (c1 != NULL)
    {
        start[i] = atoi(c1);
        sum += start[i++];
        c1 = strtok(NULL, ",");
    }

    qsort(start, i, sizeof(int), compare);

    int median = start[i / 2];
    double mean = sum;
    mean /= i;
    int wat = round(mean - 0.5);
    int diff;
    int fuel = 0;

    for (int j = 0; j < i; j++)
    {
        diff = abs(wat - start[j]) * (abs(wat - start[j]) + 1) / 2;
        fuel += diff;
    }

    printf("Total: %i", fuel);

    return;
}