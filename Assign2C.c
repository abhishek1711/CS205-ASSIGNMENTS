//Name-abhishek nautiyal
//roll no.-1601cs02
#include <stdio.h>

int count=0;//variable that counts how many steps are there
void recur(int n)//function that finally takes the number to 1 
{
  if(n==1)//base case
  {
  	printf("Final value 1, number of steps %d\n",count);
    return;
  }
  else
  {
  	if(n%2==0)//when n is odd
  	{
  		n=n/2;
  	}
  	else//when n is even
  	{
  		n=(3*n) + 1;
  	}
    if(n!=1)
    {
  	printf("Next value is %d\n",n);
    }
  	count++;
  	recur(n);//recursively calling the function
  }
}

int main()
{
	int n;
	printf("Enter a positive integer value-");
	scanf("%d",&n);
	if(n<1)
	{
		printf("\nError");
	}

	else{

		printf("Initial Value is %d\n",n);
		recur(n);
	}
}