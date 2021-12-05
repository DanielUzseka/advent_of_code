#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define PATH "D://Projektek/advent_of_code/inputs/"

void day1_1(void)
{
	FILE* fptr = NULL;

	char* locPath = "D://Projektek/advent_of_code/inputs/day1_1.txt";

	fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[99];
    char *c1 = '\0'; // note: int, not char, required to handle EOF
    int num = -1;
    int lastNum = -1;
    int sum = 0;
    while (fgets(ret, 99, fptr) != NULL) { // standard C I/O file reading loop
        c1 = ret;
        lastNum = num;
        num = atoi(c1);
        if (lastNum != -1)
        {
            if (num > lastNum)
                sum++;
        }

    }

	fclose(fptr);

    printf("Tot: %d", sum);

	return;
}

void day1_2(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day1_1.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[99];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int num = -1;
    int lastNum[3] = { -1, -1, -1 };
    int sum = 0;
    while (fgets(ret, 99, fptr) != NULL) { // standard C I/O file reading loop
        c1 = ret;
        lastNum[0] = lastNum[1];
        lastNum[1] = lastNum[2];
        lastNum[2] = num;
        num = atoi(c1);
        if (lastNum[0] != -1)
        {
            if ((num + lastNum[2] + lastNum[1]) > (lastNum[2] + lastNum[1] + lastNum[0]))
                sum++;
        }

    }

    fclose(fptr);

    printf("Tot: %d", sum);

    return;
}