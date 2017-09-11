#include <stdio.h>

int count=0;//variable that checks that number exist or not

//function to find the index of searched number 
int pen(int *arr,int l,int r,int x)
{
   if(r-l==0)
    {
    	if(arr[r]==x) 
            {   count++;
                return r;
            }
    }
    else if(r-l==1)
    {
    	if(arr[l]==x) 
            {   count++;
                return l;
            }
    	else if(arr[r]==x) 
            {   count++;
            return (r);
        }
    }
    else
    {
    	int n1=(2*(r-l+1))/5 - 1 + l;//dividing array in parts

        if(arr[n1]>=x) return  pen(arr,l,n1,x);
        else if(arr[n1+1]<=x)
        {
        	return pen(arr,n1+1,r,x);
        }		
    }

}
int main()
{
	int n,i;
    printf("Enter how many numbers you want to enter-");
	scanf("%d",&n);//number of digits to be entered
	int arr[n];
    printf("enter the numbers with space betwwen them-");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
    }

    int x;
    printf("Enter the number to be searched-");
    scanf("%d",&x);

    int ind=pen(arr,0,n-1,x);
    if(count==0)
    {
        printf("Number does not exist\n");
    }
    else
    {
    
    printf("Index of the searched number-%d",ind);
    }
}