/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dangerouspirate
 *
 * Created on April 3, 2018, 10:53 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

void displayHangMan(int);
int main(int argc, char** argv) {
    string word1 = "hello",
           word2 = "bye",
           word3 = "cya";
    char input;
    srand(time(NULL));
    bool letterFound = false;
    int randNum = rand()%999;
    string chosenWord;
    if(randNum <= 333){
        chosenWord = word1;
    }else if(randNum <= 666){
        chosenWord = word2;
    }else if(randNum > 666){
        chosenWord = word3;
    }
    string storeLine = "";
    int excludeIndex[chosenWord.length()];
    
    for(int i = 0; i < chosenWord.length(); i++){
        storeLine+="-";
        excludeIndex[i] = -1;
    }
    
    cout<<endl;
    int numTurns = 0;
    const int maxTurns = 6;
    int numWrong = 0;
    int incrExclude = 0;
    int countSlot = 0;
    
    do{
        countSlot = 0;
        displayHangMan(numWrong);
        cout<<endl<<storeLine<<endl;
        cout<<"Enter a letter: ";
        cin>>input;

        for(int i = 0; i < chosenWord.length(); i++){
            for(int j = 0; j < chosenWord.length();j++){
                if(input == chosenWord[i] && i != excludeIndex[j]){
                    excludeIndex[incrExclude] = i;
                    storeLine[i] = chosenWord[i];
                    letterFound = true;
                    incrExclude++;
                }
            }

        }

        if(letterFound == false)
            numWrong++;

        for(int i = 0; i < chosenWord.length(); i++){
            if(storeLine[i] == '-'){
                countSlot++;
            }
        }
       
        
        
        letterFound = false;
        numTurns++;





        }while(numTurns <= maxTurns && countSlot != 0);
        
        cout<<endl<<storeLine<<endl;
        if(countSlot == 0)
            cout<<"YOU'VE WON\n";
        else
            cout<<"Better luck next time!"<<endl;
    return 0;
}

void displayHangMan(int numWrong){
if(numWrong == 0){
            cout<<"|------."<<endl;
            cout<<"|       "<<endl;
            cout<<"|       "<<endl;
            cout<<"|       "<<endl;
            cout<<"|       "<<endl;
            cout<<"|       "<<endl;
        }else if(numWrong == 1){
            cout<<"|------."<<endl;
            cout<<"|      O "<<endl;
            cout<<"|        "<<endl;
            cout<<"|       "<<endl;
            cout<<"|       "<<endl;
            cout<<"|       "<<endl;
        
        }else if(numWrong == 2){
            cout<<"|------."<<endl;
            cout<<"|      O "<<endl;
            cout<<"|      #  "<<endl;
            cout<<"|       "<<endl;
            cout<<"|       "<<endl;
            cout<<"|       "<<endl;
        }else if(numWrong == 3){
            cout<<"|------."<<endl;
            cout<<"|      O "<<endl;
            cout<<"|    --#  "<<endl;
            cout<<"|       "<<endl;
            cout<<"|       "<<endl;
            cout<<"|       "<<endl;
        }else if(numWrong == 4){
            cout<<"|------."<<endl;
            cout<<"|      O "<<endl;
            cout<<"|    --#--  "<<endl;
            cout<<"|       "<<endl;
            cout<<"|       "<<endl;
            cout<<"|       "<<endl;
        }else if(numWrong == 5){
            cout<<"|------."<<endl;
            cout<<"|      O "<<endl;
            cout<<"|    --#--  "<<endl;
            cout<<"|     /  "<<endl;
            cout<<"|       "<<endl;
            cout<<"|       "<<endl;
        }else if(numWrong == 6){
            cout<<"|------."<<endl;
            cout<<"|      O "<<endl;
            cout<<"|    --#--  "<<endl;
            cout<<"|     / \\ "<<endl;
            cout<<"|       "<<endl;
            cout<<"|       "<<endl;
        }
cout<<"------------------------"<<endl<<endl;
}