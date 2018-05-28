/* Filename: main.cpp
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
#include <ctime>    //For RNG

using namespace std;
 
int main(int argc, char* argv[]){
    //Seed for RNG
    srand(time(NULL));
    
    int m = 10;  //Stores number of elements
    int inData, //Store data input
        numDelete;  //Stores number of nodes to be deleted
    
    //Object for the tree class
    BalancedBT tree;
    
    cout<<"\nLet m (NUMBER OF ELEMENTS) = "<<m<<endl;
 
    //cout<<"\nEnter m (NUMBER OF ELEMENTS): ";
    //cin>>m;
 
    /*
    //Inserts that onto tree
    for(int i = 0; i < m; i++){
        cout<<"Enter Data for Element #"<<i+1<<": ";
        cin>>inData;
        tree.runInsert(inData);
    }
    */
    
    cout<<"\nNow randomly filling the tree...\n";
    //Randomly fills in Tree
    for(int i = 0; i < m; i++){
        inData = rand()%99;
        tree.runInsert(inData);
    }
    
    cout<<endl;
    //Displays tree in Pre, In, Post, and Level order
    tree.show_allOrder();

    cout<<endl;
    
    
    //Requests if user would like to delete a node by value
    do{
        cout<<"\nHow many nodes would you like to delete from the AVL Tree?\n";
        cout<<"Enter \"0\" if do NOT wish to delete.\n";
        cout<<"\nUser Input: ";
        cin>>numDelete;

        if(numDelete < 0)
            cout<<"\nInput Error: Number of Deletion(s) must be 0 or greater.\n";
        else if(numDelete > m)
            cout<<"\nInput Error: Number of Deletion(s) must be less than the inputted m\n";
            
        
    }while(numDelete < 0 || numDelete > m);
    
    //Prompts user which integer value to delete
    for(int i = 0; i < numDelete; i++){
        cout<<"\nEnter in the integer you wish to delete for Node #"<<i+1<<": ";
        cin>>inData;
        
        tree.run_delete(inData);
        
        tree.show_allOrder();

        cout<<endl;
    }
    
    return 0;
}
