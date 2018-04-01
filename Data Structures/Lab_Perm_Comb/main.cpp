/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Assignment: Lab Permutation/Combination 03/31/18  
 * Purpose: Compare permutations and combinations with and without replacement.
 * Course: CSC-17C (42475)
 * Created on March 26, 2018, 1:58 PM
 */

#include <cstdlib>
#include <iostream>
#include "cmath"
using namespace std;

//Prototypes
float permReplacement(const int, const int);
double combReplacement(const int, const int);
float perm(const int, const int);
float comb(const int, const int);
double factorial(const int);
void display(const int, const int);

int main(int argc, char** argv) {
    //holds the minimum and maximum of n
    const int n_min = 2;
    const int n_max = 26;
    
    cout<<"** Note: double data type was used to avoid \"nan\" in some calculations\n\n";
    
    //Displays results from n.minimum to n.maximum
    for(int n = n_min; n <= n_max; n++){
        for(int m = 0; m <= n; m++){
            display(n, m);
        }
    }
    
    cout<<"** Note: double data type was used to avoid \"nan\" in some calculations\n\n";
    return 0;
}

//Calculates Permutations with Repetition
float permReplacement(const int n,const int m){
    return pow(n, m);
} 

//Calculates Combination with Repetition
double combReplacement(const int n, const int m){
    double numerator = factorial(n + m - 1);
    double denominator = factorial(n-1) * factorial(m);
return numerator/denominator;}

//Calculates Factorial
double factorial(const int size){
    double factorial = 1.0;
    for(int i = 1; i <= size; ++i)
    {
        factorial *= i;
    }
return factorial;}

//Calculates Permutation w/out Repetition
float perm(const int n, const int m){
    return factorial(n)/factorial(n-m);
}

//Calculates Permutation w/out Repetition
float comb(const int n, const int m){
    return factorial(n)/(factorial(m)*factorial(n-m));
}

//Displays all the results
void display(const int n, const int m){
    cout<<endl<<"\tN = Total Elements = "<<n<<"   --------------   M = Number of elements to take from total = "<<m<<endl<<endl;
    cout<<"Permutation w/ Rep: N^M = \t\t\t"<<permReplacement(n, m)<<endl;
    cout<<"Permutation No Rep: N!/(N-M) = \t\t\t"<<perm(n, m)<<endl;
    
    cout<<endl;
    cout<<"Combination w/ Rep: (N+M-1)!/((N-1)! M!) = \t"<<combReplacement(n, m)<<endl;
    cout<<"Combination No Rep: N!/((N-M)! M!) = \t\t"<<comb(n, m)<<endl;
    cout<<"\n____________________________________________________________________________________________________________________\n\n";
}