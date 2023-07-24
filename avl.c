#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    int height;
    struct Node* left;
    struct Node* right;
};
typedef struct Node* n;
n root=NULL;
n getnode(int key)
{
    n newNode=(n)malloc(sizeof(struct Node));
    newNode->data=key;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->height=1;
    return newNode;
}
int max(int a, int b)
{
    return (a>b)? a:b;
}
int getHeight(struct Node *node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

n ror(n y)
{
    n x=y->left;
    n t2=x->right;
    x->right=y;
    y->left=t2;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    return x;
}
n rol(n y)
{
    n x=y->right;
    n t2=x->left;
    x->left=y;
    y->right=t2;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    return x;
}
int getBalance(n node)
{
    if(node==NULL)
    return 0;
    return(getHeight(node->left)-getHeight(node->right));
}
n insertion(n node,int key)
{
    if(node==NULL)
    {
        return(getnode(key));
    }
    if(key<node->data)
    {
        node->left=insertion(node->left,key);
    }
    else if(key>node->data)
    {
        node->right=insertion(node->right,key);
    }
    else
    return node;
    node->height=max(getHeight(node->right),getHeight(node->left))+1;
    int balance=getBalance(node);

    //balancing
    if(balance>1&&key<node->left->data)
    return ror(node);
    if(balance<-1&&key>node->right->data)
    return rol(node);
    if(balance<-1&&key<node->right->data)
    {
        node->right=ror(node->right);
        return rol(node);
    }
    if(balance>1&&key>node->left->data)
    {
        node->left=rol(node->left);
        return ror(node);
    }
    return node;
}
void preOrder(n node)
{
	if(node != NULL)
	{
		printf("%d ", node->data);
		preOrder(node->left);
		preOrder(node->right);
	}
}

// Function to perform in-order traversal of the BST
void inorderTraversal(n root)
{
    if (root != NULL)
    {
        // Traverse the left subtree
        inorderTraversal(root->left);
        // Visit the current node (data)
        printf("%d %d \n", root->data,root->height);
        // Traverse the right subtree
        inorderTraversal(root->right);
    }

}

n inorderpre(n root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

n deletenode(n root, int value)
{
    if (root == NULL)
    {
        // No tree present
        return NULL;
    }

    if (value < root->data)
    {
        root->left = deletenode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deletenode(root->right, value);
    }
    else
    {
        // Node to be deleted found
        if (root->left == NULL)
        {
            // Case: Only right child or no child
            n temp = root->right;
            printf("DELETED DATA IS %d\n",root->data);
            free(root);
            return temp;
        }
    else if (root->right == NULL)
        {
            // Case: Only left child
            n temp = root->left;
            printf("DELETED DATA IS %d\n",root->data);
            free(root);
            return temp;
        } else
         {
            // Case: Both left and right children exist
            n inorderPredecessor = inorderpre(root);
              printf("DELETED DATA IS %d\t and replaced by %d",root->data,inorderPredecessor->data);
            root->data = inorderPredecessor->data;
            root->left = deletenode(root->left, inorderPredecessor->data);
        }
    }
    return root;
}
n levelorder(n root,int level)
{
    if(root->height==level)
    {
        printf("%d\t",root->data);
        return;
    }
    levelorder(root->left,level);
    levelorder(root->right,level);


 return root;
}
int main()
{
    root=NULL;
    int n,dat,b,maxy;
    while(1)
{
    printf("menu\n1: insert node \t2: inorder traversal \t3: DELETE \t4: exit\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        {
            printf("enter data \n");
            scanf("%d",&dat);
            root = insertion(root, dat);
            break;
        }
        case 2:
        {
              printf("In-order traversal of the BST: ");
                inorderTraversal(root);
                printf("\n");
            break;
        }
        case 3:
                printf("ENTER THE ELEMENT TO BE DELETED\n");
                scanf("%d", &b);
                root = deletenode(root, b);
                break;
        case 4:
                maxy=getHeight(root);
                printf("%d",maxy);
                for(int i=maxy;i>0;i--)
                {
                    for(int k=i;k>0;k--)
                    printf("  ");

                    levelorder(root,i);
                    printf("\n");

                }
                break;
        case 5:exit(0);
        break;
    }
}
return 0;
}

