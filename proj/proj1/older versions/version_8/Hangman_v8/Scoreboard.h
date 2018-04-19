/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProfileManage.h
 * Author: dangerouspirate
 *
 * Created on April 13, 2018, 6:42 PM
 */


#ifndef PROFILEMANAGE_H
#define PROFILEMANAGE_H

#include <map>
#include <string>

using namespace std;

class Scoreboard{
private:
    int countPos;
    int newScore;
    map <string, string> m;
    pair <string, string> p;
    void insertPasswordToFile(string); //Insert password to passwords.txt
    void insertUsernameToFile(string); //Insert username to usernames.txt
    unsigned int stringToInt(string);   //Converts string to an integer
    void replaceScore(); //Replaces a score in scores.txt
    
public:
    void setScore(int);         //Takes in most recent score
    void requestUsername();     //Requests username at the end of game
    void readNameScore();  //Displays the list of previous names & scores
    bool checkUsername(string); //Checks if username already exists
    unsigned int hashGen(string);        //Generates a hash key for password
    void updateNameScoreMap();  //Updates the map with the latest 

        
};


#endif /* PROFILEMANAGE_H */

