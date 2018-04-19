/* 
 * File:   WordFetch.cpp
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Assignment: Project 1
 * Course: CSC-17C (42475)
 * Purpose: Obtains word(s)/user's inputs use it with STL's containers: Set, List, Stack, and Queue
 * Created on April 10, 2018, 11:59 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>  //Use to obtain words from words.txt
#include <iterator>
#include <string>
#include <algorithm>
#include <set>  //For using sets
#include <list> //For using lists
#include <stack>
#include <queue>

#include "WordFetch.h"


using namespace std;

//Access a random line in word.txt to obtain a word for Normal Mode
//Some elements of this function was borrowed from cplusplus.com
string WordFetch::getRandWords(){
    ifstream myfile("words.txt"); //Access .txt for list of words
    string line = "";
    int numOfWords = 0;
    string newword = "";
    string word = "";
    int wordlength = 0;
    int k = 0;
    string alphabet="a b c d e f g h i j k l m n o p q r s t u v w x y z"; //used for validation
    while(getline(myfile, line)){
        numOfWords++;
    };

    int index = rand()%numOfWords + 1;

    //Reset curser to first line
    myfile.clear();    
    myfile.seekg(0, ios::beg);
    //Grab line from file
    for (int lineno = 0; getline (myfile,newword) && lineno < index; lineno++);
    wordlength=string(newword).size();
    word="";
    for (int i = 0; wordlength>i; i++){
        for (k = 0; k < 51; k+=2) //Alphabetic Checks
            if (alphabet[k]==newword[i]) //Check if letter is in alphabet
                word=word+newword[i];
    }

return word;}


//Obtains number of words based on number of rounds
void WordFetch::setWords(int nRounds){
    
    numRounds = nRounds;
    string tempWord = "";
    int count = 0;
    wordList = new string[numRounds];
    for(int numWords = 0; numWords < numRounds; numWords++){
        tempWord = getRandWords();
        wordList[numWords] = tempWord;
    }
     //for(int m = 0; m < numRounds; m++)
            //cout<<endl<<"word = "<<wordList[m]<<endl;
}

//Destructor deallocates memory
//Update word list if new custom words have been added
WordFetch::~WordFetch(){
    //If queue is not empty then it will write its existing words onto the list
    if(!q.empty()){
        //****** Updating library ******
        //Cleans duplicate entries
        //Organizes words in ABC order
        fstream fileUpdateWords;
        fileUpdateWords.open("words.txt", fstream::app);

            if (fileUpdateWords.is_open()){
                while(!q.empty()){
                    fileUpdateWords<<q.front();
                    q.pop();
                };
                fileUpdateWords.close();
            }else
                cout<<"\nWriting Error: Cannot open words.txt to update library.\n";
    }
    delete[] wordList;
}

/**********************************************************
 *                       Set -                            *
 * Use to single insert words into words.txt and display  *
 * entire list in alphabetical order with built in sort   *
 * ********************************************************/

void WordFetch::wordsInSet(){
    string line;
    const int numFreeWords = 25;
    ifstream myfileWords ("words.txt");
    if (myfileWords.is_open()){
        for(int i = 0; i < numFreeWords; i++){
            s.insert(getRandWords());
        };

        myfileWords.close();
    } else 
        cout << "\nReading Error: Cannot open words.txt"; 
}


//Displays 25 free words from the list of possible words in Alphabetical order 
//(utilizing STL set's built-in sort)if player wishes to see it in the menu
void WordFetch::DisplayListSet(){
    cout<<"\nList of 25 Possible Free Words (Alphabetical Order):\n";
    cout<<"------------------------------------------------------\n";

    for(set<string>::iterator it = s.begin(); it != s.end(); it++){
        cout<<*it<<endl;
    }
    cout<<endl<<endl<<"\n*Note: Unless playing under EZ-Mode, there is not a "
        <<"definitive chance that these words will appear\nin other"
        <<" game modes.\n\n";
    
}

//Removes a word from STL's Set
void WordFetch::removeWordEZMode(){
    char choice;    //Asks if player wants to correct their input mistake
    string input;   //Holds word to be removed from Set
    
    do{
        cout<<endl<<"From the list of words above, would you like to remove any "
            <<"one word to improve your odds? (y/n): ";
        cin>>choice;
        
        if(choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y')
            cout<<"\nSorry your has to be \"y\" for Yes or \"n\" for No.\n";
    }while(choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y');
    
    if(choice == 'y' || choice == 'Y'){
        DisplayListSet();   //Redisplay list from set for player to select
        
        //Requests player to select a word from set
        cout<<"\nEnter a word you'd like to remove from the list above: ";
        cin>>input;
        
        int n = 3; //number of attempts
        //Confirms the inputted word exists and removes it
        while(choice != 'n' && choice != 'N'  && s.count(input) == 0 && n > 0){
            cout<<"\t\t\t\t\t\t"<<n--<<" Attempt(s) Left\n\n";
            
            if(s.count(input) == 0){

                cout<<"The word \""<<input<<"\" does not exist.\n";
                cout<<"\nWould you like to try again? (y/n): ";
                cin>>choice;

                
                if(choice == 'Y')
                    choice = 'y';
                else if(choice == 'N')
                    choice = 'n';
                
                if(choice != 'n' && choice != 'y')
                    cout<<"\nSorry your input has to be \"y\" for Yes or \"n\"" 
                        <<"for No.\n";
                else if (choice == 'y'){
                    cout<<"\nEnter another word to be removed: ";
                    cin>>input; 
                }


            }
        };
        
        if(s.count(input) > 0)
            s.erase(input);
    }
}

//Obtain a word for Ez-Mode with the use of STL's Set
string WordFetch::getEzWord() const{
    string ezWord;
    
    int randomNum = rand()%s.size() + 1;
    int i = 0;
    
    for(set<string>::iterator it = s.begin(); it != s.end(); it++){
        i++;
        if(i == randomNum)
            ezWord = *it;
        
    }
    
    return ezWord;
}

//Clears the set
void WordFetch::clearWordListSet(){
    s.clear();
}

/******************************************
 *                List -                  *
 * Used store previous inputs of a round  *
 * ****************************************/

//Pushes inputed value onto the list
void WordFetch::storeInputList(string input){    
    l.push_front(input);
}

//Use to display player's input for the round so that they could see
//the letters they've already guessed
void WordFetch::displayInputList(){
        
    cout<<"\nPrevious Inputs (from Latest to Oldest) RESETS FOR EVERY NEW WORD:\n";
    cout<<"--------------------------------------------------------------------\n";
    
    for(list<string>::iterator it = l.begin(); it != l.end(); it++){
        cout<<"\t\t\t"<<*it<<endl;
    }

}


//Deletes input history list (after every round)
void WordFetch::deleteInputHist(){
    l.clear();
}


/******************************************
 *               Stacks (LIFO)-           *
 * Used store strings for marathon mode   *
 * ****************************************/


//Pushes all the words onto the stack when Marathon Mode is selected
void WordFetch::wordsInStack(){
    for(int i = 0; i < numRounds; i++)
        st.push(wordList[i]);
    
}

//Returns a popped value from the stack for Marathon Mode
string WordFetch::popWordMarathon(){
    //Pops the list when STL's stack is not empty
    if(st.empty() != true){
        string temp = st.top();
        st.pop();
        return temp;
    }else
        //Warns player stack is empty
        cout<<"\nThere are no longer any elements on the stack.\n";
return 0;}

//Informs if stack is empty for outside classes
bool WordFetch::stackIsEmpty(){
    return st.empty();
}


/******************************************
 *           Queues (FIFO) -              *
 * Uses Queue to display custom words     *
 ******************************************/

//Pushes custom words onto queue for Custom Word Mode while updating library
void WordFetch::queueCustomWords(string customWord){
    q.push(customWord);
    
    /****** Updates library ******/
    
    fstream fileUpdateWords;
    fileUpdateWords.open("words.txt", fstream::app);

        if (fileUpdateWords.is_open()){
                fileUpdateWords<<customWord<<endl;
            fileUpdateWords.close();
        }else
            cout<<"\nWriting Error: Cannot open words.txt to update library.\n";
    
}

//Returns custom words from queue
string WordFetch::getWordCustom(){
    if(!q.empty()){
        string temp = q.front();
        q.pop();
        return temp;
    }else
        cout<<"\nThe queue of custom words is empty.\n";
    return 0;
}

//Checks if the queue is empty for outside classes
bool WordFetch::queueIsEmpty(){
    return q.empty();
}

/*
 * Function below is waiting for future uses
void WordFetch::sortQueueCustomWord(){
    int size = q.size();
    string *temp = new string[size];
    int i = 0;
    
    while(!q.empty()){
        temp[i] = q.front();
        cout<<"temp[ "<<i<<" ]"<<temp[i]<<endl;
        cout<<"q.front() = "<<q.front()<<endl;
        q.pop();
        i++;
    };
    
    sort(temp, temp + size);
    
    for(int j = 0; j < size; j++){
        q.push(temp[j]);
        cout<<"temp[ "<<j<<" ]"<<temp[j]<<endl;
    }
    delete[] temp;
}
*/

//Returns a random word from words.txt for normal mode
string WordFetch::getWord() const{
    return wordList[0];
}

//Returns the number of rounds
int WordFetch::getNumRounds() const{
    return numRounds;
}