#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    int height;
    struct node* left;
    struct node* right;
};

int getheight(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

int max(int a, int b) {
    return a > b ? a : b;
}

struct node* creationNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1; // Initial height of a new node
    return newnode;
}

int balancefactor(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    return getheight(root->left) - getheight(root->right);
}

struct node* rightrotate(struct node* root) {
    struct node* x = root->left;
    struct node* T2 = x->right;

    // Perform rotation
    x->right = root;
    root->left = T2;

    // Update heights
    root->height = max(getheight(root->left), getheight(root->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;

    // Return new root
    return x;
}

struct node* leftrotate(struct node* root) {
    struct node* y = root->right;
    struct node* T2 = y->left;

    // Perform rotation
    y->left = root;
    root->right = T2;

    // Update heights
    root->height = max(getheight(root->left), getheight(root->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;

    // Return new root
    return y;
}

struct node* insertion(struct node* root, int data) {
    // Perform normal BST insertion
    if (root == NULL) {
        return creationNode(data);
    }
    if (data < root->data) {
        root->left = insertion(root->left, data);
    } else if (data > root->data) {
        root->right = insertion(root->right, data);
    } else {
        return root; // Duplicates are not allowed
    }

    // Update height of this ancestor node
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // Get balance factor
    int bf = balancefactor(root);

    // Left-Left Case
    if (bf > 1 && data < root->left->data) {
        return rightrotate(root);
    }

    // Right-Right Case
    if (bf < -1 && data > root->right->data) {
        return leftrotate(root);
    }

    // Left-Right Case
    if (bf > 1 && data > root->left->data) {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    // Right-Left Case
    if (bf < -1 && data < root->right->data) {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    // Return the unchanged root pointer
    return root;
}

// Helper function to print pre-order traversal
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Main function to test the AVL tree
int main() {
    struct node* root = NULL;

    root = insertion(root, 10);
    root = insertion(root, 20);
    root = insertion(root, 30);
    root = insertion(root, 40);
    root = insertion(root, 50);
    root = insertion(root, 25);

    printf("Pre-order traversal of the AVL tree is:\n");
    preorder(root);

    return 0;
}
