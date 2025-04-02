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


struct node* prein(struct node *root)
{
    root=root->left ;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node* deletenode(struct node* root, int data)
{
    if (root == NULL) // Base case: Node not found
        return root;

    if (data < root->data)
    {
        // Recur for the left subtree
        root->left = deletenode(root->left, data);
    }
    else if (data > root->data)
    {
        // Recur for the right subtree
        root->right = deletenode(root->right, data);
    }
    else
    {
        // Node to be deleted found
        // Case 1: Node with only one child or no child
        if (root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node with two children
        // Find the in-order predecessor
        struct node* ipe = prein(root);

        // Replace root's data with in-order predecessor's data
        root->data = ipe->data;

        // Delete the in-order predecessor
        root->left = deletenode(root->left, ipe->data);
    }

    return root; // Return the updated root
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

    deletenode(root,6);
    inorder(root);

    return 0;
}
