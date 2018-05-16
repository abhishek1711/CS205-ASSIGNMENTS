/*      
    NAME-   RAJ SHEKHAR
    ROLL-   1601CS37   
    DATE-   30/09/17

*/
/*
    AIM-    TO MAKE A PROGRAM TO FIND THE NUMBER OF STEPS TO REDUCE 
            A GIVEN NUMBER TO 1 BY GIVEN CONDITIONS 
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>      //for tolower function
#include <stdbool.h>    //for boolean function


//top-down approach

int work(long long int n)   //function to find number of  steps
{
  if(n==1)
    return 0;
  else if(n%7==0)
    return 1+work(n/7);
  else if(n%5==0)
    return 1+work(n/5);
  else if(n%3==0)
    return 1+work(n/3);
  else if(n%2==0)
    return 1 + work(n/2);
  else
    return 1+work(n-1);
}

int main()
{
  long long int n;
  printf("\nEnter a number: ");
  scanf(" %lld", &n); 
  
  int count= work(n);
  printf("\nNumber of step required- ");
  printf("%d\n\n",count);
  
return 0;
}