/*****************************************************************
** Program: assign6_trains.cpp
** Author: Chelsea Li
** Date: 03/14/2020
** Description: This program simulates a train journey.
** Input: 1D array objects and ints.
** Output: A simulated train journey.
*****************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

//Structure defining a train car
struct train_car {
    /*
     * string kind is for the type of train car.
     * I used a string because I am assuming the user will enter more than one character.
     * I also don't know how long the string will be.
     * If I used a C-style string I'll have to set the max amount of characters.
     */
    string kind;

    /*
     * unsigned short is for the number of people in a train car.
     * I am assuming the number is greater than 0 but less than 100.
     * So a unsigned short (min 0, max 65,535) is sufficient.
     */
    unsigned int current;

    /*
     * unsigned short is for the maximum number of people in a train car.
     * I am assuming the number is greater than 0 but less than or equal to 20.
     * So a unsigned short (min 0, max 65,535) is sufficient.
     */
    int max;

    /*
     * train_car* keeps track of the train cars.
     */ 
    train_car* next_car;
};

/***************************************************************************************************
 ** Function: add_cars
 ** Description: Recursively add new train cars to the train.
 ** Parameters: train_car* train, int cars, int max[3], int index
 ** Pre-Conditions: 1 1D train_car object array, 2 ints, and 1 1D int array
 ** Post-Conditions: Creates the whole train.
***************************************************************************************************/
void add_cars(train_car* train, int cars, int max[3], int index) {
    //Add another train car
    train->next_car = new train_car;
    train->next_car->next_car = NULL;

    srand(time(NULL));

    if (cars == 0) {
        train->next_car->kind = "Caboose";
        train->next_car->current = 0;
        train->next_car->max = 0;
    } else {
        train->next_car->kind = "_***_";
        train->next_car->current = 0;
        train->next_car->max = max[index];
        add_cars(train->next_car, cars - 1, max, index + 1);
    }
}

/***************************************************************************************************
 ** Function: print_train
 ** Description: Recursively print the train, one car at a time.
 ** Parameters: train_car* train
 ** Pre-Conditions: 1 1D train_car object array
 ** Post-Conditions: Prints the whole train.
***************************************************************************************************/
void print_train(train_car* train) {
    //Print this car 
    cout << train->kind << "(" << train->current << "/" << train->max << ")";

    if (train->kind == "Caboose") {
        cout <<endl;
    } else {
        print_train(train->next_car);
    }
}

/***************************************************************************************************
 ** Function: add_passengers
 ** Description: Recursively adds the passengers to the train cars.
 ** Parameters: train_car* train, int& passengers
 ** Pre-Conditions: 1 1D train_car object array and 1 int&
 ** Post-Conditions: Adds the passengers to the train.
***************************************************************************************************/
void add_passengers(train_car* train, int& passengers) {
    if (train->kind == "_***_" && train->current < train->max && passengers > 0) {
        train->current++;
        passengers--;
        add_passengers(train, passengers);
    } else if (train->kind != "Caboose") {
        add_passengers(train->next_car, passengers);
    }
} 

/***************************************************************************************************
 ** Function: add_passengers
 ** Description: Recursively delete the memory for the train.
 ** Parameters: train_car* train
 ** Pre-Conditions: 1 1D train_car object array
 ** Post-Conditions: Deletes the memory for the train.
***************************************************************************************************/
void delete_train(train_car* train) {
    if (train->kind == "Caboose") {
        delete train;
    } else {
        delete_train(train->next_car);
        delete train;
    }
}

int main() {
    train_car* trains[5];
    int lengths[5];
    int maxes[5][4];
    int passengers = 0;

    srand(time(NULL));

    cout << "5 trains and their lengths:" <<endl;

    //Getting the lengths of the trains and the max number of people per car
    for (int x = 0; x < 5; x++) {
        lengths[x] = rand() % 4 + 1;

        for (int i = 0; i < lengths[x]; i++) {
            maxes[x][i] = rand() % 11 + 10;
        }
    }

    //Creating the trains
    for (int x = 0; x < 5; x++) {
        trains[x] = new train_car;

        trains[x]->kind = "Engine";
        trains[x]->current = 0;
        trains[x]->max = 0;
        trains[x]->next_car = NULL;

        add_cars(trains[x], lengths[x], maxes[x], 0);

        cout << x << ") ";
        print_train(trains[x]);
        cout << "   Length " << lengths[x] + 2 <<endl;
    }

    cout << "\nThe journey begins, using Train 0!" << "\n" <<endl;
    print_train(trains[0]);

    //Simulates a 5 station train journey with the first train
    for (int x = 1; x <= 5; x++) {
        cout << "\nStation " << x << ": How many new passengers? ";
        cin >> passengers;
        add_passengers(trains[0], passengers);
        print_train(trains[0]);
        cout << " Seated all but " << passengers << " passengers from Station " << x <<endl;
    }

    //Deleting memory
    for (int x = 0; x < 5; x++) {
        delete_train(trains[x]);
    }

    return 0;
}
