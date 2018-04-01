
/* 
 * File:   Hash.h
 * Author: Kevin
 *
 * Created on March 31, 2018, 3:59 PM
 */

#ifndef HASH_H
#define HASH_H

#include <cstdlib>
#include <iostream>
#include <string>       //For string manipulation

using namespace std;
class Hash{
    private:
        static const int tableSize = 10; //Allows us to define the size of the table inside the class
        
        struct Item{
            string name;    //stores a name of a person
            string drink;   //that person's favorite drink;
            Item *next;     //Has the ability to point to another "Item"
        };
        
        //Creating hash table
        Item *HashTable[tableSize]; //We're using an array as our table
                                    //It also has the ability to point to an Item
        
    public:
        //Constructor
        Hash();
        int hash(string);         //Generates an integer index from a string that's the key 
        void printValue(int);    //Prints out the values within an index
        void addItem(string, string);   //Assigns values name and favorite drink to the item
        int countChain(int);    //Returns the number of Items within a chain
                                //Accepts the index
        void printTable();   //Prints the entire hash table
        void printItem(int);    //prints one item with index
        

};



#endif /* HASH_H */

