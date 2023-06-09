#include<stdio.h>
void main(){
    int available[10], allocated[30][30], need[30][30], max[30][30], m, n, finish[20], req[20], w[10], i, j, temp[10],p,k,f=0,count=0;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    printf("\nEnter the number of resource types: ");
    scanf("%d", &m);
    printf("\nEnter the allocation matrix:\n");
    for(i = 0; i < n; i++){
        finish[i] = 0;
        printf("Process %d: ", i);
        for(j = 0; j < m; j++){
            scanf("%d", &allocated[i][j]);
        }
    }
    printf("\nEnter the Maximum Resource matrix:\n");
    for(i = 0; i < n; i++){
        printf("Process %d: ", i);
        for(j = 0; j < m; j++){
            scanf("%d", &max[i][j]);
        }
    }
    printf("\nEnter the available resources:\n");
    for(i = 0; i < m; i++){
        scanf("%d", &available[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }
    // Display table
    printf("\n-------------------Resource Allocation Table----------------------\n");
    printf("Process\tAllocated\tMaximum\t\tNeed\t\tAvailable\n");
    for(i = 0; i < n; i++){
        printf("P%d\t", i);
        for(j = 0; j < m; j++){
            printf("%d ", allocated[i][j]);
        }
        printf("\t\t");
        for(j = 0; j < m; j++){
            printf("%d ", max[i][j]);
        }
        printf("\t\t");
        for(j = 0; j < m; j++){
            printf("%d ", need[i][j]);
        }
        printf("\t\t");
        if(i == 0){
            for(j = 0; j < m; j++){
                printf("%d ", available[j]);
            }
        }
        printf("\n");
    }
    printf("\nEnter the requesting process number : ");
    scanf("%d",&p);
    printf("\nEnter the requesting instances : \n");
    for(i=0;i<m;i++){
        scanf("%d",&req[i]);
    }
    f=0;
    for(i=0;i<m;i++)
	{
		if(req[i]>available[i] && req[i]>need[p][i])
		{
			f++;
			break;
		}
	}
	if(f==0)
	{
		printf("Request Status : Successfull\n");
		for(i=0;i<m;i++)
		{
			available[i]-=req[i];
			need[p][i]-=req[i];
			allocated[p][i]+=req[i];
		}
        printf("\n----------Modified Resource allocation table----------\n");
        printf("Process\tAllocated\tMaximum\t\tNeed\t\tAvailable\n");
        for(i = 0; i < n; i++){
            printf("P%d\t", i);
            for(j = 0; j < m; j++){
                printf("%d ", allocated[i][j]);
            }
            printf("\t\t");
            for(j = 0; j < m; j++){
                printf("%d ", max[i][j]);
            }
            printf("\t\t");
            for(j = 0; j < m; j++){
                printf("%d ", need[i][j]);
            }
            printf("\t\t");
            if(i == 0){
                for(j = 0; j < m; j++){
                    printf("%d ", available[j]);
                }
            }
            printf("\n");
        }
        int c=0;
        f=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(finish[j]==0)
                {
                    for(k=0;k<m;k++){
                        if(available[k]<need[j][k]){
                            f=1;
                            break;
                        }
                    }
                    if(f==0){
                        printf("\n[Process %d] : Executed\n",j);
                        w[c]=j;
                        c++;
                        finish[j]=1;
                        count++;
                        printf("Available : ");
                        for(k=0;k<m;k++){
                            available[k]=available[k]+allocated[j][k];
                            printf("%d ",available[k]);
                        }
                    }
                }
                f=0;
            }
        }
        if(count==n){
            printf("\n------DeadLock Free-------");
            printf("\nSafety Sequence : ");
            printf("p%d",w[0]);
            for(i=1;i<c;i++){
                printf(" --> p%d ",w[i]);
            }
        }
        else{
            printf("\n------DeadLock Condition-------\n");
        }
        printf("\n");
    }
    else
        printf("\nRequest status : Fail\n");
}