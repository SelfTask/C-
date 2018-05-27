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
 
#include "BalancedTree.h"


 
int main(int argc, char* argv[]){
    
    int m;
    
    BalancedBT obj;
    cout<<"\nEnter m (NUMBER OF ELEMENTS): ";
    cin>>m;
    
    int *arr = new int[m];
    
    for(int i = 0; i < m; i++){
        cout<<"Enter Data for Element #"<<i<<": ";
        cin>>arr[i];
    }
    
    obj.runformatTree(arr, 0, m-1);
    
    cout<<"\nIn-Order: ";
    obj.show_InOrder();
    
    cout<<endl;
    
    cout<<"\nPre-Order: ";
    obj.show_PreOrder();
    
    cout<<"\nLevel-Order: ";
    obj.show_LevelOrder();
    
    delete[] arr;
    return 0;
}

