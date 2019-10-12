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

void displayArray(int array[MAX_ROW][MAX_COLUMN])
{

	for (int i = 0; i < MAX_ROW; i++)
	{
		for (int j = 0; j < MAX_COLUMN; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
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

void insertionSort(int array[MAX_ROW][MAX_COLUMN], int row)
{
	int i, key, j;
	for (i = 1; i < MAX_COLUMN; i++)
	{
		key = array[row][i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && array[row][j] > key)
		{
			array[row][j + 1] = array[row][j];
			j = j - 1;
		}
		array[row][j + 1] = key;
	}
}

int binarySearch(int arr[MAX_ROW][MAX_COLUMN], int l, int r, int x, int row)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[row][mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[row][mid] > x)
			return binarySearch(arr, l, mid - 1, x, row);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x, row);
	}

	// We reach here when element is not
	// present in array
	return -1;
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

	cout << endl
		 << "AFTER BUBBLE SORT" << endl;
	displayArray(array);

	//reset array
	initalizeArray(array);

	cout << endl
		 << "BEFORE SELECTION SORT" << endl;
	displayArray(array);

	selectionSort(array, 1);

	cout << endl
		 << "AFTER SELECTION SORT" << endl;
	displayArray(array);

	//reset the array
	initalizeArray(array);

	cout << endl
		 << "BEFORE SHELL SORT" << endl;
	displayArray(array);

	shellSort(array, 2);

	cout << endl
		 << "AFTER SHELL SORT" << endl;
	displayArray(array);

	//reset the array
	initalizeArray(array);

	cout << endl
		 << "BEFORE INSERTION SORT" << endl;
	displayArray(array);

	insertionSort(array, 4);

	cout << endl
		 << "AFTER INSERTION SORT" << endl;
	displayArray(array);

	//ask user for a number to search in the 5th row
	int valToFind = 0;
	cout << "WHAT NUMBER ARE YOU SEARCHING FOR IN THE 5TH ROW? ";
	cin >> valToFind;

	int isFound = binarySearch(array, 0, MAX_COLUMN - 1, valToFind, 4);

	(isFound == -1) ? cout << "Number not found" << endl
					: cout << "Number found at index: " << isFound << " of row 5" << endl;

	cout << endl;
	displayArray(array);

	return 0;
}
