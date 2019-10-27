#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

void convertInt(int* arr, string* stringArr, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		arr[i] = stoi(stringArr[i]);
	}
}

int getMax(int arr[], int SIZE)
{
	int mx = arr[0];
	for (int i = 1; i < SIZE; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void convertString(int* arr, string* stringArr, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		stringArr[i] = to_string(arr[i]);
	}

}

// A utility function to swap two elements  
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot  
	int i = (low - 1); // Index of smaller element  

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot  
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element  
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int *arr, int low, int high)
{
	if (low > high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before  
		// partition and after partition  
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void convertToArray(vector<string> vec, int arr []) {
	int count = 0;
	for (std::vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
		arr[count] = stoi(*i);
		count++;
	}
}


template <class Container>
void split(const std::string& str, Container& cont, char delim = ' ')
{
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delim)) {
		cont.push_back(token);
	}
}

void readFile(vector<string> &vec) {
	
	//read from text file
	ifstream read("input.txt");
	
	//read the text
	string text;

	getline(read, text);

	split(text, vec, ' ');

	
}
int main()
{
	//create a vector
	 vector<string> vec;
	
	//cread from file
	readFile(vec);

	//dynamically allocate an array
	int arrSize = vec.size();
	int* arr = new int[arrSize];

	convertToArray(vec, arr);

	//quick sort from last pivot
	quickSort(arr,0, arrSize-1);



	
	//convert array to string
	string *stringArr = new string [arrSize];

	convertString(arr, stringArr, arrSize);

	int m = getMax(arr, arrSize);


	//get num of characters to have
	string temp = to_string(m);
	int numCount = temp.size();

	
	for (int i = 0; i < arrSize; i++) {
		
		if (stringArr[i].size() < numCount) {

			int count = stringArr[i].size();
			for (int j = 0; j < (numCount - count); j++) {
				stringArr[i] += "5";
			}
		}
	}


	convertInt(arr, stringArr, arrSize);

	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}

