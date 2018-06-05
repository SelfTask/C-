/* 
 * File:   Hangman.h
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Assignment: Project 2
 * Course: CSC-17C (42475)
 * Purpose: Extend project with recursive sorts, hashing, trees and graphs
 * Created on June 2, 2018, 11:59 AM
 */

#ifndef HANGMAN_H
#define HANGMAN_H
#include <queue>
#include "Scoreboard.h"
#include "WordFetch.h"
#include "Hash.h"   //For using hash to find existing words in temp. custom lib.
#include "BalancedTree.h"
#include "RecursiveSorts.h"
using namespace std;

class Hangman{
private:
    string word;     //Holds the chosen word of the game
    Scoreboard sc;   //Object for class handling scores & usernames w/ STL's Map
    WordFetch fetch; //Obtains words from containers
    
    Hash hashTable;  //Uses hash to allow player to search temp. custom library
    
    //Object for recursive sorts class
    RecursiveSorts recurSorts;
    
    //Object for the tree class
    BalancedBT tree;
    
    //Selects which type of order to use from tree
    bool isPre;
    bool isIn;
    bool isPost;
    
    static const int nWordGraph = 10;
    static const int sizeVert = 7;     //Stores constant max number of vertices
    const int maxValInt = 2147483647;   //Constant max cap for Integer data type

    //Array of Strings used to use words with 
    string wordsWGraph[nWordGraph];
    
    //Object for queue in STL to be used with graph
    queue<string> gToQ;
    
    void prim(int[][sizeVert]);
    int setWordsGraph(int[], int, int [][sizeVert]);
    int minVal(int[], bool []);
    void selectWordsGraph();
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
   
   //Uses hash table to for hint of a word
   void searchWordHash();
   
   void HangmanTree();
   
   void graphGameSetup();
   
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

