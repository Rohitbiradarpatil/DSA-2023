#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
typedef struct Node* N;

// Function to create a new node
N createNode(int value) {
    N newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in BST
N insert(N root, int value) {
    if (root == NULL) {
        // Create a new node if the tree is empty
        return createNode(value);
    }

    if (value < root->data) {
        // Recursively insert the value in the left subtree
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        // Recursively insert the value in the right subtree
        root->right = insert(root->right, value);
    }

    // Return the unchanged node pointer
    return root;
}

// Function to perform in-order traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        // Traverse the left subtree
        inorderTraversal(root->left);
        // Visit the current node (data)
        printf("%d ", root->data);
        // Traverse the right subtree
        inorderTraversal(root->right);
    }
}

N inorderpre(N root) {
    root = root->left;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

N deletenode(N root, int value)
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
            N temp = root->right;
            printf("DELETED DATA IS %d\n",root->data);
            free(root);
            return temp;
        }
    else if (root->right == NULL)
        {
            // Case: Only left child
            N temp = root->left;
            printf("DELETED DATA IS %d\n",root->data);
            free(root);
            return temp;
        } else
         {
            // Case: Both left and right children exist
            N inorderPredecessor = inorderpre(root);
              printf("DELETED DATA IS %d\t and replaced by %d",root->data,inorderPredecessor->data);
            root->data = inorderPredecessor->data;
            root->left = deletenode(root->left, inorderPredecessor->data);
        }
    }
    return root;
}

int main()
 {
    int k, a, b;
    N root = NULL;

    while (1) {
        printf("1: INSERT\t 2: INORDER \t 3: DELETE\n");
        scanf("%d", &k);

        switch (k) {
            case 1:
                printf("ENTER THE VALUE TO BE INSERTED: \n");
                scanf("%d", &a);
                root = insert(root, a);
                break;

            case 2:
                printf("In-order traversal of the BST: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("ENTER THE ELEMENT TO BE DELETED\n");
                scanf("%d", &b);
                root = deletenode(root, b);
                break;
        }
    }

    return 0;
 }
