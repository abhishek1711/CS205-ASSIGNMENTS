//Name-Abhishek Nautiyal
//Roll no.-1601CS02
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//making structure having detail of patient
struct patient
{
char name[100];
int time;
int hm;
};
 
struct patient record[200];//globally declaing array of patients

 //funtion to swap detail of two patient
 void swap(struct patient *a,struct patient *b)
 {
  
  struct patient temp;
  temp=*a;
  *a=*b;
  *b=temp;
 }
 
 //function to sort details of patient with respect to their time 
 void sort_time(int start,int end)
 {
  int i,j; 
  for(i=start;i<=end;i++)
  {
  for(j=i;j<=end;j++)
  {
    if(record[i].time>record[j].time)
    {
    swap(&record[i],&record[j]);
    
    }
  
  }
  }
  
  }
  
 //recursive function to sort them in way of their appointments
 void recurse(int start,int end,int init)
 {
  
  int i,count;
  if(start==(end))
    return;
  else
  {
  i=start;
  int max=-1;
  int ind=start;
    while(record[i].time<=init)
       {
        if(record[i].hm>max)
          {
          max=record[i].hm;
          ind=i;
          }
          i++;
          if(i==end+1)
            break;
       }
       if(i!=start)
       {
  int mint=record[ind].time;
  int newind=ind;
    for(count=start;count<i;count++)
    {
      if(record[count].hm==record[ind].hm)
      {
          if(record[count].time<mint)
          {
            mint=record[count].time;
            newind=count;
          }
      }
    }

    swap(&record[start],&record[newind]);
    sort_time(start+1,end);
    }
    if(i==start)
   recurse(start,end,init+1);
  else
    recurse(start+1,end,init+10);
   }
  
 }
 
 void print(int n)
  {
    int i;
    for(i=0;i<n;i++)
    {
      printf("%d. %s \n",(i+1),record[i].name);
    }
  }
int main()
{
 
 int n,i;
 printf("How many patients will come-");
 scanf("%d",&n);
 char doc[100];//taking name of doctor 
 
 printf("Enter name of patient and their time format(hr:min in 24 hour format) with space and the other patient name after entering space\n");
 for(i=0;i<n;i++)
 {
  
 int hr,min;
 char col;
 scanf("%s",record[i].name);
 
 //strcpy(record[i].name,word);
 scanf("%d%c%d",&hr,&col,&min);

 record[i].time=hr*60 + min;//converting full time into minutes 
 }
 printf("Enter name of doctor-");
 scanf("%s",doc);
 //print(n);
 int docl=strlen(doc);
 int docar[26]={0};
 for(i=0;i<docl;i++)
 {
  docar[tolower(doc[i])-97]++;
 }
 for(i=0;i<n;i++)
 {
 int check=0,l;
 int len=strlen(record[i].name);
 int arr[26]={0};
 for(l=0;l<len;l++)
 {
  arr[tolower(record[i].name[l])-97]++;
 }
 int j,f;
 for(j=0;j<26;j++)
 { 
   if(arr[j]!=0 && docar[j]!=0)
    check++;
 }
 record[i].hm=check;
 }
 for(i=0;i<n;i++)
  {
    //printf("%d\n",record[i].hm);
  }
  sort_time(0,n-1);
  printf("Shownig the name of patient in order-; \n");
  //print(n);
  recurse(0,n-1,480);

  print(n);
  return 0;
}
