#include "RecursiveSorts.h"

//Finds min index for recursive selection sort
int RecursiveSorts::recursiveMinIndex(string w[], int indx1, int indx2){
    if (indx1 == indx2)
        return indx1;
 
    //Locates min. index for leftovers
    int indx3 = recursiveMinIndex(w, indx1 + 1, indx2);
 
    //returns min index base on values
    if(w[indx1] > w[indx3])
        return indx1;
    else
        return indx3;
}

//Has recursive bubble sort sort the words backwards
void RecursiveSorts::recurSelectionSort(string w[], int size, int indx){

    //base
    if (indx == size)
       return;

    //stores index of min value
    int minValIndx = recursiveMinIndex(w, indx, size-1);

    //Sorts array of words
    if (minValIndx != indx)
       swap(w[minValIndx], w[indx]);

    //Recursion
    recurSelectionSort(w, size, indx + 1);
}



//Has recursive bubble sort sort the words in order
void RecursiveSorts::recursiveBubbleSort(string w[], int n){
    //base
    if (n == 1)
        return;

    //sorts array by swapping base on values
    for (int i = 0; i < n-1; i++)
        if (w[i] > w[i+1])
            swap(w[i], w[i+1]);

    //Recursion
    recursiveBubbleSort(w, n-1);
}