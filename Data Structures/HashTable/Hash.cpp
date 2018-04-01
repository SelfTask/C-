#include "Hash.h"

#include <cstdlib>
#include <iostream>
#include <string>       //For string manipulation

using namespace std;

Hash::Hash(){
    for(int i = 0; i < tableSize; i++){
        HashTable[i] = new Item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = NULL;
    }
        
        
}

int Hash::hash(string key){
    int hash = 0;

      
    for(int i = 0; i < key.length(); i++){
        hash += (int)key[i];
    }
    
    int index = hash % tableSize;   //index = remainder of (hash / tableSize)
    
return index;}


void Hash::addItem(string name, string drink){
    int index = hash(name); //get an integer index from hash with name as the key
    
    //Check if that index of the Hash Table array is empty
    if(HashTable[index]->name == "empty"){
        //if it is then go ahead an assign the values accordingly
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }else{
        
        
        //if not then create a pointer pointing to the index of the array for CHAINING
        Item *ptrHashTable = HashTable[index];
        Item *n = new Item; //Creating new Item to store info if HashTable[index] is filled already
        
        //Assign values to the new node
        n->name = name;
        n->drink = drink;
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
    
    if(HashTable[index]->name == "empty"){
        return counter;
    }
    while(ptr != NULL){
        counter++;
        ptr = ptr->next;
    };
return counter;}


//Prints out entire hash table
void Hash::printTable(){
    int numOfItems = 0;
    for(int i = 0; i < tableSize; i++)
        numOfItems += countChain(i);    //Gets total number of in items in a chain
    cout<<"Number of Items in the Hash Table: "<<numOfItems;
    cout<<"\n--------------------------------\n";
    for(int i = 0; i < tableSize; i++){
        cout<<"{ "<<HashTable[i]->name<<" }";
        if(HashTable[i]->name != "empty"){
            Item *ptr = HashTable[i];
            while(ptr != NULL){
                cout<<" --> [ "<<ptr->drink<<" ]";
                ptr = ptr->next;
            };
        }
        cout<<endl;
    }
}


//Prints only one bucket
void Hash::printItem(int index){
    cout<<"HashTable[ "<<index<<" ]->name = "<<HashTable[index]->name<<endl;
    
    if(HashTable[index]->name != "empty")
        cout<<"HashTable[ "<<index<<" ]->drink = "<<HashTable[index]->drink<<endl;
    if(countChain(index) > 1){
        Item *ptr = HashTable[index];
        cout<<"\t\t\t\t";
        while(ptr != NULL){
            cout<<" --> [ "<<ptr->drink<<" ]";
            ptr = ptr->next;
            
        };
    }
}