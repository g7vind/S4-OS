#include <stdio.h>
#include <Stdlib.h>
void firstfit(int n, int b[], int m, int p[])
{
    printf("\n--------------------------FIRST FIT------------------------");
    int i, j, k, flag = 0, frag[n], alloc[n];
    for (i = 0; i < n; i++)
    {
        frag[i] = b[i];
        alloc[i] = -1;
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (p[i] <= frag[j])
            {
                alloc[i] = j;
                frag[j] -= p[i];
                flag = 1;
                break;
            }
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\tWastage\n");
    for (i = 0; i < m; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, p[i]);
        if (alloc[i] != -1)
            printf("%d\t\t%d\n", alloc[i] + 1, frag[alloc[i]]);
        else
        {
            printf("NULL\t");
            printf("\t-\t\n");
        }
    }
}
void bestfit(int n, int b[], int m, int p[])
{
    printf("\n--------------------------BEST FIT------------------------");
    int i, j, k, flag = 0, frag[n], alloc[n];
    for (i = 0; i < n; i++)
    {
        frag[i] = b[i];
        alloc[i] = -1;
    }
    for (i = 0; i < m; i++)
    {
        flag = 0;
        for (j = 0; j < n; j++)
        {
            if (p[i] <= frag[j])
            {
                if (flag == 0)
                {
                    k = j;
                    flag = 1;
                }
                else if (frag[j] < frag[k])
                    k = j;
            }
        }
        if (flag == 1)
        {
            alloc[i] = k;
            frag[k] -= p[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\tWastage\n");
    for (i = 0; i < m; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, p[i]);
        if (alloc[i] != -1)
            printf("%d\t\t%d\n", alloc[i] + 1, frag[alloc[i]]);
        else
        {
            printf("NULL\t");
            printf("\t-\t\n");
        }
    }
}
void worstfit(int n, int b[], int m, int p[])
{
    printf("\n--------------------------WORST FIT------------------------");
    int i, j, k, flag = 0, frag[n], alloc[n];
    for (i = 0; i < n; i++)
    {
        frag[i] = b[i];
        alloc[i] = -1;
    }
    for (i = 0; i < m; i++)
    {
        flag = 0;
        for (j = 0; j < n; j++)
        {
            if (p[i] <= frag[j])
            {
                if (flag == 0)
                {
                    k = j;
                    flag = 1;
                }
                else if (frag[j] > frag[k])
                    k = j;
            }
        }
        if (flag == 1)
        {
            alloc[i] = k;
            frag[k] -= p[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\tWastage\n");
    for (i = 0; i < m; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, p[i]);
        if (alloc[i] != -1)
            printf("%d\t\t%d\n", alloc[i] + 1, frag[alloc[i]]);
        else
        {
            printf("NULL\t");
            printf("\t-\t\n");
        }
    }
}
void main()
{
    int n, m, i, j, k, ch;
    printf("\nEnter the number of blocks : ");
    scanf("%d", &n);
    int b[n];
    printf("\nEnter the size of each block : ");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);
    printf("\nEnter the number of processes : ");
    scanf("%d", &m);
    int p[m];
    printf("\nEnter the size of each process : ");
    for (i = 0; i < m; i++)
        scanf("%d", &p[i]);
    do
    {
        printf("\n1. First Fit\n2. Best Fit\n3. Worst Fit\n4. Exit\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            firstfit(n, b, m, p);
            break;
        case 2:
            bestfit(n, b, m, p);
            break;
        case 3:
            worstfit(n, b, m, p);
            break;
        case 4:
            printf("\n--------------------------Exited successfully------------------------");
            exit(0);
        default:
            printf("\nInvalid Choice");
        }
    } while (1);
}