#include <iostream>
#include <fstream>

using namespace std;

//function definitions
void stringCopy(char* a, char* b);
bool stringCompare(char* a, char* b);
void stringConcatenation(char* a, char* b);

//personal function 
void handleReadArrays(char* a, char* b);

int main() {

	//connect and open the text file
	ifstream read("input.txt");

	//character array definition
	char a[255], b[255];

	//read first line from text file
	read >> a >> b;

	cout << "Making a call to function stringCopy...\n";
	stringCopy(a, b);

	cout << "Data returned from stringCopy...\n";
	handleReadArrays(a, b);

	//read second line from text file
	read >> a >> b;

	cout << "Making a call to function stringCompare...\n";
	bool isIdentical = stringCompare(a, b);
	cout << "Data returned from stringCompare...\n";
	cout << "---------------------\n";
	cout << (isIdentical ? "a & b are identical!\n\n" : "a & b are not identical!\n\n");

	//read third line from text file
	read >> a >> b;
	cout << "Making a call to function stringConcatenation...\n";
	stringConcatenation(a, b);
	cout << "Data returned from stringConcaternation...\n";
	handleReadArrays(a, b);













}

//function bodies
void stringCopy(char* a, char* b) {

	//counter variable declared outside loop block so that we know where the last element is
	int i = 0;
	for (; i < strlen(b); i++) {

		//copy over elements
		a[i] = b[i];
	}

	//set the null, there is data still leftover in remaining spaces but 
	//we don't need to get rid of them because we have null in the right space
	a[i] = '\0';
}

bool stringCompare(char* a, char* b) {
	//get length of both arrays
	int aLength = strlen(a);
	int bLength = strlen(b);

	//if the two arrays are not the same length, automatically return false
	if (aLength != bLength) {
		return false;
	}

	//since both arrays will be the same length we can just check for array a lengt
	for (int i = 0; i < aLength; i++) {



		if (a[i] != b[i]) {
			return false;
		}
	}

	//if all other checks have not triggered false
	//then the characters must be the same
	return true;

}

void stringConcatenation(char* a, char* b) {
	//get length of both character arrays
	int aLength = strlen(a);
	int bLength = strlen(b);

	//new size total
	int newSize = aLength + bLength;

	//set counter to be at the end of a length
	int i = 4;
	
	//j counter for b
	int j = 0;
	for (; i < newSize; i++) {
		//concatenation
		a[i] = b[j];
		j++;
	}

	//add null element
	a[i] = '\0';
}



void handleReadArrays(char* a, char* b) {
	cout << "---------------------\n";
	cout << "a: " << a << endl;
	cout << "b: " << b << endl << endl;
}
