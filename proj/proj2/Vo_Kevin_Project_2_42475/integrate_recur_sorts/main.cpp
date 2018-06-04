/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: DangerousPirate
 *
 * Created on June 2, 2018, 7:38 PM
 */
#include <iostream>
#include <cstdlib>
#include "RecursiveSorts.h"
#include "BalancedTree.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    RecursiveSorts recurSorts;
    
    string arr[] = {"wife","water","aqua","tea","freak"};
    int numWordTree = sizeof(arr)/sizeof(arr[0]);
    
    //printing sorted array
    for (int i = 0; i<numWordTree ; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    
    char inputSort;
    
    do{
        cout<<"\nEnter 1 to sort ABC Order.";
        cout<<"\nEnter 2 to sort in Reverse.\n";
        cout<<"\nUser Input: ";
        cin>>inputSort;
        
        //Alerts if input is not valid
        if(inputSort != '1' && inputSort != '2')
            cout<<"\nError: Input must be \"1\" or \"2\"\n";
        
    }while(inputSort != '1' && inputSort != '2');
    
    //Sorts forward or backwards depending input
    if(inputSort == '1'){
        recurSorts.recursiveBubbleSort(arr, numWordTree);
        cout<<"\nSorted ABC Order: ";
    }else{
        // Calling function
        recurSorts.recurSelectionSort(arr, numWordTree, 0);
        cout<<"\nSorted Reversed Order: ";
    }
    
    //printing sorted array
    for (int i = 0; i<numWordTree ; i++)
        cout << arr[i] << " ";
    cout << endl;
    

    
    int m = numWordTree;  //Stores number of elements
    int numDelete;  //Stores number of nodes to be deleted
    
    //Object for the tree class
    BalancedBT tree;

    cout<<"\nInserting onto Tree...\n";
    
    //Inserts words onto tree
    for(int i = 0; i < m; i++){
        tree.runInsert(arr[i]);
    }
    
    char inputOrder;    //Use to verify choice of order
    bool isPostOrder = false;
    
    do{
        if(inputSort == '1'){
            cout<<"\nWords in Pre-Order (ABC Order):  ";
            tree.show_PreOrder();
        }else{
            cout<<"\nWords in Pre-Order (Reversed Order):  ";
            tree.show_PreOrder();
        }
        
        if(inputSort == '2'){
            cout<<"\n\nWords in In-Order (ABC Order):  ";
            tree.show_InOrder();
        }else{
            cout<<"\n\nWords in Post-Order (Reversed Order):  ";
            tree.show_PostOrder();
            isPostOrder = true;
        }
        
        cout<<endl<<endl;
        
        if(inputSort == '1')
            cout<<"Are you sure you want Pre-Order (ABC Order)? (y/n)\n";
        else if(inputSort == '2' && isPostOrder == false)
            cout<<"Are you sure you want In-Order (ABC Order)? (y/n)\n";
        else{
            cout<<"Are you sure you want Post-Order (Reversed Order)? (y/n)\n";
        }
            
        cout<<"User Input: ";
        cin>>inputOrder;
        
        if(inputOrder == 'Y')
            inputOrder = 'y';
        else if(inputOrder == 'N')
            inputOrder = 'n';

        if(inputOrder != 'y' && inputOrder != 'n')
            cout<<"\nError: Input must be \"y\" for YES or \"n\" for NO.\n";
    }while(inputOrder != 'y' && inputOrder != 'n');
    
    if(inputOrder == 'n' && inputSort == '1')
        inputSort = '2';
    else if(inputOrder == 'n' && inputSort == '2')
        inputSort = '1';
    
     
    cout<<endl;
    if(inputSort == '1'){
        //Returns strings from tree.r_getValPreOrder();
        cout<<"\nPre = ";
        while(!tree.qPre.empty()){
            cout<<tree.qPre.front()<<" ";
            tree.qPre.pop();
        };
    }else if(inputSort == '2' && isPostOrder == true){
        //Returns strings from tree.r_getValPostOrder();
        cout<<"\nPost = ";
        while(!tree.qPost.empty()){
            cout<<tree.qPost.front()<<" ";
            tree.qPost.pop();
        };
    }else if(inputSort == '2' && isPostOrder == false){
        //Returns strings from tree.r_getValPreOrder();
        cout<<"\nIn = ";
        while(!tree.qIn.empty()){
            cout<<tree.qIn.front()<<" ";
            tree.qIn.pop();
        };
    }
 
 

    
         

    cout<<endl;
    return 0;
}
