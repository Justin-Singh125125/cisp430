#include <iostream>
using namespace std;
void display(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void shellShowI(int a[], int n) {
	int temp;
	for (int gap = n / 2; gap >= 1; gap = gap / 2)
	{
		for (int i = gap; i < n; i++)
		{

			for (int j = i; j >= gap && a[j - gap] > a[j]; j = j - gap) {
				temp = a[j - gap];
				a[j - gap] = a[j];
				a[j] = temp;
			}
			cout << "i: " << i << endl;
			display(a,n);
		}
	}
		

	
}

void shellShowJ(int a[], int n) {
	int temp;
	for (int gap = n / 2; gap >= 1; gap = gap / 2)
		for (int i = gap; i < n; i++)
			for (int j = i; j >= gap && a[j - gap] > a[j]; j = j - gap) {
				temp = a[j - gap];
				a[j - gap] = a[j];
				a[j] = temp;

				cout << "j: " <<j<< endl;
				display(a, n);
			}

}
int main() {
	int a[] = {43,22,17,36,16};
	shellShowJ(a, 5);
}