#include<stdio.h>
#include<string.h>
struct process
{
int at,bt,wt,tt,st,rt;
char name[10];
}p[10],temp;
struct gantt
{
int st,ct;
char name[10];
}g[50];
void main()
{
    int n,i=0,j=0,k=0,m,idle=0,l=0,m=0;
    float avgwt=0,avgtt=0;
    printf("Enter the number of process\n");
    scanf("%d",&n);
    for(m=0;m<n;m++)
    {
        printf("Enter name,at,bt\n");
        scanf("%s%d%d",p[m].name,&p[m].at,&p[m].bt);
        p[m].st=0;
        p[m].rt=p[m].bt;
    }
    while(l<n)
    {
        k=-1;
        for(j=0;j<n;j++)
        {
            if((p[j].st==0)&&(p[j].at<=i)&&(k==-1 || p[j].rt<p[k].rt))
            {
                k=j;
            }
        }
        if((k==-1)&&(idle==0))
        {
            strcpy(g[m].name,"idle");
            g[m].st=i;
            idle=1;
            i++;
        }
        else if(k!=-1)
        {
            if(idle==1)
            {
                g[m].ct=i;
                idle=0;
                m++;
            }
            strcpy(g[m].name,p[k].name);
            g[m].st=i;
            if(p[k].rt<=1)
            {
                g[m].ct=i+p[k].rt;
                i=g[m].ct;
                p[k].tt=g[m].ct-p[k].at;
                p[k].wt=p[k].tt-p[k].bt;
                p[k].st=1;
                m++;
                l++;
            }
            else
            {
                g[m].ct=i+1;
                i=i+1;
                p[k].rt=p[k].rt-1;
                m++;
            }
        }
        else
        {
            i++;
        }
    }
    printf("Name\tAT\tBT\tTT\tWT\n");
    for(m=0;m<n;m++)
    {
        printf("%s\t%d\t%d",p[m].name,p[m].at,p[m].bt);
        printf("\t%d\t%d\n",p[m].tt,p[m].wt);
        avgwt=avgwt+p[m].wt;
        avgtt=avgtt+p[m].tt;
    }
    printf("\nGantt chart\n");
    printf("\n---------------------------------------------------------------------------\n");
    printf("|");
    for(m=0;m<m;m++)
    {
        if(strcmp(g[m].name,g[m+1].name)==0)
        {
            continue;
        }
        else
        {
            printf("%s\t|",g[m].name);
        }
    }
    printf("\n---------------------------------------------------------------------------\n");
    printf("%d\t",g[0].st);
    
    for(m=0;m<m;m++)
    {
        if(strcmp(g[m].name,g[m+1].name)==0)
        {
        continue;
        }
        else
        {
        printf("%d\t",g[m].ct);
        }
    }
    printf("\nAverage waiting time = %f",avgwt/n);
    printf("\nAverage turnaround time = %f\n",avgtt/n);
}
