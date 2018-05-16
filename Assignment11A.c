#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
int min(int a,int b)
{
return (a>b) ? b : a;
}
//finding the minimum vertex
int mindist(int dist[],bool vist[],int n)
{
    int minu=99999,minind,i;
    for(i=0;i<n;i++)
    {
        if(vist[i]==false && dist[i]<=minu)
        {
            minu=dist[i],minind=i;
        }
        
    }
    return minind;
}


int main()
{
    int n,i,j,k,ind1,ind2;
    int dist[n],par[n];
    bool vist[n];
    printf("Enter number of localities - ");
    scanf("%d",&n);
    char local[n][50];
    char hom[50],ofc[50];
    printf("Enter the name of localities\n");
    for(i=0;i<n;i++)
    {
        scanf("%s",local[i]);
        local[i][0]=tolower(local[i][0]);
    }
    printf("Enter name of your house and office (with space between two) - ");
    scanf("%s %s",hom,ofc);
    hom[0]=tolower(hom[0]);
    ofc[0]=tolower(ofc[0]);
    for(i=0;i<n;i++)
    {
        if(strcmp(local[i],hom)==0)
        {
            ind1=i;
        }
        if(strcmp(local[i],ofc)==0)
        {
            ind2=i;
        }
        
    }
    for(i=0;i<n;i++)
    {
        dist[i]=99999;//initializing the distance
        vist[i]=false;//initializing all as false
    }
    dist[ind1]=0;
    par[ind1]=-1;
    int weit[n][n];

    //initializing the weight matrix
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                weit[i][j]=0;
            }
            else
                weit[i][j]=99999;
        }
    }
    
    //Making the weight array
    for(i=0;i<n;i++)
    {
        int len1=strlen(local[i]);
        int cont1[26]={0};
        for(k=0;k<len1;k++)
        {
            cont1[local[i][k]-97]++;
        }
        for(j=0;j<n;j++)
        {
            int len2=strlen(local[j]),r,cont=0,dist=0;
            int cont2[26]={0};
            for(r=0;r<len2;r++)
            {
                cont2[local[j][r]-97]++;
            }
            
            for(r=0;r<26;r++)
            {
                cont=cont+min(cont1[r],cont2[r]);
            }
            
            int len=min(len1,len2);
            for(r=0;r<len;r++)
            {
                dist=dist+abs(local[i][r]-local[j][r]);
            }
            
            if(len1>=len2)
            {
                for(r=len;r<len1;r++)
                {
                    dist=dist+local[i][r];
                }
            }
            
            else
            {
                for(r=len;r<len2;r++)
                {
                    dist=dist+local[j][r];
                }
            }
            
            if(len2-len1==1 && cont>=1)
            {
                weit[i][j]=dist;
            }
            else if(len2-len1==2 && cont>=2)
            {
                weit[i][j]=dist;
            }
        }
        
    }
    
    // printf("The distance matrix is\n");
    // for(i=0;i<n;i++)
    // {
    //     for(j=0;j<n;j++)
    //     {
    //         printf("%d ",weit[i][j]);
    //     }
    //     printf("\n");
    // }
    
    //finding the minimum path by using dijkstra
    for(i=0;i<n-1;i++)
    {
        int u=mindist(dist,vist,n);
        
        vist[u]=true;
        
        for(j=0;j<n;j++)
        {
            if(!vist[j] && weit[u][j]!=99999 && dist[u]!=99999 && dist[u] + weit[u][j] < dist[j])
            {
                dist[j]=dist[u]+weit[u][j];
                par[j]=u;
            }
        }
    }
    

    //finding the path using parent matrix.
    if(dist[ind2]!=99999)
    {   
        int cut=0;
        int pth[n+1];
        i=par[ind2];
        while(i!=-1)
        {
           pth[cut]=i;
           i=par[i];
           cut++; 
        }
        printf("The path is - \n");
        for(i=cut-1;i>=0;i--)
        {
        printf("%s ",local[pth[i]]);
        }   
        printf("%s\n",local[ind2] );   

        printf("The cost is %d",dist[ind2]);  
    }

    else
    {
        printf("No path exists");
    }
    
    
}
