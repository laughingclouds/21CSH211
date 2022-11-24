#include <iostream>

void merge(int arr[], int mid, int first, int last) {
  int i, j, k, finalArr[100];
  i = first;
  j = mid + 1;
  k = first;
  while (i <= mid && j <= last) {
    if (arr[i] < arr[j]) {
      finalArr[k] = arr[i];
      i++;
      k++;
    } else {
      finalArr[k] = arr[j];
      j++;
      k++;
    }
  }
  while (i <= mid) {
    finalArr[k] = arr[i];
    k++;
    i++;
  }
  while (j <= last) {
    finalArr[k] = arr[j];
    k++;
    j++;
  }
  for (int i = first; i <= last; i++) {
    arr[i] = finalArr[i];
  }
}

void mergesort(int arr[], int first, int last) {
  int mid;
  if (first < last) {
    mid = (first + last) / 2;
    mergesort(arr, first, mid);
    mergesort(arr, mid + 1, last);
    merge(arr, mid, first, last);
  }
}

int main() {
  int n;
  std::cout << "Enter the number of elements: ";
  std::cin >> n;
  int arr[n];

  std::cout << "Enter the elements of the array: ";
  for (int i = 0; i < n; i++)
    std::cin >> arr[i];

  mergesort(arr, 0, n - 1);
  std::cout << "Sorted array: ";
  for (int i = 0; i < n; i++)
    std::cout << arr[i] << ' ';
  std::cout << '\n';

  return 0;
}