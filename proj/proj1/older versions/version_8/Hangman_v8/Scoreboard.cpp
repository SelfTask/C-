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
                    
                    cout<<"\nEnter Password: ";
                    cin>>pw;
                    //Checks if user's password matches the old password
                    do{
                        //Checks if passwords is correct
                        ifstream myfileCountElem ("usernames.txt");
                        int countElem = 0;
                        string lineName = "";
                        do{
                            getline(myfileCountElem, lineName);
                            //Find the position of the username on the file
                            //getline(myfileCountElem, lineName);
                            if(lineName != username)
                                countElem++;
                            cout<<"\n\t\t\t\t\tHELLO"<<lineName<<endl;
                            
                            if(lineName == username){
                                countPos = countElem;   //Stores position of desired username in usernames.txt
                                foundUsername = true;
                            }
                        }while(lineName == username);
                        
                        ifstream myfileAccessPW ("passwords.txt");
                        string linePW = "";
                        for(int i = 0; i < countElem; i++){
                            getline (myfileAccessPW, linePW);
                        }
                        
cout<<endl<<"llll = "<<linePW<<endl;                        
cout<<endl<<"linePW = "<<hashGen(linePW)<<endl; 
cout<<endl<<"pw = "<<hashGen(pw)<<endl;
                        
                        //Checks if new hash value of password matches the old
                        if(stringToInt(linePW) == hashGen(pw)){
                            passwordMatch = true;
                            if(foundUsername == true)
                                replaceScore(); //Replaces the score in scores.txt
                            else cout<<"\nUsername not found!"<<endl;
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
                                

cout<<endl<<"llll = "<<linePW<<endl;   
cout<<endl<<"linePW = "<<hashGen(linePW)<<endl; 
cout<<endl<<"pw = "<<hashGen(pw)<<endl;


                                //if the enter password matches the stored password
                                if(stringToInt(linePW) == hashGen(pw)){
                                    //Do not need to insert username if player
                                    //is a returner
                                    //Inserting password into passwords.txt
                                    insertPasswordToFile(pw);
                                    passwordMatch = true;
                                    if(foundUsername == true)
                                        replaceScore(); //Replaces the score in scores.txt
                                    else cout<<"\nUsername not found!"<<endl;
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


//FNV-Hash borrowed from Lab 5 of CSC-7
//Generate hash values for password
unsigned int Scoreboard::hashGen(string key){
   const unsigned int fnv_prime = 0x811C9DC5;
   unsigned int hash = 0;
   for(std::size_t i = 0; i < key.length(); i++)
   {
      hash *= fnv_prime;
      hash ^= key[i];
   }

return hash;}


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
    //Generate hash value from password to be stored in password.txt
    unsigned int hashKey = hashGen(pw);
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

//Returns integer from string
//For hash value validation from passwords.txt
unsigned int Scoreboard::stringToInt(string strNum){
    unsigned int val;    //Stores actual integer of a string representation of a number 

    istringstream iss (strNum);
    
    iss >> val; //Convert string into integer
    
   
return val;}

//A line in scores.txt with rewriting the whole file
void Scoreboard::replaceScore(){

    /* Write a program to delete a line from a file */
    char filename[100] = "scores.txt";
    cout<<filename<<endl;
    char str[100];
    FILE * fp1, *fp2;
    int del_line_no = countPos + 1;
    int line_no = 0;
    
    
    cout<<"\n\t\t\t\t\t\tline_no = "<<line_no<<endl;
    cout<<"\n\t\t\t\t\t\tdel_line_no = "<<del_line_no<<endl;
    
    printf("Enter the file name : ");
    //scanf("score.txt", filename);
    fp1 = fopen(filename, "r");
    printf("\nContent of file before modification : \n");
    //print_file(fp1);
    rewind(fp1);
    printf("\nEnter the no. of the line to be deleted : ");
    //scanf("countPos", &del_line_no);
    fp2 = fopen("replica.txt", "w");
    while( fgets(str, 99, fp1) != NULL )
    {
        line_no++;
        if(line_no != del_line_no)
        {
            fputs(str, fp2);
        }else{
            stringstream ss;//create a stringstream
            ss << newScore <<endl;//add number to the stream

            // assigning value to string s
            string s = ss.str();

            int n = s.length(); 

            // declaring character array
            char char_array[n+1]; 

            // copying the contents of the 
            // string to char array
            strcpy(char_array, s.c_str()); 

            for (int i=0; i<n; i++)
              cout << char_array[i]; 
    
            fputs(char_array, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove(filename);
    rename("replica.txt", filename);
    fp1 = fopen(filename, "r");
    printf("\nContent of file after modification : \n");
    //print_file(fp1);
    
  
    fclose(fp1);
}