/* 
 * File:   Hangman.h
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Assignment: Project 1
 * Course: CSC-17C (42475)
 * Purpose: Code for Hangman with it's different Modes
 *          Obtains retrieve/store elements from STL's containers: Set, 
 *              List, Stack, Queue, Map
 * Created on April 10, 2018, 11:59 AM
 */

#ifndef HANGMAN_H
#define HANGMAN_H

#include "Scoreboard.h"
#include "WordFetch.h"

using namespace std;

class Hangman{
private:
    string word;     //Holds the chosen word of the game
    Scoreboard sc;   //Object for class handling scores & usernames w/ STL's Map
    WordFetch fetch; //Obtains words from containers
    
    
   //Base game of Hangman
   void coreGame(int, string);
   
   //Displays the hanging man
   void displayHangMan(int); 
   
   //Challenge mode that includes custom amount of rounds
   void marathonMode();
   
   //User enters their own word for a friend
   void customWordMode();
   
   //User chooses the first letter for a random word and that letter will be 
   //given to them
   void ezMode();
   
   //Displays the rules
   void rulesDisplay();
   
public:
    //Constructor
    //Access entire library
    Hangman();
    
    //Destructor
    //Clears set container
    ~Hangman();
    
   //Displays the title
   void titleDisplay();
   
   //Displays the mention for the option
   void menuDisplay();
    
};

#endif /* HANGMAN_H */

