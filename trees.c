#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a node in the binary search tree
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree
struct Node* insertNode(struct Node* root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);

    return root;
}

// Function for pre-order traversal
void preorderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function for in-order traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Function for post-order traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}

// Function to search for a key in the binary search tree
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int randomNumbers[10],p,q,n,num,a;
         FILE *s;
    printf("enter the range in which N random numbers are to be generated in order [lower,upper]\n");
    scanf("%d%d",&p,&q);
    printf("enter the number of random numbers to be generated\n");
    scanf("%d",&n);
    s=fopen("input.txt","w");
    srand(time(0));
    for(int i=0;i<n;i++)
    {
       num=(rand()%(q-p+1))+p;
       printf("%d\t",num);
       fprintf(s,"%d\n",num);
    }
    fclose(s);
    s=fopen("input.txt","r");
    printf("\nenter the number of numbers to be sorted\n");
    //scanf("%d",&x);
    for(int i=0;i<n;i++)
    {
      fscanf(s,"%d",&a);
       randomNumbers[i]=a;
      printf("%d\t",randomNumbers[i]);
    }

    // Sort the array of random numbers
    for (int i = 0; i < n - 1; i++)
        {
        for (int j = 0; j < n - i - 1; j++)
         {
            if (randomNumbers[j] > randomNumbers[j + 1])
            {
                int temp = randomNumbers[j];
                randomNumbers[j] = randomNumbers[j + 1];
                randomNumbers[j + 1] = temp;
            }
        }
    }

    printf("Inserting numbers into the binary search tree:\n");
    for (int i = 0; i < n; i++) {
        printf("Inserting %d\n", randomNumbers[i]);
        root = insertNode(root, randomNumbers[i]);
    }

    printf("\nBinary Search Tree Operations\n");
    printf("1. Pre-order Traversal\n");
    printf("2. In-order Traversal\n");
    printf("3. Post-order Traversal\n");
    printf("4. Search for a Key\n");
    printf("5. Exit\n");

    int choice, key;
    struct Node* result;

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Pre-order Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 2:
                printf("In-order Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Post-order Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                result = search(root, key);
                if (result != NULL)
                    printf("Key %d found in the tree.\n", key);
                else
                    printf("Key %d not found in the tree.\n", key);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
