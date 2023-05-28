int top =-1;
void push(int arr[])
{
    int a;
    if(top==-1)
    {
        printf("stack empty\n");
    }
    else
    {
        printf("ENTER THE ELEMENT TO BE PUSHED\n");
        scanf("%d",&a);
        arr[top]=a;
        top++;
    }
}


int main()

{
  int arr[20];
    top++;
    push(arr);
    push(arr);
    printf("%d\n",arr[0]);
    printf("%d\n",arr[1]);
}
