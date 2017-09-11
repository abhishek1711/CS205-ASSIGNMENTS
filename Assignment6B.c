//NAME-Abhishek Nuatiyal
//Roll NO.-1601CS02
#include <stdio.h>
#include <stdlib.h>


//finding the minimum of three numbers
int min(int a,int b,int c)
{
  if(a<=b && a<=c)
  {
   
   return a;
  }
  else if (b<=a && b<=c)
  {
   
   return b;
  }
  else
  {
  
  return c;
  }

}
int main()
{
int m,n,i,j;
printf("enter number of rows and columns giving space between them-");
scanf("%d%d",&m,&n);
int arr[m][n];//for storing the minimum required to reach any i,j

printf("enter cost of each row by giving space and then enter-\n");
for(i=0;i<m;i++)
{
   for(j=0;j<n;j++)
   {
    scanf("%d",&arr[i][j]);
   } 
}



for(i=1;i<n;i++)
{
arr[0][i]=arr[0][i] + arr[0][i-1];
}

for(j=1;j<m;j++)
{
arr[j][0]=arr[j][0] + arr[j-1][0];
}

for(i=1;i<m;i++)
{
   for(j=1;j<n;j++)
   {
     arr[i][j]=arr[i][j] + min(arr[i-1][j],arr[i][j-1],arr[i-1][j-1]);
   }
}

int stor[100];//for storring the paths
int cot=0;
for(i=m-1,j=n-1;i!=0 || j!=0;)
{
  
    int a=min(arr[i-1][j],arr[i][j-1],arr[i-1][j-1]);
    if(a==arr[i-1][j])
    {
      stor[cot]=0;
      cot++;
      i=i-1;
      j=j;
    }
    if(a==arr[i][j-1])
    {
      stor[cot]=1;
      cot++;
      i=i;
      j=j-1;
    }
    if(a==arr[i-1][j-1])
    {
      stor[cot]=2;
      cot++;
      i=i-1;
      j=j-1;
    }
  
}
printf("Path travelled is");
for(i=cot-1;i>=0;i--)
{
if(stor[i]==0)
printf("Downwards ");
else if(stor[i]==1)
{
  printf("Rightwards ");
}
else
printf("Diagonally ");
}
printf("\nminimum cost to reach room is-");
printf("%d",arr[m-1][n-1]);



return 0;
}
