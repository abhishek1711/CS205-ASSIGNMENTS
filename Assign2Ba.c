//name-abhishek nautiyal
//roll no.-1601cs02
#include <stdio.h>

int count=0;//variable that checks that number exist or not

//function to find the number and then returns index
int ter(int *arr,int l,int r,int x)
{
    if(r-l==0)
    {
    	if(arr[r]==x) 
            {   
                count++;
                return r;
            }    
    }
    else if(r-l==1)
    {
    	if(arr[l]==x) 
            {   count++;
                return l;
            }
    	else if(arr[l+1]==x)
        {count++;
         return (l+1);
     }
    }
    else
    {
    	int n1=(r-l+1)/3 - 1 + l;//dividing array into three parts
    	int n2=(r-l+1)/3 - 1 + l + n1 + 1;
    	
    	if(arr[n1]>=x) return  ter(arr,l,n1,x);

        else if(arr[n1+1]<=x && arr[n2]>=x) return ter(arr,n1+1,n2,x);

        else 
        {
        	return ter(arr,n2+1,r,x);//recursively calling function
        }		
    }

}
int main()
{
	int n,i;
    printf("Enter how many numbers you want to enter-");
	scanf("%d",&n);//how many numbers to be inputted
	int arr[n];
    printf("enter the numbers with space betwwen them-");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
    }

    int x;
    printf("Enter the number to be searched-");
    scanf("%d",&x);

    int ind=ter(arr,0,n-1,x);
    if(count==0)
    {
        printf("Number does not exist\n");
    }
    else
    {
    
    printf("Index of the searched number-%d",ind);
    }
   
}