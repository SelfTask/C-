/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kevin
 *
 * Created on May 9, 2018, 8:40 AM
 */

#include <cstdlib>
#include <iostream>

void printArrow();

//Overloaded function to show intake of magnitudes of pointers through parameter
void addToMe(int *);
void addToMe(int **);
void addToMe(int ***);
void addToMe(int ****);

using namespace std;


int main(int argc, char** argv) {
    int var = 95;
    int *ptr = &var;
    int **dptr = &ptr;
    int ***tptr = &dptr;
    int ****qptr = &tptr;
    
    cout<<"Variable = "<<var<<"\t\t\t\t --- addr_of self = "<<&var<<endl;
    printArrow();
    cout<<"Pointer = "<<*ptr<<"\t\t\t\t --- addr_of self = "<<&ptr<<"\t --- addr_pointing to = "<<ptr<<endl;
    printArrow();
    cout<<"Double Pointer = "<<**dptr<<"\t\t\t --- addr_of self = "<<&dptr<<"\t --- addr_pointing to = "<<dptr<<endl;
    printArrow();
    cout<<"Triple Pointer = "<<***tptr<<"\t\t\t --- addr_of self = "<<&tptr<<"\t --- addr_pointing to = "<<tptr<<endl;
    printArrow();
    cout<<"Quadruple Pointer = "<<****qptr<<"\t\t\t --- addr_of self = "<<&qptr<<"\t --- addr_pointing to = "<<qptr<<endl;
    
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t ---- Changing Values with Pointers (FIRST to QUADRUPLE) ----\n";
    cout<<"++var = "<<++var<<endl;
    printArrow();
    cout<<"++Pointer = "<<++*ptr<<"\t\t\t\t --- addr_of self = "<<&ptr<<"\t --- addr_pointing to = "<<ptr<<endl;
    printArrow();
    cout<<"++Double Pointer = "<<++**dptr<<"\t\t\t --- addr_of self = "<<&dptr<<"\t --- addr_pointing to = "<<dptr<<endl;
    printArrow();
    cout<<"++Triple Pointer = "<<++***tptr<<"\t\t\t --- addr_of self = "<<&tptr<<"\t --- addr_pointing to = "<<tptr<<endl;
    printArrow();
    cout<<"++Quadruple Pointer = "<<++****qptr<<"\t\t --- addr_of self = "<<&qptr<<"\t --- addr_pointing to = "<<qptr<<endl;
    cout<<"\nvar NOW = "<<var;
    
    cout<<endl<<endl<<endl<<"\t\t\t --- Now Accepting Magnitudes of Pointers thru Parameters as Arguments ---"<<endl<<endl;
    addToMe(ptr);
    addToMe(dptr);
    addToMe(tptr);
    addToMe(qptr);
    
    
    
    return 0;
}

void printArrow(){
    cout<<"       ^"<<endl;
    cout<<"       |"<<endl;
             
}


void addToMe(int *p){
    cout<<"*p = "<<*p<<"\t\t\t\t --- addr_of self = "<<&p<<"\t --- addr_pointing to = "<<p<<endl;

}

void addToMe(int **p){
    cout<<"**p = "<<**p<<"\t\t\t\t --- addr_of self = "<<&p<<"\t --- addr_pointing to = "<<p<<endl;
}

void addToMe(int ***p){
    cout<<"***p = "<<***p<<"\t\t\t\t --- addr_of self = "<<&p<<"\t --- addr_pointing to = "<<p<<endl;
}

void addToMe(int ****p){
    cout<<"****p = "<<****p<<"\t\t\t\t --- addr_of self = "<<&****p<<"\t --- addr_pointing to = "<<p<<endl;
}

