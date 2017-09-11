#include <stdio.h>

int count=0;//variable that counts the number of digits in the binary number
void bin(int *arr,int n)//function to get all the binary digits of a number
{
	if(n/2==0)//when a single digit is there
	{
		arr[count]=1;
	    count++;
	    return;
	}    
	else
	{
		int rem;
		rem=n%2;//tells that last digit is even or odd
		if(rem==0)
			arr[count]=0;
        else
        	arr[count]=1;
        count++;
        n=n/2;
        bin(arr,n);
	}
}
int main()
{   
   int n;
   printf("Enter the number-");
   scanf("%d",&n);
   int arr[100],i;//array the stores the binary digit of the number
   bin(arr,n);//calling the function
   printf("The binary representation of a number is-");
   for(i=count-1;i>=0;i--)
   {
   printf("%d",arr[i]);
   }
   return 0;
}