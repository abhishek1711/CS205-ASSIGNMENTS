//Name-abhishek nautiyal
//roll no.-1601CS02
#include <stdio.h>

int count=0;//variable to count the how many numbers are there in output
void rsum(long *arr,long n)//function for getting sum of digits
{
	if(n/10==0)//if single digit than return
	{
		return;
	}
	else
	{
		int sum=0;//getting the sum of digit
		while(n!=0)
		{
			int rem=n%10;//getting the last digit
			
			sum=sum+rem;
			n=n/10;
		}
		arr[count]=sum;//storing the sum in array
		count++;
		n=sum;
		rsum(arr,n);
	}
}
int main()
{
	long n,i;
	printf("Enter the number-");
	scanf("%ld",&n);
	long arr[100];
    arr[count]=n;
    count++;
	rsum(arr,n);
   printf("Recursive sum is-");
   for(i=0;i<count;i++)
   { 
   	if(i==0)
   	printf("%ld",arr[i]);
   else
   	printf("->%ld",arr[i]);
   }
}