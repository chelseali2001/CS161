/******************************************************
** Program: fortune_teller.cpp
** Author: Chelsea Li
** Date: 01/12/2020
** Description: This program tells you your fortune based on your input.
** Input: 3 chars, 1 int, and 1 short int.
** Output: 5 fortunes (or message) with the 5 inputs.
******************************************************/

#include <iostream>
using namespace std;

int main() {
	// I assume number of kids, years left, and days left is between 0 and 100.
	// So a short (min 0, max 65,535) is sufficient.
	short number_of_kids, years_left, days_left;
	
	// I assume lottery prize is between 0 and 4,000,000,000.
	// So an int (min 0, max 4,294,967,295) is sufficient.
	int lottery_prize;
	
	// I assume car worth is between 0 and 10,000,000.
	// So a float (min 0, max 3.4e38) is sufficient.
	float car_worth;
	
	cout << "Enter a number" <<endl;
	cin >> number_of_kids;
	
	cout << "Enter a number" <<endl;
	cin >> years_left;
	
	cout << "Enter a number" <<endl;
	cin >> days_left;
	
	cout << "Enter an integer" <<endl;
	cin >> lottery_prize;
	
	cout << "Enter a number" <<endl;
	cin >> car_worth;
	
	cout << "You will have " << number_of_kids << " kid(s)." <<endl;
	cout << "You will live for another " << years_left << " year(s)." <<endl;
	cout << "You will meet your significant other in about " << days_left << " day(s)." <<endl;
	cout << "Next time you buy a lottery ticket, you will win $" << lottery_prize << "." <<endl;
	cout << "You're dream car will worth $" << car_worth << "." <<endl;
	
	return 0;
}