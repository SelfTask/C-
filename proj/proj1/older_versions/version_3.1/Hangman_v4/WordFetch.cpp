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
#include <map>
#include <queue>

#include "WordFetch.h"




using namespace std;
//Access .txt file with the list of words in it
void WordFetch::setWords(int nRounds){
    ifstream myfile("words.txt"); //Access .txt for list of words
    
    numRounds = nRounds;
    
    int count = 0;
    wordList = new string[numRounds];
    for(int numWords = 0; numWords < numRounds; numWords++){
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
        for (int i = 0; wordlength>i; i++)
        {
            for (k = 0; k < 51; k+=2) //Alphabetic Checks
                if (alphabet[k]==newword[i]) //Check if letter is in alphabet
                    word=word+newword[i];
        }
        
        wordList[count] = word;
        count++;

       
        
    }
     for(int m = 0; m < numRounds; m++)
            cout<<endl<<"word = "<<wordList[m]<<endl;
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
    ifstream myfileWords ("words.txt");
    if (myfileWords.is_open()){
        while(getline (myfileWords, line)){
            s.insert(line);
        };

        myfileWords.close();
    } else 
        cout << "\nReading Error: Cannot open words.txt"; 
}


//Displays entire list of possible words in Alphabetical order (utilizing STL 
//set's built-in sort)if player wishes to see it in the menu
void WordFetch::DisplayListSet(){
    cout<<"\nList of Possible Words (Alphabetical order):\n";
    cout<<"----------------------------------------------\n";
    
    // begin() returns the value of the first element
    // end() returns the last element on the list
    for(set<string>::iterator it = s.begin(); it != s.end(); it++){
        cout<<*it<<endl;
    }
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
        
    cout<<"\nPrevious Inputs (from Latest to Oldest):\n";
    cout<<"----------------------------------------------\n";
    
    // begin() returns the value of the first element
    // end() returns the last element on the list
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

//search for players on map
/**********Have custom mode with many rounds '!stop' to stop input to store your words queues********/
//

