/* 
 * File:   Scoreboard.h
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Assignment: Project 1
 * Course: CSC-17C (42475)
 * Purpose: Obtains/verify usernames and scores(s) for STL's Map 
 * Created on April 10, 2018, 11:59 AM
 */


#ifndef PROFILEMANAGE_H
#define PROFILEMANAGE_H

#include <map>
#include <string>

using namespace std;

class Scoreboard{
private:
    int countPos;
    int newScore;   //Stores the latest score
    map <string, string> m; //Object for maps
    pair <string, string> p;
    void insertPasswordToFile(string); //Insert password to passwords.txt
    void insertUsernameToFile(string); //Insert username to usernames.txt
    unsigned int stringToInt(string);   //Converts string to an integer
    void replaceScore(); //Replaces a score in scores.txt
    //bool checkUserCode(string);   //Checks backup_usernames for used names
    
public:
    void setScore(int);         //Takes in most recent score
    void requestUsername();     //Requests username at the end of game
    void readNameScore();  //Displays the list of previous names & scores
    bool checkUsername(string); //Checks if username already exists
    void updateNameScoreMap();  //Updates the map with the latest 

        
};


#endif /* PROFILEMANAGE_H */

