#include <stdio.h>

void worstFit(int blockSize[], int m, int processSize[], int n)
{

    int allocation[n];
    int i;

    for (i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for (i = 0; i < n; i++)
    {
        int wstIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (wstIdx == -1)
                    wstIdx = j;
                else if (blockSize[wstIdx] < blockSize[j])
                    wstIdx = j;
            }
        }

        if (wstIdx != -1)
        {
            allocation[i] = wstIdx;

            blockSize[wstIdx] -= processSize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t %d\t\t%d\t\t", (i + 1), processSize[i]);
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

    worstFit(block_size, bsize, process_size, psize);

    return 0;
}