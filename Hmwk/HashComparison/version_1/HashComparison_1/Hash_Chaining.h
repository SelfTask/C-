/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hash_Chaining.h
 * Author: Kevin
 *
 * Created on May 19, 2018, 11:20 PM
 */

#ifndef HASH_CHAINING_H
#define HASH_CHAINING_H
// CPP program to implement hashing with chaining
#include<iostream>
#include <list>
using namespace std;
 
class Hash
{
    int N;    //Number of elements

    //Pointer to represent to array and chaining 
    list<string> *HashTable;
    
public:
    Hash(int);  // Constructor
 
    //Inserts an array of keys on to hash table
    void insertItem(string*);
 
    //Uses RS-Hash to generate hash value
    unsigned int hashFunction(string str){
        unsigned int b = 845961;
        unsigned int a = 68456;
        unsigned int hash = 0;
        for(std::size_t i = 0; i < str.length(); i++)
        {
            hash = hash * a + str[i];
            a = a * b;
        }

        return hash;
    }
 
    //Displays the entire hash table
    void displayHash();
    
    //Determines if a key 
    bool findHash(string);
};

//Constructor
Hash::Hash(int N)
{
    this->N = N;    //Sets the number of elements
    HashTable = new list<string>[this->N];
}
 
//Pushes keys onto hash table
void Hash::insertItem(string *key)
{
    for(int i = 0; i < N; i++){
        //Generates an index for the key
        int index = hashFunction(key[i])%N;
        //pushes the key value onto table with selected index
        HashTable[index].push_back(key[i]); 
    }
}
 

 
//Displays Hash Table
void Hash::displayHash() {
  for (int i = 0; i < N; i++) {
    cout << i;
    for (auto x : HashTable[i])
      cout << " --> " << x;
    cout << endl;
  }
}

bool Hash::findHash(string key){
    int index = hashFunction(key) % N;
    if(HashTable[index].back() != "\0")
        return true;
    else 
        return false;
}
#endif /* HASH_CHAINING_H */

