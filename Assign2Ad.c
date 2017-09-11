//Name-abhishek nautiyal
//roll no.-1601cs02
#include <stdio.h>


//function for finding maximum
int maxch(int *arr,int start,int n,int maxim){

if(start==n+1){
	return maxim;
}else{
	if(arr[maxim]<arr[start]){
		maxim=start;
		
	}
	return maxch(arr,start+1,n,maxim);//recursively calling function
}




}

//function for finding minimum
int minch(int *arr,int start,int n,int minim){

if(start==n+1){
	return minim;
}else{
	if(arr[minim]>arr[start]){
		minim=start;
		
	}
	return minch(arr,start+1,n,minim);//recursively calling function
}


}


//finding maximum index
int max(int *arr,int start,int end)

{
	int maxind=start;
	if(end-start==0)
	{
		/*if(arr[start]>max)
			{max=arr[start];
		    maxind=start;
		}
		else
			max=max;
		*/
		return maxind;
	}
	else
	{
		
	/*	if(arr[start]>arr[maxind])
		{	
		    maxind=start;
		}

	   start=start+1;*/
		maxind= maxch(arr,start+1,end,start);
 
	}
	return maxind;
}

//fiding minimum index
int min(int *arr,int start,int end)
{
	int minind=start;
	if(end-start==0)
	{
		/*if(arr[start]>max)
			{max=arr[start];
		    maxind=start;
		}
		else
			max=max;
		*/
		return minind;
	}
	else
	{
		/*for(i=start+1;i<end;i++){
		if(arr[start]<arr[minind])
		{	
		    minind=start;
		}

	}*/
		
	minind = minch(arr,start+1,end,start);
 
	}
	return minind;
}
//function for sorting
void sort(int *arr,int start,int end)
{
 if(end-start==0)
  {
  	return;
  }
  else if(end-start==1)
  {
  	if(arr[start]>arr[end])
  	{
  		int temp=arr[start];
  		arr[start]=arr[end];
  		arr[end]=temp;
  	}
  	return;
  }
  else
  {
  
  	int mini=min(arr,start,end);//finding minimum index
  	int temp1,temp2;
  	temp1=arr[mini];
  	arr[mini]=arr[start];
  	arr[start]=temp1;

   int maxi = max(arr,start,end);//finding maximum index
  /*  if(maxind==start)
    {
    	maxind=end;
    }*/
   if(mini!=maxi){
  	temp2=arr[maxi];
  	arr[maxi]=arr[end];
  	arr[end]=temp2;
}
  	start=start+1;
  	end=end-1;
  	sort(arr,start,end);
  }
  
  
}
int main()
{
	int n,i;
	printf("Enter how many numbers you want to enter-");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the number with spaces-");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	sort(arr,0,n-1);//calling sorting function
    
    printf("Sorted numbers are-");
    for(i=0;i<n;i++)
	{   
		if(i==0)
		printf("%d",arr[i]);
		else	
		printf(",%d",arr[i]);
	}

}