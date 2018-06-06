/* 
 * File:   Hangman.cpp
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Assignment: Project 2
 * Course: CSC-17C (42475)
 * Purpose: Extend project with recursive sorts, hashing, trees and graphs
 * Created on June 2, 2018, 11:59 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Hangman.h"
#include "WordFetch.h"
#include "Scoreboard.h"
#include <algorithm>    //To use STL's sort algorithm


using namespace std;

void Hangman::coreGame(int numRound, string mode){
    int countSlot = 0;          //counts the value for open slots left
    bool won = false;           //holds winning status
    bool safeActivated = false; //Checks if player has activated their lifeline
    bool escapeFeature = false; //Checks if player has exited guess word mode
    bool wrongWord = false;     //Checks if the wrong word has been guessed
    int score = 0;              //Stores the number points
    int numTurns = 1;           //Stores the number of turns
    int numWrong = 0;           //Store the number of wrong guesses for letters
    string chosenWord;          //Stores the word chosen for the round
    int randNum;                //Stores a random number for choosing word
    bool letterFound = false;   //Alerts game if letter has been found
    const int maxTurns = 6;     //Holds number of max turns per round
    string input;               //Stores player's input
    bool contiTurn = true;     //Checks if turn should continue after guessing word mode
    bool finishByLetter = false;  //Checks if player previous turn was Letter Mode
    bool letterRight = false;   //Checks if guessed letter is correct
                                    
    //Holds the status of guessed characters and open slots left
    string storeLine = "";
        
    srand(time(0));


                
    //Do-Whole loops the number of rounds a game mode offers
    //Also increments the number of rounds in its condition
    for(int runGame = 1; runGame <= numRound; runGame++){
        
        /**********************************
         *         Setting Up Round       *
         **********************************/
        fetch.deleteInputHist();
        contiTurn = true;
        won = false;
        safeActivated = false;
        finishByLetter = false;
        letterFound = false;
        
        //Determines how chosenWord is selected depending on game mode
        if(mode == "ez"){
            fetch.DisplayListSet();
            fetch.removeWordEZMode();
            chosenWord = fetch.getEzWord();
        }else if(mode == "marathon"){

            if(!fetch.stackIsEmpty()){
                chosenWord = fetch.popWordMarathon();
            }else{ 
                cout<<"\nStack is empty... terminating\n";
                return;        
            }
        }else if(mode == "custom"){
            if(!fetch.queueIsEmpty()){
                chosenWord = fetch.getWordCustom();
            }else{ 
                cout<<"\nQueue is empty... terminating.\n";
                return;
            }
        }else if(mode == "normal"){
            fetch.setWords(1);
            chosenWord = fetch.getWord();
        }else if(mode == "tree"){
            if(isPre == true){
                if(!tree.qPre.empty()){
                    chosenWord = tree.qPre.front();
                    tree.qPre.pop();
                }else{ 
                    cout<<"\nQueue from TREE (Pre-Order) is empty... terminating.\n";
                    return;
                }
            }else if(isIn == true){
                if(!tree.qIn.empty()){
                    chosenWord = tree.qIn.front();
                    tree.qIn.pop();
                }else{ 
                    cout<<"\nQueue from TREE (In-Order) is empty... terminating.\n";
                    return;
                }
            }else{
                if(!tree.qPost.empty()){
                    chosenWord = tree.qPost.front();
                    tree.qPost.pop();
                }else{ 
                    cout<<"\nQueue from TREE (Post-Order) is empty... terminating.\n";
                    return;
                }
            }
        
        }else if(mode == "graph"){
            cout<<"\nNumber of Rounds for Graph Mode Left: "<<gToQ.size()<<"\n\n";
            if(!gToQ.empty()){
                    chosenWord = gToQ.front();
                    gToQ.pop();
                }else{ 
                    cout<<"\nQueue from Graph is empty... terminating.\n";
                    return;
                }
        }else{
            cout<<endl<<"Error: Game Mode has not been selected correctly.";
            cout<<" Now terminating...\n";
            contiTurn = false;
            runGame = numRound + 1000;
        }

        cout<<endl<<"(for testing purposes) chosenWord = "<<chosenWord<<endl;
        
        
        //Holds the status of guessed characters and open slots left
        storeLine = "";

        //For-loop that checks the number of open slots base on
        //the length of the chosen word for the round
        for(int i = 0; i < chosenWord.length(); i++){
            storeLine+="-"; 
        }

        cout<<endl;

        //Reset for new round
        numTurns = 1;
        numWrong = 0;

        /**********************************
         *         Starting Game          *
         **********************************/
        
        //Do-while loop: Checks the winning conditions
        do{
            cout<<"\n\t\t\t\t Try: "<<numTurns<<"/"
                <<maxTurns<<endl;
            letterRight = false;      //Resets if player guessed letter right
            //Resets countSlot to 0 for every round
            //checks if player has won
            countSlot = 0;
            
            //For-loop that assigns the number of open slots base on
            //the length of the chosen word for the round
            for(int i = 0; i < chosenWord.length(); i++){

                //Increments countSlot for every open slots avaliable
                if(storeLine[i] == '-'){
                    countSlot++;    //counts the amount of open slots left
                                        //if count == 0 then player wins
                }
                        
            }
            
            //If there are no open slots left then word has been guess
            //Therefore player has won
            if(countSlot == 0){
                score++;
                contiTurn = false;
                won = true;
                numTurns = maxTurns + 100;    //Terminates do-while loop round 
                                            //if word has been guessed in 
                                            //Letter Mode
            }
                
            escapeFeature = false;
            
            if(won == false){
             
                //inner while loop: Prompts the player to enter guessed 
                //character or select one of the following features       
                //Feature #1: Guess word and instantly lose
                //Feature #2: A once per round life line where incorrectly guessed
                //word will not cause the player to lose
                do{
                    //Displays the appropriate hangman image based on amount of 
                    //wrong guesses
                    displayHangMan(numWrong);

                    //Displays status of guessing the word
                    cout<<endl<<storeLine<<endl;
                    if(mode == "marathon")
                        cout<<"\n\nNOTE: For Marathon Mode, unless you've "
                            <<"guessed the wrong word under \"guess word\" mode"
                            <<" (Option \"1\") you can still continue "
                            <<"and play if you've gotten hangman.\n" 
                            <<"You'll just not get a point for that word.\n\n";

                    cout<<"Enter \"1\" to guess word. (Will lose instantly if "
                        <<"guessed wrong.)\n";

                    //Opens up game feature to allow a free mode where guessing
                    //a word wrong will not harm player's status of winning
                    if(safeActivated == false)
                        cout<<"Enter \"2\" to guess word without losing. "
                            <<"(Once per round)\n";
                    
                    cout<<"Enter \"3\" to see numbers you have previously entered\n";
                    
                    if(mode == "custom")
                        cout<<"Enter \"4\" to search Hash Table for hints on the word.\n";
                    
                    //Prompts player for input
                    cout<<"Enter a letter: ";
                    cin>>input;
                    
                    if(input == "4"){
                        searchWordHash();
                    }
                    
                    if(input == "3")
                        fetch.displayInputList();

                    if(input == "2" && safeActivated == true)
                        cout<<"\nSorry. You have already used up your life line"
                            <<" (Option 2). You must wait for the next round "
                            <<"to use it again.\n";
                    //Warns the player if they've enter too many letters
                    if(input.size() > 1)
                        cout<<"\nInvalid Input: You must only enter 1 character. "
                            <<"Please enter \"1\" or if you haven't \"2\" to"
                            <<" guess the entire word.\n";    

                    //do-while loop checks for activation of features and size of 
                    //input
                    //If player chooses one of the two options above, it will then
                    //terminate this do-while loop to proceed them to the next 

                }while(input.size() > 1 && input != "1" && input != "2" 
                        && input != "3");
                
                //Checks what the previous mode was
                if(input != "1" && input != "2")
                    finishByLetter = true;
                else
                    finishByLetter = false;
                
                //Stores the guessed values per turn
                //if(input != "1" && input != "2" && input != "3"){
                //    fetch.storeInputList(input);
                //}

                //Checks if inputed character is present in the chosen word
                if(input != "1" && input != "2" && input != "3" && input != "4"){
                    fetch.storeInputList(input); //Stores the guessed values per turn
                    for(int i = 0; i < chosenWord.length(); i++){
                        //for(int j = 0; j < chosenWord.length();j++){
                            if(input[0] == chosenWord[i] ){
                       
                                storeLine[i] = chosenWord[i];
                                letterFound = true;
                                letterRight = true;
                            }
                        //}

                    }

                    //Keeps track of the number of wrong guesses
                    if(letterFound == false)
                        numWrong++;


                    letterFound = false;   //resets found letter to false for
                                           //the next turn
                  //  numTurns++; //Incrementor for number of rounds

                //Unlocks word guessing mode
                }else if(input == "1"){
                    cout<<endl;
                    cout<<"BEWARE: Guess the word correctly and you will automatic"
                        <<"ally win the game.\nGuess the wrong word and you will"
                        <<" instantly lose.\n";
                    cout<<"If you're not up for it, enter \"0\" to return to "
                        <<"guessing only letters.\n";
                    cout<<"Enter the word: ";
                    cin>>input;

                    if(input != "0"){
                        if(input == chosenWord){
                            cout<<"*** You've guessed the correct word! "
                                <<"You have WON! ***"<<endl;
                            contiTurn = false;
                            numTurns = 0;
                            score++;
                        }else{
                            cout<<"\nYour guess was wrong. You Lose\n";
                            contiTurn = false;
                            runGame = numRound + 1000;
                        }
                        
                    }


                //Unlocks the safe feature of the game
                }else if(input == "2" && safeActivated == false){
                    cout<<endl;
                    cout<<"Warning: You'll only have safety mode once per turn.\n";
                    cout<<"Safe Mode --- You will not lose a guess if word is "
                        <<"guessed incorrectly.\n";
                    cout<<"Enter \"0\" if you do not wish to use up this feature.\n";
                    cout<<"Enter the word: ";
                    cin>>input;

                    if(input != "0"){
                        fetch.storeInputList(input); //Stores the guessed values per turn
                        numTurns--; //Does not count turn if life mode
                        safeActivated = true;
                        if(input == chosenWord){
                            cout<<"*** You've guessed the correct word! "
                                <<"You have WON! ***"<<endl;
                            contiTurn = false;
                            numTurns = 0;
                            score++;
                        
                        }
                    }
                }
            }
            
            //Terminates the for-loop if player loses a turn in letter mode
            //In other words, GAMEOVER
            if(numTurns > maxTurns && won == false){
                runGame = numRound + 1000;  
                contiTurn = false;
            }
            
            //Does not count turn if options are chosen
            if(!letterRight && input != "0" && input!= "1" && input!= "2" 
                    && input!= "3" && input != "4")
                numTurns++;
            
        }while(numTurns <= maxTurns && countSlot != 0 && contiTurn);

        //Redisplay man's status
        displayHangMan(numWrong);

        //Informs player of the game's outcome before game ends
        if(finishByLetter == true){
            if(won == true){
                cout<<"\n*** YOU'VE WON ***\n";
            }else
                cout<<"\n*** You lose. Better luck next time! ***"<<endl;
        }
        //Displays the word at the end of the game
        cout<<endl<<"Answer: "<<chosenWord<<endl;
        
        
    }   //End of for-loop


    //Takes in score for scoreboard
    sc.setScore(score);

    //Requests if player wants to enter a username and have score be stored
    sc.requestUsername();

    //Displays scoreboard of previous players
    sc.readNameScore();
    
    menuDisplay();

    
}



//Constructor
Hangman::Hangman(){
    fetch.wordsInSet(); //Access entire library for easy access of words
    
    isPre = false;
    isIn = false;
    isPost = false;
    
}

//Destructor - clears set (list of words)
Hangman::~Hangman(){
    fetch.clearWordListSet();
}

//Display the main menu option
void Hangman::menuDisplay(){
    char inChoice;  //Store user's choice within the menu
    Hash table;
    
   
    
    
    //table.printTable();
    cout<<endl;
    do{
        //Displays the main menu
        cout<<endl;
        cout<<"Enter 1 to play Hangman"<<endl;
        cout<<"Enter 2 to play EZ-Mode (choose the first letter of a word and"
            <<" that same letter will be given to you.)"<<endl;
        cout<<"Enter 3 to play Marathon Mode (choose number of rounds of "
            <<"Hangman to win."<<endl;
        cout<<"Enter 4 to enter your own word(s) THEN play with the use "
            <<"of a HASH TABLE for tips"<<endl;
        cout<<"Enter 5 to display the rules"<<endl;
        cout<<"Enter 6 to display scoreboard"<<endl;
        cout<<"Enter 7 to view 25 Free Words for EZ-Mode"<<endl;
        cout<<"Enter 8 to setup game with the use of TREE and "
            <<"RECURSIVE SORTS"<<endl;
        cout<<"Enter 9 to setup game with GRAPH\n";
        cout<<"Enter any other key to exit"<<endl;
        cout<<"User Input: ";
        cin>>inChoice;

        
    
    
        //Switch statement that calls upon the different game modes and rules
        //depending on player's choice
        switch(inChoice){
            case '1': coreGame(1, "normal");      break;
            case '2': ezMode();         break;
            case '3': marathonMode();   break;
            case '4': customWordMode(); break;
            case '5':{ rulesDisplay(); break;}
            case '6':{ sc.readNameScore(); menuDisplay();break;}
            case '7':{ fetch.DisplayListSet(); menuDisplay();break;}
            //case '8':{ table.searchWord(); menuDisplay(); break; }
            case '8':{HangmanTree(); break;}
            case '9':{graphGameSetup(); break;}

            default: cout<<"\nOption: Exit has been selected. "
                         <<"Terminating..."<<endl; break;
            
        }
    }while(inChoice < 1 && inChoice > 9);     
}

//There are only 25 random words to choose from for this mode and they're
//all listed
void Hangman::ezMode(){    
    coreGame(1, "ez");
}

//Game mode that allows the user to set the amount of rounds they wish to 
//complete before winning
void Hangman::marathonMode(){
    int numRound;   //Holds number of rounds for hangman   
  
        cout<<"\n----------------- Marathon Mode -----------------\n";
    do{
        cout<<"Enter the number of rounds you wish to complete to win: ";
        cin>>numRound;
        
        if(numRound >= 1)
            cout<<"Invalid Input: The number of round must be positive value."
                <<" Please try again.\n";
        
    }while(numRound < 1);
    
    fetch.setWords(numRound);
    fetch.wordsInStack();
    coreGame(numRound, "marathon");
    
}

//Game mode that allows user to enter a custom word for another player
//This word will then be added to the library of words for future games
void Hangman::customWordMode(){
    string customWord;   
    int numRounds;   //Asks for confirmation on number of rounds
    
  
    cout<<"\n----------------- Custom Word Mode -----------------\n";
    do{
        cout<<"How many rounds of Custom Word Mode would you like to play?: ";
        cin>>numRounds;
        if(numRounds < 0)
            cout<<"Error: Number of Rounds must be a positive number.\n";
    }while(numRounds < 0);

    string *temp = new string[numRounds];
    
    for(int i = 0; i < numRounds; i++){
        cout<<"Enter the a custom word for round #"<<(i+1)<<": ";
        cin>>temp[i];

    }
    
    cout<<"\nYour Custom Words:\n"
        <<"--------------------\n";
    for(int j = 0; j < numRounds; j++)
        cout<<temp[j]<<endl;
    char input;
    
    //Requests if user wants to sort their input
    do{
        cout<<"\nWould you like to sort your Custom Words? (y/n): ";
        cin>>input;
        if(input == 'y' || input == 'Y')
            sort(temp, temp + numRounds);   //using STL's SORT ALGORITHM

        if(input != 'y' && input != 'Y' && input != 'n' && input != 'N')
            cout<<"\nInput must be \"y\" or \"n\". Please try again.\n";
    }while(input != 'y' && input != 'Y' && input != 'n' && input != 'N');
    
    
    cout<<"\nYour Custom Words:\n"
        <<"--------------------\n";
    for(int j = 0; j < numRounds; j++){
        if(input == 'y' || input == 'Y')
            cout<<temp[j]<<endl;
        
        //Stores the custom words for Custom Word Mode
        fetch.queueCustomWords(temp[j]);
        hashTable.insert(temp[j]);
        
    }
    
    //Deallocate temp[]
    delete[] temp;

  
    coreGame(numRounds, "custom");
}

//Displays the title when game loads
void Hangman::titleDisplay(){
    cout<<"********************************************************************"<<endl;
    cout<<"*         *       *       *****      *      *    *********         *"<<endl;        
    cout<<"*         *       *      *     *     * *    *    *       *         *"<<endl;    
    cout<<"*         *       *      *     *     *  *   *    *                 *"<<endl; 
    cout<<"*         *********      *******     *   *  *    *   *****         *"<<endl;   
    cout<<"*         *       *      *     *     *    * *    *       *         *"<<endl;   
    cout<<"*         *       *      *     *     *     **    *       *         *"<<endl;   
    cout<<"*         *       *      *     *     *      *    *********         *"<<endl; 
    cout<<"*                                                                  *"<<endl;
    cout<<"*                **     **       *****      *      *               *"<<endl;
    cout<<"*                * *   * *      *     *     * *    *               *"<<endl;
    cout<<"*                *  * *  *      *     *     *  *   *               *"<<endl;
    cout<<"*                *   *   *      *******     *   *  *               *"<<endl;
    cout<<"*                *       *      *     *     *    * *               *"<<endl;
    cout<<"*                *       *      *     *     *     **               *"<<endl;
    cout<<"*                *       *      *     *     *      *               *"<<endl;
    cout<<"********************************************************************"<<endl;

} 

//Displays the current status of the game
void Hangman::displayHangMan(int numWrong){
    cout<<endl;
    
    if(numWrong == 0){
        cout<<"|------."<<endl;
        cout<<"|       "<<endl;
        cout<<"|       "<<endl;
        cout<<"|       "<<endl;
        cout<<"|       "<<endl;
        cout<<"|       "<<endl;
    }else if(numWrong == 1){
        cout<<"|------."<<endl;
        cout<<"|      O "<<endl;
        cout<<"|        "<<endl;
        cout<<"|       "<<endl;
        cout<<"|       "<<endl;
        cout<<"|       "<<endl;

    }else if(numWrong == 2){
        cout<<"|------."<<endl;
        cout<<"|      O "<<endl;
        cout<<"|      #  "<<endl;
        cout<<"|       "<<endl;
        cout<<"|       "<<endl;
        cout<<"|       "<<endl;
    }else if(numWrong == 3){
        cout<<"|------."<<endl;
        cout<<"|      O "<<endl;
        cout<<"|    --#  "<<endl;
        cout<<"|       "<<endl;
        cout<<"|       "<<endl;
        cout<<"|       "<<endl;
    }else if(numWrong == 4){
        cout<<"|------."<<endl;
        cout<<"|      O "<<endl;
        cout<<"|    --#--  "<<endl;
        cout<<"|       "<<endl;
        cout<<"|       "<<endl;
        cout<<"|       "<<endl;
    }else if(numWrong == 5){
        cout<<"|------."<<endl;
        cout<<"|      O "<<endl;
        cout<<"|    --#--  "<<endl;
        cout<<"|     /  "<<endl;
        cout<<"|       "<<endl;
        cout<<"|       "<<endl;
    }else if(numWrong == 6){
        cout<<"|------."<<endl;
        cout<<"|      O "<<endl;
        cout<<"|    --#--  "<<endl;
        cout<<"|     / \\ "<<endl;
        cout<<"|       "<<endl;
        cout<<"|       "<<endl;
    }
    cout<<"------------------------"<<endl<<endl;
}


//Displays the rules & extra features of the game during the menu
void Hangman::rulesDisplay(){
    cout<<endl<<endl;
    cout<<"\t\t\t\t==================== Rules of the Game ====================";
    cout<<endl;
    cout<<"Winning Condition: Quess all the letter or entire word correctly "
        <<"before getting 7 wrongs (before hangman fully displays) to win.\n";
    cout<<"\n-------------------- Player Option --------------------\n";
    cout<<"\t1) Guess entire word - Player gets to guess the entire word, if "
        <<"guessed correctly s/he will instantly, if not, then s/he will lose.";
    cout<<"\n\t2) Safe Mode - Active by entering \"2\" to safely guess the word "
        <<"without losing a guess.\n\t\t(Note: Player may only use this option "
        <<"once per round)\n";
    cout<<"\n-------------------- Game Modes --------------------"<<endl;
    cout<<"\t1) Normal Hangman"<<endl;
    cout<<"\t2) EZ Mode - Player only has to worry about up to 25 words to "
        <<"choose from and has the ability to remove 1 word of their choosing"
        <<"\n\t\tword if present.\n";
    cout<<"\t3) Marathon Mode - Player gets to choose the number of rounds "
        <<"they wish to go through before completing the game.\n";
    cout<<"\n\t\tNOTE: For Marathon Mode, unless you've guessed the wrong word "
        <<"under challenge mode \"Word Mode\" (Option \"1\") you can still "
        <<"continue and play.\n You'll just not get a point for that word.\n\n";
    cout<<"\t4) Custom Word Mode - Player add word(s) to be the mystery word(s)"
        <<"for the number of round(s) of their choosing. Afterwards the "
        <<"entered word will be a new installment of\n\t\tthe game as it is "
        <<"now on the World List and can be called upon again. You can also "
        <<"use a HASH Table of an List Array to search for a present word as"
        <<" a hint.\n";
    cout<<"\t5) Tree Mode - Uses 2 recursive sorts to allow Host to select "
        <<"if they want the random words to be ascending or descending order.\n"
        <<"\t\tThen it's inserted within a tree to which the graph will display "
        <<"the random words and have those words be used in a game either in"
        <<" Pre-, In-, or Post-Order\n";
    cout<<"\t6) Graph Mode - Selects random words from the library and have "
        <<"each word's length be inserted onto a graph so that a shorter "
        <<"accumulated number of guesses can be\n\t\tachieved throughout the "
        <<"multiple rounds by only using the "
        <<"words associated to a visited vertices through Prim's Algorithm by "
        <<"finding the Minimum Spanning Tree.";
    cout<<endl<<endl;

    //Returns to the menu after displaying the rules
    menuDisplay();
}

//Uses RS-Hash with hash table to find words on temp custom lib for hints 
void Hangman::searchWordHash(){
    char choiceHash;
    
    //Confirms that player wants to use hash table for hints
    do{
        cout<<"\nYou have chosen the Custom Word Mode.\n";
        cout<<"Would you like to search the Hash Table for possible words"
            <<" the host might have might have entered previously? (y/n): ";
        cin>>choiceHash;

        if(choiceHash == 'Y')
            choiceHash = 'y';
        else if(choiceHash == 'N')
            choiceHash = 'n';

        if(choiceHash != 'y' && choiceHash != 'n')
            cout<<"Error: Input must be \"y\" for YES or \"n\" for No.\n";
    }while(choiceHash != 'n' && choiceHash != 'y');
    
    //Allows player to interact with hash table for hints
    //Then ask if player want to interact again
    if(choiceHash == 'y'){
        do{
            //Calls to hash table
            hashTable.searchWord();
            cout<<"\nWould you like to search again? (y/n): ";
            cin>>choiceHash;
            
            if(choiceHash == 'Y')
                choiceHash = 'y';
            else if(choiceHash == 'N')
                choiceHash = 'n';
            
            if(choiceHash != 'y' && choiceHash != 'n')
                cout<<"Error: Input must be \"y\" for YES or \"n\" for No.\n";
        }while(choiceHash != 'n');
    }
}

void Hangman::HangmanTree(){
    isPre = false;
    isIn = false;
    isPost = false;
    
    const int szArr = 5;
    string arr[szArr];
    int numWordTree = szArr;
    
    //Assigns randomly chosen words to be sorted and inserted into a tree
    for(int i = 0; i < szArr; i++)
        arr[i] = fetch.getRandWords();
    
    cout<<"\nYou have chosen Tree Mode where you're able to sort the random"
            <<" words with the use of RECURSIVE SORTS and confirm your settings"
            <<" of the words from a TREE\nto confirm your selection so that "
            <<"you'd be ready to offer the game to the player.\n\n";
        
        cout<<"Let's begin...\n";
        
    char inputSort;
    
    do{
        
        cout<<"\nRandomly chosen words: ";
        //printing sorted array
        for(int i = 0; i < szArr ; i++)
            cout<<arr[i]<<" ";

        cout<<endl;
        cout<<"\nEnter 1 to sort ABC Order.";
        cout<<"\nEnter 2 to sort in Reverse.\n";
        cout<<"\nUser Input: ";
        cin>>inputSort;
        
        //Alerts if input is not valid
        if(inputSort != '1' && inputSort != '2')
            cout<<"\nError: Input must be \"1\" or \"2\"\n";
        
    }while(inputSort != '1' && inputSort != '2');
    
    //Sorts forward or backwards depending input
    if(inputSort == '1'){
        recurSorts.recursiveBubbleSort(arr, numWordTree);
        cout<<"\nSorted ABC Order: ";
    }else{
        // Calling function
        recurSorts.recurSelectionSort(arr, numWordTree, 0);
        cout<<"\nSorted Reversed Order: ";
    }
    
    //printing sorted array
    for (int i = 0; i<numWordTree ; i++)
        cout << arr[i] << " ";
    cout << endl;
    

    
    int m = numWordTree;  //Stores number of elements
    int numDelete;  //Stores number of nodes to be deleted
    

    cout<<"\nInserting onto Tree...\n";
    
    //Inserts words onto tree
    for(int i = 0; i < m; i++){
        tree.runInsert(arr[i]);
    }
    
    char inputOrder;    //Use to verify choice of order
    bool isPostOrder = false;
    
    do{
        if(inputSort == '1'){
            cout<<"\nWords in Pre-Order (ABC Order):  ";
            tree.show_PreOrder();
        }else{
            cout<<"\nWords in Pre-Order (Reversed Order):  ";
            tree.show_PreOrder();
        }
        
        if(inputSort == '2'){
            cout<<"\n\nWords in In-Order (ABC Order):  ";
            tree.show_InOrder();
        }else{
            cout<<"\n\nWords in Post-Order (Reversed Order):  ";
            tree.show_PostOrder();
            isPostOrder = true;
        }
        
        cout<<endl<<endl;
        
        if(inputSort == '1')
            cout<<"Do you want Pre-Order (ABC Order) instead? (y/n)\n";
        else if(inputSort == '2' && isPostOrder == false)
            cout<<"Do you want In-Order (ABC Order) instead? (y/n)\n";
        else{
            cout<<"Do you want Post-Order (Reversed Order) instead? (y/n)\n";
        }
            
        cout<<"User Input: ";
        cin>>inputOrder;
        
        if(inputOrder == 'Y')
            inputOrder = 'y';
        else if(inputOrder == 'N')
            inputOrder = 'n';

        if(inputOrder != 'y' && inputOrder != 'n')
            cout<<"\nError: Input must be \"y\" for YES or \"n\" for NO.\n";
    }while(inputOrder != 'y' && inputOrder != 'n');
    
    if(inputOrder == 'n' && inputSort == '1')
        inputSort = '2';
    else if(inputOrder == 'n' && inputSort == '2')
        inputSort = '1';
    
     
    cout<<endl;
    if(inputSort == '1'){
        //Selects queue of Pre-Order to be used in game
        
        isPre = true;

    }else if(inputSort == '2' && isPostOrder == true){
        //Selects queue of Post-Order to be used in game
        isPost = true;

    }else if(inputSort == '2' && isPostOrder == false){
        //Selects queue of In-Order to be used in game
        
        isIn = true;
        
    }
    
    cout<<endl;

    coreGame(numWordTree, "tree");
}


void Hangman::selectWordsGraph(){
    cout<<endl;
    cout<<"\nUsing Minimum Spanning Tree to select words...\n";



    for(int i = 0; i < nWordGraph; i++){
        wordsWGraph[i] = fetch.getRandWords();
    }
    //graph input
        
        int lngth[nWordGraph];
        
        for(int i = 0; i < nWordGraph; i++)
            lngth[i] = wordsWGraph[i].length();
                     
   int graph[sizeVert][sizeVert] = {
       
    
        {0       , lngth[0],     0   , lngth[1], 0   , lngth[2] , lngth[3]},
        {lngth[0],     0   , lngth[4] , lngth[5] , 0   , 0   , lngth[7] },
        {0   , lngth[4] , 0   , 0   , lngth[6], 0   , lngth[8] },
        {lngth[1], lngth[5] , 0   , 0   , 0, 0, lngth[9]   },
        {0   , 0   , lngth[6], 0, 0   , 0, 0},
        {lngth[2] , 0   , 0   , 0, 0   , 0   , 0},
        {lngth[3], lngth[7] , lngth[8]   , 0 , lngth[9], 0   , 0   }   
           
    };
    


 
    //uses prim to find the minimum spanning tree of random words to be selected
    //for gameplay
    prim(graph);
}

  
//Selects new vertex
int Hangman::minVal(int arrVal[], bool vertStat[]){
   // Initialize min value
   int min = maxValInt, min_index;
 
   for (int v = 0; v < sizeVert; v++)
     if (vertStat[v] == false && arrVal[v] < min)
         min = arrVal[v], min_index = v;
 
   return min_index;
}
 
//Displays results or minimum spanning tree
int Hangman::setWordsGraph(int parent[], int n, int graph[sizeVert][sizeVert]){
    
    //cout<<"   Edge    \tWeight"<<endl;
    //int weighted = 0;
    for (int i = 1; i < sizeVert; i++){
        //int temp = graph[i][parent[i]];
        //weighted += temp;
        gToQ.push(wordsWGraph[i]);
    }
    //cout<<"\nWeighted = "<<weighted<<endl;

    /*
    cout << "\nThe set gToQ is : ";
    while(!gToQ.empty()){
        cout<<gToQ.front()<<" ";
        gToQ.pop();
    };
    cout << endl;
     */
}
 
//Using prim to find the minimum spanning tree of graph
void Hangman::prim(int graph[sizeVert][sizeVert]){
    int parent[sizeVert];
    int val[sizeVert];
    bool vertStat[sizeVert];

    for(int i = 0; i < sizeVert; i++)
        val[i] = maxValInt, vertStat[i] = false;

    val[0] = 0;
    parent[0]--; //The root of min. spanning tree

    for(int count = 0; count < sizeVert-1; count++){
        int newMin = minVal(val, vertStat);
 
        //set used vertices
        vertStat[newMin] = true;
 
        for (int cVert = 0; cVert < sizeVert; cVert++)
            if (graph[newMin][cVert] && vertStat[cVert] == false && 
                    graph[newMin][cVert] <  val[cVert])
                parent[cVert] = newMin, val[cVert] = graph[newMin][cVert];
     }
 
     //Shows minimum spanning tree
     setWordsGraph(parent, sizeVert, graph);
}
 

void Hangman::graphGameSetup(){
    cout<<endl<<endl;
    cout<<"*******************************************************************"<<endl;
    cout<<"* This game mode inserts the lengths of random words into a Graph *"<<endl
        <<"* then find the graph's minimum spanning tree and use the visited *"<<endl
        <<"* vertices to select which random words to use for the game.      *"<<endl;
    cout<<"*******************************************************************"<<endl;
    cout<<endl;
    
    selectWordsGraph();
    
    coreGame(gToQ.size(), "graph");

}