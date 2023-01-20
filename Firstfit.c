// C implementation of First - Fit algorithm
#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int i, j;

    int allocation[n];

    for (i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {

                allocation[i] = j;

                blockSize[j] -= processSize[i];

                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\t\t\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %i\t\t\t", i + 1);
        printf("%i\t\t\t\t", processSize[i]);
        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);
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

    firstFit(block_size, bsize, process_size, psize);

    return 0;
}
