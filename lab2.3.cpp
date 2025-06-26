#include <iostream>
using namespace std;

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Recursive Quick Sort
void quickSortRecursive(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortRecursive(arr, low, pi - 1);
        quickSortRecursive(arr, pi + 1, high);
    }
}

// Non-Recursive Quick Sort
void quickSortIterative(int arr[], int low, int high) {
    int stack[high - low + 1], top = -1;
    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];
        int pi = partition(arr, low, high);

        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }
        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}

// Driver Code
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Recursive Quick Sort
    quickSortRecursive(arr, 0, n - 1);
    cout << "Sorted array (Recursive): ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    // Reset array for iterative version
    int arr2[] = {10, 7, 8, 9, 1, 5};
    quickSortIterative(arr2, 0, n - 1);
    cout << "Sorted array (Iterative): ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << endl;

    return 0;
}
