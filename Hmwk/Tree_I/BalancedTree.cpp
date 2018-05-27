#include <iostream>
#include "BalancedTree.h"
#include <queue>

using namespace std;

 
void BalancedBT::formatTree(Node **root, int arr[], int start, int end){
    
    if(start <= end){
        int mid = (start + end + 1) / 2;
 

        
        Node *newNode = new Node;
 
    if(newNode != NULL){
        newNode->data = arr[mid];
        newNode->left = NULL;
        newNode->right = NULL;
    }
        *root = newNode;
        formatTree(&((*root)->left), arr, start, mid - 1);
        formatTree(&((*root)->right), arr, mid + 1, end);
    }
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


/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
void BalancedBT::deleteNode(Node *r, int key)
{
    // base case
    if (r == NULL) return r;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < r->key)
        r->left = deleteNode(r->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > r->key)
        r->right = deleteNode(r->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (r->left == NULL)
        {
            temp = r->right;
            free(r);
            temp = root;
            return;
        }
        else if (r->right == NULL)
        {
            temp = r->left;
            free(r);
            temp = root;
            return;
        }
 
        
        
        Node* current = r->right;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
        // Copy the inorder successor's content to this node
        r->key = temp->data;
 
        // Delete the inorder successor
        root->right = deleteNode(r->right, temp->data);
    }
    
    // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        temp = current;
        root = temp;
}

void BalancedBT::runformatTree(int arr[], int start, int end){

    BalancedBT::formatTree(&root, arr, start, end);
}


void BalancedBT::show_PreOrder(){
    print_PreOrder(root);
}

void BalancedBT::show_InOrder(){
    print_InOrder(root);
}


void BalancedBT::show_LevelOrder(){
    print_Level(root);
}

