//Name-Abhishek Nautiyal
//Roll no.1601CS02
#include <stdio.h>
#include <string.h>
#include <math.h>
//Function to convert number from decimal to binary
void dec_to_bin(char *arra,int a)
{
	int temp=a,count=0;
	while(temp!=0)
	{
	if(temp%2==0)
	  {
       arra[count]='0';
	   }
	else
       arra[count]='1';
     count++;
     temp=temp/2;
    }
    int start=0,end=count-1;  
    arra[count]='\0';
    
}
//Function to make the binary numbers equal
void make_equal(char *arra,char *arrb)
{   
	int i;
	//when first number has more digits then second
	if(strlen(arra)>strlen(arrb))
	{
		int dif=strlen(arra)-strlen(arrb);
		for(i=strlen(arrb)-1;i>=0;i--)
		{
			arrb[i+dif]=arrb[i];
		}
		for(i=0;i<dif;i++)
		{
         arrb[i]='0';
		}
		arra[strlen(arra)]='\0';
		arrb[strlen(arra)]='\0';
	}
    //when second number has more digits then first
	if(strlen(arrb)>strlen(arra))
	{
		int dif=strlen(arrb)-strlen(arra);
		for(i=strlen(arra)-1;i>=0;i--)
		{
			arra[i+dif]=arra[i];
		}
		for(i=0;i<dif;i++)
		{
         arra[i]='0';
		}
		arra[strlen(arrb)]='\0';
		arrb[strlen(arrb)]='\0';
	}
}

//Function to add two binary
void add(char *a,char *b,char *sum)
{
   
   make_equal(a,b);
   char arr[100];
   int cut=0;
   int len=strlen(a);
   int i,carry=0;
   for(i=len-1;i>=0;i--)
   {
      int x=(a[i]-'0') + (b[i]-'0') + carry;
      if(x%2==0)
      arr[cut]='0';
      else
      	arr[cut]='1';
      carry=x/2;

      cut++;
   }
   if(carry!=0)
   {
   arr[cut]='1';

   for(i=0;i<=cut;i++)
   {
   	sum[i]=arr[cut-i];
   }
    sum[cut+1]='\0';
}
else
  {
  	for(i=0;i<cut;i++)
   {
   	sum[i]=arr[cut-i-1];
   }
   sum[cut]='\0';
  }
   
}
//function to multiply binary numbers using divide and conquer
int multiply(char *arra,char *arrb)
{   

    make_equal(arra,arrb);
	int n=strlen(arra);//finding length of binary number
	if(n==0)
	{
      return 0;
	}
	else if(n==1)
	{
		return ((arra[0] -'0')*(arrb[0]-'0'));
	}
	else
	{
	int k=n/2;
    char suma[100],sumb[100];
	char la[100],ra[100],lb[100],rb[100];
    int i;
	for(i=0;i<k;i++)
	{
		la[i]=arra[i];
		lb[i]=arrb[i];
	}
    la[k]='\0';
    lb[k]='\0';
    for(i=0;i<n-k;i++)
    {
    	ra[i]=arra[i+k];
    	rb[i]=arrb[i+k];
    }
    ra[n-k]='\0';
    rb[n-k]='\0';
    add(la,ra,suma);
    add(lb,rb,sumb);
    int p1=multiply(la,lb);//recursively calling on left part
    int p2=multiply(ra,rb);//recursively callng on right part
    int p3=multiply(suma,sumb);//recursively calling on middle part
    
    return(p1*pow(2,2*((n+1)/2 ))+ (p3-p1-p2)*pow(2,(n+1)/2) + p2);//returning the multiplication
    }

}
int main()
{
	int a,b,i;
	printf("Enter first and second number in decimal form giving space between two numbers--");
	scanf("%d %d",&a,&b);
	char arra[100];
	char arrb[100];
	char reva[100];
	char revb[100];
	//char arrc[100];
    dec_to_bin(arra,a);
	dec_to_bin(arrb,b);
	for(i=0;i<strlen(arra);i++)
    {
    	reva[i]=arra[strlen(arra)-1-i];
    }
    reva[strlen(arra)]='\0';
    for(i=0;i<strlen(arrb);i++)
    {
    	revb[i]=arrb[strlen(arrb) - 1-i];
    }
    revb[strlen(arrb)]='\0';
    
    make_equal(reva,revb);//making binary equal
	/*printf("\n");
    
    for(i=0;i<strlen(reva);i++)
    {
    	printf("%d",reva[i]-48);
    }
	printf("\n");
	for(i=0;i<strlen(revb);i++)
    {
    	printf("%d",revb[i]-48);
    }
   printf("\n");*/

    int prod=multiply(reva,revb);//getting the product
   
   printf("Product of numbers is=");
   printf("%d",prod);
}