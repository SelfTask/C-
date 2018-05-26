/* Filename: Node.cpp
 * Name: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Tree I
 * Purpose: Create an m-arry Tree
 * Date: 21 May 2018
 */

#include "Node.h"
#include <iostream>
#include <queue>

using namespace std;

//Constructor
BinaryTree::BinaryTree(){
    root = NULL;

}

//Inserts inputted data onto tree
void BinaryTree::insert(int inVal) {
    Node *newNode = new Node;
    Node *temp;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = inVal;


    if(root == NULL) {
        root = newNode;
    }else{
        Node *tRoot;
        tRoot = root;

        while(tRoot != NULL){
            temp = tRoot;

            if(tRoot->data%2 == 0){
                tRoot = tRoot->right;
            }else{
                tRoot = tRoot->left;
            }
        };

        if(temp->data%2 != 0){
            temp->left = newNode;
        }else{
            temp->right = newNode;
        }
    }
}


 //Borrowed from Dr. Lehr's code during class
 
/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void BinaryTree::prntPst(Node *n){
     if (n == NULL)
        return;
     // first recur on left subtree
     prntPst(n->left);
     // then recur on right subtree
     prntPst(n->right);
     // now deal with the node
     cout<<n->data<<" ";
}
 
/* Given a binary tree, print its nodes in inorder*/
void BinaryTree::prntIn(Node *n){
     if (n == NULL)
          return;
     /* first recur on left child */
     prntIn(n->left);
     /* then print the data of node */
     cout<<n->data<<" ";  
     /* now recur on right child */
     prntIn(n->right);
}
 
/* Given a binary tree, print its nodes in preorder*/
void BinaryTree::prntPre(Node *n){
     if (n == NULL)
          return;
     /* first print data of node */
     cout<<n->data<<" ";  
     /* then recur on left subtree */
     prntPre(n->left);  
     /* now recur on right subtree */
     prntPre(n->right);
}    

void BinaryTree::prntLvl(Node* n){
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

void BinaryTree::showPre(){
 
    this->prntPre(root);
}

void BinaryTree::showIn(){
 
    this->prntIn(root);
}

void BinaryTree::showPst(){
 
    this->prntPst(root);
}

void BinaryTree::showLvl(){
    this->prntLvl(root);
}