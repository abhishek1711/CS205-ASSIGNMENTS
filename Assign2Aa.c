#include <stdio.h>

int count=0;//variable that counts number of odd digits

//function for counting the odd digits
void find(long n)
{
	if(n/10==0)//checking for single digit
	{
		if(n%2==0)
			count;
		else
			++count;
		return;
	}

	else
	{
		int remainder=n%10;//remainder of a number when divided by 10 that is it gives last digit of a number
		if(remainder%2==0)
			count=count;
		else
			++count;
		n=n/10;
		find(n);//recursively calling the function
	}
}
int main()
{
   long n;
   printf("Enter a number-");
   scanf("%ld",&n);//scanning the number for which we have to find number of odd digits
   find(n);
   printf("\nNumber of odd digis in number is-");
   printf("%d",count);
   return 0;
}
