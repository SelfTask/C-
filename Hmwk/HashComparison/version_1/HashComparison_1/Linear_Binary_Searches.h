/* 
 * File:   Linear_Binary_Searches.h
 * Author: Kevin
 *
 * Created on May 19, 2018, 5:08 PM
 */

#ifndef LINEAR_BINARY_SEARCHES_H
#define LINEAR_BINARY_SEARCHES_H


#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <cmath>


using namespace std;

//*****************************************************************
// The searchList function performs a linear search on an         *
// integer array. The array list, which has a maximum of numElems *
// elements, is searched for the number stored in value. If the   *
// number is found, its array subscript is returned. Otherwise,   *
// -1 is returned indicating the value was not in the array.      *
//*****************************************************************
 int searchList(const string list[], int numElems, string value)
 {
    int index = 0; // Used as a subscript to search array
    int position = -1; // To record position of search value
    bool found = false; // Flag to indicate if the value was found
    
    while (index < numElems && !found){
        if (list[index] == value) // If the value is found
        {
            found = true; // Set the flag
            position = index; // Record the value's subscript
        }
    
        index++; // Go to the next element
      
    }

    
    return position; // Return the position, or -1
}
 


 

//***************************************************************
// The binarySearch function performs a binary search on an     *
// integer array. array, which has a maximum of size elements,  *
// is searched for the number stored in value. If the number is *
// found, its array subscript is returned. Otherwise, -1 is     *
// returned indicating the value was not in the array.          *
//***************************************************************
int binarySearch(const string array[], const int size, string value)
{
    int first = 0, // First array element
    last = size - 1, // Last array element
    middle, // Midpoint of search
    position = -1; // Position of search value
    bool found = false; // Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2; // Calculate midpoint

        if (array[middle] == value) // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value){ // If value is in lower half
            last = middle - 1;
        }else{
         
            first = middle + 1; // If value is in upper half
        }
        
    }
    return position;
}


#endif /* LINEAR_BINARY_SEARCHES_H */

