#include<stdio.h>
int arr[100][100];    //adjacency matrix
int valid=1;          //to check the valid input
//A function to divide the players into two teams such that no two rival players are in same team
//It takes two arguments
//1.A team array 2.no. of players
void BFS(int team[],int n)
{
	int queue[100],front=-1,end=-1;     //queue for bfs
        int i,j;                            //counter variables
        //initailsing the each node unvisited
	for(i=0;i<n;i++)
		team[i]=0;
     
	for(i=0;i<n;i++)
	{
		if(team[i]==0)
		{
                 //putting the unvisited node in front
		 queue[0]=i;
		 front=0;
		 end=0;
		 team[i]=1;
		while(front<=end)
		{
			for(j=0;j<n;j++)
			{

				if(arr[queue[front]][j]==1)    
				{
                    //putting unvisited adjacent nodes in queue
					if(team[j]==0)
					{
					  team[j]=-team[queue[front]];
					  end++;
					  queue[end]=j;
					}
					else if(team[j]==team[queue[front]])
					{
						valid=-1;          //if the input is invalid
						break;
					}

				}
			}
			if(valid<0)
				break;
			front++;
		}
		if(valid<0)
				break;
	  }
	 }
}
int main()
{
	int n;         //no. of players
	int r;         //no. of rival players
	int x,y,i,j;   //counter variables
	printf("Enter the number of players:");
	scanf("%d",&n);
	printf("Enter the number of pairs of players with rivalry:");
	scanf("%d",&r);
	int team[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			arr[i][j]=0;
	}
        printf("Enter the rival pairs\n");
	for(i=0;i<r;i++)
	{
	  scanf("%d %d",&x,&y);
	  arr[x-1][y-1]=1;
          arr[y-1][x-1]=1;
     }
       BFS(team,n);      //function call to separate the variables into two teams
      if(valid==-1)
    	printf("separation is not possible\n");
      else
     {
       printf("Players of team 1:");
       for(i=0;i<n;i++)
         {
          if(team[i]==1)
    	  printf("%d ",i+1);
         }
      printf("\nPlayers of team 2:");
       for(i=0;i<n;i++)
         {
          if(team[i]==-1)
    	  printf("%d ",i+1);
         }
     }
}


