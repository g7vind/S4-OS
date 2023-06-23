void main(){
    int i,j,n,m,block[10],size[10],frag[10],status[10],alloc[10],b_size[10],highest=10000;
    printf("\nEnter the number of blocks : ");
    scanf("%d",&n);
    printf("\nEnter the number of File : ");
    scanf("%d",&m);
    printf("\n---------------Enter Block Size----------------\n");
    for(i=0;i<n;i++)
    {
        printf("Block %d:",i+1);
        scanf("%d",&block[i]);
        status[i]=0;
    }
     printf("\n---------------Enter File Size----------------\n");
    for(i=0;i<m;i++)
    {
        printf("File size %d:",i+1);
        scanf("%d",&size[i]);
        alloc[i]=-1;
        b_size[i]=0;
        frag[i]=0;
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
              if(block[j]>=size[i] && status[j]!=1)
              {
                  if(highest>block[j])
                  {
                      highest=block[j];
                      alloc[i]=j;
                      b_size[i]=block[j];
                  }
              }
        }
        if(highest!=10000)
        {
            frag[i]=highest-size[i];
        }
        status[alloc[i]]=1;
        highest=10000;
    }
    printf("\n----------------------Allocation Table-------------------------\n");
    printf("File_no\t\tFile_size\tblock_allocated\t\tBlock_size\tWastage\n");
    for(i=0;i<m;i++)
    {
        printf("%d \t\t%d\t\t", i+1, size[i]);
        if(alloc[i]!=-1)
        {
            printf("%d\t",alloc[i]+1);
            printf("\t\t%d\t\t%d\n",b_size[i],frag[i]);
        }
        else
        {
            printf("NULL\t");
            printf("\t\t-\t\t-\n");
        }
        
    } 
 }
