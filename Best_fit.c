#include <stdio.h>
// #include <bits/stdc++.h>

void bestFit(int blockSize[], int m, int processSize[], int n)
{
    int i;
    int allocation[n];

    for (i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for (i = 0; i < n; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;

            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d\t\t%d\t\t", (i + 1), processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

int main()
{
    int psize, bsize, i = 0, j;
    printf("Enter total process number : ");
    scanf("%d", &psize);

    printf("Enter total block number : ");
    scanf("%d", &bsize);

    int process_size[psize], block_size[bsize];

    while (i < bsize)
    {
        printf("Enter %d no block size : ", (i + 1));
        scanf("%d", &block_size[i]);
        i++;
    }
    i = 0;

    while (i < psize)
    {
        printf("Enter %d no process size : ", (i + 1));
        scanf("%d", &process_size[i]);
        i++;
    }

    bestFit(block_size, bsize, process_size, psize);

    return 0;
}