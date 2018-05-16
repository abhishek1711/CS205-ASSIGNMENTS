/*      
    NAME-   RAJ SHEKHAR
    ROLL-   1601CS37   
    DATE-   30/09/17

*/
/*
    AIM-    TO MAKE A PROGRAM TO FIND THE PAIRS WITH SUM MAX DIFFERENCE 
            AND HAVE MAXIMUM SUM OF ELEMENTS
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>      //for tolower function
#include <stdbool.h>    //for boolean function


//quicksort for sorting the numbers for efficiency 
int partition(int array[], int a, int b)
{
  int r= a + rand()%(b-a+1);
  
  
  int pivot= array[r];
  int i, index=a;
  
  int temp= array[r];
  array[r]=array[b];
  array[b]=temp;
  
  for(i=a; i<b; i++)
  {
    if(array[i]<=pivot)
    {
      temp=array[i];
      array[i]=array[index];
      array[index]=temp;
      index++;
    }
  }
  
  temp=array[index];
  array[index]=pivot;
  array[b]=temp;
  return index;
}

//quicksort for sorting the numbers for efficiency 
void quicksort(int array[], int a, int b)
{
  int p;
  if(b>a)
  {
    p= partition(array, a, b);
    quicksort(array, a, p-1);
    quicksort(array, p, b); 
  }
}

int main()
{
  int n, m;

  //taking input
  printf("\nEnter total number of elements: ");
  scanf(" %d", &n);
  int i;
  int array[n];
  printf("\nEnter the numbers-\n");
  for(i=0; i<n; i++)
    scanf(" %d",&array[i]);
  
  //taking max diffence b/w pairs
  printf("\nEnter maximum difference of pairs, m: ");
  scanf(" %d",&m);
  
  quicksort(array, 0, n-1); //quicksort for sorting numbers
  
  //printing the result(pairs)
  printf("\nPair list which maximize the sum is-\n");
  int index= n-1;
  int sum=0;
  while(index>0)
  {
    if(array[index]-array[index-1]<m)
    {
      printf("(%d, %d)",array[index],array[index-1]);
      if(index>2)
        printf(", ");
      sum+=array[index]+array[index-1];
      index=index-2;
      continue;
    }
    else
    {
      index--;
      continue;
    }
  }
  
  printf("\n\nSum is %d\n\n",sum);    //printing the sum

return 0;
}