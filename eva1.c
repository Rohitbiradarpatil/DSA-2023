#include<stdio.h>
#include<string.h>
int main()
{
 int i=0,l=0,j=0,k=0,n,z;
 char m,c;
  FILE *p;
 char str[1][1000],arr2[1],arr[20],arr1[20];
 printf("NUMBER OF LINES\n");
 scanf("%d",&n);
  p=fopen("/home/rohit/DSA/sort.txt","a+");

 for(int a=0;a<n;a++)
 {
       fgets(str[a],100,p);

  }
printf("ENTER THE WORD TO BE FOUND\n");
scanf("%s",arr);
printf("ENTER THE WORD TO BE REPLACED\n");
scanf("%s",arr1);
for(int k=0;k<n;k++)
{
    while(str[0][i]!='\n')
{
printf("%c\t%c\n",str[0][i],arr[k]);
 if(str[0][i]==arr[k])
 {
 printf("ENTER\n");
  str[0][i]=arr1[k];
  k++;
 }
 i++;
}
}
for(int i=0;i<n;i++)
{
    printf("%s\n",str[i]);
}
while(str[0][i]!='\n')
fprintf(p,"%s",str[0]);
  return(0);
  fclose(p);
}
