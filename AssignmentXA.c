//Name-Abhishek Nautiyal
//Roll NO.-1601CS02
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
    int n,i,j,k,d;
    printf("How many students are there - ");
    scanf("%d",&n);
    char stud[n][25];//storing name of student
    printf("Enter the name of students\n");
    for(i=0;i<n;i++)
    {
        scanf("%s",stud[i]);
    }
    printf("\nEnter the predefined threshold distance - ");
    scanf("%d",&d);
    int arr[n][n];
    int weit[n][n];
    int ascsum[n];
    int narr[n][n];
    //finding ascii sum of all words
    for(i=0;i<n;i++)
    {
        int len1=strlen(stud[i]),sum=0;
        for(j=0;j<len1;j++)
        {
            sum=sum+stud[i][j];
        }

        ascsum[i]=sum;
    }

    //initializing distance array
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {   
            if(i==j)
            {
                weit[i][j]=0,arr[i][j]=1,narr[i][j]=-1;
            }
            else
            {
                weit[i][j]=99999,arr[i][j]=-1,narr[i][j]=-1;
            }

            
        }
    }
    
    //finding whether there is edge between words and also weight of edge
    for(i=0;i<n;i++)
    {   
        for(j=0;j<n;j++)
        {  
            int sumo=0,cont=0;
            for(k=0;k<5;k++)
            {   
                sumo=sumo + abs(stud[i][k]-stud[j][k]); 
                if(stud[i][k]==stud[j][k])
                {
                    cont++;
                }

            }
            
            if(cont==4)
            {
                //arr[i][j]=1;
                weit[i][j]=sumo;
                weit[j][i]=sumo;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {   
            if(i!=j)
            {
            if(weit[i][j]<d && ascsum[j]>ascsum[i])
            {
                weit[i][j]=weit[i][j];
            }
            else
            {
                weit[i][j]=99999;
            }
            }
        }
    }

    
    
    //applying floyyd warshall algorithm
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(weit[i][j]>weit[i][k] + weit[k][j])
                {
                    weit[i][j]=weit[i][k] + weit[k][j];
                }
            }
        }
    }
    
    printf("The cost matrix is \n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",weit[i][j]);
        }
        printf("\n");
    }
    
    //This tells only those access details which satisfy direct condition but not indirect
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(weit[i][j]<d && ascsum[j]>ascsum[i])
            {
                arr[i][j]=1;
            }
        }
    }
    

    
    for(i=0;i<n;i++)
    {   
        int cont=0;
        printf("%s will be able to be accesed by - ",stud[i]);
        for(j=0;j<n;j++)
        {
            if(arr[i][j]==1 )
            {
                printf("%s ",stud[j]);
                cont++;
            }
        }
        if(cont==0)
        {
            printf("No one access %s account",stud[i]);
        }
        printf("\n");
    }
}