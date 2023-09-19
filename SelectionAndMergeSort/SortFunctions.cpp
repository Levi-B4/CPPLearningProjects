#include <iostream>

#include "SortFunctions.h"

int SelectionSort(int array[], int numSize){
    int nOperations = 0;
    int i, j, indexSmallest, temp;

    for(i = 0; i < numSize; ++i){
        indexSmallest = i;

        //Find index of smallest remaining element
        for(j = i + 1; j < numSize; ++j){
            if(array[j] < array[indexSmallest]){
                indexSmallest = j;
				//increase number of relevant operation
				nOperations++;
            }
        }

        // Sway array[i] and array[indexSmallest]
        temp = array[i];
        array[i] = array[indexSmallest];
        array[indexSmallest] = temp;
    }
    return nOperations;
}

int Merge(int array[], int i, int j, int k){
    int nOperations = 0;
    // Size of merged partition
    int mergedSize;

    // Position to insert merged number
    int mergePos;

    // Position of elements in left partition
    int leftPos;

    // Position of elements in right partition
    int rightPos;
    int* mergedNumbers = nullptr;
	// Operation: assigns a null pointer to mergedNumbers

    mergePos = 0;
    mergedSize = k - i + 1;

    // Initialize left partition
    leftPos = i;

    // Initialize right partition
    rightPos = j + 1;

    // Dynamically allocates temporary array for merged numbers
    mergedNumbers = new int[mergedSize];

    // Add smallest element from left or right partition to merged numbers
    while(leftPos <= j && rightPos <= k){
        if(array[leftPos] < array[rightPos]){
            mergedNumbers[mergePos] = array[leftPos];
            ++leftPos;
        }
        else{
            mergedNumbers[mergePos] = array[rightPos];
            ++rightPos;
        }
        ++mergePos;
        //increase number of relevant operations
		nOperations++;
    }

    // If left partition is not empty, add remaining elements to merged numbers
    while(leftPos <= j){
        mergedNumbers[mergePos] = array[leftPos];
        ++leftPos;
        ++mergePos;
        //increase number of relevant operations
		nOperations++;
    }

    // If right partition is not empty, add remaining elements to merged numbers
    while(rightPos <= k){
        mergedNumbers[mergePos] = array[rightPos];
        ++rightPos;
        ++mergePos;
        //increase number of relevant operations
		nOperations++;
    }

    // Copy merge number back to numbers
    for(mergePos = 0; mergePos < mergedSize; ++mergePos){
        array[i + mergePos] = mergedNumbers[mergePos];
        //increase number of relevant operations
		nOperations++;
    }

    //output number of operations
    return nOperations;
}

int MergeSort(int array[],int i, int k){
    int nOperations = 0;
    int j;

    if(i < k){
        //Find the midpoint in the partition
        j = (i + k) / 2;

        nOperations += MergeSort(array, i, j);
        nOperations += MergeSort(array, j + 1, k);

        nOperations += Merge(array, i, j, k);
    }
    //output number of operations
    return nOperations;
}
