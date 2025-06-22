#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        key = value;
        left = right = nullptr;
        height = 1;
    }
};

// Get height of a node
int height(Node* node) {
    return node ? node->height : 0;
}

// Get balance factor of a node
int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Update height of a node
void updateHeight(Node* node) {
    node->height = 1 + max(height(node->left), height(node->right));
}

// Right rotate
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotate
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y;
}

// Insert node into AVL Tree
Node* insert(Node* node, int key) {
    // 1. Normal BST insertion
    if (!node)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;  // Duplicate keys not allowed

    // 2. Update height
    updateHeight(node);

    // 3. Get balance factor
    int balance = getBalance(node);

    // 4. Balance the tree
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Driver code
int main() {
    Node* root = nullptr;

    int keys[] = {30, 20, 40, 10, 25, 35, 50};

    for (int key : keys)
        root = insert(root, key);

    cout << "Inorder traversal of AVL tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
