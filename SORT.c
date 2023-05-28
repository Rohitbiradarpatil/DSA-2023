#include<stdio.h>
#include<time.h>

 void bubblesort(int a,int arr[])
  {
    int temp;
     for(int i=0;i<a-1;i++)
     {
      for(int j=0;j<a-1-i;j++)
      {
       if(arr[j+1]<arr[j])
       {
        temp=arr[j+1];
        arr[j+1]=arr[j];
        arr[j]=temp;
       }
      }
     }
     printf("SORTED ARRAY IS \n");
      for(int i=0;i<a;i++)
    {
        printf("%d\t",arr[i]);
    }
  }
  void selection(int a,int arr[])
{
int m=0;int temp=0;
 for(int i=0;i<a-1;i++)
{
  for(int j=i;j<a-1-i;j++)
  {
  if(arr[j]>arr[j+1])
  {
    m=j+1;
  }
  }
   if(m!=i)
  {
   temp=arr[i];
   arr[i]=arr[m];
   arr[m]=temp;
  }
  m=i+1;

}
 printf("SORTED ARRAY IS \n");
 for(int i=0;i<a;i++)
 printf("%d\t",arr[i]);
}
void merge(int arr[],int s,int m,int e)
{
int arr1[10],i=0,j=0;
 int k=0;
 i=s;
 j=m+1;
 while(i<=m&&j<=e)
 {
  if(arr[i]<=arr[j])
  {
   arr1[k]=arr[i];
   i++;
  }
  else
  {
  arr1[k]=arr[j];
  j++;
  }
  k++;
 }
 if(i>m)
 {
   while(j<=e)
   {
    arr1[k]=arr[j];
    j++;
    k++;
   }
 }
 else
 {
  while(i<=m)
  {
   arr1[k]=arr[i];
   k++;
   i++;
  }
 }
 for(int i=s;i<=e;i++)
 {
   arr[i]=arr1[i-s];
 }
}
void ms(int arr[],int s,int e)
{
  int m;
 if(s<e)
 {
   m=(s+e)/2;
  ms(arr,s,m);
  ms(arr,m+1,e);
  merge(arr,s,m,e);

 }
}
 int main()
 {
     int a;
     FILE *f;
     f=fopen("/home/rohit/DSA/log.txt","a");
     clock_t start_t,end_t, start1_t,end1_t,start2_t,end2_t;
     double total_t,total1_t,total2_t;
    printf("LENGHT OF AN INPUT\n");
    scanf("%d",&a);
    int arr[a];
    printf("ENTER THE ELEMENTS\n");
    for(int i=0;i<a;i++)
    {
        scanf("%d",&arr[i]);
    }
     start_t=clock();
   bubblesort(a,arr);
    end_t=clock();
    total_t=(double)(end_t-start_t)/CLOCKS_PER_SEC;
    printf("TIME TAKEN = %f\n",total_t);
    fprintf(f,"TIME TAKEN BY BUBBLE SORT IS =%f\n",total_t);
    start1_t=clock();
    selection(a,arr);
    end1_t=clock();
    total1_t=(double)(end1_t-start1_t)/CLOCKS_PER_SEC;
    printf("TIME TAKEN1 = %f\n",total1_t);
     fprintf(f,"TIME TAKEN BY SELECTION SORT IS =%f\n",total1_t);
    start2_t=clock();
    ms(arr,0,a-1);
       printf("SORTED ARRAY IS \n");
     for(int i=0;i<a;i++)
 {
   printf("%d\t",arr[i]);
 }
    end2_t=clock();
    total2_t=(double)(end1_t-start1_t)/CLOCKS_PER_SEC;
    printf("TIME TAKEN1 = %f\n",total1_t);
 fprintf(f,"TIME TAKEN BY MERGE SORT IS =%f\n",total2_t);

 }

