#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = 8;  

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Execution order" << endl;
    for (int i = 0; i < n; i++) {
        swap(&arr[0], &arr[n - 1 - i]);
        cout << arr[n - 1 - i] << endl;
        heapify(arr, n - 1 - i, 0);
    }

    return 0;
}
