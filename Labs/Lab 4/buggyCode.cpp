/*****************************************************************
 ** Program: buggyCode.cpp
 ** Authors: Chelsea and Sukhjot
 ** Date: 01/27/2020
 ** Description: THERE ARE BUGS IN THE FOLLOWING CODE.
*****************************************************************/

//iostream was spelled incorrectly
#include <iostream>

//Need this namespace
using namespace std;


int main() {

	int x=3, y;
	char myAnswer;

	y = x;
	cout << "y is set to: " << y << endl;
 
  //The again variable wan't declared properly
  //There wasn't a semi colon
	bool again = true;
	while(again){
 //Need a checking variable
    int check = 0;
    
   	cout << "Please input a number: ";
   
    //The brackets were in the wrong direction
  	cin >> x;
 
    //Need curly brackets
		if(x > y) {
			cout << "X is greater than Y\n";
      
		} else{
			cout << "X is less than Y" << endl;
		}
   
      //The brackets were in the wrong direction
      //Need quotations
			cout << "would you like to input another number? (enter 1 for yes and 0 for no)" << endl;
			cin >> check;
      
      if (check == 0) {
        again = false;
      } 
	}
 
  //The increments needed to fixed
	for(x = 0; x < 10; x = x+1)
		cout << x << endl;
	
	cout << "What number would you like to find the factorial for? " << endl;
 
  //num wasn't declared
  int num = 0;
  
  //There wasn't a semi colon
	cin >> num;
	for(int x = num - 1; x > 0; x--) {
		num *= x;
  }
  cout << num <<endl;
	cout << "Are you enjoying cs161? (y or n) " << endl;
 
  //The myAnswer variable was spelled incorrectly
	cin >> myAnswer;
 
  //The myAnswer variable was spelled incorrectly
  //myAnswer is a char and needs to be compared to a char
  //Needs '==' when comparing values
	if(myAnswer == 'y')
		cout << "YAY" << endl;
	else
		cout << "YOU WILL SOON!" << endl;

	return 0;
 
 //Missing curly bracket
 }

