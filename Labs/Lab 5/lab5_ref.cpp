#include <iostream>
using namespace std;

/****************************************************************
 ** Function: plus_10_value
 ** Description: Adds 10 to the given value
 ** Parameters: int n
 ** Pre-Conditions: An given integer.
 ** Post-Conditions: Returns the given integer plus 10.
 ***************************************************************/
int plus_10_value(int n) {
    return n + 10;
}

/****************************************************************
 ** Function: plus_10_ref
 ** Description: Adds 10 to the given value
 ** Parameters: int& n
 ** Pre-Conditions: An given integer.
 ** Post-Conditions: No return.
 ***************************************************************/
void plus_10_ref(int& n) {
    n += 10;
}

int main() {
    int n = 0, m = 0;

    cout << "Enter an integer: ";
    cin >> n;

    cout << "Enter another integer: ";
    cin >> m;

    cout << "Your number plus 10 is: " << plus_10_value(n) <<endl;
    plus_10_ref(m);
    cout << m <<endl;
    return 0;
}
