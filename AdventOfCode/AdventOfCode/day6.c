#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void day6_1(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day6.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[700];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int start[300] = { 0 };
    int i = 0;
    int fishCount[9] = { 0 };

    fgets(ret, 700, fptr);

    c1 = strtok(ret, ",");
    while (c1 != NULL)
    {
        start[i++] = atoi(c1);
        c1 = strtok(NULL, ",");
    }

    for (int j = 0; j < 300; j++)
    {
        fishCount[start[j]]++;
    }

    for (int j = 0; j < 79; j++)
    {
        int imPregnant = fishCount[0];
        for (int k = 0; k < 8; k++)
            fishCount[k] = fishCount[k + 1];
        fishCount[6] += imPregnant;
        fishCount[8] = imPregnant;
    }

    int sum = 0;
    for (int j = 0; j < 9; j++)
        sum += fishCount[j];

    printf("Total: %i", sum);

    return;
}

void day6_2(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day6.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[700];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int start[300] = { 0 };
    int i = 0;
    unsigned long long fishCount[9] = { 0 };

    fgets(ret, 700, fptr);

    c1 = strtok(ret, ",");
    while (c1 != NULL)
    {
        start[i++] = atoi(c1);
        c1 = strtok(NULL, ",");
    }

    for (int j = 0; j < 300; j++)
    {
        fishCount[start[j]]++;
    }

    for (int j = 0; j < 256; j++)
    {
        unsigned long long imPregnant = fishCount[0];
        for (int k = 0; k < 8; k++)
            fishCount[k] = fishCount[k + 1];
        fishCount[6] += imPregnant;
        fishCount[8] = imPregnant;
    }

    unsigned long long sum = 0;
    for (int j = 0; j < 9; j++)
        sum += fishCount[j];

    //printf("Total: %i", sum);

    return;
}