#include <iostream>
using namespace std;
int arr[] = {3, 4, 2, 9, 8, 6, 5, 7};
int n = sizeof(arr) / sizeof(arr[0]);
void quickSort(int arr[], int low, int high) {
if (low >= high) return;
// menentukan data tengah sebagai pivot
int mid = low + (high - low) / 2;
int pivot = arr[mid];
int i = low, j = high;
while (i <= j) {
while (arr[i] < pivot) {
i++;
}
while (arr[j] > pivot) {
j--;
}
if (i <= j) { // Tukar elemen jika berada di posisi yang salah
swap(arr[i], arr[j]);
i++;
j--;
}
}
// Rekursi untuk bagian kiri dan kanan array
if (low < j) {
quickSort(arr, low, j);
}
if (i < high) {
quickSort(arr, i, high);
}
}

ALPRO LANJUT / INFORMATIKA UNMUL 7

MODUL ALPRO LANJUT

INFORMATIKA
UNIVERSITAS MULAWARMAN

int main() {
cout << "Data Belum Terurut: ";
for (int i = 0; i < n; i++) {
cout << arr[i] << " ";
}
quickSort(arr, 0, n - 1);
cout << endl << "Hasil Quick Sort: ";
for (int i = 0; i < n; i++) {
cout << arr[i] << " ";
}
return 0;
}