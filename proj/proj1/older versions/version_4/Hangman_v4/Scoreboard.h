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
class Scoreboard{
private:
    int newScore;
    
public:
    void setScore(int);         //Takes in most recent score
    void requestUsername();     //Requests username at the end of game
    void readNameScore();  //Displays the list of previous names & scores
        
};


#endif /* PROFILEMANAGE_H */

