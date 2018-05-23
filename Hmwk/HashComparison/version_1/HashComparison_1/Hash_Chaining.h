/* 
 * File:   Hash_Chaining.h
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Hash Comparison
 * Purpose: Determine their order. O(N), O(log(N)), and O(1)
            with Search algorithms: Linear, Binary, and Hash
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
    void insert(string*);
 
    //Uses RS-Hash to generate hash value
    unsigned int RSHash(string str){
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
    void displayHashTable();
    
    //Determines if a key 
    bool findHash(string, int&, int&, int&);
};

//Constructor
Hash::Hash(int N)
{
    this->N = N;    //Sets the number of elements
    HashTable = new list<string>[this->N];
}
 
//Pushes keys onto hash table
void Hash::insert(string *key)
{
    for(int i = 0; i < N; i++){
        //Generates an index for the key
        int index = RSHash(key[i])%N;
        //pushes the key value onto table with selected index
        HashTable[index].push_back(key[i]); 
    }
}
 

 
//Displays Hash Table
void Hash::displayHashTable() {
  for (int i = 0; i < N; i++) {
    cout << i;
    for (auto x : HashTable[i])
      cout << " --> " << x;
    cout << endl;
  }
}

bool Hash::findHash(string key, int& ceq, int &ccom, int &arith){
    ceq++;
    arith++;
    int index = RSHash(key) % N;
    ccom++;
    if(HashTable[index].back() != "\0")
        return true;
    else 
        return false;
}
#endif /* HASH_CHAINING_H */

