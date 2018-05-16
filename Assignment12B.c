//Name-Abhishek Nautiyal
//Roll NO-1601CS02
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define V 99
int min(int a,int b)
{
	return (a>b) ? b : a;
}




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

//applyting pushrel algorithm
int pushrel(int graph[V][V],int s,int t,int rgraph[V][V])
{
    int u,v;
    // int rgraph[V][V];//making the residual graph

    // for(u=0;u<t+1;u++)
    // {
    //     for(v=0;v<t+1;v++)
    //     {
    //         rgraph[u][v]=graph[u][v];
    //     }
    // }

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
	int n=71,i,j,k,indg,indt;
	

    char city[71][25] = {"Goa","Delhi","Bangalore","Hyderabad",
                       "Ahmedabad","Chennai","Kolkata","Surat",
                       "Pune","Jaipur","Lucknow","Kanpur","Nagpur",
                       "Visakhapatnam","Indore","Thane","Bhopal",
                       "Patna","Vadodara","Ghaziabad","Ludhiana",
                       "Coimbatore","Agra","Madurai","Nashik","Faridabad",
                       "Meerut","Rajkot","Varanasi","Srinagar","Aurangabad",
                       "Dhanbad","Amritsar","NaviMumbai","Allahabad","Ranchi",
                       "Howrah","Jabalpur","Gwalior","Vijayawada","Jodhpur",
                       "Raipur","Kota","Guwahati","Chandigarh","Mumbai",
                       "Solapur","Tiruchirappalli","Bareilly","Moradabad",
                       "Mysore","Tiruppur","Gurgaon","Aligarh","Jalandhar",
                       "Bhubaneswar","Salem","Warangal","Guntur",
                       "Bhiwandi","Saharanpur","Gorakhpur","Bikaner",
                       "Amravati","Noida","Jamshedpur","Bhilai","Cuttack",
                       "Firozabad","Kochi","Thiruvananthapuram"};


    for(i=0;i<n;i++)
    {
    	city[i][0]=tolower(city[i][0]);
    }                   
    for(i=0;i<n;i++)
    {
    	// scanf("%s",city[i]);
    	if(strcmp(city[i],"goa")==0)
    	{
            indg=i;
    	}
    	if(strcmp(city[i],"thiruvananthapuram")==0)
    	{
            indt=i;
    	}
    }
    
    int graph[V][V],rgraph[V][V];
    
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		graph[i][j]=0;
    	}
    }
    for(i=0;i<n;i++)
    {
        int len1=strlen(city[i]);
        int cont1[26]={0},cut=0;
        for(k=0;k<len1;k++)
        {
            cont1[city[i][k]-97]++;
        }
        for(j=0;j<n;j++)
        {
            int len2=strlen(city[j]),r,cont=0,dist=0;
            int cont2[26]={0};
            for(r=0;r<len2;r++)
            {
                cont2[city[j][r]-97]++;
            }
            
            for(r=0;r<26;r++)
            {
                cont=cont+min(cont1[r],cont2[r]);
            }
            
            if(len2-len1==1 && cont>=1)
            {
            	graph[i][j]=2*cont;
            	cut++;
            }
        }

        if(cut==0)
        {
        	graph[i][indt]=20;
        }
    }

    for(i=0;i<n;i++)
    {   
    	int cuti=0;
    	for(j=0;j<n;j++)
    	{
    		if(graph[j][i]!=0)
    		{
    			cuti++;
    		}
    	}

    	if(cuti==0)
    	{
    		graph[indg][i]=20;
    	}
    }
    
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		rgraph[i][j]=graph[i][j];
    	}
    }
    

   
    int minf=pushrel(graph,0,n-1,rgraph);
    

    printf("The max flow is %d",minf);
    

    
    return 0;
}