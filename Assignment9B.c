//Name-Abhishek Nautiyal
//Roll NO-1601CS02

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
//function which is finding minimum index
int findmin(double dist[],bool sptset[],int v)
{
	double min=99999;
	int ind,u;
	for(u=1;u<=v;u++)
	{
		if(sptset[u]==false && dist[u]<=min)
		{
			min=dist[u],ind=u;
		}
	}

	return ind;
}

int main()
{
	printf("How many edges and vertices are there- ");
	int e,v,i,j,x,y;
	scanf("%d %d",&e,&v);

	double mat[v+1][v+1];
	//memset(mat,-1,sizeof(mat));
	for(i=0;i<=v;i++)
	{
		for(j=0;j<=v;j++)
		{
			mat[i][j]=-1;
		}
	}
	printf("Enter the edge and then its probability-");
    

	for(i=0;i<e;i++)
	{
		int a,b;
		double prob;
		scanf("%d %d %lf",&a,&b,&prob);
		mat[a][b]=-1*log(prob);
    }

    printf("Enter the vertices in which you want to find most reliable path");
    scanf("%d %d",&x,&y);


    double dist[v+1];//distance from source to i;
    int par[v+1];
    bool sptset[v+1];

    for(i=0;i<=v;i++)
    {
    	dist[i]=99999,sptset[i]=false;
    }

    dist[x]=0;
    par[x]=99999;//applying dijkstra's algorithm
    for(i=1;i<=v;i++)
    {
    	int u=findmin(dist,sptset,v);//picking the minimum distance vertex

    	sptset[u]=true;//vertex has now been visited

    	int g;

    	for(g=1;g<=v;g++)
    	{
    		if(!sptset[g] && mat[u][g] != -1 && dist[u] != 99999 && dist[u] + mat[u][g] < dist[g])
    		{
    			par[g]=u;
    			dist[g]=dist[u]+mat[u][g];
    		}
    	}
    }
    i=par[y];
    int pth[v+1];
    int cut=0;
    
    while(i!=99999)
    {   
    	pth[cut]=i;
    	i=par[i];
    	cut++;
    }

    
    
    printf("The path is  ");
    for(i=cut-1;i>=0;i--)
    {
    	printf("%d ",pth[i]);
    }
    printf("%d",y);
    
}