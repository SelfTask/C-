/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hangman.h
 * Author: dangerouspirate
 *
 * Created on April 5, 2018, 12:00 PM
 */

#ifndef HANGMAN_H
#define HANGMAN_H

using namespace std;

class Hangman{
private:
    string word; //Holds the chosen word of the game
    
   
   //Base game of Hangman
   void coreGame(int);
   
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
   //Displays the title
   void titleDisplay();
   
   //Displays the mention for the option
   void menuDisplay();
    
};

#endif /* HANGMAN_H */

