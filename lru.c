#include <stdio.h>
int main()
{
	int i,j,flag=0,pf=0,ref[50],frame[50],count[50],nof,nop,next=0,min;
	printf("Enter number of frames : ");
	scanf("%d",&nof);
	for(i=0;i<nof;i++)
		frame[i]=-1;
	printf("Enter number of pages : ");
	scanf("%d",&nop);
	printf("Enter page numbers : ");
	for(i=0;i<nop;i++)
		scanf("%d",&ref[i]);
	for(i=0;i<nop;i++)
	{
		printf("\n");
		flag=0;
		for(j=0;j<nof;j++)
		{
			if(frame[j]==ref[i])
			{
				flag = 1;
				count[j]=next;
				next++;
				break;
			}
		}
		if(flag == 0)
		{
			if(i<nof)
			{
				frame[i]=ref[i];
				count[i]=next;
				next++;
			}
			else
			{
				min=0;
				for(j=1;j<nof;j++)
					if(count[min]>count[j])
						min=j;
				frame[min]=ref[i];
				count[min]=next;
				next++;
			}
			pf++;
		}
		for(j=0;j<nof;j++)
		{
			if(frame[j] != -1)
			{
				printf("%d   ",frame[j]);
			}
		}
	}
	printf("\n\nPage Fault : %d\n",pf);
	return 0;
}

