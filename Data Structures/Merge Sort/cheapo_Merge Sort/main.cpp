/* 
 * File:   main.cpp
 * Author: dangerouspirate
 * Purpose: Practicing Basic Merge Sort
 * Created on May 7, 2018, 10:19 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <array>

using namespace std;

void displayArray(int*, const int);
void sortArr(int *, int);
void mergeSort(int *, int *, int, int, int *);

int main(int argc, char** argv) {
    const int size = 30;                //Holds the size of the full array
    int *arrMain = new int [size];      //Allocate memory for unsorted array
    
    //Seed for random number generator
    srand(time(NULL));
    
    //Filling array with random integers
    for(int i = 0; i < size; i++){
        *(arrMain + i) = rand()%9+1;
        //*(arrMain + i) = i;
    }
    
    int sz_a = size/2, 
        sz_b;
    
    //Checks if the total # of elements is odd or even to set the size for higher bound
    if(size%2 == 0){
        sz_b = size/2;
    }else{
        sz_b = size/2 + 1;
    }
        
    //Declaring Upper and Lower arrays to be sorted and later merge sorted
    int *arr1 = new int[sz_a];
    int *arr2 = new int[sz_b];
    
    
    //Assign values into Upper and Lower arrays
    for(int i = 0; i < sz_a; i++)
        arr1[i] = arrMain[i];
    
    int tempIndx = sz_b;    //Stores the size of lower array to increment the 2nd half of the main unsorted array
    
    for(int i = 0; i <= sz_b; i++){
        arr2[i] = arrMain[tempIndx++];
    }
    
    //Dislays unsorted elements of all arrays
    cout<<"\nMain Array = ";
    
    displayArray(arrMain, size);
    
    cout<<"\nArray 1 = ";
    
    displayArray(arr1, sz_a);
    
    cout<<"\nArray 2 = ";
    
    displayArray(arr2, sz_b);
    
    //Sorting Upper and Lower arrays
    sortArr(arr1, sz_a);
    sortArr(arr2, sz_b);
    
    //Display sorted arrays
    cout<<"\n\n\t\t\t--- SORTED ---\n";
    
    cout<<"\nArray 1 = ";
    
    displayArray(arr1, sz_a);
    
    cout<<"\nArray 2 = ";
    
    displayArray(arr2, sz_b);
    
    
    //Begin Merge sort after Upper and Lower arrays have been sorted themselves
    mergeSort(arr1, arr2, sz_a, sz_b, arrMain);
    
    cout<<"\n\n\t\t\tMerge Sort Completed";
    cout<<"\n------------------------------------------------------------------------\n";
    cout<<"\nMain Array = ";
    displayArray(arrMain, size);
    
    //Deallocate Memory
    delete[] arrMain;
    delete[] arr1;
    delete[] arr2;

    return 0;
}

//Display a given array
void displayArray(int *a, const int s){
    for(int i = 0; i < s; i++)
        cout<<"  "<<a[i];
}

//Use to sort upper and lower arrays
void sortArr(int *a, int s){
    for(int i = 0; i < s; i++){
        for(int j = i + 1; j < s; j++){
            if(a[i] > a[j] && i != j){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

//Use to compare Upper and Lower arrays to be sorted inside the main array again
void mergeSort(int *a, int *b, int sz_a, int sz_b, int *arrM){
 
    int cntl = 0, cnth = 0;
    
    for(int i = 0; i < sz_a + sz_b; i++){
        if(cntl == sz_a){
            arrM[i]=b[cnth++];
        }else if(cnth==sz_b){
            arrM[i]=a[cntl++];
        }else if(a[cntl]<b[cnth]){
            arrM[i]=a[cntl++];
        }else{
            arrM[i]=b[cnth++];
        }
    }
}