#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

struct Node
{
	Node *next;
	int data;
};

struct Queue
{
	Node *front;
	Node *rear;
};

const int SIZE = 10;

void enqueue(Queue &q, int data)
{

	if (!q.front)
	{
		q.front = new Node;
		q.rear = q.front;
		q.front->data = data;
		q.front->next = NULL;
	}
	else
	{
		//we are going to be adding at the rear everytime for queue
		q.rear->next = new Node;
		q.rear = q.rear->next;
		q.rear->data = data;
		q.rear->next = NULL;
	}
}

int dequeue(Queue &q)
{

	if (!q.front)
	{
		return NULL;
	}
	int value = 0;
	Node *temp = q.front;
	if (q.front == q.rear)
	{
		q.front = q.rear = NULL;
		value = temp->data;
	}
	else
	{
		q.front = q.front->next;
		value = temp->data;
	}
	delete temp;
	return value;
}

void convertInt(int *arr, string *stringArr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = stoi(stringArr[i]);
	}
}

int getMax(int *arr, int SIZE)
{
	int mx = arr[0];
	for (int i = 1; i < SIZE; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void radixSortDecending(Queue *q, int arr[], int arrSize)
{

	//find the maximum number to know the number of digits we going to go by
	int m = getMax(arr, arrSize);

	//number of passes
	for (int n = 1; n <= m; n *= 10)
	{

		//number of items in array
		for (int i = 0; i < arrSize; i++)
		{

			int queueIndex = arr[i] % (10 * n);
			queueIndex /= n;

			enqueue(q[queueIndex], arr[i]);
		}

		//now we need to dequeue and put the items into the array

		int count = 0;
		for (int i = arrSize - 1; i >= 0; i--)
		{

			while (q[i].front != NULL)
			{
				arr[count] = dequeue(q[i]);
				count++;
			}
		}
	}
}

void convertString(int *arr, string *stringArr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		stringArr[i] = to_string(arr[i]);
	}
}

// A utility function to swap two elements
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1);	 // Index of smaller element

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

void convertToArray(vector<string> vec, int arr[])
{
	int count = 0;
	for (std::vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i)
	{
		arr[count] = stoi(*i);
		count++;
	}
}

template <class Container>
void split(const std::string &str, Container &cont, char delim = ' ')
{
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delim))
	{
		cont.push_back(token);
	}
}

void readFile(vector<string> &vec)
{

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
	int *arr = new int[arrSize];

	convertToArray(vec, arr);

	//quick sort from last pivot
	quickSort(arr, 0, arrSize - 1);

	cout << "AFTER QUICK SORT" << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << endl;
	}

	//convert array to string
	string *stringArr = new string[arrSize];

	convertString(arr, stringArr, arrSize);

	int m = getMax(arr, arrSize);

	//get num of characters to have
	string temp = to_string(m);
	int numCount = temp.size();

	for (int i = 0; i < arrSize; i++)
	{

		if ((stringArr[i].size()) < numCount)
		{

			int count = stringArr[i].size();
			for (int j = 0; j < (numCount - count); j++)
			{
				stringArr[i] += "5";
			}
		}
	}

	convertInt(arr, stringArr, arrSize);

	delete[] stringArr;

	Queue q[SIZE];

	//initalize all queues and stacks to NULL
	for (int i = 0; i < 10; i++)
	{
		q[i].front = q[i].rear = NULL;
	}

	radixSortDecending(q, arr, arrSize);

	cout << "AFTER RADIX SORT" << endl;
	for (int i = arrSize - 1; i >= 0; i--)
	{
		cout << arr[i] << endl;
	}
	cout << endl;

	delete[] arr;
	return 0;
}
