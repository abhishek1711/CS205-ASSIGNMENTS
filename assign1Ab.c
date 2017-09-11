//NAME-ABHISHEK NAUTIYAL
//Roll NO-1601CS02
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char ini;
	struct node *next;
};
int b;
int br;
//swap function for interchanging data of nodes
void swap(struct node *a, struct node *b)
{   
	char kl;
    kl=a->ini;
     a->ini=b->ini;
     b->ini=kl;
}
//function to sort so that vowels are before consonants this is used when n is even
void sort(struct node *headx)
{
	struct node *lptr,*pptr;
    int q;
	for(q=0;q<b;q++)
		{
        lptr=headx;
        pptr=lptr->next;
		while(pptr!=NULL){
           if((pptr->ini=='a' || pptr->ini=='e'|| pptr->ini=='i'|| pptr->ini=='o'|| pptr->ini=='u' || pptr->ini=='A' || pptr->ini=='E'|| pptr->ini=='I'|| pptr->ini=='O'|| pptr->ini=='U') && (lptr->ini!='a' && lptr->ini!='e' && lptr->ini!='i' &&  lptr->ini!='o' && lptr->ini!='u'))
           {
                      	swap(lptr,pptr);

           }
           pptr=pptr->next;
           lptr=lptr->next;
		}
       
	}
}
//function to sort when n is odd
void sort1(struct node *head)
{
	struct node *lptr,*pptr;
    int q;
	for(q=0;q<br;q++)
		{
        lptr=head;
        pptr=lptr->next;
		while(pptr!=NULL){
           if((pptr->ini=='a' || pptr->ini=='e'|| pptr->ini=='i'|| pptr->ini=='o'|| pptr->ini=='u' || pptr->ini=='A' || pptr->ini=='E'|| pptr->ini=='I'|| pptr->ini=='O'|| pptr->ini=='U') && (lptr->ini!='a' && lptr->ini!='e' && lptr->ini!='i' &&  lptr->ini!='o' && lptr->ini!='u'))
           {
                      	swap(lptr,pptr);

           }
           pptr=pptr->next;
           lptr=lptr->next;
		}
       
	}
}
//function to print linked list
void print(struct node *headx)
{
	struct node *temp=headx;
    while(temp!=NULL)
    {
    	printf("%c->",temp->ini);
    	temp=temp->next;
    }
    printf("\b");
}
//function to check palindrome
int pal(char arrx[],int p,int h,int o)
{
	int q,x;
	for(q=h,x=o;q<x;q++,x--)
	{
		
		if(arrx[q]!=arrx[x]) return 0;
	}
	return 1;
}
int main()
{
	int n,i,j;
	printf("Enter number of students-");
	scanf("%d",&n);
	char word[30],*w[n];
	printf("\nEnter name of students-\n");
	for(i=0;i<n;i++)
	{
		scanf("%s",word);
		w[i]=(char *)malloc((strlen(word) + 1)*sizeof(char));//allocating memory to word
		strcpy(w[i],word);
	}
	//when n is even and is used to divide into two linked list and finding palindrome
	if(n%2==0)
	{   
		b=n/2;
		
		struct node *headx=NULL,*ptrx,*prevx;
		for(i=0;i<b;i++)
		{ 
		  ptrx=(struct node *)(malloc(sizeof(struct node)));//allocating memory to node
          ptrx->ini=w[i][0];
          ptrx->next=NULL;
          if(headx==NULL)
          	headx=ptrx;
          else
             prevx->next=ptrx;

            prevx=ptrx;
		}
        struct node *heady=NULL,*ptry,*prevy;
		for(i=b;i<n;i++)
		{
          ptry=(struct node *)(malloc(sizeof(struct node)));//allocating memory to node
          ptry->ini=w[i][0];
          ptry->next=NULL;
          if(heady==NULL)
          	heady=ptry;
          else
             prevy->next=ptry;

            prevy=ptry;
		}
    sort(headx);//calling sort function
    sort(heady);//calling sort function
    char arrx[b];
    int count=0;
    struct node *temp1;
    temp1=headx;
    while(temp1!=NULL)
    {
    	arrx[count]=temp1->ini;
    	count++;
    	temp1=temp1->next;
    }
    printf("Arranged linked list");
    for(i=0;i<b;i++)
    {   
    	if(i==0)
    	printf("%c",arrx[i]);
    else
    	printf("->%c",arrx[i]);
    }
    //printf("\b\b");
    int g=(b*(b-1))/2;
    int storx[g][2];
    int gunt=0;
    //for finding all palindromes
   for(i=0;i<b-1;i++)
   { 
   	for(j=i+1;j<b;j++)
   	{
   		if(pal(arrx,b,i,j)==1)
   		{
   			storx[gunt][0]=i;
   			storx[gunt][1]=j;
            
            gunt++;
   		}
         
   	}
   }


char arry[b];
    int count1=0;
    
    temp1=heady;
    while(temp1!=NULL)
    {
    	arry[count1]=temp1->ini;
    	count1++;
    	temp1=temp1->next;
    }
    printf(" and ");
    for(i=0;i<b;i++)
    {
    	if(i==0)
    	printf("%c",arry[i]);
    else
    	printf("->%c",arry[i]);
    }
    //printf("\b");
    printf("\n");
    int story[g][2];
    int  gunt1=0;
   for(i=0;i<b-1;i++)
   { 
   	for(j=i+1;j<b;j++)
   	{
   		if(pal(arry,b,i,j)==1)
   		{
   			story[gunt1][0]=i;
   			story[gunt1][1]=j;
            
            gunt1++;
   		}
         
   	}
   }
printf("\nPalindromes in the arranged linked list");
for(i=0;i<gunt;i++)
{   
	printf("\n");
	for(j=storx[i][0];j<=storx[i][1];j++)
	{   
		if(j==0)
		printf("%c",arrx[j]);
	    else
	    printf("->%c",arrx[j]);	
	}
	printf("\n");
}
//printf("\b");
for(i=0;i<gunt1;i++)
{
	for(j=story[i][0];j<=story[i][1];j++)
	{   
		if(j==0)
		printf("%c",arry[j]);
	    else
	    printf("->%c",arry[j]);	
	}
	printf("\n");
}

	}
	//when n is even and is used to divide into two linked list and finding palindrome
	else
	{
		b=n/2;
		br=(n/2)+1;
		struct node *headx=NULL,*ptrx,*prevx;
		for(i=0;i<b;i++)
		{ 
		  ptrx=(struct node *)(malloc(sizeof(struct node)));//allocating memory to node
          ptrx->ini=w[i][0];
          ptrx->next=NULL;
          if(headx==NULL)
          	headx=ptrx;
          else
             prevx->next=ptrx;

            prevx=ptrx;
		}
        struct node *heady=NULL,*ptry,*prevy;
		for(i=b;i<n;i++)
		{
          ptry=(struct node *)(malloc(sizeof(struct node)));//allocating memory to node
          ptry->ini=w[i][0];
          ptry->next=NULL;
          if(heady==NULL)
          	heady=ptry;
          else
             prevy->next=ptry;

            prevy=ptry;
		}
    sort(headx);//calling sort function
    sort1(heady);//calling sort function
    char arrx[b];
    int count=0;
    struct node *temp1;
    temp1=headx;
    while(temp1!=NULL)
    {
    	arrx[count]=temp1->ini;
    	count++;
    	temp1=temp1->next;
    }
    printf("Arranged linked list-");
    for(i=0;i<b;i++)
    {   
    	if(i==0)
    	printf("%c",arrx[i]);
    else
    	printf("->%c",arrx[i]);
    }
    printf(" and ");
    int g=(b*(b-1))/2;
    int storx[g][2];
    int gunt=0;
    //finding all palindromes
   for(i=0;i<b-1;i++)
   { 
   	for(j=i+1;j<b;j++)
   	{
   		if(pal(arrx,b,i,j)==1)
   		{
   			storx[gunt][0]=i;
   			storx[gunt][1]=j;
            
            gunt++;
   		}
         
   	}
   }


char arry[br];
    int count1=0;
    
    temp1=heady;
    while(temp1!=NULL)
    {
    	arry[count1]=temp1->ini;
    	count1++;
    	temp1=temp1->next;
    }
    for(i=0;i<br;i++)
    {
    	if(i==0)
    	printf("%c",arry[i]);
    else
    	printf("->%c",arry[i]);
    }
   // printf("\b\b");
    printf("\n");
    int story[g][2];
    int gunt1=0;
   for(i=0;i<br-1;i++)
   { 
   	for(j=i+1;j<br;j++)
   	{
   		if(pal(arry,br,i,j)==1)
   		{
   			story[gunt1][0]=i;
   			story[gunt1][1]=j;
            
            gunt1++;
   		}
         
   	}
   }
if(gunt==0 && gunt1==0)
printf("\nPalindromes in the arranged linked list");
for(i=0;i<gunt;i++)
{   
	printf("\n");
	for(j=storx[i][0];j<=storx[i][1];j++)
	{   
		if(j==0)
		printf("%c",arrx[j]);
	    else
	    printf("->%c",arrx[j]); 	
	}
	printf("\n");
}
for(i=0;i<gunt1;i++)
{   
	printf("\n");
	for(j=story[i][0];j<=story[i][1];j++)
	{
		if(j==0)
		printf("%c",arry[j]);
	    else
	    printf("->%c",arry[j]); 
	}
}

	}
	return 0;
   		}

