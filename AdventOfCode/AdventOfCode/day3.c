#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void day3_1(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day3.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[99];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    char* c2 = '\0';
    int gamma = 0, eps = 0;
    int count[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while (fgets(ret, 99, fptr) != NULL) { // standard C I/O file reading loop
        c1 = ret;
        int i = 0;
        while (ret[i] != '\0')
        {
            if ('1' == ret[i])
                count[i]++;
            else
                count[i]--;
            i++;
        }
    }

    for (int i = 0; i < 12; i++)
    {
        if (count[i] > 0)
            gamma++;
        else
            eps++;
        eps <<= 1;
        gamma <<= 1;
    }
    gamma >>= 1;
    eps >>= 1;
        

    fclose(fptr);

    printf("Tot: %i", gamma * eps);

    return;
}
