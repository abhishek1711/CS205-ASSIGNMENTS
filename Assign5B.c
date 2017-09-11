//Name-Abhishek Nautiyal
//Roll NO.-1601CS02

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//structure for the players
struct player{
int run;
char name[100];
int len;
};

//count sort for soting by runs
void r_sort(struct player *arr,int n,int dig)
{

struct player temp[n];
int lis[10]={0};
int i,j;
for(i=0;i<n;i++)
{
lis[(arr[i].run/dig)%10]++;
}

for(i=1;i<10;i++)
{
lis[i]=lis[i] + lis[i-1];
}

for(i=n-1;i>=0;i--)
{
temp[lis[((arr[i].run)/dig)%10]-1].run=arr[i].run;
temp[lis[((arr[i].run)/dig)%10]-1].len=arr[i].len;
strcpy(temp[lis[(arr[i].run/dig)%10]-1].name,arr[i].name);
lis[((arr[i].run)/dig)%10]--;

}

for(i=0;i<n;i++)
{
arr[i]=temp[i];
}

}

//function to do radix sort for runs
void sort(struct player *arr,int n)
{
int i,j;
int max=arr[0].run;
for(i=1;i<n;i++)
{
if(max<arr[i].run)
{
max=arr[i].run;
}
}

for(j=1;max/j>0;j=j*10)
{
r_sort(arr,n,j);

}

}


//function to sort by name by last characters by countsort
void r_sort_name(struct player *arr,int ind,int start,int end,int n)
{
int i,j;
int list[123]={0};
struct player temp[end-start+1];
for(i=start;i<=end;i++)
{
list[(arr[i].name[ind])]++;
}

for(i=1;i<123;i++)
{
list[i]=list[i] + list[i-1];
}

for(i=end;i>=start;i--)
{
strcpy(temp[list[arr[i].name[ind]]-1].name,arr[i].name);
temp[list[arr[i].name[ind]]-1].len=arr[i].len;
temp[list[arr[i].name[ind]]-1].run=arr[i].run;
list[arr[i].name[ind]]--;
}

for(i=start;i<=end;i++)
{
	arr[i]=temp[i-start];
	
}
}

//function to sort full name through radix sort
void sort_name(struct player *arr,int start,int end,int n)
{
if(start==end)
return;

else
{
int i,j;
int max=strlen(arr[start].name);
for(i=start+1;i<=end;i++)
{
if(strlen(arr[i].name)>max)
max=strlen(arr[i].name);
}

for(i=start;i<=end;i++)
{
	int len=strlen(arr[i].name);
	int dif=max-len;
	char temp[dif];
	for(j=0;j<dif;j++)
	{
		temp[j]='@';
	}
	temp[j]='\0';
	strcat(arr[i].name,temp);
    
}
for(j=max-1;j>=0;j--)
{
r_sort_name(arr,j,start,end,n);
}

for(i=start;i<=end;i++)
{
	int len=arr[i].len;
	
	arr[i].name[len]='\0';
	
}
}
}



int main()
{
int n,i;
printf("How many players are there-");
scanf("%d",&n);
struct player arr[n];
printf("enter name of player and their runs with space between them-\n");
for(i=0;i<n;i++)
{
scanf("%s %d",arr[i].name,&arr[i].run);
arr[i].len=strlen(arr[i].name);
}

sort(arr,n);//called sort function for sorting by their runs

//function till where we have to sort
for(i=0;i<n;)
{
int j=i+1;
for(;j<n ;j++)
{
	if(arr[i].run!=arr[j].run)
		break;
}

sort_name(arr,i,j-1,n);//calling sort function for sorting by name
i=j;
}


for(i=0;i<n;i++)
{
	printf("%s %d\n",arr[i].name,arr[i].run);
}
}
