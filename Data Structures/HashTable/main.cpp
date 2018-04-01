/* 
 * File:   main.cpp
 * Author: Kevin
 *
 * Created on March 31, 2018, 3:38 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>       //For string manipulation

#include "hash.h"
using namespace std;


int main(int argc, char** argv) {
    Hash test;
    
    //Assign items to the buckets
    test.addItem("Paul", "Locha");
    test.addItem("Kim", "Iced Mocha");
    test.addItem("Emma", "Strawberry Smoothy");
    test.addItem("Annie", "Hot Chocolate");
    test.addItem("Sarah", "Passion Tea");
    test.addItem("Pepper", "Caramel Mocha");
    test.addItem("Mike", "Chai Tea");
    test.addItem("Steve", "Apple Cider");
    test.addItem("Bill", "Root Beer");
    test.addItem("Marie", "Skinny Latte");
    test.addItem("Susan", "Water");
    test.addItem("Joe", "Green Tea");
    
    //Display entire hash table
    //test.printTable();
    
    test.printItem(0);
    
    return 0;
}

