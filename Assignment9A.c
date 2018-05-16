//Name-Abhishek Nautiyal
//Roll NO.-1601CS02
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


//function to find minimum
int mink(double key[],bool visit[],int n)
{
    double min=9999;
    int minind,i;
    for(i=0;i<n;i++)
    {
        if(visit[i]==false && key[i]<min)
        {
            min=key[i],minind=i;
        }
    }

    return minind;
}
int main()
{
	int n,i,j,k,m;
    printf("How many names you want to enter ");
	scanf("%d",&n);
	char name[n][100];
    printf("Enter all the names(all in small letters)\n");
    for(i=0;i<n;i++)
    {
    	scanf("%s",name[i]);
    }
     
    double sum=0;
    int arr[n][n];//for storing whether there is edge in between or not
    double cost[n][n];//for finiding the cost
    double weit[n];//for storing the cost of individual borewell in each house
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            arr[i][j]=0;
            cost[i][j]=9999;
        }
    }
    for(i=0;i<n;i++)
    {   
    	double cont1[26]={0},sum1=0;
    	for(k=0;k<strlen(name[i]);k++)
    		{
             cont1[name[i][k]-97]++;
             sum1=sum1+name[i][k];
            }

            weit[i]=(sum1/(strlen(name[i])));
    	for(j=0;j<n;j++)
    	{
    		double cont2[26]={0},dif=0,sum2=0;
   
            for(k=0;k<strlen(name[j]);k++)
            {
             cont2[name[j][k]-97]++;
             sum2=sum2+name[j][k];
            }


            for(k=0;k<26;k++)
            {
            	if(cont1[k]>=cont2[k])
            	{
            		dif=dif+cont1[k]-cont2[k];
            	}
            	else
            	{
            		dif=dif+cont2[k]-cont1[k];
            	}
            }

            if(dif==1)
    	    {
    		    arr[i][j]=1;
    		    if(sum1>sum2)
    		    {
    		    	cost[i][j]=sum1-sum2;
    		    }
    		    else
    		    	cost[i][j]=sum2-sum1;
    	    }
    	}

    	

    }

    int par[n];//for storing parent 
    double key[n];//for storing mimimum key
    bool visit[n];//for storing whether that house visited or not

    
    for(i=0;i<n;i++)
    {
        key[i]=weit[i],visit[i]=false,par[i]=-1;
    }
    
    
    double min=weit[0];
    int minind=0;
    for(i=1;i<n;i++)
    {
        if(min>weit[i])
        {
            min=weit[i],minind=i;
        }
    }
    
    
    key[minind]=weit[minind];//starting with the one which cost minimum for well
    par[minind]=-1;//if there is well at home than its parent is assigned -1 

    
    for(i=0;i<n-1;i++)
    {
        int u=mink(key,visit,n);//picking the vertex with minimum key

        visit[u]=true;
        
        for(j=0;j<n;j++)
        {
            if(cost[u][j]!=9999 && visit[j]==false && cost[u][j]<key[j])
            {
                
                {
                    par[j]=u;
                    key[j]=cost[u][j];
                }
            }
        }


    }
    

    for(i=0;i<n;i++)
    {
    	if(visit[i]==false)
    	{
    		key[i]=weit[i];
    		par[i]=-1;
    	}
    }


    for(i=0;i<n;i++)
    {
    	sum=sum+key[i];
    }
    
    

    printf("\nCost effective solution\n");
    for(i=0;i<n;i++)
    {
        if(par[i]==-1)
        {
            printf("%s -borewell is there\n",name[i]);
        }

        else
        {
        	printf("%s is getting pipeline from %s\n",name[i],name[par[i]]);
        }
    }
    
    printf("\nThe total cost is %lf",sum);

    return 0;
}



