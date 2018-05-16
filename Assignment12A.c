//Name-Abhishek Nautiyal
//Roll NO.1601CS02

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 99

int mini(int a,int b)
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

//applyting ford-fullkerson algorithm
int fordfuk(int graph[V][V],int s,int t,int rgraph[V][V])
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
    printf("Enter how many comapnies and how many candidates are there - ");
    int n,m,i,j,k,t;
    scanf("%d %d",&n,&m);
    char compnam[n][50];
    char candnam[m][50];
    int graph[V][V],rgraph[V][V];

    int storpth[V][2];
    for(i=0;i<n+m+2;i++)
    {
        for(j=0;j<n+m+2;j++)
        {
            graph[i][j]=0;
        }
    }
    printf("Enter the name of companies(in small letters without space)\n");

    for(i=0;i<n;i++)
    {
        scanf("%s",compnam[i]);
    }
    
    printf("Enter the name of candidates(in small letters without space)\n");
    for(i=0;i<m;i++)
    {
        scanf("%s",candnam[i]);
    }
    
    for(i=1;i<=m;i++)
    {
        graph[0][i]=1;
    }
    
    for(i=m+1;i<=m+n;i++)
    {
        graph[i][m+n+1]=1;
    }
    
    // for(i=0;i<n+m+2;i++)
    // {
    //     for(j=0;j<n+m+2;j++)
    //     {
    //         printf("%d ",graph[i][j]);
    //     }
    //     printf("\n");
    // }
    
    
    printf("\n\n");
    for(i=0;i<m;i++)
    {   
        int cont1[26]={0};
        int len1=strlen(candnam[i]);
        for(k=0;k<len1;k++)
        {   
            cont1[candnam[i][k]-97]++;
        }
        for(j=0;j<n;j++)
        {
            int cont2[26]={0},cot=0;
            int len2=strlen(compnam[j]);
            for(t=0;t<len2;t++)
            {
                cont2[compnam[j][t]-97]++;
            }
            
            for(t=0;t<26;t++)
            {
                cot=cot+mini(cont1[t],cont2[t]);
            }
            
            if(cot>=2)
            {
                graph[i+1][j+m+1]=1;
            }
        }
    }
    
    
    // for(i=0;i<n+m+2;i++)
    // {
    //     for(j=0;j<n+m+2;j++)
    //     {
    //         printf("%d ",graph[i][j]);
    //     }
    //     printf("\n");
    // }
    
    for(i=0;i<n+m+2;i++)
    {
        for(j=0;j<n+m+2;j++)
        {
            rgraph[i][j]=graph[i][j];
        }
        // printf("\n");
    }
    int minf=fordfuk(graph,0,n+m+1,rgraph);

    // printf("\n\n");
    // for(i=0;i<n+m+2;i++)
    // {
    //     for(j=0;j<n+m+2;j++)
    //     {
    //         printf("%d ",rgraph[i][j]);
    //     }
    //     printf("\n");
    // }
    int cot=0;
    for(i=1;i<=m;i++)
    {
        for(j=m+1;j<=n+m;j++)
        {
            if(rgraph[j][i]==1)
            {
                storpth[cot][0]=i;
                storpth[cot][1]=j;
                cot++;
            }
        }
    }
    
    printf("Maximum number of candidates that get selected are %d\n\n",minf);
    printf("CANDNIDATE NAME---COMPANY THAT CHOSES THEM\n");
    for(i=0;i<cot;i++)
    {
        printf("%s---%s\n",candnam[storpth[i][0]-1],compnam[storpth[i][1]-m-1]);
    }

    return 0;
}
