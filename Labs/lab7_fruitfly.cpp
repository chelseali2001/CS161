#include <iostream>
using namespace std;

/*
 * Test cases:
 * 1, 2, 6, 0: max = 2, min = 3
 * 5, 1, 8, 10: max = 3, min = 1
 * 0, 19, 3, 6: max = 1, min = 0
*/

int main() {
    int flies[5];
    cout << "Hello Scientists! You have 5 jars to fill with fruit flies." <<endl;
    
    cout << "How many fruit flies would you like in jar 0" << ": ";
    cin >> flies[0];

    int max = flies[0], min = flies[0];
    int maxIn = 0, minIn = 0;

    for (int x = 1; x < 5; x++) {
        cout << "How many fruit flies would you like in jar " << x << ": ";
        cin >> flies[x];

        if (max < flies[x]) {
            max = flies[x];
            maxIn = x;
        }
        
        if (min > flies[x]) {
            min = flies[x];
            minIn = x;
        }

        cout <<endl;
    }

    cout << "The jar with the most fruit flies: jar " << maxIn <<endl;
    cout << "The jar with the least fruit flies: jar " << minIn <<endl;

    return 0;
}