
/* 
 * File:   main.cpp
 * Author: Kevin
 *
 * Created on March 31, 2018, 2:16 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;


//Prints a tree based on how high the user wants
int main(int argc, char** argv) {
    //prompts user for height of tree
    cout<<"Enter height for pine tree: ";
    int numRow;
    cin>>numRow;
    
    //counts the number of spaces for front of each row
    int countSpace = numRow;
    
    //Loop the number of rows for tree
    for(int i = 0; i < numRow; i++){
        //loops to print out space in front of each row
        for(int j = 0; j < countSpace; j++){
            cout<<" ";
        }
        //Display an odd number of leaves
        if(i % 1 == 0)
            for(int k = 0; k < (i * 2) + 1; k++)
                cout<<"#";
        
        //Ends the row
        cout<<endl;
        //decrements the number of space after each row
        countSpace--;
    }
    
    //prints the number of spaces for the front of the stump
    for(int i = 0; i < numRow; i++)
        cout<<" ";
    cout<<"#"<<endl;
    
    
    return 0;
}
