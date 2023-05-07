#include<stdio.h>
#include<string.h>
struct process
{
    int at, bt, wt, tt, stat, rt, priority;
    char name[10];
} p[10], temp;
struct gantt
{
    int st, ct;
    char name[10];
} g[50];
void main()
{
    int n, i=0, j=0, k=0, m, idle=0, ls=0, ind=0;
    float avgwt=0, avgtt=0;
    printf("\nEnter the number of process : ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the process name : ");
        scanf("%s", p[i].name);
        printf("Enter the arrival time : ");
        scanf("%d", &p[i].at);
        printf("Enter the burst time : ");
        scanf("%d", &p[i].bt);
        printf("Enter the priority : ");
        scanf("%d", &p[i].priority);
        p[i].stat=0;
        p[i].rt=p[i].bt;
    }
    i=0;
    while(ls<n)
    {
        k=-1;
        for(j=0;j<n;j++)
        {
            if((p[j].stat==0)&&(p[j].at<=i)&&(k==-1 || p[j].priority<p[k].priority))
                k=j;
        }
        if((k==-1)&&(idle==0))
        {
            strcpy(g[ind].name,"idle");
            g[ind].st=i;
            idle=1;
            i++;
        }
        else if(k!=-1)
        {
            if(idle==1)
            {
                g[ind].ct=i;
                idle=0;
                ind++;
            }
            strcpy(g[ind].name,p[k].name);
            g[ind].st=i;
            if(p[k].rt<=1)
            {
                g[ind].ct=i+p[k].rt;
                i=g[ind].ct;
                p[k].tt=g[ind].ct-p[k].at;
                p[k].wt=p[k].tt-p[k].bt;
                p[k].stat=1;
                ind++;
                ls++;
            }
            else
            {
                g[ind].ct=i+1;
                i=i+1;
                p[k].rt=p[k].rt-1;
                ind++;
            }
        }
        else
            i++;
    }
    printf("\nProcess Table");
	printf("\nName \tat \tbt \twt \ttt\n");
	for(i=0;i<n;i++){
		printf("%s\t %d \t%d\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tt);
		avgwt+=p[i].wt;
		avgtt+=p[i].tt;}
    avgwt/=n;
    avgtt/=n;
    printf("\nGantt chart\n");
    printf("\n---------------------------------------------------------------------------\n");
    printf("|");
    for(m=0;m<ind;m++)
    {
        if(strcmp(g[m].name,g[m+1].name)==0)
            continue;
        else
            printf("%s\t|",g[m].name);
    }
    printf("\n---------------------------------------------------------------------------\n");
    printf("%d\t",g[0].st);
    
    for(m=0;m<ind;m++)
    {
        if(strcmp(g[m].name,g[m+1].name)==0)
            continue;
        else
            printf("%d\t",g[m].ct);
    }
    printf("\nAverage waiting time = %.2f",avgwt);
    printf("\nAverage turnaround time = %.2f\n",avgtt);
}