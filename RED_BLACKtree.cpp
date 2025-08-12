#include <stdio.h>
#include <stdlib.h>

// Enum for Red and Black colors
typedef enum {RED, BLACK} Color;

// Structure for a Red-Black Tree node
typedef struct Node {
    int data;
    Color color;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
} Node;

// A special NULL node (sentinel) which is always BLACK
Node *NIL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED; // New nodes are always RED
    newNode->left = NIL;
    newNode->right = NIL;
    newNode->parent = NIL;
    return newNode;
}

// Left rotate operation
void leftRotate(Node **root, Node *x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left != NIL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NIL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// Right rotate operation
void rightRotate(Node **root, Node *y) {
    Node *x = y->left;
    y->left = x->right;
    if (x->right != NIL) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NIL) {
        *root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
}

// Function to fix violations after insertion
void insertFixup(Node **root, Node *z) {
    Node *y;
    // Loop until z's parent is BLACK or z is the root
    while (z->parent->color == RED) {
        // Case 1: Parent of z is the left child of its grandparent
        if (z->parent == z->parent->parent->left) {
            y = z->parent->parent->right; // Uncle of z
            // Case 1a: Uncle is RED -> Recolor
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                // Case 1b: Uncle is BLACK and z is a right child -> Left rotate
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                // Case 1c: Uncle is BLACK and z is a left child -> Recolor and right rotate
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        }
        // Case 2: Parent of z is the right child of its grandparent (symmetric to Case 1)
        else {
            y = z->parent->parent->left; // Uncle of z
            // Case 2a: Uncle is RED -> Recolor
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                // Case 2b: Uncle is BLACK and z is a left child -> Right rotate
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                // Case 2c: Uncle is BLACK and z is a right child -> Recolor and left rotate
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK; // Ensure root is always BLACK
}

// Function to insert a node into the Red-Black Tree
void insertNode(Node **root, int data) {
    Node *z = createNode(data);
    Node *y = NIL;
    Node *x = *root;

    // Standard BST insert
    while (x != NIL) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == NIL) {
        *root = z;
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }

    // Fix any Red-Black Tree property violations
    insertFixup(root, z);
}

// In-order traversal to display the tree
void inorder(Node *node) {
    if (node != NIL) {
        inorder(node->left);
        printf("%d (%s) ", node->data, node->color == RED ? "RED" : "BLACK");
        inorder(node->right);
    }
}

// Main function to test the Red-Black Tree
int main() {
    // Initialize the sentinel NIL node
    NIL = (Node*)malloc(sizeof(Node));
    NIL->color = BLACK;
    NIL->left = NULL;
    NIL->right = NULL;
    NIL->parent = NULL;
    
    Node *root = NIL;

    printf("Inserting elements: 10, 20, 30, 40, 50, 25\n");

    insertNode(&root, 10);
    insertNode(&root, 20);
    insertNode(&root, 30);
    insertNode(&root, 40);
    insertNode(&root, 50);
    insertNode(&root, 25);

    printf("\nIn-order traversal of the Red-Black Tree:\n");
    inorder(root);
    printf("\n");

    // Free memory (a proper clearTree function should be implemented for production code)
    free(NIL);

    return 0;
}
