/* 
 * File:   main.cpp
 * Author: DangerousPirate
 * Purpose: 1) Convert Decimal to Binary
 *          2) Chance an Array of digits as a single Integer
 * Created on June 9, 2018, 11:33 AM
 */

#include <cstdlib>
#include <iostream>
#include <stack>    //Used to store binary digits after conversion from Decimal
#include <sstream>  //Use to convert String value to Decimal



using namespace std;
//Prototypes
//Converts decimal to Binary then pushes the bits into a stack
void decToBin(int, stack<int> &);
//Converts array of digits as a single Int.
int cvrtArr2Int(int[], int);
//Handles negative inputted Decimals into Binary
void twosComp(int);


int main(int argc, char** argv) {
    int inDeci; //Inputted Value
    stack<int> st;  //Stores the single digits of a binary

    cout<<"Enter a base 10 Number: ";
    cin>>inDeci;
    
    //Converts binary then input the bits into stack
    decToBin(inDeci, st);
    
    //Stores the size for the soon-to-be dyn. allocated array
    const int sizeArr = st.size();
    
    //Dynamically allocating memory for an array to accept bits from the stack
    int *storeBit = new int[sizeArr];
    
    //Serves as new index for newly allocated array
    int cntStore = 0;
    
    //Prints and stores the bits of the binary value
    cout<<"\nBinary Value: ";
    while(!st.empty()){
        storeBit[cntStore++] = st.top();
        cout<<st.top()<<" ";
        st.pop();
    }
    
    cout<<endl<<"\t\t";
    
    //Stores array of single digits as a single integer
    int singleVal = cvrtArr2Int(storeBit, sizeArr);
    
    //Prints out the single value
    cout<<"\nThe Single Value = "<<singleVal<<endl;
    
    //Deallocates memory
    delete[] storeBit;
    
    return 0;
}

//Converts decimal to binary then pushes it onto the stack
void decToBin(int deciNum, stack<int> &st){
    while(deciNum > 0){
      
        if(deciNum%2 != 0)
            st.push(1);
        else
            st.push(0);
        
        deciNum/=2;
    };
}

//Convert array of single digits to one integer with stringstream
//then returns it
int cvrtArr2Int(int arr[], int sz){
    string storeAsOne = "";
    int singeInVal = 0;
    
    for(int i = 0; i < sz; i++){
        //cout<<arr[i]<<" ";
        storeAsOne += (arr[i] + '0');   //Converts array of digits as a string
    }
    //cout<<"\nstoreAsOne = "<<storeAsOne<<endl;
    
    //Declares object of string stream to convert string to int
    stringstream string2Int(storeAsOne);    
    
    //converts string to int
    string2Int >> singeInVal;
return singeInVal;}



