#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_ROW = 5;
const int MAX_COLUMN = 4;

void displayColumn(int array[MAX_ROW][MAX_COLUMN], int column)
{

	for (int row = 0; row < MAX_ROW; row++)
	{
		cout << array[row][column] << endl;
	}
}

void displayArray(int array[MAX_ROW][MAX_COLUMN]) {

	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COLUMN; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

//bubble sort function that will sort an entire column based off the column that
//is passed in

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubbleSort(int array[MAX_ROW][MAX_COLUMN], int column)
{

	int i, j;
	bool swapped;
	for (i = 0; i < MAX_ROW; i++)
	{
		swapped = false;
		for (j = 0; j < MAX_ROW - 1; j++)
		{
			if (array[j][column] > array[j + 1][column])
			{
				swap(&array[j][column], &array[j + 1][column]);
				swapped = true;
			}
		}

		// IF no two elements were swapped by inner loop, then break
		if (swapped == false)
			break;
	}
}

void selectionSort(int array[MAX_ROW][MAX_COLUMN], int column)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray  
	for (i = 0; i < MAX_ROW; i++)
	{
		// Find the minimum element in unsorted array  
		min_idx = i;
		for (j = i + 1; j < MAX_ROW; j++)
			if (array[j][column] > array[min_idx][column])
				min_idx = j;

		// Swap the found minimum element with the first element  
		swap(&array[min_idx][column], &array[i][column]);
	}
}

void shellSort(int array[MAX_ROW][MAX_COLUMN], int column)
{
	// Start with a big gap, then reduce the gap 
	for (int gap = MAX_ROW / 2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size. 
		// The first gap elements a[0..gap-1] are already in gapped order 
		// keep adding one more element until the entire array is 
		// gap sorted  
		for (int i = gap; i < MAX_ROW; i += 1)
		{
			// add a[i] to the elements that have been gap sorted 
			// save a[i] in temp and make a hole at position i 
			int temp = array[i][column];

			// shift earlier gap-sorted elements up until the correct  
			// location for a[i] is found 
			int j;
			for (j = i; j >= gap && array[j - gap][column] > temp; j -= gap)
				array[j][column] = array[j - gap][column];

			//  put temp (the original a[i]) in its correct location 
			array[j][column] = temp;
		}
	}
}

//initalize array with fixed values
void initalizeArray(int array[MAX_ROW][MAX_COLUMN])
{

	//column 1
	array[0][0] = 5;
	array[1][0] = 9;
	array[2][0] = 4;
	array[3][0] = 2;
	array[4][0] = 7;

	//column 2
	array[0][1] = 3;
	array[1][1] = 8;
	array[2][1] = 7;
	array[3][1] = 5;
	array[4][1] = 9;

	//column 3
	array[0][2] = 2;
	array[1][2] = 10;
	array[2][2] = 11;
	array[3][2] = 9;
	array[4][2] = 4;

	//column 4
	array[0][3] = 16;
	array[1][3] = 17;
	array[2][3] = 18;
	array[3][3] = 12;
	array[4][3] = 10;
}

int main()
{

	//initalize a 2d array of 5 rows and 4 columns
	int array[MAX_ROW][MAX_COLUMN];

	//set array to fixed values
	initalizeArray(array);

	cout << "BEFORE BUBBLE SORT" << endl;
	displayArray(array);

	//sort array through bubble sort
	bubbleSort(array, 0);

	cout << endl << "AFTER BUBBLE SORT" << endl;
	displayArray(array);

	//reset array
	initalizeArray(array);

	cout << endl << "BEFORE SELECTION SORT" << endl;
	displayArray(array);

	selectionSort(array, 1);

	cout << endl << "AFTER SELECTION SORT" << endl;
	displayArray(array);

	//reset the array
	initalizeArray(array);


	cout << endl << "BEFORE SHELL SORT" << endl;
	displayArray(array);

	shellSort(array, 2);

	cout << endl << "AFTER SHELL SORT" << endl;
	displayArray(array);
	





	return 0;
}
