#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_ROW = 5;
const int MAX_COLUMN = 4;

void displayColumn(int array[MAX_ROW][MAX_COLUMN], int column){
    
    for(int row = 0; row < MAX_ROW; row++){
        cout << array[row][column] << endl;
    }
}

//bubble sort function that will sort an entire column based off the column that
//is passed in

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int array[MAX_ROW][MAX_COLUMN], int column){
    
    int i, j;
    bool swapped;
    for (i = 0; i < MAX_ROW; i++)
    {
        swapped = false;
        for (j = 0; j < MAX_ROW -1; j++)
        {
            if (array[j][column] > array[j+1][column])
            {
                swap(&array[j][column], &array[j+1][column]);
                swapped = true;
            }
        }
        
        // IF no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
}

void initalizeArray(int array[MAX_ROW][MAX_COLUMN]){

    //for loop to initalize 2d array with random values 1-10
    
    
    for(int row = 0; row < MAX_ROW; row++){
        for(int column=0; column< MAX_COLUMN;column++){
           array[row][column] = rand() % 10;
           
        }
    }
     
     
    
    /*
     
     
     
    array[0][0] = 5;
    array[1][0] = 9;
    array[2][0] = 4;
    array[3][0] = 2;
    array[4][0] = 7;
     
     */



    
}

int main() {
    
    //initalize a 2d array of 5 rows and 4 columns
    int array[MAX_ROW][MAX_COLUMN];
    
 
    

    
    initalizeArray(array);
    
    

    cout << "BEFORE BUBBLE SORT COLUMN 1: " << endl;
    displayColumn(array, 0);
    
    
    bubbleSort(array, 0);
    
cout << "AFTER BUBBLE SORT COLUMN 1: " << endl;
    displayColumn(array, 0);
    

    
    return 0;
}
