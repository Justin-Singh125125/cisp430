#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//functions
void handleReadFile(vector<string>& names, vector<string>& deleteNames) {

	//read from a text file
	ifstream read("input.txt");

	//read entire text file
	while (read.good()) {
		string data;

		getline(read, data);

		//check if the current line of the text file has delete
		//if it does, push data to deleteNames vector
		if (!data.find("delete")) {

			//push data to deleteNames vector
			deleteNames.push_back(data);
		}

		//if the current line does not contain a delete
		else {

			//push data to names array
			names.push_back(data);
		}
	}

}

void handleDisplayVector(vector<string> list) {
	for (vector<string>::iterator it = list.begin(); it != list.end(); it++) {
		cout << *it << endl;
	}
}
int main() {

	//declare a vector for the names
	vector<string> names;

	//declare a vector for the names we are going to delete
	vector<string> deleteNames;

	//pass in vectors to fill them with data from text file
	handleReadFile(names, deleteNames);

	
	handleDisplayVector(names);
	handleDisplayVector(deleteNames);






	return 0;
}