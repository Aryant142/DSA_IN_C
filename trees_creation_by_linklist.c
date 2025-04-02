#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *right;
    struct node *left;
};

// Function to create a new node
struct node *creationNode(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
}

// Pre-order Traversal (Root, Left, Right)
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data); // Print the root node
        preorder(root->left);      // Recurse on the left subtree
        preorder(root->right);     // Recurse on the right subtree
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);      // Recurse on the left subtree
        postorder(root->right);     // Recurse on the right subtree
        printf("%d ", root->data); // Print the root node        
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);      // Recurse on the left subtree
        printf("%d ", root->data); // Print the root node
        inorder(root->right);     // Recurse on the right subtree                
    }
}


int main() {

    // Creating the binary tree
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    struct node *root = creationNode(1);
    root->left = creationNode(2);
    root->right = creationNode(3);
    root->left->left = creationNode(4);
    root->left->right = creationNode(5);
    root->right->left = creationNode(6);
    root->right->right = creationNode(7);

    printf("Pre-order Traversal: ");
    preorder(root); // Corrected function call
    printf("\n");
    
    printf("Post-order Traversal: ");
    postorder(root);
    printf("\n");
    
    printf("in-order Traversal: ");
    inorder(root);
    printf("\n");
    
    return 0;

}


// void preorder(struct node *root) {
//     if (root == NULL) return;

//     struct node *stack[100];
//     int top = -1;
//     stack[++top] = root;

//     while (top >= 0) {
//         struct node *node = stack[top--];
//         printf("%d ", node->data);

//         if (node->right) stack[++top] = node->right;
//         if (node->left) stack[++top] = node->left;
//     }
// }

// void postorder(struct node *root) {
//     if (root == NULL) return;

//     struct node *stack1[100], *stack2[100];
//     int top1 = -1, top2 = -1;
//     stack1[++top1] = root;

//     while (top1 >= 0) {
//         struct node *node = stack1[top1--];
//         stack2[++top2] = node;

//         if (node->left) stack1[++top1] = node->left;
//         if (node->right) stack1[++top1] = node->right;
//     }

//     while (top2 >= 0) {
//         struct node *node = stack2[top2--];
//         printf("%d ", node->data);
//     }
// }

// void inorder(struct node *root) {
//     struct node *stack[100];
//     int top = -1;
//     struct node *current = root;

//     while (current != NULL || top >= 0) {
//         while (current != NULL) {
//             stack[++top] = current;
//             current = current->left;
//         }

//         current = stack[top--];
//         printf("%d ", current->data);
//         current = current->right;
//     }
// }
