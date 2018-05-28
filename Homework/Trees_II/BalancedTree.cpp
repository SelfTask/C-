/* Filename: BalancedTree.cpp
 * Name: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Tree II
 * Purpose: Functions to include would be insert, delete, balance, print with the 4 types of traversals.
 *          Show that it works by randomly filling the tree, and selectively deleting elements and then traversing the tree.
 * Date: 26 May 2018
 */


#include <iostream>
#include "BalancedTree.h"
#include <queue>

using namespace std;

BalancedBT::BalancedBT(){
    root = NULL;
}

int BalancedBT::getLength(Node *node){
    int maxLength = 0;
    
    if (node != NULL)
        maxLength = max(getLength(node->left), getLength(node->right));
    
    return maxLength + 1;
}
 

/**********************************************
* Functions with different types of rotations *
***********************************************/

BalancedBT::Node *BalancedBT::rightToRight(Node *node){
    Node *temp;
    temp = node->right;
    node->right = temp->left;
    temp->left = node;
    return temp;
}


BalancedBT::Node *BalancedBT::leftToLeft(Node *node){
    Node *temp;
    temp = node->left;
    node->left = temp->right;
    temp->right = node;
    return temp;
}
 

BalancedBT::Node *BalancedBT::leftToRight(Node *node){
    Node *temp;
    temp = node->left;
    node->left = rightToRight (temp);
    return leftToLeft (node);
}
 

BalancedBT::Node *BalancedBT::rightToLeft(Node *node){
    Node *temp;
    temp = node->right;
    node->right = leftToLeft (temp);
    return rightToRight(node);
}

//Balances Tree with rotating node
BalancedBT::Node *BalancedBT::balance(Node *node){

    if ((getLength(node) - getLength(node)) > 1){
        
        if ((getLength(node->left) - getLength(node->left)) > 0)
            node = leftToLeft (node);
        else
            node = leftToRight(node);
        
    }else if ((getLength(node) - getLength(node)) < -1){
        if ((getLength(temp->right) - getLength(temp->right)) > 0)
            node = rightToLeft (node);
        else
            node = rightToRight(node);
    }
    
    return node;
}

//Insert data into Tree
BalancedBT::Node *BalancedBT::insert(Node *root, int data){
    if (root == NULL){
        root = new Node;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (data < root->data){
        root->left = insert(root->left, data);
        root = balance (root);
    }else if (data >= root->data){
        root->right = insert(root->right, data);
        root = balance (root);
    }
    
    return root;
}


void BalancedBT::runInsert(int inVal){
    root = insert(root, inVal);
}


void BalancedBT::print_PreOrder(Node *root){
    
    if(root != NULL){
        cout<<root->data<<" ";
        print_PreOrder(root->left);
        print_PreOrder(root->right);
    }
}

void BalancedBT::print_InOrder(Node *root){
    
    if(root != NULL){
        print_InOrder(root->left);
        cout<<root->data<<" ";
        print_InOrder(root->right);
    }
}

void BalancedBT::print_PostOrder(Node *root){
    if (root == NULL)
            return;
         print_PostOrder(root->left);
         print_PostOrder(root->right);
         cout<<root->data<<" ";
}

//Prints out tree in Level Order
void BalancedBT::print_Level(Node* n){
    queue<Node*> q;

    if(n)
        q.push(n);
    
    while(q.empty() == false){
        Node * tempNode = q.front();
        
        q.pop();
        
        cout<<tempNode->data<<" ";

        if(tempNode->left) 
            q.push(tempNode->left);
        
        if(tempNode->right) 
            q.push(tempNode->right);
        
    };
}

//Searches for value to be deleted
BalancedBT::Node* BalancedBT::deleteByVal(Node* root, int val){

    if(root == NULL) 
        return root;
 
    //Determines where the value to be deleted is at
    if(val < root->data){
        
        root->left = deleteByVal(root->left, val);
        
    }else if(val > root->data){
        
        root->right = deleteByVal(root->right, val);
        
    }else{
        //Checks number of child hold a parent has
        if(root->left == NULL){
            
            Node *temp = root->right;
            delete root;
            return temp;
        }else if(root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        
        Node* current = root->right;
 
        //Traverses to the lowest left node
        while(current->left != NULL)
            current = current->left;
 
        Node* temp = current;
 
        root->data = temp->data;
        root->right = deleteByVal(root->right, temp->data);
    }
    return root;
}

void BalancedBT::run_delete(int Data){
    root = deleteByVal(root, Data);
}

/**********************************************
* Functions that displays different Order(s)  *
***********************************************/

void BalancedBT::show_PreOrder(){
    print_PreOrder(root);
}

void BalancedBT::show_InOrder(){
    print_InOrder(root);
}

void BalancedBT::show_PostOrder(){
    print_PostOrder(root);
}

void BalancedBT::show_LevelOrder(){
    print_Level(root);
}


void BalancedBT::show_allOrder(){
        cout<<"\nPre-Order: ";
        show_PreOrder();
    
        cout<<"\nIn-Order: ";
        show_InOrder();
    
        cout<<"\nPost-Order: ";
        show_PostOrder();
    
        cout<<"\nLevel-Order: ";
        show_LevelOrder();
        
        cout<<endl;
}
