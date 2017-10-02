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
        
}

void BST::InOrder(Node *x) 
{
        
}

void BST::PostOrder(Node *x) 
{
        
}

