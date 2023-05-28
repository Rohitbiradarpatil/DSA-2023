#include<stdio.h>
int i,j,arr[20];
int m,n;
void deci(char str[11][1000],int z)
{
int n,l;
char c;
 for(int m=0;m<=z;m++)
{
n=0;
l=0;
   while(str[m][n]!='\0')
  {
   c=str[m][n];
   l++;
   n++;
  }
  arr[m]=l;
  if(l>=j)
  j=l;

}
for(int n=0;n<=z;n++)
{
 if(j==arr[n])
 printf("line is %s",str[n]);
}
}
int main()
{
 int i,m=0,l=0,j=0,k,arr[20],n,z;

 printf("ENTER THE NUMBER OF LINES\n");
 scanf("%d",&z);
 char str[11][1000];
  printf("ENTER THE DATA\n");
 for(int a=0;a<=z;a++)
 {
       gets(str[a]);

  }
 deci(str,z);
  return(0);
}
