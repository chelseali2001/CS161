/*****************************************************************
 ** Program: lab2_hotel.cpp
 ** Authors: Chelsea and Sukhjot
 ** Date: 01/13/2020
 ** Description: Prints random numbers
*****************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
        int hotel_floor;

        srand(time(NULL));

        hotel_floor = rand() % 6;

        if (hotel_floor == 0) {
                cout << "You are assigned to the ground floor." <<endl;
        } else if (hotel_floor % 2 != 0) {
                if (hotel_floor == 5) {
                        cout << "You are assigned to the penthouse." <<endl;                    
                } else {
                        cout << "You are assigned to an odd floor." <<endl;
                }
        } else {
                cout << "You are assigned to an even floor." <<endl;
        }
		
        return 0;
}
