#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Hangman.h"


using namespace std;

void Hangman::coreGame(int numRound){
    int incr = 1;
    bool safeActivated = false;
    bool wrongWord = false;
    do{
        
        string word1 = "hello",
               word2 = "bye",
               word3 = "cya";

        string input;
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
           
     
            do{
                displayHangMan(numWrong);
                cout<<endl<<storeLine<<endl;
                cout<<"Enter \"1\" to guess word. (Will lose instantly if "
                    <<"guessed wrong.\n";
                if(safeActivated == false)
                    cout<<"Enter \"2\" to guess word without losing. (Once per"
                        <<" round.\n)";
                cout<<"Enter a letter: ";
                cin>>input;
                
                if(input.size() > 1)
                    cout<<"Invalid Input: You must only enter 1 character. "
                        <<"Please enter \"1\" or if you haven't \"2\" to guess"
                        <<" the entire word.\n";    
            }while(input.size() > 1 && input != "1" && input != "2");

            if(input != "1" && input != "2"){
                for(int i = 0; i < chosenWord.length(); i++){
                    for(int j = 0; j < chosenWord.length();j++){
                        if(input[0] == chosenWord[i] && i != excludeIndex[j]){
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

            }else if(input == "1"){
                cout<<endl;
                cout<<"BEWARE: Guess the word correctly and you will automatic"
                    <<"ally win the game.\nGuess the wrong word and you will"
                    <<"instantly lose.\n";
                cout<<"If you're not up for it, enter \"0\" to return to "
                    <<"guessing only letters.\n";
                cout<<"Enter the word: ";
            }else if(input == "2" && safeActivated == false){
                cout<<endl
                cout<<"Warning: You'll only have safety mode once per turn.\n";
                cout<<"Safe Mode --- You will not lose a guess if word is "
                    <<"guessed incorrectly.\n";
                cout<<"Enter \"0\" if you do not wish to use up this feature.\n";
                cout<<"Enter the word: ";
                cin>>input;
                
                if(input != "0")
                    safeActivated = true;

            }
        }while(numTurns <= maxTurns && countSlot != 0);

            cout<<endl<<storeLine<<endl;
            if(countSlot == 0)
                cout<<"YOU'VE WON\n";
            else
                cout<<"Better luck next time!"<<endl;
    }while(++incr < numRound);
}

bool checkWordCount(string input, string chosenWord){
    bool validCount = false;
    
  
    
return validCount;}

void Hangman::menuDisplay(){
    char inChoice;  //Store user's choice within the menu
    
    do{
    cout<<"Enter 1 to play Hangman"<<endl;
    cout<<"Enter 2 to play EZ-Mode (choose the first letter of a word and that same letter will be given to you.)"<<endl;
    cout<<"Enter 3 to play Marathon Mode (choose number of rounds of Hangman to win."<<endl;
    cout<<"Enter 4 to enter your own word for the round"<<endl;
    cout<<"Enter 5 to display the rules"<<endl;
    cout<<"Enter 6 to exit"<<endl;
    cout<<"User Input: ";
    cin>>inChoice;
    
    if(inChoice < 1 && inChoice > 6)
        cout<<"\nInvalid Input: Please choose only option 1-6 from the menu "
            <<"below\n";
    }while(inChoice < 1 && inChoice > 6);
    
    switch(inChoice){
        case '1': coreGame(1);      break;
        case '2': ezMode();         break;
        case '3': marathonMode();   break;
        case '4': customWordMode(); break;
        case '5': rulesDisplay();   break;
       
        default: cout<<"\nOption: Exit has been selected. Terminating..."<<endl;
    }
            
}

void Hangman::ezMode(){
    char firstLetter;
    char confirm;
    cout<<"\n----------------- EZ Mode -----------------\n";
    cout<<"Enter the first letter for a random word and it will be given to you: ";
    cin>>firstLetter;
    
    
    do{
        cout<<"\nDo you wish to proceed with "<<firstLetter
            <<" round(s)?\nEnter \"y\" for YES or \"n\" for NO: ";

        cin>>confirm;

        if(confirm != 'y' && confirm != 'Y' && confirm != 'N'
            && confirm != 'n'){

            cout<<endl;
            cout<<"Invalid Input: The character inputed does not match "
                <<"\"y\" for YES or \"n\" for NO. Please try again.\n";
            cout<<endl;

        }
    }while(confirm != 'y' && confirm != 'Y' && confirm != 'N'
            && confirm != 'n');
    
    
    //Access set to retrieve a random word 
    //*********** put function here *******
    
    
    
    coreGame(1);
}


void Hangman::marathonMode(){
    int numRound;   //Holds number of rounds for hangman   
    char confirm;   //Asks for confirmation on number of rounds

    do{
        cout<<"\n----------------- Marathon Mode -----------------\n";
        cout<<"Enter the number of rounds you wish to complete to win: ";
        cin>>numRound;
        
        if(numRound >= 1)
            do{
                cout<<"\nDo you wish to proceed with "<<numRound
                    <<" round(s)?\nEnter \"y\" for YES or \"n\" for NO: ";
                
                cin>>confirm;
                
                if(confirm != 'y' && confirm != 'Y' && confirm != 'N'
                    && confirm != 'n'){
                    
                    cout<<endl;
                    cout<<"Invalid Input: The character inputed does not match "
                        <<"\"y\" for YES or \"n\" for NO. Please try again.\n";
                    cout<<endl;
                    
                }
            }while(confirm != 'y' && confirm != 'Y' && confirm != 'N'
                    && confirm != 'n');
        else 
            cout<<"Invalid Input: The number of round must be positive value."
                <<" Please try again.\n";
        
    }while(numRound >= 1);
    
    coreGame(numRound);
    
}

void Hangman::customWordMode(){
    string customWord;   
    char confirm;   //Asks for confirmation on number of rounds
    
    do{
        cout<<"\n----------------- Marathon Mode -----------------\n";
        cout<<"Enter the first letter for a random word and it will be given "
            <<"to you: ";
        cin>>customWord;
        
      
            do{
                cout<<"\nDo you wish to proceed with \""<<customWord
                    <<"\" as your word for the round?\nEnter \"y\" for YES or "
                    <<"\"n\" for NO: ";
                
                cin>>confirm;
                
                if(confirm != 'y' && confirm != 'Y' && confirm != 'N'
                    && confirm != 'n'){
                    cout<<endl;
                    cout<<"Invalid Input: The character inputed does not match "
                        <<"\"y\" for YES or \"n\" for NO. Please try again.\n";
                    cout<<endl;
                }
            }while(confirm != 'y' && confirm != 'Y' && confirm != 'N'
                    && confirm != 'n');
       
        
    }while(confirm == 'N' && confirm == 'n');
    
    coreGame(1);
}

void Hangman::titleDisplay(){
    cout<<"********************************************************************"<<endl;
    cout<<"*         *       *       *****      *      *    *********         *"<<endl;        
    cout<<"*         *       *      *     *     * *    *    *       *         *"<<endl;    
    cout<<"*         *       *      *     *     *  *   *    *                 *"<<endl; 
    cout<<"*         *********      *******     *   *  *    *   *****         *"<<endl;   
    cout<<"*         *       *      *     *     *    * *    *       *         *"<<endl;   
    cout<<"*         *       *      *     *     *     **    *       *         *"<<endl;   
    cout<<"*         *       *      *     *     *      *    *********         *"<<endl; 
    cout<<"*                                                                  *"<<endl;
    cout<<"*                **     **       *****      *      *               *"<<endl;
    cout<<"*                * *   * *      *     *     * *    *               *"<<endl;
    cout<<"*                *  * *  *      *     *     *  *   *               *"<<endl;
    cout<<"*                *   *   *      *******     *   *  *               *"<<endl;
    cout<<"*                *       *      *     *     *    * *               *"<<endl;
    cout<<"*                *       *      *     *     *     **               *"<<endl;
    cout<<"*                *       *      *     *     *      *               *"<<endl;
    cout<<"********************************************************************"<<endl;

} 

void Hangman::displayHangMan(int numWrong){
    cout<<endl;
    
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


void Hangman::rulesDisplay(){

    cout<<endl;
    cout<<"Winning Condition: Quess all the letter or entire word correctly "
        <<"before getting 7 wrongs (before hangman fully displays) to win.\n";
    cout<<"-------------------- Player Option -----------------------------";
    cout<<"\t1) ";
    cout<<"\t2) Active by entering \"!safety\" to safely guess the word "
        <<"without losing a guess. (Note: Player may only use this option "
        <<"once per round)\n";
    
    

    
    cout<<"\nPress enter to continue...";
    cin.ignore();

menuDisplay();
}