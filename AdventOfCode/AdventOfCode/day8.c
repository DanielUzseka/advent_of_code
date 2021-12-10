#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void day8_1(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day8.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[4000];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int i = 0;
    int sum = 0;

    while (fgets(ret, 99, fptr) != NULL) {
    
        c1 = strtok(ret, "|");
        c1 = strtok(NULL, "\n");
        c1++;// = strtok(NULL, " ");
        c1 = strtok(c1, " ");

        while (c1 != NULL)
        {
            int len = strlen(c1);
            c1 = strtok(NULL, " ");

            if ((2 == len) || (3 == len) || (4 == len) || (7 == len))
                sum++;
        }
    }

    printf("Total: %i", sum);

    return;
}

void day8_2(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day8.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[4000];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int i = 0;
    int sum = 0;
    int nums[2][10] = { 0 };
    int letters[7] = { 0 };

    while (fgets(ret, 99, fptr) != NULL) {

        for (int i = 0; i < 10; i++)
            nums[0][i] = 0;

        c1 = strtok(ret, " ");
        int cnt = 0;

        while (c1[0] != '|')
        {
            int len = strlen(c1);
            for (int i = 0; i < len; i++)
            {
                nums[0][cnt] |= 1 << (c1[i] - 'a');
            }
            nums[1][cnt] = len;
            c1 = strtok(NULL, " ");
            cnt++;
        }

        //7
        int j;
        for (j = 0; j < 10; j++)
            if (3 == nums[1][j])
                break;
        int num7 = nums[0][j];
        //1
        for (j = 0; j < 10; j++)
            if (2 == nums[1][j])
                break;
        int num1 = nums[0][j];
        int A = num7 - num1;
        //8
        for (j = 0; j < 10; j++)
            if (7 == nums[1][j])
                break;
        int num8 = nums[0][j];
        for (j = 0; j < 10; j++)
            if (4 == nums[1][j])
                break;
        int num4 = nums[0][j];
        int CDE = 0;
        for (j = 0; j < 10; j++)
            if (6 == nums[1][j])
                CDE |= (num8 - nums[0][j]);
        int ADG = 127;
        for (j = 0; j < 10; j++)
            if (5 == nums[1][j])
                ADG &= nums[0][j];
        int D = ADG & CDE;
        int G = ADG - A - D;
        int B = num4 - num1 - D;
        int num5 = 0;
        for (j = 0; j < 10; j++)
            if ((5 == nums[1][j]) && (nums[0][j] &  A) && (nums[0][j] & B) && (nums[0][j] & D) && (nums[0][j] & G))
                num5 = nums[0][j];
        int F = num5 - A - B - D - G;
        int C = num1 - F;
        int E = 127 - A - B - C - D - F - G;


        c1 = strtok(NULL, "\n");
        //c1++;// = strtok(NULL, " ");
        c1 = strtok(c1, " ");

        int decodedNum = 0;

        while (c1 != NULL)
        {
            int len = strlen(c1);
            
            if (2 == len)
                decodedNum += 1;
            else if (3 == len)
                decodedNum += 7;
            else if (4 == len)
                decodedNum += 4;
            else if (7 == len)
                decodedNum += 8;
            else
            {
                int actNum = 0;
                for (int i = 0; i < len; i++)
                {
                    actNum |= 1 << (c1[i] - 'a');
                }
                if (5 == len)
                {
                    if (num5 == actNum)
                        decodedNum += 5;
                    else if ((actNum & F) != 0)
                        decodedNum += 3;
                    else
                        decodedNum += 2;
                }
                else
                {
                    if ((actNum & D) == 0)
                        decodedNum += 0;
                    else if ((actNum & C) == 0)
                        decodedNum += 6;
                    else
                        decodedNum += 9;
                }
            }

            decodedNum *= 10;

            c1 = strtok(NULL, " ");
        }
        decodedNum /= 10;
        sum += decodedNum;
    }

    printf("Total: %i", sum);

    return;
}
