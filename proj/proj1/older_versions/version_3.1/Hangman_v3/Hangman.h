/* 
 * File:   Hangman.h
 * Author: dangerouspirate
 *
 * Created on April 5, 2018, 12:00 PM
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
    
   //Displays the title
   void titleDisplay();
   
   //Displays the mention for the option
   void menuDisplay();
    
};

#endif /* HANGMAN_H */

