//NAME-Abhishek Nautiyal
//Roll No.1601CS02
#include <stdio.h>
//Structure to make matrix
struct matrix{
int array[100][100];
};

//Function to do partition of arrays in 4 parts
struct matrix partition(struct matrix a,int row,int col,int brk)
{   
	int i,j;
	struct matrix temp;
	for(i=0;i<brk;i++)
	{
		for(j=0;j<brk;j++)
		{
          temp.array[i][j]=a.array[i+row][j+col];
		}
	}

	return temp;
}
//Function to add two matrix
struct matrix add(struct matrix a,struct matrix b,int starta,int enda,int startb,int endb)
{   
	struct matrix temp;
	int i,j;
	int counti=enda-starta;
	int countj;
	for(i=0;i<counti;i++)
	{
		for(j=0;j<counti;j++)
		{
			temp.array[i][j]=a.array[i][j] + b.array[i][j];
		}
	}

	return temp;//returning structure
}

//recursive function to multiply matrices by dividing it into 4 parts
struct matrix multiply(struct matrix matrixa,struct matrix matrixb,int n)
  { 
  	int i,j,k;
  	
  	//basis when it reaches to n=2;
  	if(n==1)
  	{    
  		struct matrix tempi;
  		tempi.array[0][0]=(matrixa.array[0][0] * matrixb.array[0][0])  ;
  		
        
        return tempi;
  	}

  	else
  	{
        int k=n/2;
        struct matrix a11,a12,a21,a22;
        struct matrix b11,b12,b21,b22;
        struct matrix c11,c12,c21,c22;
        struct matrix temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp;
        
        struct matrix tempc;
        //partioning the matrix A;
        a11=partition(matrixa,0,0,k);
        
        a12=partition(matrixa,0,k,k);
         
        a21=partition(matrixa,k,0,k);
       
        a22=partition(matrixa,k,k,k);
        
        //partioning the matrix B;
        b11=partition(matrixb,0,0,k);
        b12=partition(matrixb,0,k,k);
        b21=partition(matrixb,k,0,k);
        b22=partition(matrixb,k,k,k);
        
        //Multiplying parts of matrices
        temp1=multiply(a11,b11,k);
        temp2=multiply(a12,b21,k);
        temp3=multiply(a11,b12,k);
        temp4=multiply(a12,b22,k);
        temp5=multiply(a21,b11,k);
        temp6=multiply(a22,b21,k);
        temp7=multiply(a21,b12,k);
        temp8=multiply(a22,b22,k);
        
        //Adding parts of matrices into another matrice
       
        for(i=0;i<k;i++)
        {
    	  for(j=0;j<k;j++)
    	  {
    		c11.array[i][j] = temp1.array[i][j]+temp2.array[i][j];//taking input of matrix B
    	  }
    	  
        }
        for(i=0;i<k;i++)
        {
    	  for(j=0;j<k;j++)
    	  {
    		c12.array[i][j] = temp3.array[i][j]+temp4.array[i][j];//taking input of matrix B
    	  }
    	  
        }
        for(i=0;i<k;i++)
        {
    	  for(j=0;j<k;j++)
    	  {
    		c21.array[i][j] = temp5.array[i][j]+temp6.array[i][j];//taking input of matrix B
    	  }
    	  
        }
        for(i=0;i<k;i++)
        {
    	  for(j=0;j<k;j++)
    	  {
    		c22.array[i][j] = temp7.array[i][j]+temp8.array[i][j];//taking input of matrix B
    	  }
    	  
        }
        //function to add all the parts to the main matrice that will be formed after multiplying the matrices.
        for(i=0;i<k;i++)
        {
        	for(j=0;j<k;j++)
        	{
              temp.array[i][j]=c11.array[i][j];
              
        	}
        }
        for(i=0;i<k;i++)
        {
        	for(j=0;j<k;j++)
        	{
              temp.array[i][j+k]=c12.array[i][j];
              
        	}
        }
        for(i=0;i<k;i++)
        {
        	for(j=0;j<k;j++)
        	{
              temp.array[i+k][j]=c21.array[i][j];
              
        	}
        }
        for(i=0;i<k;i++)
        {
        	for(j=0;j<k;j++)
        	{
              temp.array[i+k][j+k]=c22.array[i][j];
              
        	}
        }
        return temp;
  	}
  }
int main()
{
	int n,i,j;
	printf("Enter size of matrice-");
	scanf("%d",&n);
	struct matrix matrixa,matrixb,matrixc;//making 2-d arrays for matrix
    printf("Enter elements of matrixA give space between each row element and ata the end of each row press enter\n");
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		scanf("%d",&matrixa.array[i][j]);//taking input of matrix A
    	}
    }
    printf("Enter elements of matrixA give space between each row element and ata the end of each row press enter\n");
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		scanf("%d",&matrixb.array[i][j]);//taking input of matrix B
    	}
    }

    
   matrixc=multiply(matrixa,matrixb,n);
   printf("Matrix formed after multiplying two matrices A and B\n");
   for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		printf("%d ",matrixc.array[i][j]);//taking input of matrix B
    	}
    	printf("\n");
    }

}