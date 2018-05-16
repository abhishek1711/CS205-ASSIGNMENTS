//NAME-ABHISHEK NAUTIYAL
//ROLL NO.-1602CS02
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//partition function
int partition(int arr[], int start, int end, int x)
{
    
    int i;
    for (i=start; i<end; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[end]);

    
    i = start-1;
    for (int j = start; j <= end - 1; j++)
    {
        if (arr[j] <= x)
        {   
          i++;
            swap(&arr[i], &arr[j]);
            
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}
 
//finding the median
int findmid(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }

   
    return arr[n/2];   
}
 
//finding k-th number using statistics
int order(int arr[], int start, int end, int k)
{
    
    if (k > 0 && k <= end - start + 1)
    {
        int n = end-start+1; 
 
        
        int i, median[(n+4)/5]; 
        for (i=0; i<n/5; i++)
            median[i] = findmid(arr+start+i*5, 5);
        if (i*5 < n) 
        {
            median[i] = findmid(arr+start+i*5, n%5); 
            i++;
        }    
 
       
        int m = (i == 1)? median[i-1]:
                                 order(median, 0, i-1, i/2);
 
        
        int p = partition(arr, start, end, m);
 
        // If position is same as k
        if (p-start == k-1)
            return arr[p];
        if (p-start > k-1)  
            return order(arr, start, p-1, k);//Recursively calling on left side
 
        
        return order(arr, p+1, end, k-p+start-1);//Recursivey calling on right
    }
 
    
    return 999999;
}
 

 


int main()
{
  int n,i,j,k;
  printf("How many elements you want to enter- ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the elemnts with space between them- ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
    
    printf("enter the position ");
    scanf("%d",&k);
    if(order(arr,0,n-1,k)==999999)
    {
      printf("The position does not exist-");
    }
    else
    {
    printf("The element at that position is %d",order(arr,0,n-1,k));
    }
}
