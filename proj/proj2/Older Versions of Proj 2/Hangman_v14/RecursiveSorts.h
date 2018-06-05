/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RecursiveSorts.h
 * Author: DangerousPirate
 *
 * Created on June 3, 2018, 4:23 PM
 */

#ifndef RECURSIVESORTS_H
#define RECURSIVESORTS_H
#include <iostream>
using namespace std;

class RecursiveSorts{
    private:
        // Return minimum index
        int recursiveMinIndex(string[], int, int);

    public:
        // Recursive selection sort. n is size of a[] and index
        // is index of starting element.
        void recurSelectionSort(string[], int, int);
        
        // A function to implement bubble sort
        void recursiveBubbleSort(string[], int);
 


};


#endif /* RECURSIVESORTS_H */

