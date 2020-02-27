#include <iostream>
using namespace std;

/*
 * Test cases:
 * 6.2, 1.3, 2.7 = 3.4
 * 1, 2, 3 = 2
 * 5, 6, 7 = 6
*/

int main() {
    int size = 0;
    float total = 0;

    cout << "Hello Scientists! You need to record the rainfall per city (in inches)." <<endl;
    cout << "How many cities would you like to record the rainfall of: ";

    cin >> size;

    float* arr = new float[size];

    for (int x = 0; x < size; x++) {
        cout << "How much rainfall was there in city " << x << ": ";
        cin >> arr[x];
        total += arr[x];
        cout <<endl;
    }

    cout << "Average rainfall per city: " << (float) total / (float) size << " inches." <<endl;
    
    delete arr;
    
    return 0;
}