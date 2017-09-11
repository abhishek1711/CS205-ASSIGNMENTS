//name-Abhishek Nautiyal
//Roll No.-1601CS02
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



int main()
{
  int s,n,i,j,count=0;
  printf("Enter the sum- ");
  scanf("%d",&s);
  
  printf("Enter number of coins- ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter value of coins");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  int table[s+1];//array that store how many coins are needed to make that denomintion
  int stor[1000];
  for (i=1; i<=s; i++)
        table[i] = 9999;//initially assigning some maximum value to them
 
    
    for (i=1; i<=s; i++)
    {   
        
        for (j=0; j<n; j++)
          //if denomnation is less than sum
          if (arr[j] <= i)
          {
              int sub_res = table[i-arr[j]];
              if (sub_res != 9999 && sub_res + 1 < table[i])
                  {
                  stor[i]=arr[j];
                  table[i] = sub_res + 1;
                  
                  }
          }
    }
  
  if(table[s]==9999)
  {
    printf("That sum is not possible");
  }
  else
  {
  printf("minimum number of coins neede are- ");
  printf("%d",table[s]);
  printf("\nDenominations of coins that are needed is-  ");
  //getting the denominations that were needed
  while(stor[s]!=0)
  {
    printf("%d ",stor[s]);
    s=s-stor[s];
  }
}
  return 0;
}