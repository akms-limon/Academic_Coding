#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int leftSize = mid - low + 1, rightSize = high - mid;

    int left[leftSize], right[rightSize];
    for (int i = 0; i < leftSize; i++) {
        left[i] = arr[low + i];
    }
    for (int i = 0; i < rightSize; i++) {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;
    while ((i < leftSize) && (j < rightSize)) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < rightSize) {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void printArr(int arr[], int low, int high) {
    cout << "Merge: ";
    for (int i = low; i <= high; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        printArr(arr, low, mid);
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        printArr(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {1, 5, 7, 4, 2, 6, 3};
    int n = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, n - 1);

    for (auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}