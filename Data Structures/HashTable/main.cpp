/* 
 * File:   main.cpp
 * Author: Kevin
 *
 * Created on May 30, 2018, 3:38 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>       //For string manipulation

#include "hash.h"
using namespace std;


int main(int argc, char** argv) {
    Hash test;
    
    //Assign items to the buckets
    test.insert("Mark E. Lehr", "Locha");
    test.insert("Paul", "Locha");
    test.insert("Kim", "Iced Mocha");
    test.insert("Emma", "Strawberry Smoothy");
    test.insert("Annie", "Hot Chocolate");
    test.insert("Sarah", "Passion Tea");
    test.insert("Pepper", "Caramel Mocha");
    test.insert("Mike", "Chai Tea");
    test.insert("Steve", "Apple Cider");
    test.insert("Bill", "Root Beer");
    test.insert("Marie", "Skinny Latte");
    test.insert("Susan", "Water");
    test.insert("Joe", "Green Tea");
    
    //Display entire hash table
    test.printTable();
    
    //test.printItem(0);
    
    return 0;
}

