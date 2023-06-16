#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];

    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    cout << "Partition"
         << " ";
    for (int k = low; k <= high; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;
    return i;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int part = partition(arr, low, high);
        cout << low << " " << part << " " << high << endl;
        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);
    }
}

int main() {
    int arr[] = {1, 5, 7, 4, 2, 6, 3};
    int n = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, n - 1);

    for (auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}