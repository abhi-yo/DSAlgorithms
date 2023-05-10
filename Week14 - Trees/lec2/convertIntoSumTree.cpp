#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
public:
    int toSumTree(Node* root) {
        if (root == NULL)
            return 0;

        int leftSum = toSumTree(root->left);
        int rightSum = toSumTree(root->right);
        int oldValue = root->data;

        root->data = leftSum + rightSum;
        return root->data + oldValue;
    }
};

// creating a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    if (newNode) {
        newNode->data = data;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

// inorder traversal of the tree
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // tree creation
    Node* root = createNode(10);
    root->left = createNode(-2);
    root->right = createNode(6);
    root->left->left = createNode(8);
    root->left->right = createNode(-4);
    root->right->left = createNode(7);
    root->right->right = createNode(5);

    Solution obj;
    obj.toSumTree(root);

    cout << "Converted tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
