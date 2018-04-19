/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Assignment: Project 1
 * Course: CSC-17C (42475)
 * Purpose: Utilize STL library.  (Maps, Sets, Lists, Stacks and Queues), 
 *              with Iterators and Algorithms
 * Created on April 10, 2018, 11:59 AM
 */

#include <ctime>
#include <cstdlib>
#include <iostream> //For input output
#include <fstream>  //Use to obtain words from words.txt
#include "WordFetch.h"  
#include "Hangman.h"

using namespace std;

int main(int argc, char** argv) {
    srand(time(NULL));
    
    //Declares object for Hangman class
    Hangman h;
    //Display the Hangman title on the screen
    h.titleDisplay();
    //Displays the menu to select game mode
    h.menuDisplay();
     
    return 0;
}