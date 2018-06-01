/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hash.h
 * Author: DangerousPirate
 *
 * Created on May 31, 2018, 9:34 PM
 */

#ifndef HASH_H
#define HASH_H

#include <cstdlib>
#include <iostream>
#include <string>       //For string manipulation

using namespace std;

class Hash{
    private:
        int numItem;
        //9+9+9 = 27
        static const int tableSize = 1000; //Allows us to define the size of the table inside the class
        
        struct Item{
            string initial;   //that person's initials;
            Item *next;     //Has the ability to point to another "Item"
        };
        
        //Creating hash table
        Item *HashTable[tableSize]; //We're using an array as our table
                                    //It also has the ability to point to an Item
        
    public:
        //Constructor
        Hash();
        unsigned int RSHash(string str);         //Generates an integer index from a string that's the key 
        void printValue(int);    //Prints out the values within an index
        void insert(string);   //Assigns values name then initial
        int countChain(int);    //Returns the number of Items within a chain
                                //Accepts the index
        void printTable();   //Prints the entire hash table
        void printItem(int);    //prints one item with index
        
        int getNumItem(){return numItem;}
        
        static const int getTableSize(){ return tableSize; }
        
        string getInitial(int indx){
            return HashTable[indx]->initial; 
        }
        
        void storeWordInHash(); 
        void searchWord();

};




#endif /* HASH_H */

