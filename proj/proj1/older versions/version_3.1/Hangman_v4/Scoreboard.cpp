#include "Scoreboard.h"
#include <cstdlib>
#include <iostream>
#include <map>  //Use to store username with their heighest score
#include <fstream>
#include <string>
#include <sstream>//Use to convert string into an integer with std::stringstream

using namespace std;

/******************************************
 *                Map -                   *
 * Stores and displays usernames paired   *
 * with its scores                        *
 * ****************************************/

//Requests username at the end of the game to store score
void Scoreboard::requestUsername(){
    char input;

    cout<<"\nYou have a score of "<<newScore<<endl;
    do{
        cout<<"\nWould you like to log your score? (y/n): ";
        cin>>input;
        
        if(input != 'n' && input != 'N' && input != 'y' && input != 'Y')
            cout<<"\n\nSorry. Your input must be \"y\" for Yes or \"n\" for"
                <<" No. Please try again.\n";
        
    }while(input != 'n' && input != 'N' && input != 'y' && input != 'Y');
    
    if(input == 'y' || input == 'Y'){
        string username;
        cout<<"\nEnter Username: ";
        cin>>username;
        
        //****** Write to usernames.txt ******
        fstream myfileName;
        myfileName.open("usernames.txt", fstream::app);

        if (myfileName.is_open()){
            myfileName<<username<<endl;
            myfileName.close();
        
        }else
            cout<<"\nWriting Error: Cannot open usernames.txt\n";
        
        //****** Write to scores.txt ******
        fstream myfileScore;
        myfileScore.open("scores.txt", fstream::app);
        
        if (myfileScore.is_open()){
            stringstream ss;    //create a stringstream
            ss << newScore;     //add integer to the stream
   
            myfileScore<<ss.str()<<endl;
            myfileScore.close();
        }else
            cout<<"\nWriting Error: Cannot open scores.txt\n";
        
    }
}

//Displays the list of previous names & scores
void Scoreboard::readNameScore(){
    
    string line;        //temporary string for each line in .txt
      
    int countLine = 0;  //Counts the number of lines (elements) in .txt
    int i = 0;          //incrementer       
    
    ifstream myfileCount ("usernames.txt");
  
    while(getline (myfileCount, line) ){
      countLine++;
    };
    
    string *score = new string[countLine];
    string *name = new string[countLine];
    
    myfileCount.close();
 
    
    
    ifstream myfileName ("usernames.txt");
    if (myfileName.is_open()){
    
        while(getline (myfileName, line)){
            name[i] = line;
            i++;
        };

        myfileName.close();
    } else 
        cout << "\nReading Error: Cannot open usernames.txt"; 


    //Reset incrementer for listing score
    i = 0;
  
  
    ifstream myfileScore ("scores.txt");
    if (myfileScore.is_open()){
        
        
        while (getline (myfileScore,line) ){
            score[i] = line;
            i++;
        };

        myfileScore.close();
    }else 
        cout<<"\nReading Error: Cannot open scores.txt"; 
  
  
  
    map<string, string> m;
    pair <string, string> p;
    
    for(int i = 0; i < countLine; i++){
        p.first = name[i];
        p.second = score[i];
        m.insert(p);
    }
        

    map <string, string> :: iterator itr;
    
    cout<<endl<<endl;
    cout<<"*******************************************"<<endl;
    cout<<"*               Scoreboard                *"<<endl;
    cout<<"*******************************************"<<endl;
    cout<<endl;
    cout<<"Players:\n";
    cout<<"--------\n";
    for (itr = m.begin(); itr != m.end(); ++itr){
        cout << itr->first<< endl << "\tScore ----> " << itr->second<<endl;
    }
    cout << endl;
    
    delete[] name;
    delete[] score;
}

//Takes in score
void Scoreboard::setScore(int score){
    newScore = score;
}

