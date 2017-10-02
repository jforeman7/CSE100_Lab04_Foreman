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
        
}

BST::~BST() 
{
        
}

void BST::Insert(int toInsert) 
{
        
}

void BST::Delete(int toDelete) 
{
        
}

void BST::Transplant(Node *u, Node *v) 
{
        
}

Node *BST::Successor(Node *x) 
{
        
}

Node *BST::Minimum(Node *x) 
{
        
}

Node *BST::Maximum(Node *x) 
{
        
}

Node *BST::Search(int toFind) 
{
        
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
        // Print as long as the current node is not NULL.
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

