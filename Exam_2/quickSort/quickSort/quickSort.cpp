#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
#define SIZE 6
void print_array(int arr[])
{
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void insertion_sort(int arr[])
{
	int i, j, tmp;
	for (i = 1; i < SIZE; i++) {
		for (j = i; j > 0 && arr[j] > arr[j - 1]; j--) {
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
		}

		cout << "i: " << i << endl;
		print_array(arr);
	}
}
int sum(int n) {
	if (n < 8) {
		return n + sum(n + 1);
	}
	else {
		return 2;
	}
}

void test(int i) {
	if (i < 8) {
		test(i + 1);
		cout << i << " ";
	}
}



int main() {
	
	float gigabyte = 0.0;

	cout << "how many gigs? ";
	cin >> gigabyte;

	gigabyte = ceil(gigabyte);

	cout << gigabyte << endl;
}


