#include<bits/stdc++.h>
using namespace std;
int heighch(int* heights, int size) {
    int* expected = new int[size];

    for (int i = 0; i < size; i++) {
        expected[i] = heights[i];
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (expected[i] > expected[j]) {
                int temp = expected[i];
                expected[i] = expected[j];
                expected[j] = temp;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        if (heights[i] != expected[i]) {
            count++;
        }
    }

    delete[] expected;
    return count;
}

int main() {
    int size;
    cin >> size;

    int* heights = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> heights[i];
    }

    int mismatches = heightch(heights, size);
    cout  << mismatches << endl;

    delete[] heights;
    return 0;
}