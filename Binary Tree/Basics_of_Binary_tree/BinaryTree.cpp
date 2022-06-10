#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(char x)
{
    struct Node *node;
    node = new Node;
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preOrder(struct Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node *root)
{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void inOrder(struct Node *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

vector<vector<char>> levelOrder(Node *root)
{
    vector<vector<char>> result;
    queue<Node *> q;
    vector<char> temp;
    int count;

    if (root == NULL)
        return result;

    q.push(root);
    while (!q.empty())
    {
        count = q.size();

        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            temp.push_back(curr->data);
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
            q.pop();
        }
        result.push_back(temp);
        temp.clear();
    }

    return result;
}

int main()
{
    cout << "This is a Binary Tree: " << endl;
    struct Node *a;
    struct Node *b;
    struct Node *c;
    struct Node *d;
    struct Node *e;
    struct Node *f;
    struct Node *g;

    // Creating the nodes of the tree
    a = createNode('a'); // a is the root Node
    b = createNode('b');
    c = createNode('c');
    d = createNode('d');
    e = createNode('e');
    f = createNode('f');
    g = createNode('g');

    // Connecting the nodes of the tree
    // to establish parent-child relationship
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    vector<vector<char>> LevelOrder;
    LevelOrder = levelOrder(a);
    // Printing the tree-Tree traversal methods
    cout << "PreOrder: ";
    preOrder(a);
    cout << endl
         << "InOrder: ";
    inOrder(a);
    cout << endl
         << "PostOrder: ";
    postOrder(a);

    cout << "\nLevelOrder: ";
    for (auto it : LevelOrder)
    {
        for (auto n : it)
        {
            cout << n << " ";
        }
    }
    return 0;
}