//Name-Abhishek Nautiyal
//Roll No.-1601CS02
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	int n,i,j,sum=0;
	printf("Enter total no. of elements- ");
	scanf("%d",&n);

	int arr[n];
	printf("Enter the number with space between them  ");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
    	sum=sum+arr[i];//calculated tottal sum
    }

    bool find[n+1][sum+1];//2-d array which store that is the particular sum possible from the given numbers

    for(i=0;i<=n;i++)
    {
    	find[i][0]=true;//SUM =0 is possible from evry given number
    }

    for(i=1;i<=sum;i++)
    {
    	find[0][i]=false;//no sum is possible form given numbers equal to zero
    }

    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=sum;j++)
    	{
    		if(arr[i-1]>j)
    		{
    			find[i][j]=find[i-1][j];
    		}

    		else
    		{
    			find[i][j]=find[i-1][j-arr[i-1]]  || find[i-1][j];
    		}
    	}
    }
    
    int dif;
    for(j=sum/2;j>=0;j--)
    {
    	if(find[n][j]==true)
    	{
    		dif=sum-2*j;//getting the maximum possible difference
    		break;
    	}
    }

    printf("the minimum difference possible between the two sets is %d\n",dif);
    
    int x=(sum-dif)/2 + 1;
    int stor1[n];
    int stor2[n];
    int count1=0,count2=0;
    printf("Elements of set1 are- ");
    for(i=0;i<n;i++)
    {
    	if(arr[i]<=x)
        {
        	stor1[count1]=arr[i];
        	x=x-arr[i];
        	printf("%d ",stor1[count1]);
        	count1++;
        }
        else
        {
        	stor2[count2]=arr[i];
        	count2++;
        }
    }

    printf("\nElements of set2 are- ");
    for(i=0;i<count2;i++)
    	printf("%d ",stor2[i]);
}