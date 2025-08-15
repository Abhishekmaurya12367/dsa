#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cstdlib>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;       

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]); // Swap if element is smaller than the pivot
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in the correct position
    return i + 1;
}

// Function to perform Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1);        // Sort the left subarray
        quickSort(arr, pi + 1, high);       // Sort the right subarray
    }
}

int main() {
    ofstream outFile("quick_sort_results.csv");
    outFile << "ArraySize,TimeTaken(ms)\n"; // CSV header

    vector<int> sizes = {1000, 5000, 10000, 20000, 50000}; // Different input sizes

    for (int n : sizes) {
        vector<int> arr(n);
        // Generate random numbers
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100000; // Random numbers in the range [0, 99999]
        }

        // Measure sorting time
        auto start = chrono::high_resolution_clock::now();
        quickSort(arr, 0, n - 1);
        auto end = chrono::high_resolution_clock::now();

        // Calculate elapsed time in milliseconds
        double timeTaken = chrono::duration<double, milli>(end - start).count();
        cout << "Array size: " << n << ", Time taken: " << timeTaken << " ms\n";
        outFile << n << "," << timeTaken << "\n"; // Write results to the file
    }

    outFile.close();

    cout << "\nResults saved to 'quick_sort_results.csv'. Use a plotting tool to plot the graph.\n";
    return 0;
}
