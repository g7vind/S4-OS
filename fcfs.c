#include<stdio.h>
#include<string.h>
struct process{
	char name[20];
	int at,bt,tt,wt,st;
}p[50],temp;
struct chart{
	int ct,st;
	char name[20];
}g[50];
void main()
{
	int n,i,j=0;
	float avgtt=0,avgwt=0;
	printf("\nEnter the number of process : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the process name : ");
		scanf("%s",p[i].name);
		printf("\nEnter the arrival time : ");
		scanf("%d",&p[i].at);
		printf("\nEnter the burst time : ");
		scanf("%d",&p[i].bt);
		p[i].st=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}	
		}
	}
	i=0;
	int k=0;
	while(k<n)
	{
		if(p[k].at<=i)
		{
			strcpy(g[j].name,p[k].name);
			g[j].st=i;
			g[j].ct=i+p[k].bt;
			i=g[j].ct;
			p[k].wt=g[j].st-p[k].at;
			p[k].tt=g[j].ct-p[k].at;
			j++;
			k++;
		}
		else if(p[k].at>i)
		{
			strcpy(g[j].name,"idle");
			g[j].st=i;
			g[j].ct=p[k].at;
			i=g[j].ct;
			j++;
		}
	}
	for(i=0;i<n;i++){
		avgwt+=p[i].wt;
		avgtt+=p[i].tt;}
	avgwt/=n;
	avgtt/=n;
	printf("\nProcess Table");
	printf("\nName \tat \tbt \twt \ttt\n");
	for(i=0;i<n;i++)
		printf("%s\t %d \t%d\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tt);
	printf("\nGantt Chart\n");
	printf("---------------------------------------------------------\n");
	printf("|");
	for(i=0;i<j;i++)
		printf("%s\t|",g[i].name);
	printf("\n---------------------------------------------------------\n");
	printf("%d\t",g[j].st);
	for(i=0;i<j;i++)
		printf("%d\t",g[i].ct);
	printf("\n\nAverage waiting time : %.2f",avgwt);
	printf("\nAverage turnaround time : %.2f\n",avgtt);
}
