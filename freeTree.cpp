// Program to delete a binary tree
#include <iostream>

using namespace std;

// Struct to hold the information for a tree node
struct treeNode {
    int val;
    treeNode * leftChild;
    treeNode * rightChild;
};

// Function to create new node
treeNode * newNode(int value)
{
    treeNode * NewTreeNode = new treeNode;
    NewTreeNode->val = value;
    NewTreeNode->rightChild = NULL;
    NewTreeNode->leftChild = NULL;
    return NewTreeNode;
}

// Function to print entire tree in a two dementional format
void printTree(treeNode * node, int spaces)
{
    if(node == NULL)
    {
        return;
    }
    
    spaces += 5;

    printTree(node->rightChild, spaces);

    cout << endl;
    for(int i = 5; i < spaces; i++)
    {
        cout << " ";
    }
    cout << node->val << endl;

    printTree(node->leftChild, spaces);
}

// Main recursive function to clear the whole tree (Post order recursive traversal)
void freeTree(treeNode * node)
{
    // Checking if the current node is null
    if(node != NULL)
    {
        // Traversing down the left subtree first recursively
        freeTree(node->leftChild);
        // Then traversing down the right subtree recursively
        freeTree(node->rightChild);
        // Deleting the node by freeing the memory
        delete node;
    }
}

int main()
{
    // Declaring nodes for tree
    treeNode * root = newNode(1);
    treeNode * node1 = newNode(2);
    treeNode * node2 = newNode(4);
    treeNode * node3 = newNode(8);
    treeNode * node4 = newNode(16);
    treeNode * node5 = newNode(32);
    treeNode * node6 = newNode(64);

    // Linking nodes in Tree formation
    root->leftChild = node1;
    root->rightChild = node2;
    node1->leftChild = node3;
    node1->rightChild = node4;
    node2->leftChild = node5;
    node2->rightChild = node6;

    // Printing the tree before deleting
    cout << "Printing tree before clearing:\n";
    printTree(root, 1);

    // Deleting the tree
    freeTree(root);

    // Printing again after clearing
    cout << "Printing tree after clearing:\n";
    printTree(root, 1);

    return 0;
}