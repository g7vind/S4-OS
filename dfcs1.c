#include<stdio.h>
#include<stdlib.h>
void main(){
	int i,j,n,num,mov=0,track[50];
	printf("\nEnter the number of tracks : ");
	scanf("%d",&n);
	printf("\nEnter the tracks : ");
	for(i=1;i<=n;i++)
		scanf("%d",&track[i]);
	printf("\nEnter the start head : ");
	scanf("%d",&num);
	track[0]=num;
	for(i=0;i<n;i++)
	{
		printf("\n[Traversed] : %d",track[i+1]);
		mov+=abs(track[i]-track[i+1]);
	}
	printf("\nTracked Sequence : ");
	for(i=0;i<n;i++){
	printf(" %d -> ",track[i]);
	}
	printf(" %d \n",track[n]);
	printf("Total seek time : %d\n",mov);
}
