#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void day3_2(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day3.txt";
    

    /*if (!fptr) {
        perror("File opening failed");
        return;
    }*/

    char ret[99];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    char* o2string = '\0';
    char* co2string = '\0';
    char o2tmp[12];
    char co2tmp[12];
    int o2 = 0, co2 = 0;
    int o2Count[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    char o2Char[12];
    int co2Count[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    char co2Char[12];
    int o2Cnt = 0, co2Cnt = 0;
    for (int i = 0; i < 12; i++)
    {
        fptr = fopen(locPath, "r");
        o2Cnt = 0; 
        co2Cnt = 0;
        while (fgets(ret, 99, fptr) != NULL) { // standard C I/O file reading loop
            c1 = ret;
            bool o2Allowed = true;
            for (int j = 0; j < i; j++)
            {
                if (o2Char[j] != c1[j])
                {
                    o2Allowed = false;
                }
            }
            if (true == o2Allowed)
            {
                if ('1' == c1[i])
                    o2Count[i]++;
                else
                    o2Count[i]--;
                o2Cnt++;
                strcpy(o2tmp, c1);
            }

            bool co2Allowed = true;
            for (int j = 0; j < i; j++)
            {
                if (co2Char[j] != c1[j])
                {
                    co2Allowed = false;
                }
            }
            if (true == co2Allowed)
            {
                if ('1' == c1[i])
                    co2Count[i]++;
                else
                    co2Count[i]--;
                co2Cnt++;
                strcpy(co2tmp, c1);
            }
        }
        if (o2Count[i] >= 0)
            o2Char[i] = '1';
        else
            o2Char[i] = '0';

        if (co2Count[i] >= 0)
            co2Char[i] = '0';
        else
            co2Char[i] = '1';

        if (1 == o2Cnt)
            o2string = o2tmp;
        if (1 == co2Cnt)
            co2string = co2tmp;
    }

    for (int i = 0; i < 12; i++)
    {
        if ('1' == o2Char[i])
            o2++;
        if ('1' == co2tmp[i])
            co2++;
        o2 <<= 1;
        co2 <<= 1;
    }
    o2 >>= 1;
    co2 >>= 1;
    
    fclose(fptr);

    printf("Tot: %i", o2 * co2);

    return;
}