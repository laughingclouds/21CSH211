#include <iostream>

void insertionSort(int arr[], int n) {
  int key, j;
  for (int i = 1; i <= n - 1; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main() {
  int len;
  std::cout << "Enter number of elements: ";
  std::cin >> len;

  int arr[len];

  std::cout << "Enter elements: ";
  for (int i = 0; i < len; i++)
    std::cin >> arr[i];

  insertionSort(arr, len);

  std::cout << "Sorted array: ";
  for (int i = 0; i < len; i++)
    std::cout << arr[i] << ' ';
  std::cout << '\n';

  return 0;
}