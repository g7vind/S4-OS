#include<stdio.h>
#include<string.h>
struct process{
	char name[20];
	int at,bt,tt,wt,stat,pr;
}p[50],temp;
struct chart{
	int ct,st;
	char name[20];
}g[50];
void main()
{
	int n,i,j=0,idle=0,flag,l=0,m=0;
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
        printf("\nEnter the priority number : ");
        scanf("%d",&p[i].pr);
		p[i].stat=0;
	}
    i=0;
    while (l < n) {
        int k = -1;
        for (j = 0; j < n; j++) {
            if (p[j].stat == 0 && p[j].at <= i && (k == -1 || p[j].pr < p[k].pr)) {
                k = j;
            }
        }
        if (k == -1) {
            if (idle == 0) {
                strcpy(g[m].name, "idle");
                g[m].st = i;
                idle = 1;
                i++;
            } else {
                i++;
            }
        } else {
            if (idle == 1) {
                g[m].ct = i;
                m++;
            }
            strcpy(g[m].name, p[k].name);
            g[m].st = i;
            g[m].ct = i + p[k].bt;
            p[k].wt = g[m].st - p[k].at;
            p[k].tt = g[m].ct - p[k].at;
            i = g[m].ct;
            m++;
            p[k].stat = 1;
            idle = 0;
            l++;
        }
    }
    printf("\nProcess Table");
	printf("\nName \tat \tbt \twt \ttt \tpriority\n");
	for(i=0;i<n;i++){
		printf("%s\t %d \t%d\t%d\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tt,p[i].pr);
		avgwt+=p[i].wt;
		avgtt+=p[i].tt;}
	avgwt/=n;
	avgtt/=n;
    printf("\nGantt Chart\n");
	printf("---------------------------------------------------------\n");
	printf("|");
	for(i=0;i<m;i++)
		printf("%s\t|",g[i].name);
	printf("\n---------------------------------------------------------\n");
	printf("%d\t",g[m].st);
	for(i=0;i<m;i++)
		printf("%d\t",g[i].ct);
	printf("\n\nAverage waiting time : %.2f",avgwt);
	printf("\nAverage turnaround time : %.2f\n",avgtt);
}