/* 
 * File:   WordFetch.h
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Assignment: Project 1
 * Course: CSC-17C (42475)
 * Purpose: Obtains random word(s) then insert them into containers: Set, List, Stack, and Queue
 * Created on April 10, 2018, 11:59 AM
 */

#ifndef WORDFETCH_H
#define WORDFETCH_H

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>  //Use to obtain words from words.txt
#include <set>  //For using sets
#include <list> //For using lists
#include <stack>    //For using stacks
#include <queue>    //For using queues

#include <algorithm>
#include <iterator>
using namespace std;

class WordFetch{
    private:
        string *wordList;   //Temporarily stores the words for different game modes
        int numRounds;      //Stores the number of rounds
        list<string> l;     //Object to STL's list
        stack<string> st;   //Object to STL's stack
        set<string> s;      //For display sorted free words & custom word insertion
        queue<string> q;    //Object to STL's queue


    public:
        //Stores all inputs of the round into STL's list
        void storeInputList(string);

        //Displays previously inputted values of the round from STL's list
        void displayInputList();

        //Clears previously guessed values
        void deleteInputHist();

        //obtains random words from .txt
        string getRandWords();
        //Stores
        void wordsInSet();

        //Displays list of possible words
        void DisplayListSet();

        //Stores # of words onto stack based on # of rounds (Marathon Mode)
        void wordsInStack();

        //Returns a random word for Marathon Mode
        string popWordMarathon();
        
        //Returns a random word from set
        string getEzWord()const;
        
        //Obtains number of words based on number of rounds
        void setWords(int);

        //Destructor
        //Insert new custom words into library with queue and set
        //Deallocates string pointer use to temporarily hold the words
        ~WordFetch();

        //Getter method for the number of rounds
        int getNumRounds()const;
        
        //Inserts words into library
        void addWordLib(string);
        
        //Accepts custom words with queue
        void queueCustomWords(string);
        
        //Returns custom words from queue
        string getWordCustom();
        
        //Checks if queue is empty
        bool queueIsEmpty();
        
        //Returns word for normal mode
        string getWord()const;
        
        //Checks if stack is empty
        bool stackIsEmpty();
        
        //clears the list of words
        void clearWordListSet();
        
        //sorts custom words
        void sortQueueCustomWord();
        
        //Removes a word in EZ MODE from STL's Stack
        void removeWordEZMode();
        
    
};


#endif /* WORDFETCH_H */

