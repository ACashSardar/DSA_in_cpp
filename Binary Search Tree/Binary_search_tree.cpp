#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int x)
{
    struct Node *node;
    node = new Node;
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
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

struct Node *searchElement(struct Node *root, int Key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (Key == root->data)
    {
        return root;
    }
    else if (Key < root->data)
    {
        return searchElement(root->left, Key);
    }
    else
    {
        return searchElement(root->right, Key);
    }
}

// Inserting an element(Recursive approach)
struct Node *insertElement(struct Node *root, int Key)
{
    if (root == NULL)
    {
        return createNode(Key);
    }
    if (Key < root->data)
    {
        root->left = insertElement(root->left, Key);
    }
    else
    {
        root->right = insertElement(root->right, Key);
    }
    return root;
}

// Inserting an element(iterative approach)
void insertElement_itr(struct Node *root, int Key)
{
    struct Node *prev;

    // prev acts as a parent of root everytime root is updated
    while (root)
    {
        prev = root;
        if (Key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct Node *temp;
    temp = createNode(Key);

    if (Key < prev->data)
    {
        if (prev->left == NULL)
            prev->left = temp;
    }
    else if (Key >= prev->data)
    {
        if (prev->right == NULL)
            prev->right = temp;
    }
}

// Deleting an element

/* InorderPreceder is Right most node of Left subtree */
struct Node *findInorderPredecessor(struct Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node *deleteElement(struct Node *root, int Key)
{
    struct Node *inPre;
    if (root == NULL)
    {
        return NULL;
    }
    // when a leaf node contains the Key value
    if (root->left == NULL && root->right == NULL && root->data == Key)
    {
        free(root);
        return NULL;
    }

    if (Key < root->data)
    {
        root->left = deleteElement(root->left, Key);
    }
    else if (Key > root->data)
    {
        root->right = deleteElement(root->right, Key);
    }
    else
    {
        inPre = findInorderPredecessor(root);
        root->data = inPre->data;
        root->left = deleteElement(root->left, inPre->data);
    }
}

int main()
{

    cout << "This is a Binary Search Tree: " << endl;
    struct Node *a;
    struct Node *b;
    struct Node *c;
    struct Node *d;
    struct Node *e;

    // Creating the nodes of the tree
    //         5
    //        / \
    //       3   6
    //      / \   
    //     1   4

    a = createNode(5); // a is the root Node
    b = createNode(3);
    c = createNode(6);
    d = createNode(1);
    e = createNode(4);

    // Connecting the nodes of the tree
    // to establish parent-child relationship
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;

    // In-order traversal
    cout << endl
         << "InOrder: ";
    inOrder(a);

    // // Searching an element
    // int num;
    // cout<<endl<<"Enter the element: ";
    // cin>>num;
    // if (searchElement(a,num)!=NULL)
    //     cout<<"Element Found!"<<endl;
    // else cout<<"Element not present!"<<endl;

    int num;
    cout << endl
         << "Enter the element: ";
    cin >> num;
    // // Inserting an element(Recursive approach)
    a = insertElement(a, num);
    inOrder(a);
    cout << endl;
    // // Inserting an element(iterative approach)
    // insertElement_itr(a,num+2);
    // inOrder(a);
    a = deleteElement(a, num);
    inOrder(a);

    return 0;
}