#include <iostream>
#include <cmath>

using namespace std;

void max_heapify(double A[], int heap_size, int i) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest = i;

    if (l <= heap_size && A[l - 1] > A[i - 1]) {
        largest = l;
    }

    if (r <= heap_size && A[r - 1] > A[largest - 1]) {
        largest = r;
    }

    if (largest != i) {
        swap(A[i - 1], A[largest - 1]);
        max_heapify(A, heap_size, largest);
    }
}

void build_max_heap(double A[], int length) {
    int heap_size = length;
    for (int i = floor(heap_size / 2); i >= 1; --i) {
        max_heapify(A, heap_size, i);
    }
}

void heap_sort(double A[], int length) {
    build_max_heap(A, length);
    int heap_size = length;
    for (int i = heap_size; i >= 2; --i) {
        swap(A[0], A[i - 1]);
        heap_size -= 1;
        max_heapify(A, heap_size, 1);
    }
}

int main() {
    int length;
    cout << "Enter the number of elements: ";
    cin >> length;

    double* arr = new double[length];

    cout << "Enter the elements: ";
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }

    heap_sort(arr, length);

    cout << "Sorted array: ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
