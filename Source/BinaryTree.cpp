//Binary Tree is a tree with not more than two child nodes.
//If it has 0 or exactly 2 nodes then it is a strict binary tree
//If children is zero then it is a leaf node
//A tree with n nodes will have n-1 edges, A tree never has a cycle
//Depth of a node is path length from root to that node
//Height of a node is the longest path of the node from any child leaf node
//Depth of tree is zero while height of tree can vary

//Complete Binary Tree is a binary tree in which it is completely filled except fot the last level
//Last level has to be as left as possible
//So h = floor( log base 2 (n) )
//If all are filled then it is called a perfect binary tree
//Maximum number of nodes in a perfect binary tree = 2^0 + 2^1 + 2^2 + 2^3 + ... + 2^h = 2^(h+1) - 1
//So h = log base 2 (n+1) - 1
//More: Video 25, 26

//Cost of serching and other operations depends upon the height of binary tree so we want to keep
//our binary tree less in height but broad

//Binary trees can be stored dynamicaaly using a struct and class or by using an Array
//like 1 2 3 4 5 6 7 in array will be 1 root with 2 & 3 child then 4 & 5 child of 2 and 6 & 7 child of 3
//This is used for perfect balanced binary tree
//A balanced binary tree has left node data lesser or equal to the current node and right has greater

//To differentiate between tree and graph also we can do degree = 2*(n-1) for tree - Handshaking lemma

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class BinaryTree
{
private:
    struct Node
    {
        int data;
        Node* left = NULL;
        Node* right = NULL;
    };

    void Delete(Node* node)
    {
        if(node -> left != NULL)
            Delete(node -> left);
        if(node -> right != NULL)
            Delete(node -> right);
        delete node;
    }

    bool isBST(Node* node, Node* l=NULL, Node* r=NULL)
    {
        if (node == NULL)
            return true;
        
        if ((l != NULL && node -> data < l -> data) ||
            (r != NULL && node -> data > r -> data))
            return false;
        
        return (isBST(node -> left, l, node) && isBST(node -> right, node, r));
    }

    int GetHeight(Node* node)
    {
        if(node == NULL)
            return -1;
        return max(GetHeight(node -> left), GetHeight(node -> right)) + 1;
    }

    void DepthFirstTraversalRecurssion (Node* node)
    {
        if(node == NULL)
            return;
        
        cout << node -> data << " ";

        DepthFirstTraversalRecurssion(node -> left);
        DepthFirstTraversalRecurssion(node -> right);
    }
    Node* root;

public:
    BinaryTree(int value)
    {
        root = new Node;
        root -> data = value;
    }

    int FindMin()
    {
        Node* node = root;
        while(node -> left != NULL)
            node = node -> left;
        
        return node -> data;
    }

    int FindMax()
    {
        Node* node = root;
        while(node -> right != NULL)
            node = node -> right;
        
        return node -> data;
    }

    int FindHeight(int value)
    {
        if(root -> data == value)
            return GetHeight(root);
        
        Node* node = root;
        while(true)
        {
            if(value > node -> data)
            {
                if(node -> right == NULL)
                    return -1;
                else if(node -> right -> data == value)
                   return GetHeight(node -> right);
                node = node -> right;
            }
            else
            {
                if(node -> left == NULL)
                    return -1;
                else if(node -> left -> data == value)
                    return GetHeight(node -> left);
                node = node -> left;
            }
        }        
    }

    int FindDepth(int value)
    {
        if(root -> data == value)
            return 0;

        Node* node = root;
        int depth = 0;
        while(true)
        {
            if(value > node -> data)
            {
                if(node -> right == NULL)
                    return -1;
                else if(node -> right -> data == value)
                    return depth + 1;
                node = node -> right;
            }
            else
            {
                if(node -> left == NULL)
                    return -1;
                else if(node -> left -> data == value)
                    return depth + 1;
                node = node -> left;
            }
            depth++;
        }
    }

    bool Search(int value)
    {
        if(root -> data == value)
            return true;

        Node* node = root;
        while(true)
        {
            if(value > node -> data)
            {
                if(node -> right == NULL)
                    return false;
                else if(node -> right -> data == value)
                    return true;
                node = node -> right;                
            }
            else
            {
                if(node -> left == NULL)
                    return false;
                else if(node -> left -> data == value)
                    return true;
                node = node -> left;
            }
        }
    }

    void Insert(int value)
    {
        Node* curNode = new Node;
        curNode -> data = value;

        Node* node = root;
        while (true)
        {
            if(value > node -> data)
            {
                if(node -> right == NULL)
                {
                    node -> right = curNode;
                    break;
                }
                node = node -> right;                
            }
            else
            {
                if(node -> left == NULL)
                {
                    node -> left = curNode;
                    break;
                }
                node = node -> left;
            }
        }
    }

    bool Remove(int value)
    {
        if(root -> data == value)
            return true;

        Node* node = root;
        while(true)
        {
            if(value > node -> data)
            {
                if(node -> right == NULL)
                    return false;
                else if(node -> right -> data == value)
                {
                    Node* del = node -> right;
                    node -> right = NULL;
                    Delete(del);
                    return true;
                }
                node = node -> right;                
            }
            else
            {
                if(node -> left == NULL)
                    return false;
                else if(node -> left -> data == value)
                {
                    Node* del = node -> left;
                    node -> left = NULL;
                    Delete(del);
                    return true;
                }
                node = node -> left;
            }
        }
    }

    void BreadthFirstTraversal()
    {
        Node* node = root;
        queue<Node*> nodeQueue;
        int type = 0;

        while(true)
        {
            if (node != NULL)
            {
                cout << node -> data << " ";
                nodeQueue.push(node);
            }
            
            if(type == 0)
            {
                type++;
                node = nodeQueue.front() -> left;
            }
            else if (type == 1)
            {
                type++;
                node = nodeQueue.front() -> right;
            }
            else
            {
                type = 1;
                nodeQueue.pop();

                if (nodeQueue.empty())
                    break;
                
                node = nodeQueue.front() -> left;
            }
        }
        cout << endl;
    }

    void DepthFirstTraversalUsingRecurssion()
    {
        DepthFirstTraversalRecurssion(root);
        cout << endl;
    }

    bool IsBinarySearchTree()
    {
        return isBST(root);
    }

    ~BinaryTree()
    {
        Delete(root);
    }
};

int main()
{
    {
        BinaryTree tree(15);
        tree.Insert(10);
        tree.Insert(20);
        tree.Insert(8);
        tree.Insert(12);
        tree.Insert(17);
        tree.Insert(25);
        tree.Insert(6);
        tree.Insert(11);
        tree.Insert(16);
        tree.Insert(27);
        cout << tree.Remove(25) << endl;
        cout << tree.Search(25) << endl;
        cout << tree.Search(5) << endl;
        cout << tree.FindMin() << endl;
        cout << tree.FindMax() << endl;
        cout << tree.FindDepth(17) << endl;
        cout << tree.FindHeight(15) << endl;
        tree.BreadthFirstTraversal();
        tree.DepthFirstTraversalUsingRecurssion();
        cout << tree.IsBinarySearchTree() << endl;
    }
    return 0;
}