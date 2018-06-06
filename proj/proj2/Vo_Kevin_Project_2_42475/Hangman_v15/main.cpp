/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Assignment: Project 2
 * Course: CSC-17C (42475)
 * Purpose: Extend project with recursive sorts, hashing, trees and graphs
 * Created on June 2, 2018, 11:59 AM
 */

/*
Project 2 Checklist:
--------------------
Hash: Located in Hash.cpp (Lines: 18 - 138)
			Object Declaration of Hash --> Located in Hangman.cpp (Line 27)

			
Tree: Located in BalancedTree.cpp (Lines: 18 - 264)
			Object Declaration of BalancedTree --> Located in Hangman.h (Line 33)

			
Recursive Sorts: Located in RecursiveSorts.cpp (Lines: 4 - 51)
			Object Declaration of RecursiveSorts --> Located in Hangman.cpp (Line 30)

			
Graph: Located in Hangman.cpp (Lines: 834 – 948)
 
*/


#include <ctime>
#include <cstdlib>
#include <iostream> //For input output
#include <fstream>  //Use to obtain words from words.txt
#include "WordFetch.h"  
#include "Hangman.h"    //Contains code for the game

using namespace std;

int main(int argc, char** argv) {
    //Seed for RNG
    srand(time(NULL));
    
    //Declares object for Hangman class
    Hangman h;
    //Display the Hangman title on the screen
    h.titleDisplay();
    //Displays the menu to select game mode
    h.menuDisplay();
     
    return 0;
}