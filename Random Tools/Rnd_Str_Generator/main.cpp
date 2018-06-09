/* 
 * File:   main.cpp
 * Author: dangerouspirate
 *
 * Created on May 8, 2018, 1:14 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


int main(int argc, char** argv) {
    srand(time(NULL));
    
    //Char array of possible characters
    const char letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
    'o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6',
    '7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
    'Q','R','S','T','U','V','W','X','Y','Z'}; 
    
    //Stores the number of elements in char[] letters
    int lengthStr = sizeof(letters);
    
    //Generate a random length for key
    int rndSize = (rand() % 100) + 1;   //"+ 1" is for storing the NULL
    
    //Allocate memory for random strings
    char* rndKey = new char[rndSize];

    //Assigning ascii values into key
    for(int i = 0; i < rndSize - 1; i++){
        
        rndKey[i] = letters[rand() % lengthStr];
       
    }
    
    //Sets the end of string as NULL
    rndKey[rndSize - 1] = '\0';
    
    //Display key
    cout<<string(rndKey);
    
    //Locate key
    delete[] rndKey;
    return 0;
}

