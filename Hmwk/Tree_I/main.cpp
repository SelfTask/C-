/* Filename: main.cpp
 * Name: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Tree I
 * Purpose: Create an m-arry Tree that goes Left to Right
 * Date: 21 May 2018
 */

#include <iostream>
 
using namespace std;
 
#include "Node.h"

//Prototypes
Node *createNode(int);
void formatTree(Node **, int[], int, int);
void print_PreOrder(Node *);
void print_InOrder(Node *);
 
int main(int argc, char* argv[]){
    
    int m;
    
    Node *root;
    
    cout<<"\nEnter m (NUMBER OF ELEMENTS): ";
    cin>>m;
    
    int *arr = new int[m];
    
    for(int i = 0; i < m; i++){
        cout<<"Enter Data for Element #"<<i<<": ";
        cin>>arr[i];
    }
    
    formatTree(&root, arr, 0, m-1);
    
    cout<<"\nIn-order: ";
    print_InOrder(root);
    
    cout<<endl;
    
    cout<<"\nPre-order: ";
    print_PreOrder(root);
    
    delete[] arr;
    return 0;
}

Node *createNode(int data){
    
    Node *newNode = new Node;
 
    if(newNode != NULL){
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
 
    return newNode;
}
 
void formatTree(Node **root, int arr[], int start, int end){
    
    if(start <= end){
        int mid = (start + end + 1) / 2;
 
        *root = createNode(arr[mid]);
        formatTree(&((*root)->left), arr, start, mid - 1);
        formatTree(&((*root)->right), arr, mid + 1, end);
    }
}
 
void print_PreOrder(Node *root){
    
    if(root != NULL){
        cout<<root->data<<"  ";
        print_PreOrder(root->left);
        print_PreOrder(root->right);
    }
}

void print_InOrder(Node *root){
    
    if(root != NULL){
        print_InOrder(root->left);
        cout<<root->data<<"  ";
        print_InOrder(root->right);
    }
}