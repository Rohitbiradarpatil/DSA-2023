#include<stdio.h>
void read(int (*arr)[100],int (*arr1)[100],int a,int b,int c,int d)
{
printf("ENTER THE ELEMENTS OF AN ARRAY\n");
 for(int i=0;i<a;i++)
 {
 for(int j=0;j<b;j++)
 {
   scanf("%d",&*(*(arr+i)+j));
 }
}
 for(int i=0;i<c;i++)
 {
 for(int j=0;j<d;j++)
 {
   scanf("%d",&*(*(arr1+i)+j));
 }
}

}
 void display(int (*arr)[100],int (*arr1)[100],int a,int b,int c,int d)
{
 for(int i=0;i<a;i++)
 {
 for(int j=0;j<b;j++)
 {
  printf("%d\t",*(*(arr+i)+j));
 }
 printf("\n");
 }
  for(int i=0;i<c;i++)
 {
 for(int j=0;j<d;j++)
 {
  printf("%d\t",*(*(arr1+i)+j));
 }
 printf("\n");
 }


}
 void display1(int (*arr2)[100],int a,int d)
{ printf("MULTIFIED ARRAY IS \n");
 for(int i=0;i<a;i++)
 {
 for(int j=0;j<d;j++)
 {
  printf("%d\t",*(*(arr2+i)+j));
 }
 printf("\n");
 }

}
void mul(int (*arr)[100],int (*arr1)[100],int a,int b,int c)
{
int arr2[a][100],sum=0;
int (*q)[100];
q=arr2;
  for(int i=0;i<a;i++)
 {
 for(int j=0;j<b;j++)
 {
 for(int k=0;k<c;k++)
 {
  printf("1=%d\t2=%d\n",*(*(arr+i)+k), (*(*(arr1+k)+j)));
 sum=sum+((*(*arr+i)+k))*(*(*arr1+k)+j);
 }
 *(*(arr2+i)+j)=sum;
 sum=0;
 }
}
display1(q,a,b);
}
int main()
{
int a,b,c,d;
 printf("ENTER THE ROWS AND COLOUMN OF ARRAY 1\n");
 scanf("%d%d",&a,&b);
 printf("ENTER THE ROWS AND COLOUMN OF ARRAY 2\n");
 scanf("%d%d",&c,&d);
 int arr[a][b];
 int arr1[c][d];
 int (*p)[100];
 int (*p1)[100];
 p=arr;
 p1=arr1;
  if(b==c)
  {
    read(p,p1,a,b,c,d);
  display(p,p1,a,b,c,d);
  mul(p,p1,a,d,c);
  }
  else
  printf("CANNOT MULTIPLY THE GIVEN TWO ARRAYS\n");
return 0;
}
