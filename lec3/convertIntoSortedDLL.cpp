#include <iostream>
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
void convertIntoSortedDLL(Node *root, Node *&head)
{
    if (root == NULL)
    {
        return;
    }
    // right subtre into LL
    convertIntoSortedDLL(root->right, head);
    // attach root node
    root->right = head;
    // if head is not null
    if (head != NULL)
    {
        head->left = root;
    }
    // update head
    head = root;
    // left subtree into LL
    convertIntoSortedDLL(root->left, head);
}
void printDLL(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
}
int main()
{
    // Create a binary search tree
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    Node *head = nullptr;
    convertIntoSortedDLL(root, head);
    printDLL(head);
    return 0;
}