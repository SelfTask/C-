/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WordFetch.h
 * Author: dangerouspirate
 *
 * Created on April 12, 2018, 12:33 AM
 */

#ifndef WORDFETCH_H
#define WORDFETCH_H

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>  //Use to obtain words from words.txt
#include <set>  //For using sets
#include <list> //For using lists
#include <stack>
#include <queue>

#include <algorithm>
#include <iterator>
using namespace std;

class WordFetch{
    private:
        string *wordList;   //Temporarily stores the words for different game modes
        int numRounds;      //Stores the number of rounds
        list<string> l;     //Object to STL's list
        stack<string> st;   //Object to STL's stack
        set<string> s;      //For display entire list in ABC order & custom word insertion
        queue<string> q;    //Object to STL's queue


    public:
        //Stores all inputs of the round into STL's list
        void storeInputList(string);

        //Displays previously inputted values of the round from STL's list
        void displayInputList();

        //Clears previously guessed values
        void deleteInputHist();

        //Stores words into
        void wordsInSet();

        //Displays list of possible words
        void DisplayListSet();

        //Stores # of words onto stack based on # of rounds (Marathon Mode)
        void wordsInStack();

        //Returns a random word for Marathon Mode
        string popWordMarathon();

        //Obtains number of words based on number of rounds
        void setWords(int);

        //Destructor
        //Insert new custom words into library with queue and set
        //Deallocates string pointer use to temporarily hold the words
        ~WordFetch();

        //Getter method for the number of rounds
        int getNumRounds(){return numRounds;}
        
        //Inserts words into library
        void addWordLib(string);
        
        //Accepts custom words with queue
        void queueCustomWords(string);
        
        //Returns custom words from queue
        string getWordCustom();
        
        //Checks if queue is empty
        bool queueIsEmpty();
        
        //Returns word for normal mode
        string getWord(){return wordList[0];}
        
        //Checks if stack is empty
        bool stackIsEmpty();
    
};


#endif /* WORDFETCH_H */

