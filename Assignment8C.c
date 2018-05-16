#include<stdio.h>
int arr[100][100];     //adjacency matrix
//A function to found longest connected component
int  BFS(int n)
{
	int queue[100],front=-1,end=-1; //queue using array
	int i,j;                 //counter variables
	int curedge,edge=0;     //variables for no. of edges
	for(i=0;i<n;i++)
	{
		 curedge=0;
		 queue[0]=i;
		 front=0;
		 end=0;
		 //counting no. of edges
		while(front<=end)
		{
			for(j=0;j<n;j++)
			{

				if(arr[queue[front]][j]==1)
				{
					arr[queue[front]][j]--;
					arr[j][queue[front]]--;
					curedge++;
			                end++;
				 	queue[end]=j;
				}
			}
			front++;
		}
		//updating the edge if bigger component is found
	  if(curedge>edge)
	  	edge=curedge;
	 }
     return edge;
}
//main function begins
int main()
{
	int n;               //no. of players
	int m;               //no. of rival pairs 
	int x,y,i,j;
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	printf("Enter the number of edges:");
	scanf("%d",&m);
	int team[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			arr[i][j]=0;
	}
	printf("Enter the start and end of each edge\n");
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		arr[x-1][y-1]++;
        arr[y-1][x-1]++;
    }
    
    	printf("The longest connected component has %d edges\n",BFS(n));  //function call
}


