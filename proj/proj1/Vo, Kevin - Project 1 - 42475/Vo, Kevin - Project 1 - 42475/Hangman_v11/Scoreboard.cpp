/* 
 * File:   Scoreboard.cpp
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Assignment: Project 1
 * Course: CSC-17C (42475)
 * Purpose: Obtains/verify usernames and scores(s) for STL's Map 
 * Created on April 10, 2018, 11:59 AM
 */

#include "Scoreboard.h"
#include <cstdlib>
#include <iostream>
#include <map>  //Use to store username with their heighest score
#include <fstream>
#include <string>
#include <sstream>//Use to convert string into an integer with std::stringstream
#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
#include <functional>//To be used with pre-made hashes

using namespace std;

/******************************************
 *                Map -                   *
 * Stores and displays usernames paired   *
 * with its scores                        *
 * ****************************************/

//Requests username at the end of the game to store score
void Scoreboard::requestUsername(){
    char input;
    bool foundUsername = false; //Checks if username is present to allow change of score

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
        
        //Checks if username already exists
        bool foundName = checkUsername(username);
        
        if(foundName == false){
            
            //Assigns password & username to their respective .txt files
            insertUsernameToFile(username);
            
        }else if(foundName == true){
            //Checks if user is a returning player
            //Validates their input for (y/n) as well
            cout<<"\nThere already exist a username \""<<username<<"\".\n";
                
            do{
                cout<<"\nEnter new Username: ";
                cin>>username;
                
                //Checks if username exist
                if(checkUsername(username) == true){
                    do{
                        cout<<"\""<<username<<"\" has been taken.\n";
                        cout<<"Would you like to try again? (y/n): ";
                        cin>>input;
                        if(input == 'Y')
                            input = 'y';
                        else if(input == 'N')
                            input = 'n';

                            if(input != 'y' && input != 'n')
                                cout<<"Input must be \"y\" for Yes or \"n\" for No.\n";
                    }while(input != 'y' && input != 'n');
                }
            }while(checkUsername(username) == true && input != 'n');
            
            //Uses hash
            //if(checkUserCode(username) != true)
                //cout<<"\nUsername has been verified to be new... now inserting name.\n";
            
            //Assigns password & username to their respective .txt files
            if(checkUsername(username) != true)
                insertUsernameToFile(username);

            
    
        }
        
    }
    updateNameScoreMap();
}

/**********************************************************
 *                       Map -                            *
 * Used to store and display both usernames & score from  *
 * usernames.txt & scores.txt                             *
 * ********************************************************/

//Displays the list of previous names & scores
void Scoreboard::readNameScore(){
    
    updateNameScoreMap();
        

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
    
    
}

//Takes in score
void Scoreboard::setScore(int score){
    newScore = score;
}


//Checks if username already exists
bool Scoreboard::checkUsername(string username){
    updateNameScoreMap();
    
    bool foundName;     //Returns if username already exist or not
    
    //Checks to see if the name on already on the map
    if(m.count(username) == 0) 
        foundName = false;
    else
        foundName = true;
    
    //cout<<endl<<endl<<"foundName = "<<foundName<<endl;
    //cout<<endl<<endl<<"m.count = "<<m.count(username)<<endl;
  
return foundName;}

/*
//Checks if backup username already exists too
bool Scoreboard::checkUserCode(string username){
    bool foundCode = false;     //Returns if username already exist or not
    
    std::hash<std::string> str_hash;

    string line;
    ifstream myfile ("backup_usernames.txt");
    if (myfile.is_open()){
        stringstream ss;    //create a stringstream
        while ( getline (myfile,line) && foundCode != true){
            
            ss << str_hash(username);     //add integer to the stream
            //cout<<"\n\t\t\t\tss.str() = "<<ss.str()<<endl;
            if(ss.str() == line)
                foundCode = true;
        }
        myfile.close();
    }else cout <<"\nReading error: Unable to open backup_usernames.txt for "
               <<"cross-referencing with hash.\n";
  

    //cout<<endl<<endl<<"foundCode = "<<foundCode<<endl;
  
return foundCode;}
*/

//Updates the map dealing with the scoreboard
void Scoreboard::updateNameScoreMap(){
    string lineName;
    string lineScore;        //temporary string for each line in .txt
      
    int countLine = 0;  //Counts the number of lines (elements) in .txt
    int i = 0;          //incrementer       
    
    ifstream myfileCount ("usernames.txt");
  
    while(getline (myfileCount, lineName) ){
      countLine++;
    };
    
    myfileCount.close();
 
    
    //Reading files usernames.txt & scores.txt to insert into map
    ifstream myfileName ("usernames.txt");
    ifstream myfileScore ("scores.txt");
    if (myfileName.is_open() && myfileScore.is_open()){
    
        while(getline (myfileName, lineName) && getline (myfileScore, lineScore)){
            
            p.first = lineName;
            p.second = lineScore;
            m.insert(p);
        };

        myfileName.close();
    } else 
        cout << "\nReading Error: Cannot open usernames.txt or scores.txt"; 


}

//Inserts username to usernames.txt
void Scoreboard::insertUsernameToFile(string username){
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
    
    /*
    //****** Write hash value to backup_usernames.txt ******
    fstream myfileCode;
    myfileCode.open("backup_usernames.txt", fstream::app);

    if (myfileCode.is_open()){
        std::hash<std::string> str_hash;
        myfileCode<<str_hash(username)<<endl;
        myfileCode.close();

    }else
        cout<<"\nWriting Error: Cannot open backup_usernames.txt\n";
      */
}


