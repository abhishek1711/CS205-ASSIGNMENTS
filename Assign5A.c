//NAME-Abhishek Nautiyal
//Roll No.-1601CS02
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to swap namas
void swap(long int *a, long int *b)
{
	long int temp=*a;
	*a=*b;
	*b=temp;
}

//function to do partition 
int partition(long int *arr,long int low,long int high,int choice)
{ 
  
   
   if(choice==0)
   {
   swap(&arr[low],&arr[high]);
   }
   else if(choice==1)
   {
    int randind=low+rand()%(high-low+1);
    swap(&arr[randind],&arr[high]);
   }
   else if(choice==2)
   { int temp=(high-low+1);
    
     long int a=arr[low];
    long int b=arr[high];
    long int c=arr[low+temp/2];
    if(((a<=b)&&(b<=c)) || ((a>=b)&&(a<=c)))
    {
        swap(&arr[high],&arr[high]);
    }
    else if(((b<=a)&&(a>=c)) || ((a>=b)&&(a<=c)))
    {
        swap(&arr[low],&arr[high]);
    }
    //else (((c<=a)&&(c>=b)) || ((c>=a)&&(c<=b)))
    else
    {
       swap(&arr[low+temp/2],&arr[high]);
    }
   }
   else if(choice==3)
   {
     long int temp=(high-low+1);
     long int a=arr[low+temp/4];
     long int b=arr[low+temp/2];
     long int c=arr[low+3*temp/4];
      if(((a<=b)&&(b<=c)) || ((a>=b)&&(a<=c)))
    {
        swap(&arr[low+temp/2],&arr[high]);
    }
    else if(((b<=a)&&(a>=c)) || ((a>=b)&&(a<=c)))
    {
        swap(&arr[low+temp/4],&arr[high]);
    }
    //if(((c<=a)&&(c>=b)) || ((c>=a)&&(c<=b)))
    else
    {
       swap(&arr[low+3*temp/4],&arr[high]);
    }
   }
   long int pivot=arr[high];

   long int i=(low-1),j;
   
   for(j=low;j<=high-1;j++)
   {
   	if(arr[j]<=pivot)
   	{
   		i++;
   		swap(&arr[i],&arr[j]);
   	}
   }

    swap(&arr[i+1],&arr[high]);

    return (i+1);
}

//function to do quicksort
void q_sort(long int *arr,long int low,long int high,int choice)
{
	if(low<high)
	{
		int pi=partition(arr,low,high,choice);

		q_sort(arr,low,pi-1,choice);
		q_sort(arr,pi+1,high,choice);
	}
}



int main()
{   
    srand((unsigned int)time(NULL));
    long int n=10000,oi;
    
    while(n<=100000)
    {
    for(oi=0;oi<4;oi++)
    {  
     long int *arr;
    clock_t c1,c2;
    double runtime1,runtime2,runtime3;
    arr=(long int *) malloc(n * sizeof(long int));
    long long int i,j;
    for(i=0;i<n;i++)
    {
      arr[i]=rand() % 1000000000;
    }
   
    c1=clock();
    q_sort(arr,0,n-1,oi);
    c2=clock();

    runtime1=(double)(c2-c1)/CLOCKS_PER_SEC;

    

    c1=clock();
    q_sort(arr,0,n-1,oi);
    c2=clock();

    runtime2=(double)(c2-c1)/CLOCKS_PER_SEC;
    
    for(i=0;i<n/100;i++)
    {
      long int k=rand()%n;
      long int s=rand()%n;
      swap(&arr[k],&arr[s]);
    }

    c1=clock();
    q_sort(arr,0,n-1,oi);
    c2=clock();

    runtime3=(double)(c2-c1)/CLOCKS_PER_SEC;
    
    printf("%ld %ld %lf %lf %lf\n",n,oi,runtime1,runtime2,runtime3);

    
  free(arr);
  }
  n=n*10;
  
}
while(n<=10000000)
    {
    for(oi=1;oi<4;oi++)
    {  
     long int *arr;
    clock_t c1,c2;
    double runtime1,runtime2,runtime3;
    arr=(long int *) malloc(n * sizeof(long int));
    long long int i,j;
    for(i=0;i<n;i++)
    {
      arr[i]=rand() % 1000000000;
    }
    
    c1=clock();
    q_sort(arr,0,n-1,oi);
    c2=clock();

    runtime1=(double)(c2-c1)/CLOCKS_PER_SEC;

    

    c1=clock();
    q_sort(arr,0,n-1,oi);
    c2=clock();

    runtime2=(double)(c2-c1)/CLOCKS_PER_SEC;
    
    for(i=0;i<n/100;i++)
    {
      long int k=rand()%n;
      long int s=rand()%n;
      swap(&arr[k],&arr[s]);
    }

    c1=clock();
    q_sort(arr,0,n-1,oi);
    c2=clock();

    runtime3=(double)(c2-c1)/CLOCKS_PER_SEC;
    
    printf("%ld %ld %lf %lf %lf\n",n,oi,runtime1,runtime2,runtime3);

    
  free(arr);
  }
  n=n*10;
  
}
  return 0;
}