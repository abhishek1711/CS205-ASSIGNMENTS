//Name-Abhishek Nautiyal
//Roll NO-1601CS02

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int mini(int a,int b,int c)
{
	int temp=(a<b) ? a : b;
	int min=(c<temp) ? c : temp;

	return min;
}

int main()
{
	int n,i,j,e,k;
	printf("Enter number of localities - " );
	scanf("%d",&n);
	char city[n][100];
	printf("Enter the name of localities\n");
    for(i=0;i<n;i++)
    {
    	scanf("%s",city[i]);
    }
    printf("Enter how many edges are there  - ");
    scanf("%d",&e);
    
    printf("Enter the both the vetices of the edges and its traffic\n");
    
    double time[n][n];
    //memset(time,99999,sizeof(time));
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		time[i][j]=99999;
    	}
    }
    for(i=0;i<n;i++)
    {
    	time[i][i]=0;
    }
    for(i=0;i<e;i++)
    {
    	char a[25],b[25];
    	double traf;
    	scanf("%s %s %lf",a,b,&traf);
    	int ind1,ind2,j,k,len1=strlen(a),len2=strlen(b);
        int dp[len1+1][len2+1];//for finding edit distance
        
        for(j=0;j<n;j++)
        {
        	if(strcmp(city[j],a)==0)
        	{
        		ind1=j;
        	}
        	if(strcmp(city[j],b)==0)
        	{
        		ind2=j;
        	}
        }
        for(j=0;j<=len1;j++)
        {
        	for(k=0;k<=len2;k++)
        	{
        		if(j==0)
        		{
        			dp[j][k]=k;
        		}

        		else if(k==0)
        		{
        			dp[j][k]=j;
        		}

        		else if(a[j-1]==b[k-1])
        		{
        			dp[j][k]=dp[j-1][k-1];
        		}

        		else
        		{
        			dp[j][k]=1+mini(dp[j][k-1],dp[j-1][k],dp[j-1][k-1]);
        		}

        	}
        }

        time[ind1][ind2]=dp[len1][len2]*traf;
        time[ind2][ind1]=dp[len1][len2]*traf;
    }


    double ntime[n][n];//time matrix containing all the minimum times between nodes
    
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		ntime[i][j]=time[i][j];//initializing the matrix
    	}
    }
    

    int pth[n][n];//matrix for finding the path
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		if(i!=j && time[i][j]!=99999)
    		{
    			pth[i][j]=i;
    			pth[j][i]=j;
    		}
    		else
    			pth[i][j]=-1;
    	}
    }
    
    //floyyd warshall algorithm
    for(k=0;k<n;k++)
    {
    	for(i=0;i<n;i++)
    	{
    		for(j=0;j<n;j++)
    		{
    			if(ntime[i][k] + ntime[k][j] < ntime[i][j])
    			{
    				ntime[i][j]=ntime[i][k] + ntime[k][j];
    				pth[i][j]=pth[k][j];
    			}
    		}
    	}
    }


    bool visit[n];
    int src[n];
    
    for(i=0;i<n;i++)
    {
    	visit[i]=false,src[i]=-1;
    }


    

   
    for(i=0;i<n-1;i++)
    {
    	int cont=0,ind;
    	//always calculating the index with maximum reachable localities
        for(j=0;j<n;j++)
        {   
        	int cot=0;
        	if(visit[j]==false)
        	{
        		for(k=0;k<n;k++)
        		{
        			if(visit[k]==false && ntime[j][k]<30)
        			{
        				cot++;
        			}

        		}
        	}
            if(cot>cont)
            {
            	cont=cot,ind=j;
            }
        }
        
        if(cont!=0)
        {
        	visit[ind]=true;
            src[ind]=-1;
            for(j=0;j<n;j++)
            {
        	    if(visit[j]==false && ntime[ind][j]<30)
        	    {
        		    src[j]=ind;
        		    visit[j]=true;
        	    }
            }
        }
        
    }
    
    
    printf("The localities where restaurants is made are - ");
    for(i=0;i<n;i++)
    {
    	if(src[i]==-1)
    	{
    		printf("%s ",city[i]);
    	}
    }
    printf("\n");
    

    //This is finding paths between the source and destination
    printf("The paths are -\n");
    for(i=0;i<n;i++)
    {
    	if(src[i]==-1)
    	{
    		int strt=i;
    		
    		for(j=0;j<n;j++)
    		{   
    			int cut=0,arr[n],dest;
    			if(j!=strt && src[j]==strt)
    			{
    				dest=j;

    				arr[cut]=dest;
                    cut++;
                    while(dest!=strt)
                    {
                 	    arr[cut]=pth[strt][dest];
                 	    dest=pth[strt][dest];
                 	    cut++;
                    }
                
                    for(k=cut-1;k>=0;k--)
                    {
                	    printf("%s ",city[arr[k]]);
                    }

                    printf("\n");
    			}
                
                

    		}
    	}
    	
    }
    

}