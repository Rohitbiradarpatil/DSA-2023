#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node *Node;
Node createNode();
Node insertEnd(Node head);
void displayList(Node head);
Node inserFront(Node head);
Node delend(Node head);
Node delfron(Node head);
Node count(Node head);
Node search(Node head);
int main()
{Node head=NULL;
    int ch;
    while(1)
    {
        printf("\nSINGLY LINKED MENU\n\n");
        printf("1:insertEnd 2:InsertFront 3:DELETE THE ENd NODE 4:DELETE FRONT 5:COUNT NODE 6:SERACH 7:Display 8:Exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head=insertEnd(head);
               break;
            case 2:head=inserFront(head);
             break;
            case 3:head=delend(head);
              break;
              case 4:head=delfron(head);
              break;
              case 5:count(head);
              break;
               case 6:search(head);
              break;
            case 7:displayList(head);
              break;
               case 8:exit(0);
              break;
            default:printf("invalid choice\n");
             break;
        }
    }
    return 0;
}
Node createNode()
{
    Node newnode;
    newnode=(Node)malloc(sizeof(struct node));
   // printf("%d",sizeof(Node));
    if(newnode==NULL)
    {
        printf("memory not allocated\n");
        exit(0);
    }
    printf("enter data\n");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}
Node insertEnd(Node head)
{
    Node cur,newnode;
    newnode=createNode();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        cur=head;
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;
    }
    return head;
}
void displayList(Node head)
{
    Node cur=head;
    if(head==NULL)
    {
        printf("\nSingly linked list is empty\n");
    }
    else
    {
        while(cur!=NULL)
        {
            printf("%d \t",cur->data);
            cur=cur->link;
        }
    }
}
Node inserFront(Node head)
{
    Node newnode;
    newnode=createNode();
    if (head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->link=head;
        head=newnode;
    }
    return head;
}
Node delend(Node head)
{
    Node cur,prev;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else if(head->link==NULL)
    {
        printf(" DELETED DATA IS =%d",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        prev=NULL;
        cur=head;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=NULL;
        printf("DELETED DATA IS =%d",cur->data);
        free(cur);
    }
    return head;

}
Node delfron(Node head)
{
    Node cur=NULL;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else if(head->link==NULL)
    {
        printf(" DELETED DATA IS =%d",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        cur=head;
        head=head->link;
        printf("DELETED DATA IS %d",cur->data);
        cur->link=NULL;
        free(cur);


    }


    return head;
}
Node count(Node head)
{
    int count=0;
    Node cur;
    cur=head;
    if(head==NULL)
    {
       // printf("count is %d",count);
    }
    else if(cur->link!=NULL)
    {
        count++;
        cur=cur->link;
    }
    printf("COUNT IS %d",count+1);

}
Node search(Node head)
{
    int status=0,key;
    Node cur=NULL;
    printf("ENTER THE NUMBER TO BE SEACRCHED \n");
    scanf("%d",&key);
    if(head==NULL)
    {
        printf("list is empty");
    }
   else
    {
        cur=head;
        while(cur!=NULL)
        {
            if(cur->data=key)
            {
                status=1;
                break;
            }
            cur=cur->link;
        }
        if(status==1)
        {
            printf("SERACH SUCCESFULL %d found\n",key);
        }
        else
            {
                printf("SEARCH UNSUCCESFULL \n");
            }


    }


    return head;
}
Node delspec(Node head)
{
    int status=0,key;
    Node cur=NULL,prev;;
    printf("ENTER THE NUMBER TO BE SEACRCHED \n");
    scanf("%d",&key);
    if(head==NULL)
    {
        printf("list is empty");
    }
   else
    {
        prev=NULL;
        cur=head;
        while(cur!=NULL)
        {
            if(cur->data=key)
            {
                status=1;
                break;
            }
            prev=cur;
            cur=cur->link;
        }
        if(status=1)
        {
            prev->link=cur->link;
           printf("DELETED DARA %d\n",cur->data);
           free(cur);
        }
        else
            {
                printf("SERACH UNSECCUSFULL\n");
            }



    }


    return head;
}
