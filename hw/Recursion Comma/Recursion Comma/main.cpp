#include <iostream>
#include <iomanip>

template <class T>
void RecursiveCommas(std::ostream &os, T n)
{
	T rest = n % 1000; //"last 3 digits"
	n /= 1000;		   //"begining"

	if (n > 0)
	{
		RecursiveCommas(os, n); //printing "begining"

		//and last chunk
		os << ',' << std::setfill('0') << std::setw(3) << rest;
	}
	else
		os << rest; //first chunk of the number
}

int main()
{
	RecursiveCommas(std::cout, 1087045);

	return 0;
}