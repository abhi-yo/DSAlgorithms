#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    cout << "Enter data for the left child of " << data << " node: " << endl;
    root->left = buildTree();

    cout << "Enter data for the right child of " << data << " node: " << endl;
    root->right = buildTree();

    return root;
}

void printBottomView(Node *root)
{
    if (root == NULL)
        return;

    unordered_map<int, int> bottomNode; // Store bottom view nodes
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        // Update the bottom node for the current horizontal distance
        bottomNode[hd] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));

        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    cout << "Bottom View of the tree: " << endl;
    for (auto i : bottomNode)
    {
        cout << i.second << " ";
    }
}

int main()
{
    Node *root = buildTree();
    cout << "Bottom View of the tree: " << endl;
    printBottomView(root);
    return 0;
}
