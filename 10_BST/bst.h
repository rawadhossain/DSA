#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree
{
private:
    Node *root;

public:
    BinarySearchTree()
    {
        root = NULL;
    }

    void insert(int value)
    {
        root = insertHelper(root, value);
    }

    Node *insertHelper(Node *node, int value)
    {
        if (node == NULL)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insertHelper(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertHelper(node->right, value);
        }

        return node;
    }

    bool search(int value)
    {
        return searchHelper(root, value);
    }

    bool searchHelper(Node *node, int value)
    {
        if (node == NULL)
        {
            return false;
        }

        if (value == node->data)
        {
            return true;
        }
        else if (value < node->data)
        {
            return searchHelper(node->left, value);
        }
        else
        {
            return searchHelper(node->right, value);
        }
    }

    void inorderTraversal()
    {
        inorderTraversalHelper(root);
    }

    void inorderTraversalHelper(Node *node)
    {
        if (node != NULL)
        {
            inorderTraversalHelper(node->left);
            cout << node->data << " ";
            inorderTraversalHelper(node->right);
        }
    }

    void remove(int value)
    {
        root = removeHelper(root, value);
    }

    Node *removeHelper(Node *node, int value)
    {
        if (node == NULL)
        {
            return node;
        }

        if (value < node->data)
        {
            node->left = removeHelper(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = removeHelper(node->right, value);
        }
        else
        {
            if (node->left == NULL)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            Node *temp = getMinNode(node->right);
            node->data = temp->data;
            node->right = removeHelper(node->right, temp->data);
        }

        return node;
    }

    Node *getMinNode(Node *node)
    {
        Node *current = node;
        while (current && current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    int getMin()
    {
        if (root == NULL)
        {
            throw runtime_error("Tree is empty");
        }

        Node *current = root;
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current->data;
    }

    int getMax()
    {
        if (root == NULL)
        {
            throw runtime_error("Tree is empty");
        }

        Node *current = root;
        while (current->right != NULL)
        {
            current = current->right;
        }
        return current->data;
    }

    int getHeight()
    {
        return getHeightHelper(root);
    }

    int getHeightHelper(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        int leftHeight = getHeightHelper(node->left);
        int rightHeight = getHeightHelper(node->right);

        return max(leftHeight, rightHeight) + 1;
    }
};
