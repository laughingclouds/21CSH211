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

void bubbleSort(std::vector<int> &arr) {
  for (int i = 0; i < arr.size() - 1; i++) {
    for (int j = 0; j < arr.size() - i - 1; j++) {
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
    }
  }
}

int main() {
  std::vector<int> arr{9, 5, 1, 4, 3};
  bubbleSort(arr);
  printArr(arr);
  return 0;
}