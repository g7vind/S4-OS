// c program to implement fifo page replacement
#include <stdio.h>
void main()
{
    int i, j, flag = 0, pf = 0, ref[50], frame[50], nof, nop, next = 0;
    printf("Enter number of frames : ");
    scanf("%d", &nof);
    for (i = 0; i < nof; i++)
        frame[i] = -1;
    printf("Enter number of pages : ");
    scanf("%d", &nop);
    printf("Enter page numbers : ");
    for (i = 0; i < nop; i++)
        scanf("%d", &ref[i]);
    for (i = 0; i < nop; i++)
    {
        printf("\n");
        flag = 0;
        for (j = 0; j < nof; j++)
        {
            if (frame[j] == ref[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            frame[next] = ref[i];
            next = (next + 1) % nof;
            pf++;
        }
        printf("Page no -> ");
        for (j = 0; j < nof; j++)
        {
            if (frame[j] != -1)
            {
                printf("%d   ", frame[j]);
            }
        }
    }
    printf("\n\nPage Fault : %d\n", pf);
}
