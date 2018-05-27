/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dangerouspirate
 *
 * Created on February 22, 2018, 4:12 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

void menu(char *);
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
int doSomething(int *, int *);
void prob6();

int main(int argc, char** argv) {
    char inSelect;
    
    do{
        menu(&inSelect);
    
        switch(inSelect){
            case '1': prob1(); break;
            case '2': prob2(); break;
            case '3': prob3(); break;
            case '4': prob4(); break;
            case '5': prob5(); break;
            case '6': prob6(); break;
        
            case 'e': cout<<"\nProgram Terminating..."<<endl; break;
            default: cout<<"Error: Invalid Input"<<endl;
        };
        
        if(inSelect == 'E')
            inSelect = 'e';
    }while(inSelect != 'e');
    
    return 0;
}


void prob6(){
    int numDonation;
    
    cout<<"How many number of donations will be inputted: ";
    cin>>numDonation;
    
    //Dynamically Allocating Memory
    int *donation = new int [numDonation];
    
    for(int i = 0; i < numDonation; i++){
        do{
            cout<<"Enter in Donation #1"<<(i+1)<<": $";
            cin>>donation[i];
            if(donation[i] < 0)
                cout<<"Input Validation: donation value must be $0 or more."<<endl;
        }while(donation[i] < 0);
    }
    
    int *arrPtr[numDonation];
    
    delete[] donation;
}




int doSomething(int *x, int *y){
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}

void prob5(){
    int a, b;
    
    cout<<"Enter x: ";
    cin>>a;
    
    cout<<"Enter y: ";
    cin>>b;
    
    cout<<"doSomething(&a, &b): "<< doSomething(&a, &b)<<endl;
}

void prob4(){
    int index;
    
    cout<<"Enter number of student(s): ";
    cin>>index;
    
    //Dynamically allocate memory for un-predefined variable
    int *score = new int [index];
    string *name = new string [index];
    
    bool sameElement = true;
    
    for(int i = 0; i < index; i++){
        cout<<"Enter NAME then SCORE of Entry #"<<(i+1)<<": ";
        cin>>*(name + i)>>*(score+i);
        
        if(*score != *(score+i))
            sameElement = false;
    }
    
    if(sameElement == false){
        for(int i = 0; i < index; i++){
            for(int j = i; j < index; j++){
                if(*(score+i) > *(score+j) && i != j){
                    int tempScore = *(score+j);
                    *(score + j) = *(score + i);
                    *(score + i) = tempScore;
                    
                    string tempName = *(name+j);
                    *(name + j) = *(name + i);
                    *(name + i) = tempName;
                }    
            }
        }
    }
    
    cout<<"Name\t\tScore"<<endl;
    cout<<"-----------------------"<<endl;
    
    for(int i = 0; i < index; i++)
        cout<<*(name+i)<<"\t\t"<<*(score+i)<<endl;
    
    
    delete[] name;
    delete[] score;

}

void prob3(){
    int numStud;
    bool sameElement = true;
    
    //Enter number of elements
    cout<<"Enter Number of Students: ";
    cin>>numStud;
    
    //Remember to dynamically allocate after entering the number of elements or else bad_sec error
    int *score = new int [numStud];
    string *name = new string [numStud];
    
    //Loops through for entering each data
    for(int i = 0; i < numStud; i++){
        cout<<"Enter NAME then SCORE of student #"<<(i+1)<<": ";
        cin>>*(name+i)>>*(score+i);
        
        //sorts if all elements are identical
        if(*score != *(score + i))
            sameElement = false;
    }
    

    int index_lowestScore = 0; //Stores index with the lowest score
    int temp = *(score); //Stores lowest score for further comparison
    
    //Searches for the index with the lowest score if elements are not all identical
    if(sameElement == false){
        for(int i = 0; i < numStud; i++)
            if(temp > score[i]){
                temp = score[i];
                index_lowestScore = i;
            }
    
    }
    
   
    //Prints out list
    cout<<"Name\t\tScore\n"
        <<"--------------------------------------------\n";
    
    if(sameElement == false){
        for(int i = 0; i < numStud; i++)
            if(i != index_lowestScore)
                cout<<*(name + i)<<"\t\t"<<*(score+i)<<endl<<endl;
    }else if(sameElement == true){
        cout<<"hello"<<endl;
        for(int i = 0; i < numStud; i++){
            cout<<*(name+i)<<"\t\t"<<*(score+i)<<endl<<endl;
        }
    }
    
    delete[] score;
    delete[] name;
    
}

void prob2(){
    int size;
    
    cout<<"Enter number of entries: ";
    cin>>size;
    
    int *arrScore = new int[size];
    string *arrName = new string[size];
    
    for(int i = 0; i < size; i++){
        
        do{
            cout<<"Enter Name then Score of ENTRY #"<<(i+1)<<": ";
            cin>>*(arrName+i)>>*(arrScore+i);
            
            if(*(arrScore+i) < 0)
                cout<<"\nInput Validation: Do not accept negative numbers for test scores.\n";
            
        }while(*(arrScore+i) < 0);
    }
    
    cout<<"\nName\t\tScore\n";
    cout<<"-----------------------------------\n";
    
    for(int i = 0; i < size; i++){
        cout<<*(arrName+i)<<"\t\t"<<*(arrScore+i)<<endl;
    }
    
    delete[] arrScore;
    delete[] arrName;
}

void prob1(){
    int inSize;
    
    cout<<"How many elements in the array: ";
    cin>>inSize;
    
    int *arrNum = new int [inSize];
    
    for(int i = 0; i < inSize; i++){
        cout<<"Enter element #"<<(i+1)<<": ";
        cin>>*(arrNum+i);
    }
    
    for(int i = 0; i < inSize; i++)
        cout<<"["<<*(arrNum+i)<<"] ";
}

void menu(char *inSelect){
    cout<<"\n\n1) Array Allocator - Interchagge uses between Pointer and Array"<<endl;
    cout<<"2) Test Scores #1 - User pointer to display Names and corresponding Scores"<<endl;
    cout<<"3) Drop Lowest Score - Displays Name with Score but drops the lowest Score"<<endl;
    cout<<"4) Use pointers to sort score list then display it"<<endl;
    cout<<"5) Changing References to Pointers in parameter"<<endl;
    cout<<"6) Rewrite Program 9-17 so that it can take any number of donations with dynamically allocating memory"<<endl;
    
    
    cout<<"\nEnter 'e' to Exit"<<endl;
    cout<<"\nUser Input: ";
    cin>>*inSelect;
        
}
