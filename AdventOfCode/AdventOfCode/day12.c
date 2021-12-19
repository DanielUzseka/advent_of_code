#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct
{
    char path[20][2];
    int depth;
}T_LIST;

typedef struct
{
    T_LIST array[32000000];
}A_LIST;

void day12_1(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day12.txt";

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
    char pairs[22][2][2];
    int cnt = 0;
    //char frontier[100][10][2];
    //T_LIST frontier[15000];
    A_LIST* l = malloc(sizeof(A_LIST));
    bool keepGoing = true;
    int headCnt = 0;
    int depthCnt = 0;

    while (fgets(ret, 200, fptr) != NULL) {
        c1 = ret;
        c1 = strtok(c1, "-");
        //start
        if (strlen(c1) == 5)
        {
            pairs[cnt][0][0] = 'a';
            pairs[cnt][0][1] = 'a';
        }
        else if(strlen(c1) == 3)
        {
            pairs[cnt][0][0] = 'z';
            pairs[cnt][0][1] = 'z';
        }
        else
        {
            pairs[cnt][0][0] = c1[0];
            pairs[cnt][0][1] = c1[1];
        }
            
        c1 = strtok(NULL, "\n");
        if (strlen(c1) == 5)
        {
            pairs[cnt][1][0] = 'a';
            pairs[cnt][1][1] = 'a';
        }
        else if (strlen(c1) == 3)
        {
            pairs[cnt][1][0] = 'z';
            pairs[cnt][1][1] = 'z';
        }
        else
        {
            pairs[cnt][1][0] = c1[0];
            pairs[cnt][1][1] = c1[1];
        }
        cnt++;
    }
    
    l->array[headCnt].depth = 1;
    l->array[headCnt].path[l->array[headCnt].depth - 1][0] = 'a'; l->array[headCnt].path[l->array[headCnt].depth - 1][1] = 'a';
    headCnt++;

    for (int i = 0; i < headCnt; i++)
    {
        T_LIST tmp;
        tmp.depth = l->array[i].depth;
        for (int j = 0; j < tmp.depth; j++)
        {
            tmp.path[j][0] = l->array[i].path[j][0]; tmp.path[j][1] = l->array[i].path[j][1];
        }
        for (int cnt1 = 0; cnt1 < 22; cnt1++)
        {
            if ((pairs[cnt1][0][0] == tmp.path[tmp.depth - 1][0]) && (pairs[cnt1][0][1] == tmp.path[tmp.depth - 1][1])  && 
                (tmp.path[tmp.depth - 1][0] != 'z') && (tmp.path[tmp.depth - 1][1] != 'z'))
            {
                if ((pairs[cnt1][1][0] >= 'a') && (pairs[cnt1][1][0] <= 'z'))
                {
                    bool found = false;
                    for (int cnt2 = 0; cnt2 < tmp.depth; cnt2++)
                        if ((tmp.path[cnt2][0] == pairs[cnt1][1][0]) && (tmp.path[cnt2][1] == pairs[cnt1][1][1]))
                            found = true;
                    if (false == found)
                    {
                        l->array[headCnt].depth = tmp.depth + 1;
                        int k;
                        for (k = 0; k < tmp.depth; k++)
                        {
                            l->array[headCnt].path[k][0] = tmp.path[k][0]; l->array[headCnt].path[k][1] = tmp.path[k][1];
                        }
                        l->array[headCnt].path[k][0] = pairs[cnt1][1][0];
                        l->array[headCnt].path[k][1] = pairs[cnt1][1][1];
                        headCnt++;
                    }
                }
                else
                {
                    l->array[headCnt].depth = tmp.depth + 1;
                    int k;
                    for (k = 0; k < tmp.depth; k++)
                    {
                        l->array[headCnt].path[k][0] = tmp.path[k][0]; l->array[headCnt].path[k][1] = tmp.path[k][1];
                    }
                    l->array[headCnt].path[k][0] = pairs[cnt1][1][0];
                    l->array[headCnt].path[k][1] = pairs[cnt1][1][1];
                    headCnt++;
                }
            }
            else if ((pairs[cnt1][1][0] == tmp.path[tmp.depth - 1][0]) && (pairs[cnt1][1][1] == tmp.path[tmp.depth - 1][1]))
            {
                if ((pairs[cnt1][0][0] >= 'a') && (pairs[cnt1][0][0] <= 'z'))
                {
                    bool found = false;
                    for (int cnt2 = 0; cnt2 < tmp.depth; cnt2++)
                        if ((tmp.path[cnt2][0] == pairs[cnt1][0][0]) && (tmp.path[cnt2][1] == pairs[cnt1][0][1]))
                            found = true;
                    if (false == found)
                    {
                        l->array[headCnt].depth = tmp.depth + 1;
                        int k;
                        for (k = 0; k < tmp.depth; k++)
                        {
                            l->array[headCnt].path[k][0] = tmp.path[k][0]; l->array[headCnt].path[k][1] = tmp.path[k][1];
                        }
                        l->array[headCnt].path[k][0] = pairs[cnt1][0][0];
                        l->array[headCnt].path[k][1] = pairs[cnt1][0][1];
                        headCnt++;
                    }
                }
                else
                {
                    l->array[headCnt].depth = tmp.depth + 1;
                    int k;
                    for (k = 0; k < tmp.depth; k++)
                    {
                        l->array[headCnt].path[k][0] = tmp.path[k][0]; l->array[headCnt].path[k][1] = tmp.path[k][1];
                    }
                    l->array[headCnt].path[k][0] = pairs[cnt1][0][0];
                    l->array[headCnt].path[k][1] = pairs[cnt1][0][1];
                    headCnt++;
                }
            }
        }
    }

    for (int i = 0; i < headCnt; i++)
    {
        if ((l->array[i].path[l->array[i].depth - 1][0] == 'z') && (l->array[i].path[l->array[i].depth - 1][1] == 'z'))
            sum++;
    }

    free(l);

    printf("Total size: %i", sum);


    return;
}

void day12_2(void)
{
    FILE* fptr = NULL;

    char* locPath = "D://Projektek/advent_of_code/inputs/day12.txt";

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
    char pairs[22][2][2];
    int cnt = 0;
    bool discovered = false;
    char actCave[2];
    char actPath[30][2];
    int headCnt = 0;
    int depthCnt = 0;
    int start = 0;
    int starts[30] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    while (fgets(ret, 200, fptr) != NULL) {
        c1 = ret;
        c1 = strtok(c1, "-");
        //start
        if (strlen(c1) == 5)
        {
            pairs[cnt][0][0] = 'a';
            pairs[cnt][0][1] = 'a';
        }
        else if (strlen(c1) == 3)
        {
            pairs[cnt][0][0] = 'z';
            pairs[cnt][0][1] = 'z';
        }
        else
        {
            pairs[cnt][0][0] = c1[0];
            pairs[cnt][0][1] = c1[1];
        }

        c1 = strtok(NULL, "\n");
        if (strlen(c1) == 5)
        {
            pairs[cnt][1][0] = 'a';
            pairs[cnt][1][1] = 'a';
        }
        else if (strlen(c1) == 3)
        {
            pairs[cnt][1][0] = 'z';
            pairs[cnt][1][1] = 'z';
        }
        else
        {
            pairs[cnt][1][0] = c1[0];
            pairs[cnt][1][1] = c1[1];
        }
        cnt++;
    }

    actCave[0] = 'a'; actCave[1] = 'a';
    actPath[depthCnt][0] = actCave[0]; actPath[depthCnt][1] = actCave[1];
    depthCnt = 1;

    while (false == discovered)
    {
        bool foundChild = false;
        start = starts[depthCnt - 1] + 1;
        for (int cnt1 = start; cnt1 < 22; cnt1++)
        {
            if ((pairs[cnt1][0][0] == actCave[0]) && (pairs[cnt1][0][1] == actCave[1]))
            {
                if ((pairs[cnt1][1][0] >= 'a') && (pairs[cnt1][1][0] <= 'z'))
                {
                    bool found = false;
                    int caves = 0;
                    int tmp1 = 0, tmp2 = 0;
                    for (int cnt2 = 0; cnt2 < depthCnt; cnt2++)
                        if ((actPath[cnt2][0] == pairs[cnt1][1][0]) && (actPath[cnt2][1] == pairs[cnt1][1][1]))
                            caves++;
                    if (((pairs[cnt1][1][0] == 'a') && (pairs[cnt1][1][1] == 'a')) ||
                        ((pairs[cnt1][1][0] == 'z') && (pairs[cnt1][1][1] == 'z')))
                    {
                        if (caves > 0)
                            found = true;
                    }
                    else if (caves > 0)
                    {
                        for (int l = 1; l < depthCnt; l++)
                        {
                            tmp1 = 0;
                            for (int m = l + 1; m < depthCnt; m++)
                            {
                                if ((actPath[l][0] == actPath[m][0]) && (actPath[l][1] == actPath[m][1]))
                                {
                                    if ((actPath[l][0] >= 'a') && (actPath[l][0] <= 'z'))
                                        tmp1++;
                                }
                            }
                            if (tmp1 > tmp2)
                                tmp2 = tmp1;
                        }
                        if(tmp2 > 0)
                            found = true;
                    }
                    if (false == found)
                    {
                        actCave[0] = pairs[cnt1][1][0];
                        actCave[1] = pairs[cnt1][1][1];
                        actPath[depthCnt][0] = actCave[0];
                        actPath[depthCnt][1] = actCave[1];
                        starts[depthCnt-1] = cnt1;
                        depthCnt++;
                        foundChild = true;
                        break;
                    }
                }
                else
                {
                    actCave[0] = pairs[cnt1][1][0];
                    actCave[1] = pairs[cnt1][1][1];
                    actPath[depthCnt][0] = actCave[0];
                    actPath[depthCnt][1] = actCave[1];
                    starts[depthCnt-1] = cnt1;
                    depthCnt++;
                    foundChild = true;
                    break;
                }
            }
            else if ((pairs[cnt1][1][0] == actCave[0]) && (pairs[cnt1][1][1] == actCave[1]))
            {
                if ((pairs[cnt1][0][0] >= 'a') && (pairs[cnt1][0][0] <= 'z'))
                {
                    bool found = false;
                    int caves = 0;
                    int tmp1 = 0, tmp2 = 0;
                    for (int cnt2 = 0; cnt2 < depthCnt; cnt2++)
                        if ((actPath[cnt2][0] == pairs[cnt1][0][0]) && (actPath[cnt2][1] == pairs[cnt1][0][1]))
                            caves++;
                    if (((pairs[cnt1][0][0] == 'a') && (pairs[cnt1][0][1] == 'a')) ||
                        ((pairs[cnt1][0][0] == 'z') && (pairs[cnt1][0][1] == 'z')))
                    {
                        if (caves > 0)
                            found = true;
                    }
                    else if (caves > 0)
                    {
                        for (int l = 1; l < depthCnt; l++)
                        {
                            tmp1 = 0;
                            for (int m = l + 1; m < depthCnt; m++)
                            {
                                if ((actPath[l][0] == actPath[m][0]) && (actPath[l][1] == actPath[m][1]))
                                {
                                    if((actPath[l][0] >= 'a') && (actPath[l][0] <= 'z'))
                                        tmp1++;
                                }
                            }
                            if (tmp1 > tmp2)
                                tmp2 = tmp1;
                        }
                        if (tmp2 > 0)
                            found = true;
                    }
                    if (false == found)
                    {
                        actCave[0] = pairs[cnt1][0][0];
                        actCave[1] = pairs[cnt1][0][1];
                        actPath[depthCnt][0] = actCave[0];
                        actPath[depthCnt][1] = actCave[1];
                        starts[depthCnt - 1] = cnt1;
                        depthCnt++;
                        foundChild = true;
                        break;
                    }
                }
                else
                {
                    actCave[0] = pairs[cnt1][0][0];
                    actCave[1] = pairs[cnt1][0][1];
                    actPath[depthCnt][0] = actCave[0];
                    actPath[depthCnt][1] = actCave[1];
                    starts[depthCnt - 1] = cnt1;
                    depthCnt++;
                    foundChild = true;
                    break;
                }
            }
        }
        if (false == foundChild)
        {
            depthCnt--;
            if (depthCnt < 1)
            {
                discovered = true;
                continue;
            }
            actCave[0] = actPath[depthCnt - 1][0];
            actCave[1] = actPath[depthCnt - 1][1];
            for (int j = depthCnt; j < 30; j++)
                starts[j] = -1;
            
        }
        else if ((actCave[0] == 'z') && (actCave[1] == 'z'))
        {
            depthCnt--;
            actCave[0] = actPath[depthCnt - 1][0];
            actCave[1] = actPath[depthCnt - 1][1];
            for (int j = depthCnt; j < 30; j++)
                starts[j] = -1;
            sum++;
        }
    }


    printf("Total size: %i", sum);


    return;
}