#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node with the given value
Node* createNode(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
void insert(Node*& root, int val) {
    // If the tree is empty, create a new node and set it as the root
    if (root == NULL) {
        root = createNode(val);
        return;
    }

    // Otherwise, recursively insert into the left or right subtree
    if (val < root->data) {
        insert(root->left, val);
    } else if (val > root->data) {
        insert(root->right, val);
    }
}

// Function to perform an inorder traversal of the binary tree
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
void preordertrversal(){
    if(root==NULL){
        return;
    }
    cout<<root->data<< "  ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}
void postordertraversal(){
if(root==NULL){
        return;
    }
    cout<<root->data<< "  ";
    postordertraversal(root->left);
    postordertraversal(root->right);
    
}

int main() {
    // Create the binary search tree by inserting values
    Node* root = NULL;
    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);

    // Inorder traversal of the binary tree
    cout << "Inorder Traversal: ";
    inorderTraversal(root);

    return 0;
}




