#include <iostream>
#include <stdlib.h>
#include <fstream>

#include "SortFunctions.h"

/////make functions return operations instead


using namespace std;

int main(){
    //open/create csv file
    ofstream outputFile;
    outputFile.open("sortComparison.csv");
    if(!outputFile){
        cout << "file not available" << endl;
        return -1;
    }

    //declare variables
    const int NUM_TRIALS = 10000;
    srand(0);
    int arraySize;
    int nOperations = 0;
    int newValue;
    int mergeWorstCase = 0;
    int selectionWorstCase = 0;

    //add first line as a header for csv
    outputFile << "n, MS operations, SS operations" << endl;

	//loop to run each trial
	for(int i = 0; i < NUM_TRIALS; i++){
        // set array size to rand number 2-100
        arraySize = rand() % 99 + 2;
        //add array size to csv output
        outputFile << arraySize << ",";

        //set size of arrays
        int arrMergeSort[arraySize];
        int arrSelectSort[arraySize];

        // loop through arrays and set random values
        for(int i = 0; i < arraySize; i++){
            // append rand number 1-1000 to arrays
            newValue = rand() % 1000 + 1;
            arrMergeSort[i] = newValue;
            arrSelectSort[i] = newValue;
        }

        //sort array using merge sort and save output to track number of operations
        nOperations = MergeSort(arrMergeSort, (int)0, arraySize - 1);
        //track worst case
        if(nOperations > mergeWorstCase){
            mergeWorstCase = nOperations;
        }
        //add number of operations for merge sort to output
        outputFile << nOperations << ",";

        //sort array using selection sort and save output to track number of operations
        nOperations = SelectionSort(arrSelectSort, arraySize);
        //track worst case
        if(nOperations > selectionWorstCase){
            selectionWorstCase = nOperations;
        }
        //add number of operations for selection sort to output
        outputFile << nOperations << endl;
    }

    outputFile << "Worst Merge:," << mergeWorstCase << ",Worst Selection:," << selectionWorstCase << endl;

    //close output file
    outputFile.close();

    cout << "Trials Complete" << endl;

    return 0;
}
