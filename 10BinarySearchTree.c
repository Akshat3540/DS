#include <stdio.h>
#include <stdlib.h>

// Structure for the Binary Search Tree node
struct BST
{
    int data;
    struct BST *lchild;
    struct BST *rchild;
};

typedef struct BST *NODE;

// Function to create a new node with the given value
NODE create()
{
    NODE temp = (NODE)malloc(sizeof(struct BST));
    if (!temp)
    { // Check if memory allocation was successful
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("\nEnter the value: ");
    scanf("%d", &temp->data);
    temp->lchild = temp->rchild = NULL;
    return temp;
}

// Function to insert a node into the BST
void insert(NODE root, NODE newnode)
{
    if (newnode->data < root->data)
    {
        if (root->lchild == NULL)
            root->lchild = newnode;
        else
            insert(root->lchild, newnode);
    }
    else if (newnode->data > root->data)
    {
        if (root->rchild == NULL)
            root->rchild = newnode;
        else
            insert(root->rchild, newnode);
    }
    // No action is taken for duplicate nodes (root->data == newnode->data)
}

// Function to search for a key element in the BST
void search(NODE root)
{
    if (root == NULL)
    {
        printf("\nBST is empty.\n");
        return;
    }

    int key;
    printf("\nEnter element to be searched: ");
    scanf("%d", &key);

    NODE cur = root;
    while (cur != NULL)
    {
        if (cur->data == key)
        {
            printf("\nKey element is present in BST\n");
            return;
        }
        cur = (key < cur->data) ? cur->lchild : cur->rchild;
    }
    printf("\nKey element is not found in the BST\n");
}

// Inorder Traversal (Left, Root, Right)
void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}

// Main function to drive the menu-driven program
int main()
{
    int ch, n, i;
    NODE root = NULL, newnode;

    printf("\n~~~~ BST MENU ~~~~");
    printf("\n1. Create a BST");
    printf("\n2. BST Traversal");
    printf("\n3. Search for an element");
    printf("\n0. Exit");
    
    // Menu loop for operations
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the number of elements: ");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)
            {
                newnode = create(); // Create a new node
                if (root == NULL)
                    root = newnode; // Set root if tree is empty
                else
                    insert(root, newnode); // Insert new node into the tree
            }
            break;

        case 2:
            if (root == NULL)
            {
                printf("\nTree is not created.\n");
            }
            else
            {
                printf("\nPreorder traversal: ");
                preorder(root);
                printf("\nInorder traversal: ");
                inorder(root);
                printf("\nPostorder traversal: ");
                postorder(root);
            }
            break;

        case 3:
            search(root); // Search for a given key
            break;

        case 0:
            exit(0); // Exit the program

        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}
