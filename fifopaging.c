#include<stdio.h>
void main()
{
	int i,j,fn,pn,ref[50],frame[50],page_fault=0,victim=-1,flag;
	printf("Enter the number of frames : ");
	scanf("%d",&fn);
	printf("Enter the number of pages : ");
	scanf("%d",&pn);
	printf("\n------------------Enter reference string-----------------------\n");
	for(i=0;i<pn;i++)
	{
		scanf("%d",&ref[i]);
	}
	printf("\n\n");
	printf("\n----------------FIFO page replacement--------------\n");
	for(i=0;i<fn;i++)
	{
		frame[i]=-1;
	}
	for(i=0;i<pn;i++)
	{
		flag=0;
		for(j=0;j<fn;j++)
		{
			if(ref[i]==frame[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			page_fault++;
			victim++;
			victim=victim%fn;
			frame[victim]=ref[i];
			printf("[incoming : %d ] : ",ref[i]);
			for(j=0;j<fn;j++)
			{	
				if(frame[j]!=-1){
				printf("%d\t",frame[j]);
				}
			}
			printf("\n");
		}
		else
		{
			printf("[incoming : %d ] : existing\n",ref[i]);
		}
	}
	printf("\nPAGE FAULT : %d",page_fault);
	printf("\n");
}
