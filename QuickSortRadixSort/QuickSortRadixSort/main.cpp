#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

//max size for array
const int MAX_SIZE = 10;


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

void readFile(vector<string> vec, int arr []) {
	
	//read from text file
	ifstream read("input.txt");
	
	//read the text
	string text;

	getline(read, text);

	split(text, vec, ' ');

	convertToArray(vec, arr);
}
int main()
{
	//create a vector
	 vector<string> vec;

	 //create an array
	 int arr[MAX_SIZE];
	
	//cread from file
	readFile(vec, arr);


	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}

