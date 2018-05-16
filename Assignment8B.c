#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//A function to check edge between two  strings
//It takes both strings as input
int check_edge(char *str1,char *str2)
{
	int l,i,j,count=0;                                 
	char temp;
	char *ptr1=malloc(sizeof(char)*(strlen(str1)+1));   //dynimiclly allocating the space
	char *ptr2=malloc(sizeof(char)*(strlen(str2)+1));   //dynimiclly allocating the space
	strcpy(ptr1,str1);               
	strcpy(ptr2,str2);
	l=strlen(ptr1);          //lenth of string
	//sorting the first string from frist letter
	for(i=1;i<l;i++)
	{
		for(j=i+1;j<l;j++)
			if((ptr1[i]-'a')>(ptr1[j]-'a'))
			{
				temp=ptr1[i];
				ptr1[i]=ptr1[j];
				ptr1[j]=temp;
			}
    }
    //sorting the second string from start
    for(i=0;i<l;i++)
	{
		for(j=i+1;j<l;j++)
			if((ptr2[i]-'a')>(ptr2[j]-'a'))
			{
				temp=ptr2[i];
				ptr2[i]=ptr2[j];
				ptr2[j]=temp;
			}
    }
    i=1;
    j=0;
    //counting the number of matching characters
    while(i<l&&j<l)
    {
    	if(ptr1[i]==ptr2[j])
    	{
    		count++;
    		i++;
    		j++;
    	}
    	else
    	{
    		if(ptr1[0]==ptr2[j])
    		{
    	      count=-100;
    	      break;
    	    }
    	    j++;
    	}
    }
    if(count>=l-1)
    	return 1;
    else
    	return 0;
}
//main function begins
int main()
{
	int n;                //no. of strings
	int i,j;              //counter varaibles
	int valid=-1;      
	int front=-1,end=-1;   //variables for queue
	printf("Enter the number of strings:");
	scanf("%d",&n);
	char *ptr[n];         //array of string pointers
	char str[50];        //string array for words
    int link[n][n];      //A 2-D to tell the link between words
    int arr[100][100];          //Adjacency matrix
    printf("Enter the words:\n");
	for(i=0;i<n;i++)
	{
		scanf("%s",str);
		ptr[i]=malloc(sizeof(char)*(strlen(str)+1));
		strcpy(ptr[i],str);
	}
    for(i=0;i<n;i++)
     {
        for(j=0;j<n;j++)
           {
             arr[i][j]=0;
             link[i][j]=0;
           }
        }
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j&&arr[i][j]!=1)
			 arr[i][j]=check_edge(ptr[i],ptr[j]);
		}
	}
	//A bfs approach to find link
	for(i=0;i<n;i++)
	{
		int queue[100];          //A array for queue
		int visit[100]={0};      //A array to show node is explored or not
		//putting the node in front
		 queue[0]=i;
		 front=0;
		 end=0;
		 visit[i]=1;
		while(front<=end)
		{
		for(j=0;j<n;j++)
		{
			//exploring the adjacent nodes
		     if(arr[queue[front]][j]==1&&visit[j]==0)
		     {
		      end++;
		      queue[end]=j;
              link[queue[0]][j]=1;
              visit[j]=1;		
	         }
		}
		front++;
	  }
	}
	int visit[100]={0};
	for(i=0;i<n;i++)
	{
		if(visit[i]==0)
		{
		int queue[100];
		 queue[0]=i;
		 front=0;
		 end=0;
		 visit[i]=1;
		while(front<=end)
		{
		 for(j=0;j<n;j++)
		 {
			 if(arr[queue[front]][j]==1&&visit[j]==1)
			 {
			 	printf("The graph is cyclic\n");
			 	valid=1;
			 	break;
			 }
		     if(arr[queue[front]][j]==1&&visit[j]==0)
		     {
		      end++;
		      queue[end]=j;
              visit[j]=1;		
	         }
		 }
		 if(valid==1)
	   	    break;
	   	visit[queue[front]]==-1;
		front++;
	   }
	   if(valid==1)
	   	break;
	  }
	 }
	 printf("The following matrix shows path between nodes:\n");
	 printf("0 indicates no path and 1 shows path\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",link[i][j]);
		}
		printf("\n");
	}
}

