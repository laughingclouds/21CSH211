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

void selectionSort(std::vector<int> &arr) {
  for (int phase = 0; phase < arr.size() - 1; phase++) {
    int minI = phase;
    for (int step = phase + 1; step < arr.size(); step++) {
      if (arr[step] < arr[minI])
        minI = step;
    }
    swap(arr[phase], arr[minI]);
  }
}

int main() {
  std::vector<int> arr{9, 5, 1, 4, 3};
  selectionSort(arr);
  printArr(arr);
  return 0;
}