/*****************************************************************8
 ** Program: lab2_values.cpp
 ** Authors: Chelsea and Sukhjot
 ** Date: 01/13/2020
 ** Description: Program asks user to input number of bits. It calculates and prints the maximum and minimum signed values that can be stored in b bits, and the maximum unsigned value.
*****************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

int main()

{
        int inputBits;
        cout << "Please enter a positive integer: " << endl;
        cin >> inputBits;

        cout << "The maximum unsigned value is " << pow (2, inputBits) - 1 << endl;

        cout << "The maximum signed value is " << pow (2, inputBits - 1) -1 << endl;

        cout << "The minimum signed value is " << pow ( -2, inputBits - 1) - 1 << endl;

		int max_int = pow (2, 32 - 1);
		int min_int = pow (2, 32 - 1) -2;
		
		cout << "Max: " << max_int <<endl;
		cout << "Min: " << min_int <<endl;

        return 0;
}
