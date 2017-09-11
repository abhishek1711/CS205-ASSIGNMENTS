//NAME-ABHISHEK NAUTIYAL
//ROLL NO.-1601CS02

#include <stdio.h>

int summax=0;//global variable which gives maximum sum of chocolates
//recursive function to find largest digit in integer maximum sum
int LargeDigit(int summax)
{   
  
  
	if((summax/10)==0)
    {return summax;}

    else{
    	int large=summax%10;
    	summax=summax/10;
    	int count1=0;
    	int dig[200];
    	int temp=summax;
    while(temp!=0)
  {
  	dig[count1]=temp%10;
    
   temp=temp/10;
   count1++;
  }
    	int h;
    	for(h=0;h<count1;h++)
    	{
          if(dig[h]>large)
          return LargeDigit(summax);
          else
          	return LargeDigit(large);
    	}
        
    }

}

int main()
{   
	//int ld;
	printf("Enter the no. of boxes-");
	int n;
	scanf("%d",&n);
	int arr[n];//putting chocolates in each box in array
	int stormax[n];//putting the maximum from each element in another array
	int i;
	printf("Enter no of chocolates in each boxes-");
    for(i=0;i<n;i++)
    {
     scanf("%d",&arr[i]);//entering chocolate in each boxes
    }
    stormax[0]=arr[0];
    stormax[1]=arr[1];
  
    for (i = 2; i < n; i++)
    {
    	int j;
    	int max=0;
          for(j=i-2;j>=0;j--)
            {
            	if(stormax[j]>max)
            		max=stormax[j];
            }

            stormax[i]=max+arr[i];
    }

    //finding maximum from the array
   for(i=0;i<n;i++)
   {
   	if(stormax[i]>summax)
   		summax=stormax[i];
   }

   printf("Maximum Chocolates she can takeout-%d\n",summax);
   
   int t=LargeDigit(summax);//largest digit
   printf("largest digit in the number-%d\n",t);
}