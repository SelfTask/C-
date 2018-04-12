#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Hangman.h"


using namespace std;

void Hangman::coreGame(int numRound){
    int incr = 1;
    int countSlot = 0;      //counts the value for open slots left
    bool won = false;
    bool safeActivated = false;
    bool escapeFeature = false;
    bool wrongWord = false;
    
    
    //Do-Whole loops the number of rounds a game mode offers
    //Also increments the number of rounds in its condition
    do{
        
        string word1 = "hello",
               word2 = "bye",
               word3 = "cya";

        string input;
        srand(time(NULL));
        bool letterFound = false;
        int randNum = rand()%999;
        randNum = 1;
        string chosenWord;
        if(randNum <= 333){
            chosenWord = word1;
        }else if(randNum <= 666){
            chosenWord = word2;
        }else if(randNum > 666){
            chosenWord = word3;
        }
        
        cout<<endl<<chosenWord<<endl;
        
        //Holds the status of guessed characters and open slots left
        string storeLine = "";
        
        
        int excludeIndex[chosenWord.length()];

        //For-loop that checks the number of open slots base on
        //the length of the chosen word for the round
        for(int i = 0; i < chosenWord.length(); i++){
            storeLine+="-";
            excludeIndex[i] = -1;
        }

        cout<<endl;
        
        int numTurns = 0;
        const int maxTurns = 6;
        int numWrong = 0;
        int incrExclude = 0;

        //Do-while loop: Checks the winning conditions
        do{
            //Resets countSlot to 0 for every round
            //checks if player has won
            countSlot = 0;
            
            //For-loop that assigns the number of open slots base on
            //the length of the chosen word for the round
            for(int i = 0; i < chosenWord.length(); i++){

                //Increments countSlot for every open slots avaliable
                if(storeLine[i] == '-'){
                    countSlot++;    //counts the amount of open slots left
                                        //if count == 0 then player wins
                }
                        
            }
                
            if(countSlot == 0){
                won = true;
                numTurns = maxTurns + 1;
            }
                
            escapeFeature = false;
            
            if(won == false){
             
                //inner while loop: Prompts the player to enter guessed 
                //character or select one of the following features       
                //Feature #1: Guess word and instantly lose
                //Feature #2: A once per round life line where incorrectly guessed
                //word will not cause the player to lose
                do{
                    //Displays the appropriate hangman image based on amount of 
                    //wrong guesses
                    displayHangMan(numWrong);

                    cout<<endl<<storeLine<<endl;

                    cout<<"Enter \"1\" to guess word. (Will lose instantly if "
                        <<"guessed wrong.)\n";

                    //Opens up game feature to allow a free mode where guessing
                    //a word wrong will not harm player's status of winning
                    if(safeActivated == false)
                        cout<<"Enter \"2\" to guess word without losing. (Once per"
                            <<" round)\n";

                    //Prompts player for input
                    cout<<"Enter a letter: ";
                    cin>>input;

                    if(input == "2" && safeActivated == true)
                        cout<<"\nSorry. You have already used up your life line"
                            <<" (Option 2). You must wait for the next round "
                            <<"to use it again.\n";
                    //Warns the player if they've enter too many letters
                    if(input.size() > 1)
                        cout<<"Invalid Input: You must only enter 1 character. "
                            <<"Please enter \"1\" or if you haven't \"2\" to"
                            <<" guess the entire word.\n";    

                    //do-while loop checks for activation of features and size of 
                    //input
                    //If player chooses one of the two options above, it will then
                    //terminate this do-while loop to proceed them to the next 

                }while(input.size() > 1 && input != "1" && input != "2");

                //Checks if inputed character is present in the chosen word
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

                    //Keeps track of the number of wrong guesses
                    if(letterFound == false)
                        numWrong++;




                    letterFound = false;
                    numTurns++;

                //Unlocks word guessing mode
                }else if(input == "1"){
                    cout<<endl;
                    cout<<"BEWARE: Guess the word correctly and you will automatic"
                        <<"ally win the game.\nGuess the wrong word and you will"
                        <<"instantly lose.\n";
                    cout<<"If you're not up for it, enter \"0\" to return to "
                        <<"guessing only letters.\n";
                    cout<<"Enter the word: ";
                    cin>>input;

                    if(input != "0"){
                        if(input == chosenWord){
                            cout<<"*** You've guessed the correct word! "
                                <<"You have WON! ***"<<endl;
                        }else{
                            cout<<"\nYour guess was wrong. You Lose\n";
                        }
                        return;
                    }else
                        numTurns--;


                //Unlocks the safe feature of the game
                }else if(input == "2" && safeActivated == false){
                    cout<<endl;
                    cout<<"Warning: You'll only have safety mode once per turn.\n";
                    cout<<"Safe Mode --- You will not lose a guess if word is "
                        <<"guessed incorrectly.\n";
                    cout<<"Enter \"0\" if you do not wish to use up this feature.\n";
                    cout<<"Enter the word: ";
                    cin>>input;

                    if(input != "0"){
                        safeActivated = true;
                        if(input == chosenWord){
                            cout<<"*** You've guessed the correct word! "
                                <<"You have WON! ***"<<endl;
                            return;
                        }
                    }else
                        numTurns--;

                }
            }
        }while(numTurns <= maxTurns && countSlot != 0);

        //Redisplay man's status
        displayHangMan(numWrong);

        //Informs player of the game's outcome before game ends
        if(won == true)
            cout<<"\n*** YOU'VE WON ***\n";
        else
            cout<<"\n*** You lose. Better luck next time! ***"<<endl;
        
        //Displays the word at the end of the game
        cout<<endl<<"Answer: "<<chosenWord<<endl;
        ++incr;
    }while(incr <= numRound);
}

bool checkWordCount(string input, string chosenWord){
    bool validCount = false;
    
  
    
return validCount;}

void Hangman::menuDisplay(){
    char inChoice;  //Store user's choice within the menu
    
    do{
        //Displays the main menu
        cout<<"Enter 1 to play Hangman"<<endl;
        cout<<"Enter 2 to play EZ-Mode (choose the first letter of a word and"
            <<" that same letter will be given to you.)"<<endl;
        cout<<"Enter 3 to play Marathon Mode (choose number of rounds of "
            <<"Hangman to win."<<endl;
        cout<<"Enter 4 to enter your own word for the round"<<endl;
        cout<<"Enter 5 to display the rules"<<endl;
        cout<<"Enter 6 to exit"<<endl;
        cout<<"User Input: ";
        cin>>inChoice;

        if(inChoice < 1 && inChoice > 6)
            cout<<"\nInvalid Input: Please choose only option 1-6 "
                <<"from the menu below\n";
    }while(inChoice < 1 && inChoice > 6);
    
    //Switch statement that calls upon the different game modes and rules
    //depending on player's choice
    switch(inChoice){
        case '1': coreGame(1);      break;
        case '2': ezMode();         break;
        case '3': marathonMode();   break;
        case '4': customWordMode(); break;
        case '5': rulesDisplay();   break;
       
        default: cout<<"\nOption: Exit has been selected. Terminating..."<<endl;
    }
            
}

//Game mode that allows user to select a random word by the first character
//of that same word, and repeats of that letter within the selected word will
//given as well
void Hangman::ezMode(){
    char firstLetter;
    char confirm;
    cout<<"\n----------------- EZ Mode -----------------\n";
    cout<<"Enter the first letter for a random word and it will be "
        <<"given to you: ";
    cin>>firstLetter;
    
    
    do{
        cout<<"\nDo you wish to proceed with \""<<firstLetter
            <<"\" as your letter of choice?\nEnter \"y\" for YES "
            <<"or \"n\" for NO: ";

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

//Game mode that allows the user to set the amount of rounds they wish to 
//complete before winning
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

//Game mode that allows user to enter a custom word for another player
//This word will then be added to the library of words for future games
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
                    cout<<"Invalid Input: The character inputed does "
                        <<"not match \"y\" for YES or \"n\" for NO. "
                        <<"Please try again.\n";
                    cout<<endl;
                }
            }while(confirm != 'y' && confirm != 'Y' && confirm != 'N'
                    && confirm != 'n');
       
        
    }while(confirm == 'N' && confirm == 'n');
    
    coreGame(1);
}

//Displays the title when game loads
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

//Displays the current status of the game
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


//Displays the rules & extra features of the game during the menu
void Hangman::rulesDisplay(){
    cout<<endl<<endl;
    cout<<"\t\t\t\t==================== Rules of the Game ====================";
    cout<<endl;
    cout<<"Winning Condition: Quess all the letter or entire word correctly "
        <<"before getting 7 wrongs (before hangman fully displays) to win.\n";
    cout<<"\n-------------------- Player Option --------------------\n";
    cout<<"\t1) Guess entire word - Player gets to guess the entire word, if "
        <<"guessed correctly s/he will instantly, if not, then s/he will lose.";
    cout<<"\n\t2) Safe Mode - Active by entering \"2\" to safely guess the word "
        <<"without losing a guess.\n\t\t(Note: Player may only use this option "
        <<"once per round)\n";
    cout<<"\n-------------------- Game Modes --------------------"<<endl;
    cout<<"\t1) Normal Hangman"<<endl;
    cout<<"\t2) EZ Mode - Player gets to enter pick the first letter for "
        <<"the mystery word along with repeats of that letter within that same"
        <<"\n\t\tword if present.\n";
    cout<<"\t3) Marathon Mode - Player gets to choose the number of rounds "
        <<"thnumRoundey wish to go through before completing the game.\n";
    cout<<"\t4) Custom Word Mode - Player add a word to be the mystery word "
        <<"for the round. Afterwards the entered word will be a new installment"
        <<" of\n\t\tthe game as it is now on the World List and can be "
        <<"called upon again.\n";
    cout<<endl<<endl;

    //Returns to the menu after displaying the rules
    menuDisplay();
}