//Name-Abhishek Nautiyal
//Roll No.-1601CS02
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


#define V 99 

//Applying the bfs for finding is there any path and also the parent of the vertices if their is path from "s to t"
bool bfs(int rgraph[V][V],int s,int t,int par[])
{
	bool visit[V];
	memset(visit,0,sizeof(visit));

	int arr[100],front=-1,rear=-1;
	front=0;
	arr[++rear]=s;
	visit[s]=true;
	par[s]=-1;

	while(front<=rear)
	{
		int u=arr[front];
		front++;

		for(int v=0;v<t+1;v++)
		{
			if(visit[v]==false && rgraph[u][v]>0)
			{
				arr[++rear]=v;
				par[v]=u;
				visit[v]=true;
			}
		}
	}

	return (visit[t]==true);
}

//applyting ford-fullkerson algorithm
int fordfuk(int graph[V][V],int s,int t)
{
	int u,v;
	int rgraph[V][V];//making the residual graph

	for(u=0;u<t+1;u++)
	{
		for(v=0;v<t+1;v++)
		{
			rgraph[u][v]=graph[u][v];
		}
	}

	int par[V];//making the par array for finding the parent
    
    int max_flow=0;

    while(bfs(rgraph,s,t,par))
    {
    	int path_flow=99999;
    	for(v=t;v!=s;v=par[v])
    	{
    		u=par[v];
    		if(path_flow>rgraph[u][v])
    		{
    			path_flow=rgraph[u][v];
    		}
    	}


    	for(v=t;v!=s;v=par[v])
    	{
    		u=par[v];
    		rgraph[u][v]-=path_flow;
    		rgraph[v][u]+=path_flow;
    	}

    	max_flow+=path_flow;
    }

    return max_flow;
}

int main()
{
	int n,i,j;
	printf("Enter the value of  - ");
	scanf("%d",&n);

	int graph[V][V];
    
    for(i=0;i<n+2;i++)
    {
    	for(j=0;j<n+2;j++)
    	{
    		graph[i][j]=0;
    		//arr[i][j]=0;
    	}
    }

    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
    	{
    		if(j-i>0 && j-i<=3)
    		{
    			//arr[i][j]=1;
    			graph[i][j]=i+j;
    		}
    	}
    }

    for(i=1;i<=n/4;i++)
    {
    	///arr[0][i]=1;
    	//arr[i][0]=1;
    	graph[0][i]=i;
    	//graph[i][0]=i;
    }

    for(i=((3*n)/4);i<=n;i++)
    {
    	//arr[i][n+1]=1;
    	graph[i][n+1]=i;
    }



    int minf=fordfuk(graph,0,n+1);   

    printf("The maximum flow is %d",minf);               
}


