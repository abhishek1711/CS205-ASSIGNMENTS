#include <stdio.h>

int max=0;//variable that gives maximum digit
int min=9;//variable that gives minimum digit
//function to find maximum and minimum digit
void maxmin(int n)
{
	if(n/10==0)//checking for single digit
	{   
		
			if(max<n)
				max=n;
			else
				max=max;
            if(n<min)
            	min=n;
            else
            	min=min;
            return;
	}
	
	else
	{
      int g=n%10;//it gives last digit of the number 
      if(g>max)
      	max=g;
      if(g<min)
      	min=g;

      n=n/10;
      maxmin(n);//recursively calling the function
	}
}
int main()
{
 int n;
 printf("Enter the number-");
 scanf("%d",&n);

 maxmin(n);//calling the function
 printf("Largest digit in the number is-");
 printf("%d\n",max);
 printf("Smallest digit in the number is-");
 printf("%d",min);
}