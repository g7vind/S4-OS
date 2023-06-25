#include <stdio.h>
void main()
{
    int tr[30], i, j, t, cur, s = 0, n, temp, size;
    printf("\nEnter the number of tracks : ");
    scanf("%d", &t);
    printf("\nEnter current head position : ");
    scanf("%d", &cur);
    printf("\nEnter the tracks : ");
    for (i = 2; i <= t + 1; i++)
        scanf("%d", &tr[i]);
    printf("\nEnter the disk size : ");
    scanf("%d", &size);
    tr[0] = 0;
    tr[1] = cur;
    tr[t + 2] = size - 1;
    n = t + 3;
    size = size - 1;
    for (i = 0; i < (n - 1); i++)
    {
        for (j = 0; j < (n - i - 1); j++)
        {
            if (tr[j] > tr[j + 1])
            {
                temp = tr[j];
                tr[j] = tr[j + 1];
                tr[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (tr[i] == cur)
            break;
    }
    printf("\nHead Movements : ");
    if ((cur - 0) < (size - cur))
    {
        for (j = i; j > 0; j--)
        {
            s = s + (tr[j] - tr[j - 1]);
            printf("%d-->", tr[j]);
        }
        printf("0-->");
        s = s + (size - 0);
        for (j = n - 1; j > i + 1; j--)
        {
            s = s + (tr[j] - tr[j - 1]);
            printf("%d-->", tr[j]);
        }
        printf("%d", tr[i + 1]);
        printf("\nTotal Seek Time: %d", s);
        printf("\n");
    }
    else if ((cur - 0) > (size - cur))
    {
        for (j = i; j < n - 1; j++)
        {
            s = s + (tr[j + 1] - tr[j]);
            printf("%d-->", tr[j]);
        }
        printf("%d-->0-->", size);
        s = s + (size - 0);
        for (j = 1; j < i - 1; j++)
        {
            s = s + (tr[j] - tr[j - 1]);
            printf("%d-->", tr[j]);
        }
        s += (tr[i - 1] - tr[i - 2]);
        printf("%d", tr[i - 1]);
        printf("\nTotal Seek time : %d", s);
        printf("\n");
    }
}
