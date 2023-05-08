#include<stdio.h>
#include<string.h>
int q[50],f=-1,r=-1;
struct process
{
	int at,bt,wt,tt,stat,rt;
	char name[10];
}p[10];
struct gantt
{
	int st,ct;
	char name[10];
}g[10];
void enqueue(int a)
{
    if(f==-1)
        f=0;
    q[++r]=a;
}
int dequeue()
{
    if(f==-1 && r==-1)
        return -1;
    else if(f==r)
    {
        int a=q[f];
        f=-1;
        r=-1;
        return a;
    }
    else
        return q[f++];
}
void main()
{
    int n,i,j=0,idle=0,ls=0,m=0,t,num=0,k;
	float avgtt=0,avgwt=0;
	printf("\nEnter the number of process : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the process name : ");
		scanf("%s",p[i].name);
		printf("Enter the arrival time : ");
		scanf("%d",&p[i].at);
		printf("Enter the burst time : ");
		scanf("%d",&p[i].bt);
		p[i].stat=0;
        p[i].rt=p[i].bt;
	}
    printf("\nEnter the time quantum : ");
    scanf("%d",&t);
    i=0;
    while(ls<n)
	{
		for(j=0;j<n;j++)
		{
			if((p[j].stat==0)&&(p[j].at<=i))
			{
				enqueue(j);
				p[j].stat=1;
			}
		}
		if((idle==0)&&(f==-1))
		{
			strcpy(g[num].name,"idle");
			g[num].st=i;
			idle=1;
			i++;
		}
		else if(f!=-1)
		{
			if(idle==1)
			{
				g[num].ct=i;
				idle=0;
				num++;
			}
			k=dequeue();
			g[num].st=i;
			strcpy(g[num].name,p[k].name);
			if(p[k].rt<=t)
			{
				g[num].ct=i+p[k].rt;
				i=g[num].ct;
				p[k].tt=i-p[k].at;
				p[k].wt=p[k].tt-p[k].bt;
				p[k].stat=2;
				ls++;
				num++;
			}
			else
			{
				g[num].ct=i+t;
				i=i+t;
				p[k].rt=p[k].rt-t;
				num++;
				for(m=0;m<n;m++)
				{
					if((p[m].stat==0)&&(p[m].at<=i))
					{
						enqueue(m);
						p[m].stat=1;
					}
				}
				enqueue(k);
			}
		}
		else
		{
			i++;
		}
	}
    printf("\nProcess Table");
	printf("\nName \tat \tbt \twt \ttt\n");
	for(i=0;i<n;i++){
		printf("%s\t %d \t%d\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tt);
		avgwt+=p[i].wt;
		avgtt+=p[i].tt;}
    printf("\nGantt chart");
	printf("\n-------------------------------------------------------------------------------------------------\n");
	printf("|");
	for(m=0;m<num;m++)
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
	printf("\n-------------------------------------------------------------------------------------------------\n");
	printf("%d\t",g[0].st);
	for(m=0;m<num;m++)
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
	printf("\nAverage waiting time = %0.2f",avgwt/n);
	printf("\nAverage turnaround time = %0.2f\n",avgtt/n);
}