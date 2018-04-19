#include "Scoreboard.h"
#include <cstdlib>
#include <iostream>
#include <map>  //Use to store username with their heighest score
#include <fstream>
#include <string>
#include <sstream>//Use to convert string into an integer with std::stringstream
#include <boost/functional/hash.hpp> //Use to generate hash value

using namespace std;

/******************************************
 *                Map -                   *
 * Stores and displays usernames paired   *
 * with its scores                        *
 * ****************************************/

//Requests username at the end of the game to store score
void Scoreboard::requestUsername(){
    char input;
    string pw;  //Holds password to be hashed

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
            cout<<"\nPlease enter a Password to log future scores "
                <<"with the same Username: "; 
            cin>>pw;
            
            //Assigns password & username to their respective .txt files
            insertUsernameToFile(username);
            insertPasswordToFile(pw);
            
        }else if(foundName == true){
            //Checks if user is a returning player
            //Validates their input for (y/n) as well
            do{
                cout<<"\nThere already exist a username \""<<username<<"\".\n";
                cout<<"Does this username belong to you? (y/n): ";
                cin>>input;
            
                //Check if person is a returning user
                if(input == 'y' || input == 'Y'){
                    bool passwordMatch = false;
                    int countAttempts = 3;
                    //Checks if user's password matches the old password
                    do{
                    //************ Insert Code that checks if password is correct **************/
                        ifstream myfileCountElem ("usernames.txt");
                        int countElem = 0;
                        string lineName = "";
                        while(getline (myfileCountElem, lineName)){
                            countElem++;
                        };
                        
                        ifstream myfileAccessPW ("passwords.txt");
                        string linePW = "";
                        for(int i = 0; i < countElem; i++){
                            getline (myfileAccessPW, linePW);
                        }
                        
                        
cout<<endl<<"linePW = "<<hashGen(linePW)<<endl; 
cout<<endl<<"pw = "<<hashGen(pw)<<endl;
                        
                        
                        if(hashGen(linePW) == hashGen(pw)){
                            passwordMatch = true;
                        }else{  //If player entered the wrong password
                            
                            cout<<"\nYour password did not match."<<endl;
                            cout<<"\nYou have now have 3 attempts to enter"
                                <<" the correct password or you will not be"
                                <<" able to log in your score.\n";
                            
                            
                            //Provides 
                            while(countAttempts > 0 && passwordMatch == false){
                                cout<<endl<<countAttempts--<<" Attempts Left\n";
                                cout<<"\nEnter your Password: ";
                                cin>>pw;
                                

cout<<endl<<"linePW = "<<hashGen(linePW)<<endl; 
cout<<endl<<"pw = "<<hashGen(pw)<<endl;


                                //if the enter password matches the stored password
                                if(hashGen(linePW) == hashGen(pw)){
                                    //Do not need to insert username if player
                                    //is a returner
                                    //Inserting password into passwords.txt
                                    insertPasswordToFile(pw);
                                    passwordMatch = true;
                                }
                            }
                        }
                            
                        
                    }while(passwordMatch != true && countAttempts > 0);
                }
                    
                    
                if(input != 'n' && input != 'N' && input != 'y' && input != 'Y'){
                
                    cout<<"\nSorry buy your input must be \"y\" for Yes or "
                        <<"\"n\" for No.\n";
                }
            }while(input != 'n' && input != 'N' && input != 'y' && input != 'Y');
            
            //If user is not a returning player
            if(input == 'n' || input == 'N'){
                do{
                    cout<<"\nEnter new Username: ";
                    cin>>username;
                }while(checkUsername(username) == true);
                
                cout<<"\nEnter new Password: ";
                cin>>pw;
                
            //Assigns password & username to their respective .txt files
            insertUsernameToFile(username);
            insertPasswordToFile(pw);
            
                
            }
        }
        
    }
}

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
    
    cout<<endl<<endl<<"foundName = "<<foundName<<endl;
    cout<<endl<<endl<<"m.count = "<<m.count(username)<<endl;
  
return foundName;}


int Scoreboard::hashGen(std::string key){
    boost::hash<std::string> string_hash;

    return string_hash(key);}


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
}


//Inserts password to passwords.txt
void Scoreboard::insertPasswordToFile(string pw){

    int hashKey = hashGen(pw);
    cout<<endl<<hashKey<<endl;
    //****** Write to passwords.txt ******
    fstream myfilePassword;
    myfilePassword.open("passwords.txt", fstream::app);

    if (myfilePassword.is_open()){
        myfilePassword<<hashKey<<endl;
        myfilePassword.close();

    }else
        cout<<"\nWriting Error: Cannot open usernames.txt\n";
}

