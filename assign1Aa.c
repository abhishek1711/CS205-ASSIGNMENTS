//NAME-ABHISHEK NAUTIYAL
//ROLL NO.-1601CS02

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
struct node
{
	char word[100];
	int refno;
	struct node *next;

};
//swap function for changing the data of nodes
void swap(struct node *a, struct node *b)
{   
	char temp[100];
    strcpy(temp,a->word);
     strcpy(a->word,b->word);
     strcpy(b->word,temp);
     int g;
     g=a->refno;
     a->refno=b->refno;
     b->refno=g;

}
//function to sort the nodes in lexicographically
void sort(struct node *head)
{  

	struct node *lptr=head,*ptr1;
	
	int i;
   while(lptr!=NULL){
   	ptr1=lptr->next;
   	while(ptr1!=NULL)
   	{
     if(strcmp(lptr->word,ptr1->word) > 0)
     {
     	swap(lptr,ptr1);
     }
       ptr1=ptr1->next;
   	}
   	lptr=lptr->next;
   }
}
int main()
{   printf("Enter no. of student-");
	int i;
    scanf("%d",&n);//n is number of words
    char word[100], *w[n];
    printf("Enter name of student-\n");
    for(i=0;i<n;i++)
    {
    	scanf("%s",word);
    	w[i]=(char *)malloc((strlen(word)+1)*sizeof(char));//allocating memory to words
    	strcpy(w[i],word);
    }
    int arr[n];
    //this loop is for getting the part of student's name.
    for(i=0;i<n;i++)
    	{   
    		int len2;
    		int len=strlen(w[i]);
    		int len1;//lenght of  word
    		int t=0;
    		int j;
    		for(j=0;j<n;j++)
    		{   
    			int temp;
    			if(j!=i){
    				len1=strlen(w[j]);
    				
    				if(len1>len)
    					len2=len1;
    				else
    					len2=len;
                    int k;
                for(k=0;k<len2;k++){
                	if((w[i][k] != w[j][k]) || k==len2-1){
                		temp=k;
                	
                	break;
                }
                }
    			}
    			 /*if(temp==len2)
    			 {
    			 	if(len>len1)
    			 	{
    			 		t=len2+1;
    			 	}
    			}*/
    			if(temp>t)
    			{
    				t=temp;
    			}

    		}
           
    		arr[i]=t;

    	}
    	char *w1[n];
    	for(i=0;i<n;i++)
    		{
    			w1[i]=(char *)malloc((arr[i] + 1)*sizeof(char));//allocating memory to the word
    			int j;
    			for(j=0;j<=arr[i];j++)
    			w1[i][j]=w[i][j];
    		}
    		

    struct node *head=NULL,*p,*prev;
        for(i=0;i<n;i++)
        {
          p=(struct node*)malloc(sizeof(struct node));
          
          strcpy(p->word,w1[i]);
         
          p->next=NULL;
          p->refno=i;
          if(head==NULL)
          	head=p;
          else
          	prev->next=p;
        
        prev=p;
        }
        sort(head);
        
        struct node *temp;
        temp=head;
        printf("\nSorted parts of students name-");
        while(temp!=NULL)
        {   
        	if(temp==head)
        	{
        		printf("%s",temp->word);
        	}
        	else
        	printf(",%s",temp->word);
        	temp=temp->next;
        }
        printf("\b");
        
      
       // printf("\n");
       printf("\nSorted student name: ");
       temp=head;
        for(i=0;i<n;i++)
        {
        	printf("%s,",w[temp->refno]);
        temp=temp->next;
        }
        printf("\b");
	return 0;
}

