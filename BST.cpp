// Jeff Foreman
// CSE 100 04L
// Created on 2 Oct 2017
// Referenced pseudocode found in:
// "Introduction To Algorithms" by Cormen, Leiserson, Rivest, and Stein

#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

BST::BST() 
{
        root = NULL;
}

BST::~BST() 
{
        
}

void BST::Insert(int toInsert) 
{
        Node * y = NULL;
        Node * x = root;
        
        // Create the new node.
        Node * z = new Node();
        z -> val = toInsert;
        z -> left = NULL;
        z -> right = NULL;
        
        // Find an empty position in the tree while following...
        // the properties of a Binary Search Tree.
        while (x != NULL)
        {
                y = x;
                
                if (toInsert < x -> val)
                        x = x -> left;
                else
                        x = x -> right;
        }
        
        z -> parent = y;
        
        // If y is still NULL, then the new node is the new root.
        if (y == NULL)
                root = z;
        
        // If its not the root, then place it in the appropriate position...
        // in relation to y, its parent.
        else if (z -> val < y -> val)
                y -> left = z;
        else 
                y -> right = z;
}

// Pseudocode found on page 298.
void BST::Delete(int toDelete) 
{
        Node * z = Search(toDelete);
        
        if (z -> left == NULL)
                Transplant(z, z->right);
        else if (z -> right == NULL)
                Transplant(z, z->left);
        else
        {
                Node * y = Minimum(z -> right);
                
                if (y -> parent != z)
                {
                        Transplant(y, y -> right);
                        y -> right = z -> right;
                        y -> right -> parent = y;
                }
                
                Transplant(z, y);
                y -> left = z -> left;
                y -> left -> parent = y;
        }
        delete z;
}

void BST::Transplant(Node *u, Node *v) 
{
        if (u -> parent == NULL)
                root = v;
        else if (u == u -> parent -> left)
                u -> parent -> left = v;
        else
                u -> parent -> right = v;
        
        if (v != NULL)
                v -> parent = u -> parent;
}

// Pseudocode found on page 292.
Node *BST::Successor(Node *x) 
{
        if (x -> right != NULL)
                return Minimum(x -> right);
        
        Node * y = x -> parent;
        
        while (y != NULL && x == y -> right)
        {
                x = y;
                y = y -> parent;
        }
}

// Pseudocode found on 291.
Node *BST::Minimum(Node *x) 
{
        // Since the BST property guarantees the minimum is to the leftmost node...
        // Just iterate to said node.
        while (x -> left != NULL)
                x = x -> left;
        
        return x;
}

// Pseudocode found on 291.
Node *BST::Maximum(Node *x) 
{
        // Since the BST property guarantees the maximum is to the rightmost node...
        // Just iterate to said node.
        while (x -> right != NULL)
                x = x -> right;
        
        return x;
}

// Pseudocode found on page 290.
Node *BST::Search(int toFind) 
{
        // Set a temporary node to the root of the tree to begin.
        Node * x = root;
        
        // If the node is null, no solution and therefore returns null.
        // If the value of the node matches the key we are looking for...
        // Then we found the node we are looking for.
        while (x != NULL && toFind != x -> val)
        {
                // If the key is less than the current node, then it is to the left.
                // If it is greater than, then it is to the right.
                if (toFind < x -> val)
                        x = x -> left;
                else
                        x = x -> right;
        }
        
        return x;
}

void BST::Print(TraversalOrder Order) 
{
        if(Order==InOrderTrav)
                InOrder(root);
        else if(Order==PreOrderTrav)
                PreOrder(root);
        else if(Order==PostOrderTrav)
                PostOrder(root);
}

void BST::PreOrder(Node *x) 
{
        if (x != NULL)
        {
                cout << x -> val << endl;
                PreOrder(x -> left);
                PreOrder(x -> right);
        }
}

// Pseudocode found on page 288.
void BST::InOrder(Node *x) 
{
        if (x != NULL)
        {
                InOrder(x -> left);
                cout << x -> val << endl;
                InOrder(x -> right);
        }
}

void BST::PostOrder(Node *x) 
{
        if (x != NULL)
        {
                PostOrder(x -> left);
                PostOrder(x -> right);
                cout << x -> val << endl;
        }
}

