#include <iostream>
using namespace std;

// Fungsi untuk menukar posisi dua elemen dalam array
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk melakukan Bubble Sort
void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Jika tidak ada pertukaran pada iterasi ini, array sudah terurut
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array sebelum diurutkan: ";
for (int i : arr ) cout << i << " ";
    cout << endl;

    bubbleSort(arr, n);

    cout << "Array setelah diurutkan: ";
    for (int i : arr ) cout << i << " ";
    cout << endl;

    return 0;
}
