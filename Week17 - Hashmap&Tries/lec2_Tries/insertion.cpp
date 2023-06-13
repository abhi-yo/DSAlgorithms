#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char d)
    {
        this->data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

void insertWord(TrieNode *root, string word)
{
    // Base Case
    if (word.size() == 0)
    {
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    // present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // not present
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    // Recursive Case
    insertWord(child, word.substr(1));
}

void deleteWord(TrieNode *root, string word)
{
    // Base Case
    if (word.size() == 0)
    {
        root->isTerminal = false;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child = root->children[index];
    // Word does not exist in the Trie
    if (child == NULL)
        return;
    deleteWord(child, word.substr(1));
    // Delete the child node if it can be safely removed
    if (!child->isTerminal)
    {
        bool hasChildren = false;
        for (int i = 0; i < 26; i++)
        {
            if (child->children[i] != NULL)
            {
                hasChildren = true;
                break;
            }
        }
        if (!hasChildren)
        {
            delete child;
            root->children[index] = NULL;
        }
    }
}

int main()
{
    TrieNode *root = new TrieNode('-');
    insertWord(root, "hello");
    return 0;
}
