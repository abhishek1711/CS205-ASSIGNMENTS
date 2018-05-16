//Name-Abhishek Nautiyal
//Roll no.-1601CS02
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
bool vist[100];

//finding minimum index 
int minu(int n,int u,int graph[][n])
{
	int i,j,min=99999,minind=-1;

	for(i=0;i<n;i++)
	{
		if(vist[i]==false && min>graph[u][i])
		{
			min=graph[u][i],minind=i;
		}
	}

	return minind;
}

int main()
{
	int v=8,i,j,k;
	char city[][1000]={
                       {"MA chidambaram Stadium,Chennai"},
                       {"Eden Gardens,Kolkata"},
                       {"Holkar Cricket Stadium,Indore"},
                       {"M.Chinnaswamy Stadium,Bengaluru"},
                       {"Vidarbha Cricket Association Ground,Nagpur"},
                       {"JSCA International Stadium Complex,Ranchi"},
                       {"Barsapara Cricket Stadium,Guwahati"},
                       {"Rajiv Gandhi Interanational Stadium,Hyderabad"}
	                  };

	int graph[][8]={
                    {0,1400,1200,300,900,1300,1900,500},
                    {1400,0,1300,1600,1000,300,500,1200},
                    {1200,1300,0,1100,400,1000,1600,700},
                    {300,1600,1100,0,900,1400,2100,500},
                    {900,1000,400,900,0,700,1400,400},
                    {1300,300,1000,1400,700,0,700,1000},
                    {1900,500,1600,2100,1400,700,0,1600},
                    {500,1200,700,500,400,1000,1600,0}
	                };

	// int graph[][8]={
 //                    {0,1678,1172,284,910,1234,1885,520},
 //                    {1678,0,1286,1559,980,325,528,1180},
 //                    {1172,1286,0,1100,383,973,1697,653},
 //                    {284,1559,1100,0,925,1415,2075,499},
 //                    {910,980,383,925,0,891,1392,423},
 //                    {1234,325,973,1415,891,0,713,973},
 //                    {1885,528,1697,2075,1392,713,0,2447},
 //                    {520,1180,653,499,423,973,2447,0}
	//                 };

//applying floyd warshall
    for(k=0;k<v;k++)
    {
    	for(i=0;i<v;i++)
    	{
    		for(j=0;j<v;j++)
    		{
    			if(graph[i][j]>graph[i][k] + graph[k][j])
    			{
    				graph[i][j]=graph[i][k] + graph[k][j];
    			}
    		}
    	}
    }

    int cost[8]={0};
    int mincost=99999,mini;
    //finding path
    int pth[v][v];

   //finding minimum cost and path
   for(i=0;i<v;i++)
      {   

    	int cont=0;
    	
    	
    	for(j=0;j<v;j++)
    	{
    		vist[j]=false;
    	}
         
        int qu[1000],front=-1,rear=-1; 
    	vist[i]=true;
        front=0;
        qu[++rear]=i;

        while(front<=rear)
        {   
        	int u=qu[front];
        	
        	front++;	
        	pth[i][cont]=u;
        	cont++;

        	int p=minu(v,u,graph);

        	if(p==-1)
             break;
        
        	else
        	{   
        		vist[p]=true;
        		cost[i]=cost[i] + graph[u][p];
        		qu[++rear]=p;
        	}

        }

        
    	if(mincost>cost[i])
    	{
    		mincost=cost[i];
    		mini=i;
    	} 

    }
    
    printf("The path that it will take is\n");
    for(i=0;i<v;i++)
    {
    	printf("%s\n",city[pth[mini][i]]);
    }

    printf("The total cost is %d",mincost);
}