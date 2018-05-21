/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Hash Comparison
 * Purpose: Determine their order. O(N), O(log(N)), and O(1)
            with Search algorithms: Linear, Binary, and Hash
 * Created on May 19, 2018, 11:20 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>       //RNG
#include <set>        //Use to ensure that each string is unique
#include <algorithm> //For sorting array for Binary search

#include "Linear_Binary_Searches.h" //Contains FNs for Linear and Binary Searches
#include "Hash_Chaining.h"  //Contains hashing table's class

using namespace std;


string rndStr(const int);
void ptrArr(string*, const int);

int main(int argc, char** argv) {
    srand(time(NULL));
    
    set<string> s;
    
    const int size = 20;
 
    int ceqL = 0, ccomL = 0, cincrL = 0, carithL = 0,
        ceqB = 0, ccomB = 0, cincrB = 0, carithB = 0,
        ceqH = 0, ccomH = 0, cincrH = 0, carithH = 0;
    
        
    const int N = 2000000;
    
    const int loop = 20000000; 
    cout<<"\nLet N = "<<N<<endl;
    
    string *arr1 = new string[N];
    string *arr2 = new string[N];
    string *arr3 = new string[N];
    
    string *un_knownHalf = new string [N];
    
    for(int i = 0; i < N; i++){
        string tempRndStr = rndStr(size);   //temporarily stores a random string that's 20 characters long
        
        //Assigns 3 arrays with the same 20 char length strings
        arr1[i] = tempRndStr;
        arr2[i] = tempRndStr;
        arr3[i] = tempRndStr;
        
        //Stores the randomly generated strings to check for uniqueness
        s.insert(tempRndStr);
        
        //50-50 mix of given strings that are in the array and those that are not
        if(i%2 == 0)
            un_knownHalf[i] = tempRndStr;
        else{
            //Assigns a string that has not been in the array
            string tempDiffStr = rndStr(size);
            
            //Makes certain 50% of the random strings are unique
            while(s.count(tempDiffStr) != 0){
                tempDiffStr = rndStr(size);
            };
                un_knownHalf[i] = tempDiffStr;
        }
    }
    
    sort(arr2, arr2+size);
    sort(un_knownHalf, un_knownHalf+size);
    string findVal = un_knownHalf[rand()%(N-1)];
    int results;
          

    int start = time(0);
    for(int i = 0; i < loop; i++){
        
        // Search the array for findVal
        searchList(arr1, size, findVal, ceqL, ccomL, cincrL);
        
    }
    int end = time(0);

    cout<<"\nwhen LOOP = "<<loop;
    cout<<"\nRuntime for Linear Search (SECONDS) = "<<end-start<<endl;
    cout<<"\nOperations of Equals = "<<ceqL;
    cout<<"\nOperations of Compares = "<<ccomL;
    cout<<"\nOperations of Increments = "<<cincrL;
    cout<<"\nOperations of Arithmetic = "<<carithL;
    cout<<"\nTotal Operations = "<<ceqL+ccomL+cincrL<<endl;
    cout<<"\n--------------------------------------------------------\n";

    
  
    start = time(0);
    for(int i = 0; i < loop; i++){
        
        binarySearch(arr2, size, findVal, ceqB, ccomB, cincrB, carithB);
        
    }
    end = time(0);

    cout<<"\nwhen LOOP = "<<loop;
    cout<<"\nRuntime for Binary Search (SECONDS) = "<<end-start<<endl;
    cout<<"\nOperations of Equals = "<<ceqB;
    cout<<"\nOperations of Compares = "<<ccomB;
    cout<<"\nOperations of Increments = "<<cincrB;
    cout<<"\nOperations of Arithmetic = "<<carithB;
    cout<<"\nTotal Operations = "<<ceqB+ccomB+cincrB+carithB<<endl;
    cout<<"\n--------------------------------------------------------\n";
    
    
    Hash h(N);
    h.insert(arr3);
    
 
    start = time(0);
    for(int i = 0; i < loop; i++){ 
        
        h.findHash(findVal, ceqH, ccomH, carithH);

    }
    end = time(0);
    cout<<"\nwhen LOOP = "<<loop;
    cout<<"\nRuntime for Hash Linked List (SECONDS) = "<<end-start<<endl;
    cout<<"\nOperations of Equals = "<<ceqH;
    cout<<"\nOperations of Compares = "<<ccomH;
    cout<<"\nOperations of Increments = "<<cincrH;
    cout<<"\nOperations of Arithmetic = "<<carithH;
    cout<<"\nTotal Operations = "<<ceqH+ccomH+cincrH+carithH<<endl;
    cout<<"\n--------------------------------------------------------\n";
    
    // display the Hash table
    //h.displayHash();
    /*
    //Print out the arrays
    ptrArr(arr1, N);
    cout<<endl;
    ptrArr(arr2, N);
    cout<<endl;
    ptrArr(arr3, N);
    cout<<endl;
    ptrArr(un_knownHalf, N);
    cout<<endl;
    */
    //Deallocate Memory
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] un_knownHalf;
    
    return 0;
}

string rndStr(const int size){
    char letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
                      'o','p','q','r','s','t','u','v','w','x','y','z','0','1',
                      '2','3','4','5','6','7','8','9'};
    
    int szLetters = sizeof(letters)/sizeof(letters[0]);
    char *arrChar = new char[size];
    
    for(int i = 0; i < size; i++){
        arrChar[i] = letters[rand()%(szLetters - 1)];
    }
    
    string str = arrChar;
    
    delete[] arrChar;
return str;}

void ptrArr(string *arr, const int size){
    
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<"  ";
        
        if((i+1)%5 == 0)
            cout<<endl;
    }
}

