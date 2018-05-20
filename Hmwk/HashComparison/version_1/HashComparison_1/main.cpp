/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kevin
 *
 * Created on May 19, 2018, 2:28 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <set>
#include <algorithm> //For sorting array for Binary search

#include "Linear_Binary_Searches.h"
#include "Hash_Chaining.h"

using namespace std;

string rndStr(const int);
void ptrArr(string*, const int);

int main(int argc, char** argv) {
    srand(time(NULL));
    
    set<string> s;
    
    const int size = 20;
    for(int k = 1; k <= 8; k*=2){
    int N = 10000000 * k;
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
    string findVal = "6";
    int results;
    
    const int loop = 10000000;        
    
    int start = time(0);
    for(int i = 0; i < loop; i++)
        // Search the array for findVal
        searchList(arr1, size, findVal);
    int end = time(0);
    
    cout<<"\nRuntime for Linear Search = "<<end-start<<endl;
    //cout<<"\nResults = "<<results<<endl;
    
    start = time(0);
    for(int i = 0; i < loop; i++)
        binarySearch(arr2, size, findVal);
    end = time(0);
    
    cout<<"\nRuntime for Binary Search = "<<end-start<<endl;
    //cout<<"\nResults = "<<results<<endl;
    
    
    Hash h(N);
    h.insertItem(arr3);
    
    start = time(0);
    for(int i = 0; i < loop; i++){ 
        h.findHash(findVal);
    }
    end = time(0);
    
    cout<<"\nRuntime for Hash Linked List = "<<end-start<<endl;
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
    }
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

