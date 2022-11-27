#include <iostream>
#include <vector>

void printArr(std::vector<int> arr) {
  for (int val: arr)
    std::cout << val << ' ';
  std::cout << '\n';
}


int main() {
  std::vector<int> arr{1, 2, 3, 4, 5, 6};
  printArr(arr);
  return 0;
}