#include <stdio.h>
#include <stdlib.h>
void main()
{
    int i, j, n, k, num, mov = 0, track[50], end, temp;
    printf("\nEnter the number of tracks : ");
    scanf("%d", &n);
    printf("\nEnter the tracks : ");
    for (i = 3; i <= n + 2; i++)
        scanf("%d", &track[i]);
    printf("\nEnter the disk size : ");
    scanf("%d", &end);
    printf("\nEnter the start head : ");
    scanf("%d", &num);
    track[0] = 0;
    track[1] = num;
    track[2] = end - 1;
    end = end - 1;
    n = n + 3;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (track[j] > track[j + 1])
            {
                temp = track[j];
                track[j] = track[j + 1];
                track[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (track[i] == num)
        {
            k = i;
            break;
        }
    }
    if ((num - 0) <= (end - num))
    {
        for (j = k; j > 1; j--)
        {
            mov += (track[j] - track[j - 1]);
            printf("%d -> ", track[j]);
        }
        printf("%d -> ", track[1]);
        mov = mov + (track[k + 1] - track[1]);
        for (j = k + 1; j < n - 2; j++)
        {
            mov += (track[j + 1] - track[j]);
            printf("%d -> ", track[j]);
        }
        printf("%d", track[n - 2]);
        printf("\n");
        printf("Total Seek Time : %d\n", mov);
    }
    else if ((num - 0) > (end - num))
    {
        for (j = i; j < n - 2; j++)
        {
            mov += (track[j + 1] - track[j]);
            printf("%d -> ", track[j]);
        }
        printf("%d -> ", end);
        mov += (track[n - 1] - track[i - 1]);
        for (j = i - 1; j > 1; j--)
        {
            mov += (track[j] - track[j - 1]);
            printf("%d -> ", track[j]);
        }
        printf("%d", track[1]);
        printf("\nTotal Seek time : %d\n", mov);
    }
}
