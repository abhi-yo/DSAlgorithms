#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

struct NodeData
{
    int size;   // size of the BST
    int minVal; // minimum value in the BST
    int maxVal; // maximum value in the BST
    bool isBST; // flag indicating if the subtree is a BST

    NodeData(int s, int minV, int maxV, bool bst)
    {
        size = s;
        minVal = minV;
        maxVal = maxV;
        isBST = bst;
    }
};

NodeData *findLargestBST(Node *root, int &ans)
{
    // base case
    if (root == nullptr)
    {
        return new NodeData(0, INT_MAX, INT_MIN, true);
    }

    NodeData *leftkaAns = findLargestBST(root->left, ans);
    NodeData *rightkaAns = findLargestBST(root->right, ans);

    // check if current subtree is a valid BST
    if (leftkaAns->isBST && rightkaAns->isBST && root->data > leftkaAns->maxVal && root->data < rightkaAns->minVal)
    {
        int size = leftkaAns->size + rightkaAns->size + 1;
        int minVal = min(root->data, min(leftkaAns->minVal, rightkaAns->minVal));
        int maxVal = max(root->data, max(leftkaAns->maxVal, rightkaAns->maxVal));
        ans = max(ans, size); // update the maximum BST size
        return new NodeData(size, minVal, maxVal, true);
    }

    // if the current subtree is not a valid BST
    return new NodeData(0, INT_MIN, INT_MAX, false);
}

int main()
{
    // Create a binary tree
    Node *root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int ans = 0;
    findLargestBST(root, ans);

    cout << "Largest BST size: " << ans << endl;

    return 0;
}
