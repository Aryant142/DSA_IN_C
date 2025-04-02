#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for a tree node
struct node
{
    int data;
    struct node *right;
    struct node *left;
};

// Function to create a new node
struct node *creationNode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
}

// Pre-order Traversal (Root, Left, Right)
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data); // Print the root node
        preorder(root->left);      // Recurse on the left subtree
        preorder(root->right);     // Recurse on the right subtree
    }
}

// Post-order Traversal (Left, Right, Root)
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);     // Recurse on the left subtree
        postorder(root->right);    // Recurse on the right subtree
        printf("%d ", root->data); // Print the root node
    }
}

// In-order Traversal (Left, Root, Right)
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);       // Recurse on the left subtree
        printf("%d ", root->data); // Print the root node
        inorder(root->right);      // Recurse on the right subtree
    }
}

// Helper function to check if a tree is a BST
int isBSTUtil(struct node *root, int min, int max)
{
    if (root == NULL)
    {
        return 1; // An empty tree is a BST
    }

    // Check if the current node violates the min/max constraints
    if (root->data <= min || root->data >= max)
    {
        return 0;
    }

    // Recursively check left and right subtrees with updated constraints
    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

// Wrapper function to check if a tree is a BST
int isBST(struct node *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{
    // Constructing a binary search tree (BST)
    //     8
    //    / \
    //   3   10
    //  / \    \
    // 1   6    14
    //    / \   /
    //   4   7 13

    struct node *root = creationNode(8);
    root->left = creationNode(3);
    root->right = creationNode(10);
    root->left->left = creationNode(1);
    root->left->right = creationNode(6);
    root->left->right->left = creationNode(4);
    root->left->right->right = creationNode(7);
    root->right->right = creationNode(14);
    root->right->right->left = creationNode(13);

    // Pre-order traversal
    printf("Pre-order Traversal: ");
    preorder(root);
    printf("\n");

    // Post-order traversal
    printf("Post-order Traversal: ");
    postorder(root);
    printf("\n");

    // In-order traversal
    printf("In-order Traversal: ");
    inorder(root);
    printf("\n");

    // Check if the tree is a BST
    if (isBST(root))
    {
        printf("The tree is a BST\n");
    }
    else
    {
        printf("The tree is NOT a BST\n");
    }

    return 0;
}
