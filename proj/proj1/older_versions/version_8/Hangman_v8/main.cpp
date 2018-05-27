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

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>  //Use to obtain words from words.txt
#include "WordFetch.h"
#include "Hangman.h"



using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(NULL));
    
    //Declares object for Hangman class
    Hangman h;
    //Display the Hangman title on the screen
    h.titleDisplay();
    //Displays the menu to select game mode
    h.menuDisplay();
     
    return 0;
}