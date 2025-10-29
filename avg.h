#ifndef AVERAGE_H
#define AVERAGE_H
#include <iostream>
using namespace std;

float findAverage(int numbers[], int size) {
    float sum = 0.0f;
    for (int i = 0; i < size; ++i) {
        sum += numbers[i];
    }
    return sum / size;
}

void runAverage() {
    int size;
    cout << "Enter number of elements: ";
    cin >> size;
    int numbers[size];
    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) cin >> numbers[i];

    cout << "Average = " << findAverage(numbers, size) << endl;
}
#endif

