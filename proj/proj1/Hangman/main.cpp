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
#include "Hangman.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Hangman h;
    h.titleDisplay();
    h.menuDisplay();
    return 0;
}

