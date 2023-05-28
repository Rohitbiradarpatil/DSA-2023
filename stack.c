#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct stack
{
    int max;
    int top;
    int *arr;
};
void generate(int min,int max,int n)
{
    FILE *f;
    f=fopen("rinput.txt","r+");
    srand(time(0));
    for(int i=0;i<n;i++)
    {
        int num=rand()%(max-min+1)+min;
        fprintf(f,"%d\n",num);
    }
    fclose(f);
}
void push(struct stack *p,int *ptr)
{
    int fk,arr[20];
    FILE *f;
    FILE *f1;
    FILE *f3;
    f=fopen("rinput.txt","r+");
    f1=fopen("push.txt","r+");
     f3=fopen("oper.txt","r+");
    if(f==NULL)
        printf("FILE NOT FOUND\n");
    for(int i=0;i<10;i++)
    {
        fscanf(f,"%d",&fk);
        arr[i]=fk;
    }
    fclose(f);
    if(p->top==p->max-1)
    printf("STACK OVERFLOW\n");
    else
    {
        p->top++;
        p->arr[p->top]=arr[*ptr];
        printf("PUSHEDIS %d\n",p->arr[p->top]);
        fprintf(f1,"ELEMENT %d is pushed %d\n",*ptr+1,p->arr[p->top]);
         fprintf(f3,"ELEMENT %d is pushed %d\n",*ptr,p->arr[p->top]);
        *ptr=*ptr+1;
    }
   fclose(f1);
   fclose(f3);
}
void pop(struct stack *p)
{
    FILE *f2;
    FILE *f3;
    f2=fopen("pop.txt","r+");
     f3=fopen("oper.txt","r+");
    int element=0;
    if(p->top==-1)
        printf("STACK UNDERFLOW\n");
    else
    {
       element=p->arr[p->top];
       printf("ELEMENT POPED IS %d\n",element);
       fprintf(f2,"ELEMENT POPED IS %d\n",element);
       fprintf(f3,"ELEMENT POPED IS %d\n",element);
       p->top--;
    }
    fclose(f2);
    fclose(f3);
}
int main()
{
    int count=0,min=0,max=0,k=0;
    int *ptr=&count;
    struct stack *p=(struct stack *)malloc(sizeof(struct stack));
    p->max=10;
    p->top=-1;
    p->arr=(int *)malloc(p->max*sizeof(int));
    if(p->arr==NULL)
        printf("MEMEORY NOT ALLOCATED\n");
    int n;
    while(1)
    {
        printf("MENU\t PLEASE CHOICE FROM BELOW\n");
        printf("1:GENERATE NUMBER\t2:PUSH THE ELEMENTS\t3:POP THE ELEMENTS\t4:EXIT\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                {
                    printf("ENTER THE RANGE \n");
                    scanf("%d%d",&min,&max);
                    printf("ENTER THE NUMBER OF NUMBER TO GENERATE\n");
                    scanf("%d",&k);
                    generate(min,max,k);
                }
                break;
            case 2:push(p,ptr);
            break;
            case 3:pop(p);
            break;
            case 4:
                {printf("\n\nTHANK YOU '   _   '\n");
                exit(0);
            }
            break;
        }
    }

}
