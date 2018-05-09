/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Hashing Lab 05/09/18 
 * Purpose: Determine when the first collision occurs and the maximum number of collisions.
 *              Dynamically create arrays -> sizes from 2^10 to 2^25.
 *              Randomly choose an element, increment the element by 1.
 *              Record when first collision occurred and find the maximum number of collisions.
 * Created on May 8, 2018, 9:25 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>    //Used to get a random num
#include <cmath>    //Used to abtain size 2^x

using namespace std;

int Hash(int n){

return rand()%n; }

int main(int argc, char** argv) {
    //Seed for RNG
    srand(time(NULL));

    int numCollision = 0;       //Stores max numbers of collisions
    int N;                      //Holds the size
    bool firstColli = false;    //use to check if a collision is the first for alert
  
    for(int x = 10; x <= 25; x++){
        cout<<"\nLet x = "<<x<<endl;
        N = pow(2, x);   //Assigning size with 2^x

        //Allocating memory
        int *arr = new int[N];   //Allocating memory for array with new size
        
        //Assign randomly chosen element then incrementing it by 1
        for(int i = 0; i < N; i++)
            arr[i] = Hash(rand());

        //Randomly picking an index to be incremented by 1
        int rndIndx = rand()%N;
        
        //Checking for collision with nested loop
        for(int i = rndIndx; i < N; i++)
            for(int j = i + 1; j < N; j++){
                if(arr[i] == arr[j] && j != i){
                    if(firstColli == false)
                        cout<<"\n****** First Collision Occurred when x = "<<x
                            <<", indexes: "<<i<<" & "<<j<<", with hash vale = "
                            <<arr[i]<<endl;
                    
                    firstColli = true;  //If first collision had occured
                    numCollision++;     //counts the number of max collisions
                    //cout<<"Update Check on Collision Count = "<<numCollision<<endl;
                }
            }
        //Deallocate memory
        delete[] arr;
        cout<<"\n------------------------------------------------------------\n";
    }
    cout<<"\nMax Number of Collisions = "<<numCollision<<endl;
    return 0;
}

