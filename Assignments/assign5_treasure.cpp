/*****************************************************************
** Program: assign5_treasure.cpp
** Author: Chelsea Li
** Date: 03/08/2020
** Description: This program stores items in a treasure chest.
** Input: 2D array objects and ints.
** Output: A treasure chest full of moon rocks.
*****************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct treasure {
    /*
     * string name is for the name of the moon rock
     * I used a string because I am assuming the user will enter more than one character.
     * I also don't know how long the string will be.
     * If I used a C-style string I'll have to set the max amount of characters.
     */
    string name;

    /*
     * string color is for the color of the moon rock
     * I used a string because I am assuming the user will enter more than one character.
     * I also don't know how long the string will be.
     * If I used a C-style string I'll have to set the max amount of characters.
     */
    string color;

    /*
     * string texture is for the texture of the moon rock
     * I used a string because I am assuming the user will enter more than one character.
     * I also don't know how long the string will be.
     * If I used a C-style string I'll have to set the max amount of characters.
     */
    string texture;

    /*
     * float weight is for the weight of the moon rock
     * I am assuming weight is going to be a large number and it may not be an exact integer.
     * So a float (min 0, max 3.4E38) is sufficient.
     */
    float weight;

    /*
     * float value is for the value of the moon rock
     * I am assuming value is going to be a large number and it may not be an exact integer.
     * So a float (min 0, max 3.4E38) is sufficient.
     */
    float value;
};

/**************************************************************************************************************************************************
 ** Function: treasure_chest
 ** Description: Displays the contents of the treasure chest and tells you if the treasure chest is empty.
 ** Parameters: treasure** items, int rows, int columns
 ** Pre-Conditions: 1 2D array treasure object and 2 ints.
 ** Post-Conditions: Prints out the contents of the treasure chest and returns a bool showing whether or not the treasure chest is empty.
**************************************************************************************************************************************************/
bool treasure_chest(treasure** items, int rows, int columns) {
    bool empty = true;

    for (int x = 0; x < rows; x++) {
        for (int i = 0; i < columns; i++) {
            if (items[x][i].name == "") {
                cout << "|_";
            } else {
                cout << "|" << items[x][i].name[0];
                empty = false;
            }
        }

        cout << "|" <<endl;
    }

    return empty;
}

/**************************************************************************************************************************************************
 ** Function: full
 ** Description: Determines whether or not the treasure chest is full.
 ** Parameters: treasure** items, int rows, int columns
 ** Pre-Conditions: 1 2D array treasure object and 2 ints.
 ** Post-Conditions: Returns a boolean that indicates whether or not the treasure chest is full.
**************************************************************************************************************************************************/
bool full(treasure** items, int rows, int columns) {
    int total = 0;

    for (int x = 0; x < rows; x++) {
        for (int i = 0; i < columns; i++) {
            if (items[x][i].name != "") {
                total++;
            }
        }
    }

    if (total == rows * columns) {
        return true;
    } else {
        return false;
    }
}

/**************************************************************************************************************
 ** Function: total_value
 ** Description: Tells you the total value of the moon rocks and how many of them there are.
 ** Parameters: treasure** items, int rows, int columns
 ** Pre-Conditions: 1 2D array treasure object and 2 ints.
 ** Post-Conditions: Prints the total value of the moon rocks and how many of them there are.
**************************************************************************************************************/
void total_value(treasure** items, int rows, int columns) {
    float total = 0;
    int item_num = 0;

    for (int x = 0; x < rows; x++) {
        for (int i = 0; i < columns; i++) {
            total += items[x][i].value;

            if (items[x][i].name != "") {
                item_num++; 
            }
        }
    }

    cout << "Total value of " << item_num << " items: $" << total <<endl;
}

/**************************************************************************************************************
 ** Function: in_bounds
 ** Description: Checks if the chosen location is in bounds.
 ** Parameters: int rows, int columns, int desired_row, int desired_col
 ** Pre-Conditions: 4 ints
 ** Post-Conditions: Returns a bool indicating whether or not the chosen location is in bounds.
**************************************************************************************************************/
bool in_bounds(int rows, int columns, int desired_row, int desired_col) {
    if (desired_row >= 0 && desired_row < rows && desired_col >= 0 && desired_col < columns) {
        return true;
    } else {
        return false;
    }
}

/**************************************************************************************************************
 ** Function: area_check
 ** Description: Tells you if there's already an item at the chosen location.
 ** Parameters: treasure** items, int desired_row, int desired_col
 ** Pre-Conditions: 1 2D array treasure object and 2 ints.
 ** Post-Conditions: Returns a bool indicating whether or not there's an item at the chosen location.
**************************************************************************************************************/
bool area_check(treasure** items, int desired_row, int desired_col) {
    if (items[desired_row][desired_col].name == "") {
        return true;
    } else {
        return false;
    }
}

/****************************************************************************************************************************
 ** Function: row_col_check
 ** Description: Tells you if the location is valid for the operation.
 ** Parameters: treasure** items, int rows, int columns, int desired_row, int desired_col, int choice, bool new_choice
 ** Pre-Conditions: 1 2D array treasure object, 5 ints, and 1 bool.
 ** Post-Conditions: Returns a bool indicating whether or not the location is valid for the chosen operation.
****************************************************************************************************************************/
bool row_col_check(treasure** items, int rows, int columns, int desired_row, int desired_col, int choice, bool new_choice) {
    if (in_bounds(rows, columns, desired_row, desired_col)) {
        if (!area_check(items, desired_row, desired_col) && (choice == 1 || choice == 3 || (choice == 5 && new_choice))) {
            cout << "There's already an item at this location. Try again" <<endl;
        } else if (area_check(items, desired_row, desired_col) && choice == 2) {
            cout << "There is no item to remove. Try again" <<endl;
        } else if (area_check(items, desired_row, desired_col) && choice == 4) {
            cout << "There is no item to show. Try again" <<endl;
        } else if (area_check(items, desired_row, desired_col) && choice == 5 && !new_choice) {
            cout << "There is no item to move. Try again" <<endl;
        } else if (area_check(items, desired_row, desired_col) && choice == 6) {
            cout << "There is no item to edit. Try again" <<endl;
        } else {
            return true;
        }                        
    } else {
        cout << "Error: invalid coordinates. Try again" <<endl;
    }

    return false;
}

/*****************************************************************************************************************************
 ** Function: enter_row_col
 ** Description: Allows the user to enter the location for the item.
 ** Parameters: treasure** items, int rows, int columns, int choice, int& desired_row, int& desired_col, bool new_choice
 ** Pre-Conditions: 1 2D array treasure object, 3 ints, 2 int&s, and 1 bool.
 ** Post-Conditions: If the entered location is valid, the location will be used for the chosen operation.
*****************************************************************************************************************************/
void enter_row_col(treasure** items, int rows, int columns, int choice, int& desired_row, int& desired_col, bool new_choice) {
    bool good = false;

    while (!good) {
        if (new_choice) {
            cout << "\nEnter new row (int): ";
            cin >> desired_row;

            cout << "Enter new column (int): ";
            cin >> desired_col;
        } else {
            cout << "\nEnter row (int): ";
            cin >> desired_row;

            cout << "Enter column (int): ";
            cin >> desired_col;
        }

        if (row_col_check(items, rows, columns, desired_row, desired_col, choice, new_choice)) {
            good = true;
        }
    }
}

/**************************************************************************************************************
 ** Function: add_rock
 ** Description: Adds a moon rock to the treasure chest.
 ** Parameters: treasure** items, int desired_row, int desired_column
 ** Pre-Conditions: 1 2D array treasure object and 2 ints
 ** Post-Conditions: Adds a new object to the 2D array treasure object.
**************************************************************************************************************/
void add_rock(treasure** items, int rows, int columns) {
    int desired_row = 0, desired_col = 0;

    enter_row_col(items, rows, columns, 1, desired_row, desired_col, false);

    cout << "\nEnter name (string): ";
    cin >> items[desired_row][desired_col].name;

    cout << "\nEnter color (string): ";
    cin >> items[desired_row][desired_col].color;

    cout << "\nEnter texture (string): ";
    cin >> items[desired_row][desired_col].texture;

    cout << "\nEnter weight (lb, float): ";
    cin >> items[desired_row][desired_col].weight;

    cout << "\nEnter value ($, float): ";
    cin >> items[desired_row][desired_col].value;
}

/**************************************************************************************************************
 ** Function: remove_rock
 ** Description: Removes a moon rock from the treasure chest.
 ** Parameters: treasure** items, int desired_row, int desired_column
 ** Pre-Conditions: 1 2D array treasure object and 2 ints
 ** Post-Conditions: Removes an object from the 2D array treasure object.
**************************************************************************************************************/
void remove_rock(treasure** items, int rows, int columns) {
    int desired_row = 0, desired_col = 0;

    enter_row_col(items, rows, columns, 2, desired_row, desired_col, false);

    items[desired_row][desired_col].name = "";
    items[desired_row][desired_col].color = "";
    items[desired_row][desired_col].texture = "";
    items[desired_row][desired_col].weight = 0.0;
    items[desired_row][desired_col].value = 0.0;
}

/**************************************************************************************************************
 ** Function: random_rock
 ** Description: Adds a random moon rock to the treasure chest.
 ** Parameters: treasure** items, int desired_row, int desired_column
 ** Pre-Conditions: 1 2D array treasure object and 2 ints
 ** Post-Conditions: Adds a random new object to the 2D array treasure object.
**************************************************************************************************************/
void random_rock(treasure** items, int rows, int columns) {
    int desired_row = 0, desired_col = 0;
    string name[3] = {"Chelsea", "Armstrong", "Maxine"}, color[3] = {"grey", "black", "white"}, texture[3] = {"rough", "smooth", "glassy"};

    enter_row_col(items, rows, columns, 3, desired_row, desired_col, false);

    srand(time(NULL));

    items[desired_row][desired_col].name = name[rand() % 3];
    items[desired_row][desired_col].color = color[rand() % 3];
    items[desired_row][desired_col].texture = texture[rand() % 3];
    items[desired_row][desired_col].weight = ((float) (rand() % 20)) / 10.0 + 1.0;
    items[desired_row][desired_col].value = ((float) (rand() % 1000000)) / 10.0 + 50000.0;

    cout << "\nRandom moon rock: name = " << "\"" << items[desired_row][desired_col].name
         << "\", color: " << items[desired_row][desired_col].color
         << ", texture: " << items[desired_row][desired_col].texture
         << ", weight: " << items[desired_row][desired_col].weight 
         << "lb, value: $" << items[desired_row][desired_col].value <<endl;
}

/**************************************************************************************************************
 ** Function: show_rock
 ** Description: Displays the values of a moon rock from the treasure chest.
 ** Parameters: treasure** items, int desired_row, int desired_column
 ** Pre-Conditions: 1 2D array treasure object and 2 ints
 ** Post-Conditions: Prints an object from the 2D array treasure object.
**************************************************************************************************************/
void show_rock(treasure** items, int rows, int columns) {
    int desired_row = 0, desired_col = 0;

    enter_row_col(items, rows, columns, 4, desired_row, desired_col, false);

    cout << "\nMoon rock: name: " << "\"" << items[desired_row][desired_col].name 
         << "\", color: " << items[desired_row][desired_col].color
         << ", texture: " << items[desired_row][desired_col].texture
         << ", weight: " << items[desired_row][desired_col].weight
         << "lb, value: $" << items[desired_row][desired_col].value <<endl;
}

/**************************************************************************************************************
 ** Function: move_rock
 ** Description: Moves a moon rock in the treasure chest.
 ** Parameters: treasure** items, int rows, int columns, int desired_row, int desired_column
 ** Pre-Conditions: 1 2D array treasure object and 4 ints
 ** Post-Conditions: Changes the location of an object in the 2D array treasure object.
**************************************************************************************************************/
void move_rock(treasure** items, int rows, int columns) {
    bool valid = false;
    int desired_row = 0, desired_col = 0, new_row = 0, new_col = 0;

    enter_row_col(items, rows, columns, 5, desired_row, desired_col, false);
    enter_row_col(items, rows, columns, 5, new_row, new_col, true);

    items[new_row][new_col].name = items[desired_row][desired_col].name;
    items[new_row][new_col].color = items[desired_row][desired_col].color;
    items[new_row][new_col].texture = items[desired_row][desired_col].texture;
    items[new_row][new_col].weight = items[desired_row][desired_col].weight;
    items[new_row][new_col].value = items[desired_row][desired_col].value;

    items[desired_row][desired_col].name = "";
    items[desired_row][desired_col].color = "";
    items[desired_row][desired_col].texture = "";
    items[desired_row][desired_col].weight = 0.0;
    items[desired_row][desired_col].value = 0.0;
}

/**************************************************************************************************************
 ** Function: edit_rock
 ** Description: Edits a moon rock in the treasure chest.
 ** Parameters: treasure** items, int desired_row, int desired_column
 ** Pre-Conditions: 1 2D array treasure object and 2 ints
 ** Post-Conditions: Changes the values of an object in the 2D array treasure object.
**************************************************************************************************************/
void edit_rock(treasure** items, int rows, int columns) {
    int desired_row = 0, desired_col = 0;

    enter_row_col(items, rows, columns, 5, desired_row, desired_col, false);

    cout << "\nNew name (string): ";
    cin >> items[desired_row][desired_col].name;

    cout << "New color (string): ";
    cin >> items[desired_row][desired_col].color;

    cout << "New texture (string): ";
    cin >> items[desired_row][desired_col].texture;

    cout << "New weight (lb, float): ";
    cin >> items[desired_row][desired_col].weight;

    cout << "New value ($, float): ";
    cin >> items[desired_row][desired_col].value;
}

int main() {
    bool valid = false;
    int rows = 0, columns = 0, choice = 0;

    srand(time(NULL));

    cout << "Welcome to the Moon Rock Treasure Chest!" <<endl;

    //Entering the number of rows
    while (!valid) {
        cout << "Enter number of rows (int): ";
        cin >> rows;

        if (rows > 0) {
            valid = true;
        } else {
            cout << "Error: invalid input. Try again" <<endl;
        }
    }

    //Entering the number of columns
    while (valid) {
        cout << "Enter number of columns (int): ";
        cin >> columns;

        if (columns > 0) {
            valid = false;
        } else {
            cout << "Error: invalid input. Try again" <<endl;
        }
    }

    //Setting up the treasure chest
    treasure** items = new treasure*[rows];

    for (int x = 0; x < rows; x++) {
        items[x] = new treasure[columns];

        for (int i = 0; i < columns; i++) {
            items[x][i].name = "";
            items[x][i].color = "";
            items[x][i].texture = "";
            items[x][i].weight = 0.0;
            items[x][i].value = 0.0;
        }
    }

    //Main menu
    while (!valid) {
        bool empty = treasure_chest(items, rows, columns), spotted = false, correct = false;
        int affected_row = 0, affected_col = 0, new_val = 0;

        //Changing the values of the items in the chest by random
        if (!empty) {
            if (rand() % 2 == 0) {
                while (!spotted) {
                    int affected_row = rand() % rows, affected_col = rand() % columns;
                    float new_val = ((float) (rand() % 1000000)) / 10.0 + 50000.0;

                    if (items[affected_row][affected_col].name != "" && items[affected_row][affected_col].value != new_val) {
                        items[affected_row][affected_col].value = new_val;
                        
                        cout << "NASA has changed the value of the Moon rock at location [" << affected_row << "][" << affected_col << "] to " << new_val <<endl;

                        spotted = true;
                    }
                }
            }
        }

        total_value(items, rows, columns);

        //Selecting an operation
        while (!correct) {
            cout << "\n1) Add a moon rock" <<endl;
            cout << "2) Remove a moon rock" <<endl;
            cout << "3) Add random moon rock" <<endl;
            cout << "4) Show moon rock" <<endl;
            cout << "5) Move moon rock" <<endl;
            cout << "6) Edit moon rock" <<endl;
            cout << "7) Quit" <<endl;
            cout << "Please make your choice (int): ";
            cin >> choice;

            if (full(items, rows, columns) && (choice == 1 || choice == 3 || choice == 5)) {
                cout << "The treasure chest is currently full. Try again" <<endl;
            } else if (empty && (choice == 2 || choice == 4 || choice == 5 || choice == 6)) {
                cout << "The treasure chest is currently empty. Try again" <<endl;
            } else if (choice >= 1 && choice <= 7) {
                if (choice == 1) {
                    add_rock(items, rows, columns);
                } else if (choice == 2) {
                    remove_rock(items, rows, columns);
                } else if (choice == 3) {
                    random_rock(items, rows, columns);
                } else if (choice == 4) {
                    show_rock(items, rows, columns);
                } else if (choice == 5) {
                    move_rock(items, rows, columns);
                } else if (choice == 6) {
                    edit_rock(items, rows, columns);
                }

                correct = true;
            } else {
                cout << "Error: invalid input. Try again" <<endl;
            }
        }

        if (choice == 7) {
            valid = true;
        }
    }

    //Freeing memory
    for (int x = 0; x < rows; x++) {
        delete [] items[x];
    }

    delete [] items;

    return 0;
}