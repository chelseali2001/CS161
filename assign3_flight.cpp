/*****************************************************************
** Program: assign3_flight.cpp
** Author: Chelsea Li
** Date: 02/09/2020
** Description: This program simulates a flight.
** Input: Unsiged and signed integers.
** Output: Flight time, cost, and an animation of the flight.
*****************************************************************/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <unistd.h>
using namespace std;

/*************************************************************************
 ** Function: flight_simulation
 ** Description: Simulates the flight.
 ** Parameters: int time, int seconds, int flight
 ** Pre-Conditions: 2 unsigned ints and 1 bool
 ** Post-Conditions: Simulates the flight
*************************************************************************/
void flight_simulation(unsigned int time = 600, unsigned int seconds = 1, bool flight = false);

/*************************************************************************
 ** Function: flight_duration
 ** Description: Calculates the duration of the flight (in minutes).
 ** Parameters: int distance, int airSpeed, int windSpeed
 ** Pre-Conditions: 2 unsigned ints and 1 signed int
 ** Post-Conditions: Returns the flight duration in the form of an int.
*************************************************************************/
int flight_duration(unsigned int distance, unsigned int airSpeed, signed int windSpeed) {
    // I assume totalSpeed below is a positive number that can be in the form of a decimal.
	// So an unsigned int (min 0, max 65,535) is sufficient.
    unsigned int totalSpeed = airSpeed - windSpeed;

    return ((float) distance / (float) totalSpeed) * 60;
}

/***********************************************************************************
 ** Function: flight_cost
 ** Description: Calculates the cost of the flight.
 ** Parameters: int fuelRate, int fuelPrice, float flight_time, int people
 ** Pre-Conditions: 3 unsigned ints and 1 float
 ** Post-Conditions: Returns the cost of the flight in the form of a float.
***********************************************************************************/
float flight_cost(unsigned int fuelRate, unsigned int fuelPrice, float flight_time, unsigned int people) {
    // I assume the values below are going to be in the form of a decimal.
	// So a float (min 0, max 3.4*10^38) is sufficient.
    float totalGallons = (float) fuelRate * flight_time;
    float fuelCost = totalGallons * (float) fuelPrice;
    float cost_per_person = fuelCost / (float) people;

    return cost_per_person;
}

/*************************************************************************
 ** Function: flight_simulation
 ** Description: Simulates the flight.
 ** Parameters: int time, int seconds, int flight
 ** Pre-Conditions: 2 unsigned ints and 1 bool
 ** Post-Conditions: Simulates the flight
*************************************************************************/
void flight_simulation(unsigned int time, unsigned int seconds, bool flight) {
    string fly = "";

    // I assume hours is going to be positive and a whole number.
    // So an unsigned int (min 0, max 65,535) is sufficient.
    unsigned int hours = ceil((float) time / 60);

    if (flight) {
        fly = "<=";

        for (int x = 0; x < hours; x++) {
            sleep(seconds);

            for (int i = hours; i > x + 1; i--) {
                cout << "  ";
            }

            cout << fly << "\r";
        }

    } else {
        fly = "=>";

        for (int x = 0; x < hours; x++) {
            sleep(seconds);   

            cout << fly;          
        }
    }

    cout << "\n";
}

int main() {
    // I assume the values below are going to be positive and can be a large number.
	// So a unsigned int (min 0, max 65,535) is sufficient.
    unsigned int distance = 0, 
                 airSpeed = 0, 
                 fuelRate = 0, 
                 fuelPrice = 0, 
                 people = 0, 
                 seconds = 0,
                 flight_time = 0,
                 return_time = 0;

    // I assume windSpeed is going to be postive or negative and can be a large number.
	// So a signed int (min -32,768, max 32,767) is sufficient.
    signed int windSpeed = 0; 

    bool good = false;  

    cout << "Please provide the following flight information:";

    while (!good) {
        cout << "\n1) Flight distance (miles): ";
        cin >> distance;

        if (distance > 0) {
            good = true;
        } else {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Error: invalid input";
        }
    }

    while (good) {
        cout << "\n2) Airplane airspeed (miles per hour): ";
        cin >> airSpeed;

        if (airSpeed > 0) {
            good = false;
        } else {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Error: invalid input";
        }
    }

    cout << "\n3) Wind speed (miles per hour): ";

    while (!(cin >> windSpeed)) {
        cin >> windSpeed;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Error: invalid input";
        cout << "\n3) Wind speed (miles per hour): ";
    }

    while (!good) {
        cout << "\n4) Fuel burn rate (gallons per hour): ";
        cin >> fuelRate;

        if (fuelRate > 0) {
            good = true;
        } else {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Error: invalid input";
        }
    }

    while (good) {
        cout << "\n5) Fuel price (dollars per gallon): ";
        cin >> fuelPrice;

        if (fuelPrice > 0) {
            good = false;
        } else {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Error: invalid input";
        }
    }

    while (!good) {
        cout << "\n6) Number of people onboard: ";
        cin >> people;

        if (people > 0) {
            good = true;
        } else {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Error: invalid input";
        }
    }

    while (good) {
        cout << "\n7) Seconds of animation per flight hour: ";
        cin >> seconds;

        if (seconds > 0) {
            good = false;
        } else {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Error: invalid input";
        }
    }

    flight_time = flight_duration(distance, airSpeed, windSpeed);
    return_time = flight_duration(distance, airSpeed, windSpeed * -1);

    cout << "\nLoading results" <<endl;
    flight_simulation();

    cout << "\nYour flight will take " << flight_time / 60 << " hour(s) and " << flight_time - ((flight_time / 60) * 60) << " minute(s) " 
         << "and cost $" << fixed << setprecision(2) << flight_cost(fuelRate, fuelPrice, (float) flight_time / 60, people) << " per person." <<endl;
    flight_simulation(flight_time, seconds, false);
    
    cout << "\nYour return flight will take " << return_time / 60 << " hour(s) and " << return_time - ((return_time / 60) * 60) << " minute(s) "
         << "and cost $" << fixed << setprecision(2) << flight_cost(fuelRate, fuelPrice, (float) return_time / 60, people) << " per person." <<endl;
    flight_simulation(return_time, seconds, true);

    return 0;
}