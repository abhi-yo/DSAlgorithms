#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to build a binary tree
Node* buildTree() {
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    // Step A, B, and C
    Node* root = new Node(data);

    cout << "Enter data for the left part of " << data << " node " << endl;
    root->left = buildTree();

    cout << "Enter data for the right part of " << data << " node " << endl;
    root->right = buildTree();

    return root;
}


// Function to perform inorder traversal of a binary tree
void inorderTraversal(Node* root) {
    // Base case: if root is NULL, return
    if (root == NULL) {
        return;
    }

    // LNR: left subtree, node, right subtree
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Function to perform preorder traversal of a binary tree
void preorderTraversal(Node* root) {
    // Base case: if root is NULL, return
    if (root == NULL) {
        return;
    }

    // NLR: node, left subtree, right subtree
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to perform postorder traversal of a binary tree
void postorderTraversal(Node* root) {
    // Base case: if root is NULL, return
    if (root == NULL)
        return;

    // LRN: left subtree, right subtree, node
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// Function to calculate the height of a binary tree
int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int ans = max(leftHeight, rightHeight) + 1;
    return ans;
}

int main(){
    Node* root = NULL;

    root = buildTree();

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "Height of the tree: " << height(root) << endl;

    return 0;
}
   
