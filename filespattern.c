#include<stdio.h>
#include<string.h>

int i,j,arr[20];
int m,n;
void deci(char str[11][1000],int z)
{
int n,l;
char c;
 for(int m=0;m<=z;m++)
{
n=0;
   while(str[m][n]!='\0')
  {
     if(str[m][n]=='o')
     {
      n++;
      if(str[m][n]=='u')
      {
       n++;
       if(str[m][n]=='l')
       {
        n++;
        if(str[m][n]=='d')
        {n++;
          printf("THE LINE IS %s",str[m]);
        }
        goto label;
       } 
       goto label;
      }
      goto label;
     }
     n++;
     label:
  }

}
}
int main()
{
 int i,m=0,l=0,j=0,k,arr[20],n,z;
  FILE *p;
  int *a,*b,c,d;
 printf("ENTER THE NUMBER OF LINES\n");
 scanf("%d",&z);
 char str[11][1000];
  p=fopen("/home/rohit/DSA/test.txt","r");
 for(int a=0;a<=z;a++)
 {
       fgets(str[a],100,p);

  }
 deci(str,z);
  return(0);
  fclose(f);
}
