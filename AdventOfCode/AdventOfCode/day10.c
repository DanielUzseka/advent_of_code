#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void day10_1(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day10.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[4000];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int i = 0, j = 0;
    int sum = 0;
    char row[200];
    int cnt = 0;

    while (fgets(ret, 200, fptr) != NULL) {
        c1 = ret;
        cnt = 0;
        for (i = 0; i < strlen(c1); i++)
        {
            if (('(' == c1[i]) || ('[' == c1[i]) || ('{' == c1[i]) || ('<' == c1[i]))
            {
                row[cnt++] = c1[i];
            }
            else if (i > 0)
            {
                if (')' == c1[i])
                {
                    if (row[cnt - 1] != '(')
                        break;
                    else
                        cnt--;
                }
                else if (']' == c1[i])
                {
                    if (row[cnt - 1] != '[')
                        break;
                    else
                        cnt--;
                }
                else if ('}' == c1[i])
                {
                    if (row[cnt - 1] != '{')
                        break;
                    else
                        cnt--;
                }
                else if ('>' == c1[i])
                {
                    if (row[cnt - 1] != '<')
                        break;
                    else
                        cnt--;
                }
            }
            else
                break;
        } //for
        if (')' == c1[i]) sum += 3;
        else if (']' == c1[i]) sum += 57;
        else if ('}' == c1[i]) sum += 1197;
        else if ('>' == c1[i]) sum += 25137;
    }

    printf("Total: %i", sum);
}

int compare2(const void* a, const void* b)
{
    if (*(long long*)a > *(long long*)b)
        return 1;
    else if (*(long long*)a < *(long long*)b)
        return -1;
    else
        return 0;
    //return (*(long long*)a - *(long long*)b);
}

void day10_2(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day10.txt";

    fptr = fopen(locPath, "r");

    if (!fptr) {
        perror("File opening failed");
        return;
    }

    char ret[4000];
    char* c1 = '\0'; // note: int, not char, required to handle EOF
    int i = 0, j = 0;
    long long sum = 0;
    char row[200];
    int cnt = 0;
    int corrupted = 0;
    long long sums[51];
    int sumCnt = 0;

    while (fgets(ret, 200, fptr) != NULL) {
        c1 = ret;
        cnt = 0;
        corrupted = 0;
        for (i = 0; i < strlen(c1); i++)
        {
            if (('(' == c1[i]) || ('[' == c1[i]) || ('{' == c1[i]) || ('<' == c1[i]))
            {
                row[cnt++] = c1[i];
            }
            else if (cnt > 0)
            {
                if (')' == c1[i])
                {
                    if (row[cnt - 1] != '(')
                        corrupted = 1;
                    else
                        cnt--;
                }
                else if (']' == c1[i])
                {
                    if (row[cnt - 1] != '[')
                        corrupted = 1;
                    else
                        cnt--;
                }
                else if ('}' == c1[i])
                {
                    if (row[cnt - 1] != '{')
                        corrupted = 1;
                    else
                        cnt--;
                }
                else if ('>' == c1[i])
                {
                    if (row[cnt - 1] != '<')
                        corrupted = 1;
                    else
                        cnt--;
                }
            }
            else
                corrupted = 1;

            if (1 == corrupted)
                break;
        } //for

        if (0 == corrupted)
        {
            sum = 0;
            for (j = cnt - 1; j >= 0; j--)
            {
                sum *= 5;
                if ('(' == row[j]) sum += 1;
                else if ('[' == row[j]) sum += 2;
                else if ('{' == row[j]) sum += 3;
                else if ('<' == row[j]) sum += 4;
            }
            sums[sumCnt++] = sum;
        }
    }

    qsort(sums, sumCnt, sizeof(long long), compare2);

    printf("Total: %i", sum);
}