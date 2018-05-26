/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dangerouspirate
 *
 * Created on April 5, 2018, 11:59 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>  //Use to obtain words from words.txt
#include "Hangman.h"
#include "WordFetch.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    /*
    Hangman h;
    h.titleDisplay();
    h.menuDisplay();
     */
    
    
    srand(time(0));
    WordFetch o(5);
    o.wordsInSet();
    /*
    o.storeInputList("fwogjow");
    o.storeInputList("fwogdsfwgwgwgwgwgjow");

    o.displayInputList();
    
    cout<<"\n-------------\n";
    o.wordsInStack();
    string IAmString = o.popWordMarathon();
    cout<<"IAmString = "<<IAmString<<endl;
    */
    
    o.setUsernameMap();
    
    
    
  
    return 0;
}

