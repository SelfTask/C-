#include "Hash.h"

#include <cstdlib>
#include <iostream>
#include <string>       //For string manipulation

using namespace std;

Hash::Hash(){
    numItem = 0;
    for(int i = 0; i < tableSize; i++){
        HashTable[i] = new Item;
        HashTable[i]->name = "empty";
        HashTable[i]->initial = "empty";
        HashTable[i]->next = NULL;
    }
        
        
}

int Hash::phoneHash(string init){
    int hashVal = 0;
    int temp;
    for(int i = 0; i < 3; i++){
        if(init[i] == 'A' || init[i] == 'B' || init[i] == 'C')
            temp = 2;
        else if(init[i] == 'D' || init[i] == 'E' || init[i] == 'F')
            temp = 3;
        else if(init[i] == 'G' || init[i] == 'H' || init[i] == 'I')
            temp = 4;
        else if(init[i] == 'J' || init[i] == 'K' || init[i] == 'L')
            temp = 5;
        else if(init[i] == 'M' || init[i] == 'N' || init[i] == 'O')
            temp = 6;
        else if(init[i] == 'P' || init[i] == 'Q' || init[i] == 'R' || init[i] == 'S')
            temp = 7;
        else if(init[i] == 'T' || init[i] == 'U' || init[i] == 'V')
            temp = 8;
        else if(init[i] == 'W' || init[i] == 'X' || init[i] == 'Y' || init[i] == 'Z')
            temp = 9;
        
        hashVal += temp;
    }
return hashVal;}


void Hash::insert(string name, string initial){
    numItem++;
    int index = phoneHash(name); //get an integer index from hash with name as the key
    
    //Check if that index of the Hash Table array is empty
    if(HashTable[index]->name == "empty"){
        //if it is then go ahead an assign the values accordingly
        HashTable[index]->name = name;
        HashTable[index]->initial = initial;
    }else{
        
        
        //if not then create a pointer pointing to the index of the array for CHAINING
        Item *ptrHashTable = HashTable[index];
        Item *n = new Item; //Creating new Item to store info if HashTable[index] is filled already
        
        //Assign values to the new node
        n->name = name;
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
                cout<<" --> [ "<<ptr->initial<<" ]";
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
        cout<<"HashTable[ "<<index<<" ]->initial = "<<HashTable[index]->initial<<endl;
    if(countChain(index) > 1){
        Item *ptr = HashTable[index];
        cout<<"\t\t\t\t";
        while(ptr != NULL){
            cout<<" --> [ "<<ptr->initial<<" ]";
            ptr = ptr->next;
            
        };
    }
}