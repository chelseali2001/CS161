#include <iostream>
using namespace std;

void count_punctuation(string s, int& n_periods, int& n_commas) {
	for (int x = 0; x < s.length(); x++) {
		if (s[x] == ',') {
			n_commas++;
		} else if (s[x] == '.') {
			n_periods++;
		}
	}
}

void count_punctuation2(string s, int* n_periods, int* n_commas) {
	for (int x = 0; x < s.length(); x++) {
		if (s[x] == ',') {
			n_commas++;
		} else if (s[x] == '.') {
			n_periods++;
		}
	}
}

int main() {
	string input = "";
	int m = 0, n = 0;
	
	cout << "Enter value: ";
	cin >> input;

	count_punctuation(input, m, n);

	cout << "The number of periods are: " << m <<endl;
	cout << "The number of commas are: " << n <<endl;

	m = 0;
	n = 0;

	count_punctuation2(input, &m, &n);

	cout << "\nWith pointers: " <<endl;
	cout << "The number of periods are: " << m <<endl;
	cout << "The number of commas are: " << n <<endl;

	return 0;
	/*
	 * Test Cases:
	 * "adsf" = 0 periods and 0 commas
	 * "a.ersg,.er" = 2 periods and 1 comma
	 * ".....,,," = 5 periods and 3 commas
	 */
}
