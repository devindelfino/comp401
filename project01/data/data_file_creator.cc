// generates random data file for binomial heap

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	string filename;
	cout << "Enter the name of the file you wish to create (without extension): ";
	cin >> filename;
	filename += ".dat";
	
	// seed random number generator
	srand(time(NULL));

	int upper_bound;
	int length;
	cout << "Number of integers in file: ";
	cin >> length;
	cout << "Upper bound for integer values: ";
	cin >> upper_bound;

	ofstream fout;
	fout.open(filename);

	if(fout.fail()) {
		cout << "Error opening " << filename << endl;
		return 0;
	}

	int random_int = 0;
	for(int i = 0; i < length; i++) {
		random_int = rand() % upper_bound;
		fout << random_int;
		if(i != length-1) {
			fout << endl;
		}
	}

	fout.close();

	return 0;
}