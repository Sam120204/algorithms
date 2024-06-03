#include <iostream>
#include <vector>

using namespace std;

/// https://www.youtube.com/watch?v=WprjBK0p6rw
// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = (low - 1);     // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of the smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    cout << "Unsorted array: ";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}

/* Example Walkthrough for QuickSort Partition Function */

/* Initial Array */
.array {
    content: "[10, 7, 8, 9, 1, 5]";
}

/* Step 1: Choose the last element as pivot */
.pivot {
    content: "pivot = 5";
}

/* Step 2: Initialize i */
.initial-i {
    content: "i = -1";
}

/* Step 3: Iterate through the array */

/* j = 0, arr[j] = 10 */
.step1-j0 {
    content: "arr[j] = 10, 10 > 5 => no swap, i = -1";
}

/* j = 1, arr[j] = 7 */
.step2-j1 {
    content: "arr[j] = 7, 7 > 5 => no swap, i = -1";
}

/* j = 2, arr[j] = 8 */
.step3-j2 {
    content: "arr[j] = 8, 8 > 5 => no swap, i = -1";
}

/* j = 3, arr[j] = 9 */
.step4-j3 {
    content: "arr[j] = 9, 9 > 5 => no swap, i = -1";
}

/* j = 4, arr[j] = 1 */
.step5-j4 {
    content: "arr[j] = 1, 1 <= 5 => swap(arr[i+1], arr[j]), i = 0";
}

/* Array after swap */
.array-after-swap1 {
    content: "[1, 7, 8, 9, 10, 5]";
}

/* Step 4: Swap pivot with element at i+1 */
.final-swap {
    content: "swap(arr[i+1], arr[high]), swap(arr[1], arr[5])";
}

/* Final array after placing pivot */
.final-array {
    content: "[1, 5, 8, 9, 10, 7]";
}

/* Pivot index after partition */
.pivot-index {
    content: "Pivot index = 1";
}

/* Resulting subarrays */
/* Left subarray (before pivot) */
.left-subarray {
    content: "[1]";
}

/* Right subarray (after pivot) */
.right-subarray {
    content: "[8, 9, 10, 7]";
}

/* Repeat partition steps for right subarray */
