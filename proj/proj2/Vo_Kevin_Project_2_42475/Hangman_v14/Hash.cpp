/* 
 * File:   Hash.cpp
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Assignment: Project 2
 * Course: CSC-17C (42475)
 * Purpose: Extend project with recursive sorts, hashing, trees and graphs
 * Created on June 2, 2018, 11:59 AM
 */

#include "Hash.h"
#include <fstream>  //Use to obtain words from words.txt
#include <string>

//Constant string variable to alert that a word DNE in library
const string alertDNE = "WORD-DOES-NOT-EXIST";

Hash::Hash(){
    numItem = 0;
    for(int i = 0; i < tableSize; i++){
        HashTable[i] = new Item;
        HashTable[i]->initial = alertDNE;
        HashTable[i]->next = NULL;
    }
    
   
        
}

void Hash::storeWordInHash(){
    string line;
    ifstream rFileHash ("words.txt");
    if(rFileHash.is_open()){
        while( getline (rFileHash,line) ){
                    //cout<<endl<<line;
            insert(line);
        }
        
        rFileHash.close();
    }
    else cout<<"Unable to open words.txt for hashing.\n"; 
}
unsigned int Hash::RSHash(string str){

    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;
    unsigned int i = 0;
    unsigned int len = str.length();

    for (i = 0; i < len; i++)
    {
            hash = hash * a + (str[i]);
            a *= b;
    }

    return hash;
}


void Hash::insert(string initial){
    numItem++;
    unsigned int index = RSHash(initial) % 1000; //get an integer index from hash with name as the key
    
    //Check if that index of the Hash Table array is empty
    if(HashTable[index]->initial == alertDNE){
        //if it is then go ahead an assign the values accordingly
        HashTable[index]->initial = initial;
    }else{
        
        
        //if not then create a pointer pointing to the index of the array for CHAINING
        Item *ptrHashTable = HashTable[index];
        Item *n = new Item; //Creating new Item to store info if HashTable[index] is filled already
        
        //Assign values to the new node
        n->initial = initial;
        n->next = NULL;

        //Traverse until you reach the end of this chain
        while(ptrHashTable->next != NULL){
            ptrHashTable = ptrHashTable->next;

        };

        //Have the last Item on that chain point to our newest item
        ptrHashTable->next = n;
        
    }
}

//Counts the number of BUCKETS in an index; index + chain(s)
int Hash::countChain(int index){
    Item *ptr = HashTable[index];
    int counter = 0;
    
    if(HashTable[index]->initial == alertDNE){
        return counter;
    }
    while(ptr != NULL){
        counter++;
        ptr = ptr->next;
    };
return counter;}


//Prints only one bucket
void Hash::printItem(int index){
    if(HashTable[index]->initial != alertDNE)
        cout<<"\nYour hinted word(s) may be:\n";
    
    cout<<HashTable[index]->initial<<endl;

    if(countChain(index) > 1){
        Item *ptr = HashTable[index];
        while(ptr != NULL){
            cout<<endl<<ptr->initial;
            ptr = ptr->next;
            
        };
    }
    cout<<endl;
}

//Searches words on hash table
void Hash::searchWord(){
    string word;
    
    //Request word to be hashed and used as index for hash table
    cout<<"\nEnter a word to be searched: ";
    cin>>word;

    //generates index for hash table with RS-Hash
    unsigned int index = RSHash(word) % 1000;
    
    //Prints the item
    printItem(index);
}