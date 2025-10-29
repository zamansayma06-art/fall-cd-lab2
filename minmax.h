#ifndef MINMAX_H
#define MINMAX_H
#include <iostream>
using namespace std;

void minMax(int arr[], int size, int &min, int &max) {
    min = arr[0];
    max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
}

void runMinMax() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int min, max;
    minMax(arr, n, min, max);
    cout << "Min value = " << min << endl;
    cout << "Max value = " << max << endl;
}
#endif

