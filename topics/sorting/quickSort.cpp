#include <iostream>
#include <vector>

void printArr(std::vector<int> arr) {
  for (int val: arr)
    std::cout << val << ' ';
  std::cout << '\n';
}

void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

/*Bring the pivot (rightmost element) to it's correct location*/
int partition(std::vector<int> &arr, int low, int high) {
  printArr(arr);
  int pivot = arr[high];
  int greaterI = low - 1;

  for (int smallerI = low; smallerI < high; smallerI++) {
    if (arr[smallerI] <= pivot) {
      greaterI++;
      swap(arr[greaterI], arr[smallerI]);
    }
  }

  swap(arr[greaterI], arr[high]);
  return greaterI + 1;
}

void quickSort(std::vector<int> &arr, int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}

int main() {
  std::vector<int> arr{9, 5, 1, 4, 3};
  quickSort(arr, 0, arr.size() - 1);
  printArr(arr);
  return 0;
}