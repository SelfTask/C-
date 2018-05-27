/* Filename: main.cpp
 * Name: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Tree I
 * Purpose: Create an m-arry Tree
 * Date: 21 May 2018
 */

#include <cstdlib>
#include <iostream>
#include "Node.h"

using namespace std;

int main(int argc, char** argv) {
    BinaryTree tree;    //Declare obj for BinaryTree class
    int m;  //Stores number of elements
    int inVal;  //Stores inputed value
    
    //Prompts for number of elements
    cout<<"\nEnter m (NUMBER OF ELEMENTS): ";
    cin>>m;
    
    //Prompts for data
    for(int i = 0; i < m; i++){
        cout<<"\nEnter Value for Node #"<<i<<": ";
        cin>>inVal;
        tree.insert(inVal);
    }
    
    //Prints tree using different traversals 
    cout<<"\n\nPre-Order: ";
    tree.showPre();
    
    cout<<"\n\nIn-Order: ";
    tree.showIn();
    
    cout<<"\n\nPost-Order: ";
    tree.showPst();
    
    cout<<"\n\nLevel-Order: ";
    tree.showLvl();
  
    return 0;
}
